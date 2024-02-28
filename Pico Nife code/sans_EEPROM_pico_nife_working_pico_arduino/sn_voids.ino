
void serialNumberReceive() {
  // char dispSerialNumber[7];
  // char responseBufferInstsn[7];
  char intermediateSN[64];
  // uart_flush_input();
  if (ModNumSetMode == 9250) {
    uart_send_string_without_delay("id?\r\n", 0);
    uartReceive(intermediateSN, 64);
    char* model9250string = strstr(intermediateSN, "9250,");
    if (model9250string != NULL) {
      int startIndex = (model9250string - intermediateSN) + 5;
      strncpy(dispSerialNumber, intermediateSN + startIndex, 6);
    }
  } else {
    uart_send_string_without_delay("sn?\r\n", 0);
    uartReceive(dispSerialNumber, 6);
  }
}




void setSNXPosition(int caseNum) {
  lcd.setCursor(6, 0);
  lcd.print(caseNum);
  SNX = caseNum;
  currentMainMenuState = MDualSNxX;
}



void setSNxXPosition(int caseNum) {
  lcd.setCursor(7, 0);
  lcd.print(caseNum);
  SNxX = caseNum;
  currentMainMenuState = MDualSNxxX;
}



void setSNxxXPosition(int caseNum) {
  lcd.setCursor(8, 0);
  lcd.print(caseNum);
  SNxxX = caseNum;
  currentMainMenuState = MDualSNxxxX;
}



void setSNxxxXPosition(int caseNum) {
  lcd.setCursor(9, 0);
  lcd.print(caseNum);

  if (ModNumSetMode == 9250) {
    if (M9250DayAlreadySet == 1) {
      monthDayFloatingCharacter = 1;
      M9250DayOnes = caseNum;
      currentMainMenuState = MDual9250SNDateSend;
      // M9250DayAlreadySet = 0;
      ModNumSetMode = 0;
    } else {
      // M9250DayOnes = caseNum;
      SNxxxX = caseNum;
      currentMainMenuState = MDual9250Month;
      M9250DayAlreadySet = 1;
    }
  } else {
    SNxxxX = caseNum;
    currentMainMenuState = MDualSNSend;
  }
}




void SNSend() {
  lcd.clear();
  // Generate the "mynum=" string
  char mynumString[16];
  sprintf(mynumString, "mynum=99%d%d%d%d\r\n", SNX, SNxX, SNxxX, SNxxxX);
  uart_send_string_without_delay(mynumString, strlen(mynumString));
  lcd.setCursor(7, 2);
  lcd.print("Sent");
  currentMainMenuState = MDualSNSend;
}


void setM9250MonthPosition(int caseNum) {
  lcd.setCursor(5, 0);
  lcd.print(caseNum);
  // if (caseNum < 10) {
  //   M9250Month = ("0%d", caseNum);
  // } else {
  //   M9250Month = caseNum;
  // }
  M9250Month = caseNum;
  currentMainMenuState = MDual9250DayTens;
}





void setM9250DayTensPosition(int caseNum) {
  lcd.setCursor(8, 0);
  lcd.print(caseNum);
  M9250DayTens = caseNum;
  currentMainMenuState = MDualSNxxxX;
}
