
// Function to handle button presses
void handle_button_presses() {
  if (!buttonPressed) {
    currentMainMenuPageList();

    // Handle the select button press
    if (digitalRead(SELECT_BUTTON_PIN) == LOW) {
      if (!selectPressed) {
        switch (currentMainMenuState) {

          case MainMenu:
            // Depending on the cursor position, select the appropriate submenu
            switch (cursorPos) {
              case 0:
                lcd.clear();
                currentMainMenuState = XdcrSubMenu;
                break;
              case 1:
                lcd.clear();
                currentMainMenuState = M9414SubMenu;
                break;
              case 2:
                lcd.clear();
                currentMainMenuState = MDualSubMenu;
                break;
            }
            break;

          case XdcrSubMenu:
            // Handle the XdcrSubMenu options
            switch (cursorPos) {
              case 0:
                lcd.clear();
                currentMainMenuState = XdcrCommsBaud;
                break;
              case 1:
                lcd.clear();
                currentMainMenuState = XdcrComms;
                digitalWrite(XDCR_PWR_PIN, XDCR_PWR_ON);
                // delay(1000);
                //?????
                // lcd.setCursor(0, 3);
                // lcd.print("                    ");
                break;
              case 2:
                lcd.clear();
                currentMainMenuState = XdcrAddressAD14;
                digitalWrite(XDCR_PWR_PIN, XDCR_PWR_ON);
                // delay(1000);
                break;
            }
            break;

          case XdcrCommsBaud:
            switch (cursorPos) {
              case 0:
                lcd.clear();
                uartInit(9600);
                // uartPutString("9600\r\n");
                break;
              case 1:
                lcd.clear();
                uartInit(19200);
                // uartPutString("19200\r\n");
                break;
              case 2:
                lcd.clear();
                uartInit(57600);
                // uartPutString("57600\r\n");
                break;
            }
            break;





          case XdcrComms:
            switch (cursorPos) {

              case 0:
                {
                  char dispXDCRInfo[34];
                  lcd.clear();
                  uart_send_string_without_delay("#*ID?\r\n", 0);
                  // uart_send_string_without_delay("5 ID   Mensor,     6110,   590455, V1.10\r\n", 0);

                  uartReceive(dispXDCRInfo, 34);
                  // Serial.println(dispXDCRInfo);
                  // readUartString(dispXDCRInfo, sizeof(dispXDCRInfo), RESPONSE_TIMEOUT);
                  // readUartString(dispXDCRInfo, sizeof(dispXDCRInfo), RESPONSE_TIMEOUT);

                  if (strlen(dispXDCRInfo) > 0) {
                    char line1[18];  // Buffer for the first line (20 characters + null terminator)
                    char line2[18];  // Buffer for the second line

                    // Copy up to the first 19 characters to line1
                    strncpy(line1, dispXDCRInfo, 18);
                    // If the response is longer than 20 characters, copy the next 20 characters to line2
                    if (strlen(dispXDCRInfo) > 18) {
                      strncpy(line2, dispXDCRInfo + 18, 18);
                      // line2[19] = '\0';  // Start copying from the 21st character
                    } else {
                      line2[0] = '\0';  // If no more characters, set line2 to an empty string
                    }
                    // Display on the LCD
                    lcd.setCursor(1, 2);  // Set cursor to line 3
                    lcd.print(line1);
                    lcd.setCursor(1, 3);  // Set cursor to line 4
                    lcd.print(line2);
                    line1[0] = '\0';
                    line2[0] = '\0';
                    dispXDCRInfo[0] = '\0';
                    lcd.setCursor(19, 1);
                    lcd.print("#");

                  } else {
                    lcd.setCursor(0, 2);
                    lcd.print(" 0 ");
                    // lcd.print("\x03");
                    // lcd.print("\x04");
                    // lcd.print("\x05");
                    // lcd.print("\x06");
                    lcd.print("COMS");
                    lcd.print(":Confirm Baud");
                    lcd.setCursor(1, 3);
                    lcd.print("Or Use RS485 Jumper");
                    lcd.setCursor(19, 1);
                    lcd.print("X");
                    // uartPutString("X\n");  // Indicate no reception by sending 'X' and a newline
                  }
                  break;
                }
              case 1:
              case 2:
                // uart_flush_input();
                lcd.clear();
                break;
            }
            break;




          case XdcrAddressAD14:
            switch (cursorPos) {
              case 2:
                lcd.clear();
                uart_send_string_without_delay("#*A A\r\n", 10);
                delay(2000);
                uart_send_string_without_delay("#*SAVE\r\n", 10);
                delay(3000);
                break;
              case 3:
                lcd.clear();
                uart_send_string_without_delay("#*A B\r\n", 10);
                delay(1000);
                uart_send_string_without_delay("#*SAVE\r\n", 10);
                delay(3000);
                break;
              case 4:
                lcd.clear();
                uart_send_string_without_delay("#*A C\r\n", 10);
                delay(1000);
                uart_send_string_without_delay("#*SAVE\r\n", 10);
                delay(3000);
                break;
              case 5:
                lcd.clear();
                uart_send_string_without_delay("#*A D\r\n", 10);
                delay(1000);
                uart_send_string_without_delay("#*SAVE\r\n", 10);
                delay(3000);
                break;
              case 6:
                lcd.clear();
                uart_send_string_without_delay("#*A 0\r\n", 10);
                delay(1000);
                uart_send_string_without_delay("#*SAVE\r\n", 10);
                delay(3000);
                break;
              case 7:
                lcd.clear();
                uart_send_string_without_delay("#*A 1\r\n", 10);
                delay(1000);
                uart_send_string_without_delay("#*SAVE\r\n", 10);
                delay(3000);
                break;
              case 8:
                lcd.clear();
                uart_send_string_without_delay("#*A 2\r\n", 10);
                delay(1000);
                uart_send_string_without_delay("#*SAVE\r\n", 10);
                delay(3000);
                break;
              case 9:
                lcd.clear();
                uart_send_string_without_delay("#*A 3\r\n", 10);
                delay(1000);
                uart_send_string_without_delay("#*SAVE\r\n", 10);
                delay(3000);
                break;
              case 0:
                lcd.clear();
                uart_send_string_without_delay("#*A 4\r\n", 10);
                delay(1000);
                uart_send_string_without_delay("#*SAVE\r\n", 10);
                delay(3000);
                break;
              case 1:
                lcd.clear();
                uart_send_string_without_delay("#*A 5\r\n", 10);
                delay(1000);
                uart_send_string_without_delay("#*SAVE\r\n", 10);
                delay(3000);
                break;
            }
            break;




          case M9414SubMenu:
            // Add logic to navigate within M9414SubMenu and its submenus
            switch (cursorPos) {
              case 0:
                lcd.clear();
                currentMainMenuState = M9414RegTest;
                uartInit(57600);
                // uartPutString("57600\r\n");
                break;
              case 1:
                lcd.clear();
                currentMainMenuState = M9414RegTestRevertSettings;
                uartInit(57600);
                // uartPutString("57600\r\n");
                break;
              case 2:
                lcd.clear();
                currentMainMenuState = M9414RxDx;
                uartInit(57600);
                // uartPutString("57600\r\n");
                break;
            }
            break;



          case M9414RegTest:
            // Add logic to navigate within M9414SubMenu and its submenus
            switch (cursorPos) {
              case 0:
                lcd.clear();
                currentMainMenuState = M9414RegTestCurrentGet;
                break;
              case 1:
                lcd.clear();
                currentMainMenuState = M9414RegTestPressSettings;
                break;
              case 2:
                lcd.clear();
                currentMainMenuState = M9414RegTestRevertSettings;
                break;
            }
            break;




          case M9414RegTestCurrentGet:
            switch (cursorPos) {
              case 0:
                {
                  char dispMult[8];
                  char responseBufferMult[128];
                  // char dispSetWin[38];
                  char responseBufferSW[10];
                  lcd.clear();
                  //memset(response, '\0', sizeof(response));
                  // uart_flush_input();
                  uart_send_string_without_delay("setwindow?\r\n", 0);
                  uartReceive(responseBufferSW, 10);
                  // uart_flush_input();
                  uart_send_string_without_delay("gains?\r\n", 0);
                  uartReceive(responseBufferMult, 128);



                  lcd.setCursor(1, 2);
                  lcd.print("Mult= ");


                  char* multPos = strstr(responseBufferMult, "mult:");

                  if (multPos != NULL) {
                    int startIndex = (multPos - responseBufferMult) + 6;
                    strncpy(dispMult, responseBufferMult + startIndex, 8);
                    dispMult[8] = '\0';  // Null-terminate the string
                    lcd.print(dispMult);
                    lcd.print("      ");
                  } else {
                    lcd.print("--.-----");
                    lcd.setCursor(19, 1);
                    lcd.print("X");
                  }

                  lcd.setCursor(1, 3);  // Set cursor position on LCD
                  lcd.print("SetWin= ");
                  if (strlen(responseBufferSW) > 0) {
                    lcd.print(responseBufferSW);
                    lcd.print("      ");
                  } else {
                    lcd.print("--.-----");
                  }
                }
                break;
              case 1:
              case 2:
                // uart_flush_input();
                lcd.clear();
                break;
            }
            break;







          case M9414RegTestPressSettings:
            switch (cursorPos) {
              case 0:
                lcd.clear();
                uart_send_string_without_delay("mult= 1\r\n", 10);
                delay(1000);
                uart_send_string_without_delay("setwindow= 0.1\r\n", 10);
                delay(1000);
                uart_send_string_without_delay("unitno= 1\r\n", 10);
                break;
            }
            break;



          case M9414RegTestRevertSettings:
            switch (cursorPos) {
              case 0:
                lcd.clear();
                uart_send_string_without_delay("mult= 25\r\n", 10);
                delay(1000);
                uart_send_string_without_delay("setwindow= 0.004\r\n", 10);
                delay(3000);
                break;
              case 1:
                lcd.clear();
                uart_send_string_without_delay("mult= 25\r\n", 10);
                delay(1000);
                uart_send_string_without_delay("setwindow= 0.03\r\n", 10);
                delay(3000);
                break;
              case 2:
                lcd.clear();
                uart_send_string_without_delay("mult= 50\r\n", 10);
                delay(1000);
                uart_send_string_without_delay("setwindow= 0.03\r\n", 10);
                delay(3000);
                break;
            }
            break;



          case M9414RxDx:
            // Add logic to navigate within M9414SubMenu and its submenus
            switch (cursorPos) {
              case 0:
                uart_send_string_without_delay("SN?\r\n", 0);
                wait(1000);
                uart_send_string_without_delay("GAINS?\r\n", 0);
                // responseReceived1 = readUartString(response, sizeof(response), RESPONSE_TIMEOUT);

                // lcd.setCursor(19, 1);
                // if (responseReceived1) {
                //   lcd.print("#");
                // } else {
                //   lcd.print("X");
                //   // uartPutString("X\n");  // Indicate no reception by sending 'X' and a newline
                // }
                break;

              case 1:
              case 2:
                // String uartData = "test eeprom file text";  //response1, response2,etc
                // int eepromAddress = 0;
                // for (int i = 0; i < uartData.length(); i++) {
                //   EEPROM.write(eepromAddress++, uartData[i]);
                // }
                // EEPROM.commit();
                lcd.clear();
                break;
            }
            break;



          case MDualSubMenu:
            // Add logic to navigate within MDualSubMenu and its submenus
            switch (cursorPos) {

              case 0:
                serialNumberReceive();
                currentMainMenuState = MDualSNX;
                uartInit(57600);
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("SN: ");
                lcd.print(dispSerialNumber);
                // uartPutString("57600\n");
                break;
              case 1:
                lcd.clear();
                currentMainMenuState = MDualPriSec;
                uartInit(57600);
                // uartPutString("57600\n");
                break;
              case 2:
                ModNumSetMode = 9250;
                monthDayFloatingCharacter = 1;
                serialNumberReceive();
                currentMainMenuState = MDualSNX;
                uartInit(57600);
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("SN: ");
                lcd.print(dispSerialNumber);
                // lcd.print[19] = '\0';

                // uartPutString("57600\n");

                break;
            }
            break;




            // case MDualSN:
            // displayMDualSN();
            //
            //   switch (cursorPos) {
            //     case 0:
            //       lcd.clear();
            //       break;
            //     case 1:
            //       lcd.clear();
            //       break;
            //     case 2:
            //       lcd.clear();
            //       break;
            //     case 3:
            //       lcd.clear();
            //       break;
            //   }
            //   break;




          case MDualSNX:
            switch (cursorPos) {
              case 0:
                setSNXPosition(0);
                break;
              case 1:
                setSNXPosition(1);
                break;
              case 2:
                setSNXPosition(2);
                break;
              case 3:
                setSNXPosition(3);
                break;
              case 4:
                setSNXPosition(4);
                break;
              case 5:
                setSNXPosition(5);
                break;
              case 6:
                setSNXPosition(6);
                break;
              case 7:
                setSNXPosition(7);
                break;
              case 8:
                setSNXPosition(8);
                break;
              case 9:
                setSNXPosition(9);
                break;
            }
            break;




          case MDualSNxX:
            switch (cursorPos) {
              case 0:
                setSNxXPosition(0);
                break;
              case 1:
                setSNxXPosition(1);
                break;
              case 2:
                setSNxXPosition(2);
                break;
              case 3:
                setSNxXPosition(3);
                break;
              case 4:
                setSNxXPosition(4);
                break;
              case 5:
                setSNxXPosition(5);
                break;
              case 6:
                setSNxXPosition(6);
                break;
              case 7:
                setSNxXPosition(7);
                break;
              case 8:
                setSNxXPosition(8);
                break;
              case 9:
                setSNxXPosition(9);
                break;
            }
            break;




          case MDualSNxxX:
            switch (cursorPos) {
              case 0:
                setSNxxXPosition(0);
                break;
              case 1:
                setSNxxXPosition(1);
                break;
              case 2:
                setSNxxXPosition(2);
                break;
              case 3:
                setSNxxXPosition(3);
                break;
              case 4:
                setSNxxXPosition(4);
                break;
              case 5:
                setSNxxXPosition(5);
                break;
              case 6:
                setSNxxXPosition(6);
                break;
              case 7:
                setSNxxXPosition(7);
                break;
              case 8:
                setSNxxXPosition(8);
                break;
              case 9:
                setSNxxXPosition(9);
                break;
            }
            break;




          case MDualSNxxxX:
            switch (cursorPos) {
              case 0:
                setSNxxxXPosition(0);
                break;
              case 1:
                setSNxxxXPosition(1);
                break;
              case 2:
                setSNxxxXPosition(2);
                break;
              case 3:
                setSNxxxXPosition(3);
                break;
              case 4:
                setSNxxxXPosition(4);
                break;
              case 5:
                setSNxxxXPosition(5);
                break;
              case 6:
                setSNxxxXPosition(6);
                break;
              case 7:
                setSNxxxXPosition(7);
                break;
              case 8:
                setSNxxxXPosition(8);
                break;
              case 9:
                setSNxxxXPosition(9);
                break;
            }
            break;





          case MDualSNSend:
            // char dispSerialNum[7];
            switch (cursorPos) {
              case 0:
                SNSend();
                serialNumberReceive();
                lcd.clear();
                // uart_send_string_without_delay("sn?\r\n", 0);
                // uartReceive(dispSerialNum, 7);
                lcd.setCursor(0, 0);
                lcd.print("New SN:");
                lcd.print(dispSerialNumber);
                break;
              case 1:
                serialNumberReceive();
                lcd.clear();
                // uart_send_string_without_delay("sn?\r\n", 0);
                // uartReceive(dispSerialNum, 7);
                lcd.setCursor(0, 0);
                lcd.print("SN: ");
                lcd.print(dispSerialNumber);
                currentMainMenuState = MDualSNX;
                break;
            }
            break;




          case MDualPriSec:
            switch (cursorPos) {
              case 0:
                lcd.clear();
                uart_send_string_without_delay("slaveopt= 1\r\n", 10);
                break;
              case 1:
                lcd.clear();
                uart_send_string_without_delay("slaveopt= 0\r\n", 10);
                break;
            }
            break;




          case MDual9250Month:
            lcd.clear();
            switch (cursorPos) {
              case 0:
                setM9250MonthPosition(1);
                break;
              case 1:
                setM9250MonthPosition(2);
                break;
              case 2:
                setM9250MonthPosition(3);
                break;
              case 3:
                setM9250MonthPosition(4);
                break;
              case 4:
                setM9250MonthPosition(5);
                break;
              case 5:
                setM9250MonthPosition(6);
                break;
              case 6:
                setM9250MonthPosition(7);
                break;
              case 7:
                setM9250MonthPosition(8);
                break;
              case 8:
                setM9250MonthPosition(9);
                break;
              case 9:
                setM9250MonthPosition(10);
                break;
              case 10:
                setM9250MonthPosition(11);
                break;
              case 11:
                setM9250MonthPosition(12);
                break;
            }
            break;




          case MDual9250DayTens:
            switch (cursorPos) {
              case 0:
                setM9250DayTensPosition(0);
                break;
              case 1:
                setM9250DayTensPosition(1);
                break;
              case 2:
                setM9250DayTensPosition(2);
                break;
              case 3:
                setM9250DayTensPosition(3);
                break;
            }
            break;




          case MDual9250SNDateSend:
            char mynumString[32];

            char dispDateOfManufacture[12];
            switch (cursorPos) {
              case 0:

                monthDayFloatingCharacter = 0;
                sprintf(mynumString, "INSTSN 99%d%d%d%d\r\n", SNX, SNxX, SNxxX, SNxxxX);
                uart_send_string_without_delay(mynumString, strlen(mynumString));
                wait(200);
                mynumString[0] = '\0';
                if (M9250Month < 10){
                sprintf(mynumString, "INSTDOM 0%d/%d%d/%d\r\n", M9250Month, M9250DayTens, M9250DayOnes, M9250Year);
                } else {
                sprintf(mynumString, "INSTDOM %d/%d%d/%d\r\n", M9250Month, M9250DayTens, M9250DayOnes, M9250Year);
                }
                uart_send_string_without_delay(mynumString, strlen(mynumString));
                wait(200);
                mynumString[0] = '\0';
                  lcd.clear();
                ModNumSetMode = 9250;
                lcd.setCursor(0, 0);
                lcd.print("New SN:");
                serialNumberReceive();  
                lcd.print(dispSerialNumber);
                lcd.print("     ");
                wait(200);
                lcd.setCursor(0, 1);
                lcd.print("New Date:");
                // lcd.print(M9250Month);
                // lcd.print(",");
                // lcd.print(M9250DayTens);
                // lcd.print(M9250DayOnes);
                // lcd.print(",");
                // lcd.print(M9250Year);
                uart_send_string_without_delay("DOM?\r\n", 0);
                uartReceive(dispDateOfManufacture, 12);
                lcd.print(dispDateOfManufacture);
                // Serial.println(dispDateOfManufacture);
                // lcd.setCursor(7, 1);
                // lcd.print("   ");
                break;
              case 1:
                ModNumSetMode = 9250;
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("SN: ");
                serialNumberReceive();
                lcd.print(dispSerialNumber);
                currentMainMenuState = MDualSNX;
                M9250DayAlreadySet = 0;
                break;
            }
            break;
        }
        selectPressed = true;
      }
    } else {
      selectPressed = false;
    }




    // Handle the back button press
    if (digitalRead(BACK_BUTTON_PIN) == LOW) {
      if (!backPressed) {
        // If we are in a submenu, go back to the main menu
        if (currentMainMenuState != MainMenu) {
          // Serial.print("Hello World!");
          lcd.clear();
          currentMainMenuState = MainMenu;
          backPressed = true;
          delay(200);
          digitalWrite(XDCR_PWR_PIN, XDCR_PWR_OFF);
          M9250DayAlreadySet = 0;
          ModNumSetMode = 0;
          monthDayFloatingCharacter = 0;
        }
      } else {
        backPressed = false;
      }
    }


    if (digitalRead(UP_BUTTON_PIN) == LOW) {
      if (!upPressed) {
        if (currentMainMenuState == XdcrAddressAD14) {
          cursorPos = (cursorPos - 1 + numOptionAD14) % numOptionAD14;  // Wrap around the options
        } else if (currentMainMenuState == MDualSNX || currentMainMenuState == MDualSNxX || currentMainMenuState == MDualSNxxX || currentMainMenuState == MDualSNxxxX) {
          cursorPos = (cursorPos - 1 + numOptionSN09) % numOptionSN09;
        } else if (currentMainMenuState == M9414RxDx) {
          cursorPos = (cursorPos - 1 + numOptionCH18) % numOptionCH18;
        } else if (currentMainMenuState == MDual9250Month) {
          cursorPos = (cursorPos - 1 + numOptionMonth) % numOptionMonth;
        } else if (currentMainMenuState == MDual9250DayTens) {
          cursorPos = (cursorPos - 1 + numOptionDayTens) % numOptionDayTens;
        } else if (currentMainMenuState == MDual9250DayTens) {
          cursorPos = (cursorPos - 1 + 4) % 4;
        } else {
          cursorPos = (cursorPos - 1 + 3) % 3;
        }
        upPressed = true;
      }
    } else {
      upPressed = false;
    }

    if (digitalRead(DOWN_BUTTON_PIN) == LOW) {
      if (!downPressed) {
        if (currentMainMenuState == XdcrAddressAD14) {
          cursorPos = (cursorPos + 1) % numOptionAD14;
        } else if (currentMainMenuState == MDualSNX || currentMainMenuState == MDualSNxX || currentMainMenuState == MDualSNxxX || currentMainMenuState == MDualSNxxxX) {
          cursorPos = (cursorPos + 1) % numOptionSN09;
        } else if (currentMainMenuState == M9414RxDx) {
          cursorPos = (cursorPos + 1) % numOptionCH18;
        } else if (currentMainMenuState == MDual9250Month) {
          cursorPos = (cursorPos + 1) % numOptionMonth;
        } else if (currentMainMenuState == MDual9250DayTens) {
          cursorPos = (cursorPos + 1) % numOptionDayTens;
        } else if (currentMainMenuState == MDual9250DayTens) {
          cursorPos = (cursorPos + 1) % 4;
        } else {
          cursorPos = (cursorPos + 1) % 3;
        }
        downPressed = true;
      }
    } else {
      downPressed = false;
    }




    buttonPressed = true;
  } else {
    buttonPressed = false;
  }
}
