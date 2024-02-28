/* //////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//
// All the pages below are constantly looped due to the "handle_button_presses" FUNCTION
// (this is not to be confused with the handle_button_presses.ino page).
//
// Anything you don't want to be constantly refreshed should not be included in these pages.
//
// This is the main reason why a lot of the pages which have more than three options
// don't have text that starts at (0,0).
//
// Additionally, that's another reason why the pages don't start with "lcd.clear();"
//  ; the constant update and clearing makes the LCD look like it's glitching out and doesn't 
// instill confidence in the programming, functionality or...the programmer personnel.
// 
// if those functions are needed (lcd.clear();, address/SN updating, etc.) place those
// text functions within the particular block of the "handle_button_presses.ino" page.
//
/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////*/

// Function to display the main menu
void displayMainMenu() {
  //lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Main Menu");

  // Display menu options with cursor indicator
  lcd.setCursor(0, 1);
  lcd.print(cursorPos == 0 ? ">1. XDCR" : " 1. XDCR");
  lcd.setCursor(0, 2);
  lcd.print(cursorPos == 1 ? ">2. 9414" : " 2. 9414");
  lcd.setCursor(0, 3);
  lcd.print(cursorPos == 2 ? ">3. 9414/9424" : " 3. 9414/9424");
}

/////////////////////////////////////////////////////////////////////////////

// Function to display the XDCR submenu
void displayXdcrSubMenu() {
  //lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("XDCR Submenu");
  lcd.setCursor(0, 1);
  lcd.print(cursorPos == 0 ? ">1. Set Baud Rate" : " 1. Set Baud Rate");
  lcd.setCursor(0, 2);
  lcd.print(cursorPos == 1 ? ">2. Test Comms" : " 2. Test Comms");
  lcd.setCursor(0, 3);
  lcd.print(cursorPos == 2 ? ">3. Set Address" : " 3. Set Address");
}

////////////////////////////////////////////////////

void displayXdcrComms() {
  //void displayXdcrSubMenu2() {
  lcd.setCursor(0, 0);
  lcd.print("XDCR comms          ");
  lcd.setCursor(0, 1);
  lcd.print(cursorPos == 0 ? ">1. Go >>>         " : " 1. Go >>>         ");
  lcd.setCursor(0, 2);
  lcd.print(cursorPos == 1 ? ">                   " : " ");
  lcd.setCursor(0, 3);
  lcd.print(cursorPos == 2 ? ">                   " : " ");
}

//////////////////////////////////

void displayXdcrCommsBaud() {
  lcd.setCursor(0, 0);
  lcd.print("XDCR Comms Baud");
  lcd.setCursor(0, 1);
  lcd.print(cursorPos == 0 ? ">1. 9600" : " 1. 9600");
  lcd.setCursor(0, 2);
  lcd.print(cursorPos == 1 ? ">2. 19200" : " 2. 19200");
  lcd.setCursor(0, 3);
  lcd.print(cursorPos == 2 ? ">3. 57600" : " 3. 57600");
}

//////////////////////////////////////////////////



void displayXdcrAddressAD14() {
  lcd.setCursor(0, 0);
  lcd.print("XDCR Comms Address  ");

  for (int i = 0; i < 3; i++) {
    int optionIndex = (cursorPos + i) % 10;  // Adjust the modulus to the number of options you want to display
    lcd.setCursor(0, i + 1);

    if (i == 1) {
      lcd.print("> ");
    } else {
      lcd.print("  ");
    }

    lcd.print(optionAD14[optionIndex]);
  }
}







/////////////////////////////////////////////////////////////////////////////

// Function to display the 9414/9424 submenu
void displayM9414SubMenu() {
  //lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("9414 Submenu");
  // Display menu options with cursor indicator
  lcd.setCursor(0, 1);
  lcd.print(cursorPos == 0 ? ">1. Regulator Test" : " 1. Regulator Test");

  lcd.setCursor(0, 2);
  if (cursorPos == 1) {
    scrollTextWithPrefix(">", "      2. Reset Pressure Rate and Set Window             ", 20);
  } else {
    printLimitedChars(" 2. Reset Pressure Rate and Set Window", 20);
  }

  lcd.setCursor(0, 3);
  if (cursorPos == 2) {
    scrollTextWithPrefix(">", "      TBD>>3. Capture Receive/Delivered As Settings            ", 20);
  } else {
    printLimitedChars(" TBD>>3. Capture Receive/Delivered As settings", 20);
  }
}

/////////////////////////////////////////////////////

void displayM9414RegTest() {
  lcd.setCursor(0, 0);
  lcd.print("9414 Regulator test");
  // Display menu options with cursor indicator
  lcd.setCursor(0, 1);
  lcd.print(cursorPos == 0 ? ">1. Current Settings" : " 1. Current Settings");
  lcd.setCursor(0, 2);
  lcd.print(cursorPos == 1 ? ">2. Leak Testing" : " 2. Leak Testing");
  lcd.setCursor(0, 3);
  if (cursorPos == 2) {
    scrollTextWithPrefix(">", "      3. Revert Back to Default Settings            ", 20);
  } else {
    printLimitedChars(" 3. Revert Back to Default Settings", 20);
  }
}

//also...duplicate.  see M9414PressureRateSetWindow
void displayM9414RegTestCurrentGet() {
  lcd.setCursor(0, 0);
  lcd.print("Current Settings    ");
  lcd.setCursor(0, 1);
  lcd.print(cursorPos == 0 ? ">1. Go >>>         " : " 1. Go >>>");
  lcd.setCursor(0, 2);
  lcd.print(cursorPos == 1 ? ">                   " : " ");
  lcd.setCursor(0, 3);
  lcd.print(cursorPos == 2 ? ">                   " : " ");
}

void displayM9414RegTestPressSettings() {
  lcd.setCursor(0, 0);
  lcd.print("Set Leak-Test Rates");
  lcd.setCursor(0, 1);
  lcd.print(cursorPos == 0 ? ">1.PR 1.0 SW 0.1 >>>" : " 1.PR 1.0 SW 0.1 >>>");
  lcd.setCursor(0, 2);
  lcd.print(cursorPos == 1 ? ">" : " ");
  lcd.setCursor(0, 3);
  lcd.print(cursorPos == 2 ? "> " : " ");
}

void displayM9414RegTestRevertSettings() {
  lcd.setCursor(0, 0);
  lcd.print("Set Default Settings");
  lcd.setCursor(0, 1);
  lcd.print(cursorPos == 0 ? ">1. PR 25 SW 0.004" : " 1. PR 25 SW 0.004");
  lcd.setCursor(0, 2);
  lcd.print(cursorPos == 1 ? ">2. PR 25 SW 0.03" : " 2. PR 25 SW 0.03");
  lcd.setCursor(0, 3);
  lcd.print(cursorPos == 2 ? ">3. PR 50 SW 0.03" : " 3. PR 50 SW 0.03");
}


//TBD
void displayM9414RxDx() {
  lcd.setCursor(0, 0);
  lcd.print("Record Ctlr Settings");

  for (int i = 0; i < 3; i++) {
    int optionIndex = (cursorPos + i) % 5;  // Modulus for 5 options
    lcd.setCursor(0, i + 1);

    if (i == 1) {
      lcd.print(" > ");  // Cursor indicator for selected option
    } else {
      lcd.print("   ");  // Spaces for unselected options
    }

    lcd.print(optionCH18[optionIndex]);
  }
}


////////////////////////////////////////////////////////////////////////////

// Function to display the 9414/9424 submenu
void displayMDualSubMenu() {
  //lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("9414/9424 Submenu");
  // Display menu options with cursor indicator
  lcd.setCursor(0, 1);
  lcd.print(cursorPos == 0 ? ">1. S/N Set" : " 1. S/N Set");

  lcd.setCursor(0, 2);
  if (cursorPos == 1) {
    scrollTextWithPrefix(">", "      2. Slave Opt Set 9414 2.04.xx S/W            ", 20);
  } else {
    printLimitedChars(" 2. Slave Opt Set 9414 2.04.xx S/W", 20);
  }

  lcd.setCursor(0, 3);
  if (cursorPos == 2) {
    scrollTextWithPrefix(">", "      3. Set 9250 SN and Date         ", 20);
  } else {
    printLimitedChars(" 3. Set 9250 SN and Date", 20);
  }
}

////////////////////////////////////////////////////

// void displayMDualSN() {
// lcd.setCursor(0, 0);
// lcd.print(cursorPos == 0 ? ">Set SN 99 X _ _ _ " : " Set SN 99 X _ _ _ ");
// lcd.setCursor(0, 1);
// lcd.print(cursorPos == 1 ? ">Set SN 99 _ X _ _ " : " Set SN 99 _ X _ _ ");
// lcd.setCursor(0, 2);
// lcd.print(cursorPos == 2 ? ">Set SN 99 _ _ X _ " : " Set SN 99 _ _ X _ ");
// lcd.setCursor(0, 3);
// lcd.print(cursorPos == 3 ? ">Set SN 99 _ _ _ X " : " Set SN 99 _ _ _ X ");
// }

void displayMDualSNX() {
  for (int i = 0; i < 3; i++) {
    int optionIndex = (cursorPos + i) % 10;  // Adjust the modulus to the number of options you want to display
    lcd.setCursor(0, i + 1);

    if (i == 1) {
      lcd.print("   >  ");
    } else {
      lcd.print("      ");
    }

    lcd.print(optionSN09[optionIndex]);
  }
}

void displayMDualSNxX() {
  for (int i = 0; i < 3; i++) {
    int optionIndex = (cursorPos + i) % 10;  // Adjust the modulus to the number of options you want to display
    lcd.setCursor(0, i + 1);

    if (i == 1) {
      lcd.print("   >   ");
    } else {
      lcd.print("       ");
    }

    lcd.print(optionSN09[optionIndex]);
  }
}

void displayMDualSNxxX() {
  for (int i = 0; i < 3; i++) {
    int optionIndex = (cursorPos + i) % 10;  // Adjust the modulus to the number of options you want to display
    lcd.setCursor(0, i + 1);

    if (i == 1) {
      lcd.print("   >    ");
    } else {
      lcd.print("        ");
    }

    lcd.print(optionSN09[optionIndex]);
  }
}

void displayMDualSNxxxX() {
  for (int i = 0; i < 3; i++) {
    int optionIndex = (cursorPos + i) % 10;  // Adjust the modulus to the number of options you want to display
    lcd.setCursor(0, i + 1);

    if (i == 1) {
      lcd.print("   >     ");
    } else {
      lcd.print("         ");
    }

    lcd.print(optionSN09[optionIndex]);
  }
}



void displayMDualSNSend() {
  lcd.setCursor(0, 1);
  lcd.print("Send Serial Number?");
  lcd.setCursor(0, 2);
  lcd.print(cursorPos == 0 ? "     >Yes           " : "      Yes           ");
  lcd.setCursor(0, 3);
  lcd.print(cursorPos == 1 ? "     >No; Restart   " : "      No; Restart   ");
}


//////////////////////////////////////

///////////////////////////////////////////////////
void displayMDualPriSec() {
  lcd.setCursor(0, 0);
  scrollTextWithPrefix("", "      Pri/Sec Set (Only Applies to 2.04.XX S/W and Later            ", 20);
  // Display menu options with cursor indicator
  lcd.setCursor(0, 1);
  lcd.print(cursorPos == 0 ? ">1. Primary/Master" : " 1. Primary/Master");
  lcd.setCursor(0, 2);
  lcd.print(cursorPos == 1 ? ">2. Secondary/Slave" : " 2. Secondary/Slave");
  lcd.setCursor(0, 3);
  lcd.print(cursorPos == 2 ? ">" : " ");
}

//////////////////////////////////////////////////////////////////////////////


void displayMDual9250Month() {
  lcd.setCursor(0, 0);
  lcd.print("Date:MM,DD,2024    ");
  for (int i = 0; i < 3; i++) {
    int optionIndex = (cursorPos + i) % 12;  // Adjust the modulus to the number of options you want to display
    lcd.setCursor(0, i + 1);

    if (i == 1) {
      lcd.print("   > ");
    } else {
      lcd.print("     ");
    }

    lcd.print(optionMonth[optionIndex]);
    lcd.print("    ");
  }
}




void displayMDual9250DayTens() {
  lcd.setCursor(0, 0);
  lcd.print("Date:");
  if (M9250Month < 10) {
    lcd.print("0");
    lcd.print(M9250Month);
  } else {
    lcd.print(M9250Month);
  }
  lcd.print(",DD,2024    ");


  for (int i = 0; i < 3; i++) {
    int optionIndex = (cursorPos + i) % 4;  // Modulus for 4 options
    lcd.setCursor(0, i + 1);

    if (i == 1) {
      lcd.print("   >    ");  // Cursor indicator for selected option
    } else {
      lcd.print("        ");  // Spaces for unselected options
    }

    lcd.print(optionDayTens[optionIndex]);
    lcd.print("    ");
  }
}


void displayMDual9250SNDateSend() {
  // lcd.setCursor(0, 1);
  // lcd.print("Send Serial Number?");
  if (monthDayFloatingCharacter == 1) {
    lcd.setCursor(9, 1);
    lcd.print(" ");
  } else {
  }
  lcd.setCursor(0, 2);
  lcd.print(cursorPos == 0 ? "     >Yes           " : "      Yes           ");
  lcd.setCursor(0, 3);
  lcd.print(cursorPos == 1 ? "     >No; Restart   " : "      No; Restart   ");
}

// void M9250DayOnes() {
//   for (int i = 0; i < 3; i++) {
//     int optionIndex = (cursorPos + i) % 10;  // Adjust the modulus to the number of options you want to display
//     lcd.setCursor(0, i + 1);

//     if (i == 1) {
//       lcd.print("    >");
//     } else {
//       lcd.print("     ");
//     }

//     lcd.print(optionSN09[optionIndex]);
//   }
// }
