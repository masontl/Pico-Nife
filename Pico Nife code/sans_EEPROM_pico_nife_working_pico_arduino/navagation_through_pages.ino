

void currentMainMenuPageList() {



  // Display the menu based on the current state
  if (currentMainMenuState == MainMenu) {
    displayMainMenu();
  } else if (currentMainMenuState == XdcrSubMenu) {
    displayXdcrSubMenu();
  } else if (currentMainMenuState == XdcrComms) {
    displayXdcrComms();
  } else if (currentMainMenuState == XdcrCommsBaud) {
    displayXdcrCommsBaud();
  } else if (currentMainMenuState == XdcrAddressAD14) {
    displayXdcrAddressAD14();
  } else if (currentMainMenuState == M9414SubMenu) {
    displayM9414SubMenu();
  } else if (currentMainMenuState == M9414RegTest) {
    displayM9414RegTest();
  } else if (currentMainMenuState == M9414RegTestCurrentGet) {
    displayM9414RegTestCurrentGet();
  } else if (currentMainMenuState == M9414RegTestPressSettings) {
    displayM9414RegTestPressSettings();
  } else if (currentMainMenuState == M9414RxDx) {
    displayM9414RxDx();
  } else if (currentMainMenuState == MDualSubMenu) {
    displayMDualSubMenu();
  } else if (currentMainMenuState == MDualPriSec) {
    displayMDualPriSec();
  } else if (currentMainMenuState == MDualSNX) {
    displayMDualSNX();
  } else if (currentMainMenuState == MDualSNxX) {
    displayMDualSNxX();
  } else if (currentMainMenuState == MDualSNxxX) {
    displayMDualSNxxX();
  } else if (currentMainMenuState == MDualSNxxxX) {
    displayMDualSNxxxX();
  } else if (currentMainMenuState == MDualSNSend) {
    displayMDualSNSend();
  } else if (currentMainMenuState == MDual9250Month) {
    displayMDual9250Month();
  } else if (currentMainMenuState == MDual9250DayTens) {
    displayMDual9250DayTens();
  } else if (currentMainMenuState == MDual9250SNDateSend) {
    displayMDual9250SNDateSend();
  }
}