
void uartInit(unsigned long baudRate) {
#if raspberryPiPicoMicroController == 1
  uart_init(UART_ID, baudRate);
  gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
  gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
  uart_init(UART1_ID, BAUD_RATE);  // Initialize UART1 with the same baud rate
  gpio_set_function(UART1_TX_PIN, GPIO_FUNC_UART);
  gpio_set_function(UART1_RX_PIN, GPIO_FUNC_UART);
#else
  Serial.begin(baudRate);
#endif
}



void uart_flush_input() {
#if raspberryPiPicoMicroController == 1
  // Clear RX FIFO directly without potentially infinite reads
  uart_set_fifo_enabled(uart0, false);  // Disable FIFO temporarily
  uart_set_fifo_enabled(uart0, true);   // Re-enable FIFO
                                        // while ( ((volatile uint32_t)readRegister(UartRegister::FR)) & (1 << 3) ) ; // bit 3 == Tx Fifo BUSY flag
#else
  // Optimized for Arduino: discard available bytes without explicit reads
  while (Serial.available() > 0) {
    Serial.read();  // Peek at the next byte without removing it
  }
#endif
}



void wait(unsigned long milliseconds) {
#if raspberryPiPicoMicroController == 1
  // For Raspberry Pi Pico
  sleep_ms(milliseconds);
#else
  // For Arduino Mega 2560
  delay(milliseconds);
#endif
}



void printLimitedChars(const char* text, int maxChars) {
  char buffer[maxChars + 1];  // Static buffer for truncation
  strncpy(buffer, text, maxChars);
  buffer[maxChars] = '\0';
  lcd.print(buffer);  // Directly print to LCD within the function
}



void scrollTextWithPrefix(const char* prefix, const char* text, int maxChars) {
  int prefixLength = strlen(prefix);
  int textLength = strlen(text);
  int totalLength = prefixLength + textLength;

  // Check if scrolling is necessary
  if (totalLength > maxChars) {
    static int shift = 0;

    // Display the fixed prefix
    for (int i = 0; i < prefixLength; i++) {
      lcd.write(prefix[i]);
    }

    // Shift and display the scrolling text
    for (int i = 0; i < maxChars - prefixLength; i++) {
      lcd.write(text[(i + shift) % textLength]);
    }

    // Increment the shift value for the next iteration
    shift = (shift + 1) % textLength;

    // Introduce a delay to control the scrolling speed
    delay(150);  // Adjust the delay to control the speed
  } else {
    // Total length fits within the 20-character limit, just display it
    lcd.print(prefix);
    lcd.print(text);
  }
}






// Function to send a string over UART with a delay between characters
void uart_send_string_with_delay(const char* str, unsigned int delay_ms) {
  for (; *str != '\0'; ++str) {
    uartPutChar(*str);
    wait(delay_ms);
  }
}


void uartPutChar(char c) {
#if raspberryPiPicoMicroController == 1
  // For Raspberry Pi Pico
  uart_putc(UART_ID, c);
#else
  // For Arduino Mega 2560
  Serial.write(c);
#endif
}





void uart_send_string_without_delay(const char* str, unsigned int delay_ms) {
  uartPutString(str);
  wait(delay_ms);
}



void uartPutString(const char* str) {
#if raspberryPiPicoMicroController == 1
  // For Raspberry Pi Pico
  uart_puts(UART_ID, str);
#else
  // For Arduino Mega 2560
  Serial.print(str);
#endif
}








void uartReceive(char* uartReceivedText, size_t uartReceivedTextSize) {
  uart_flush_input();
  readUartString(uartReceivedText, uartReceivedTextSize, RESPONSE_TIMEOUT);

  // if (uartReceivedTextSize > 0) {
  //   lcd.setCursor(19, 1);
  //   lcd.print("#");
  // } else {
  //   lcd.setCursor(19, 1);
  //   lcd.print("X");
  // }
  // uart_flush_input();
}


char readUartString(char* buffer, size_t bufferSize, unsigned long responseTimeout) {
  size_t index = 0;
  unsigned long startTime = millis();

  while (index < bufferSize - 1 && (millis() - startTime) < responseTimeout) {
    char c;
    uartGetChar(c);  // Call uartGetChar for platform-specific reading

    if (c != -1) {  // Check if a character was successfully read
      // Buffer limit check
      if (index < bufferSize - 1) {
        buffer[index++] = c;
      } else {
        buffer[bufferSize - 1] = '\0';  // Truncate and terminate
        return '\0';                    // Indicate buffer full
      }

      if (c == '\n' || c == '\r') {
        buffer[index] = '\0';
        return c;  // Indicate successful read
      }
    }
  }

  buffer[index] = '\0';  // Terminate string in case of timeout
  return '\0';           // Indicate timeout or buffer full
}


// void uartGetChar(char& c) {
// #if raspberryPiPicoMicroController == 1
//   uart_read_blocking(UART_ID, reinterpret_cast<uint8_t*>(&c), 1);  // Typecast &c to uint8_t*
//     // uart_read_blocking(UART_ID, &c, 1);  // Read directly into c using the address-of operator
//     // uart_getc(UART_ID);  // Read directly into c using the address-of operator
// #else
//   c = Serial.read();
// #endif
// }




void uartGetChar(char& c) {
#if raspberryPiPicoMicroController == 1
  unsigned long startTime = millis();
  while (uart_is_readable(UART_ID) == 0) {
    // Handle timeout
    if (millis() - startTime >= RESPONSE_TIMEOUT) {
      // Serial.println("UART timeout!");
      c = '\0';  // Indicate timeout
      return;
    }
    // Add additional logging or debugging actions here if needed
  }
  // Serial.println("UART data available");
  c = uart_getc(UART_ID);
#else
  c = Serial.read();
#endif
}
