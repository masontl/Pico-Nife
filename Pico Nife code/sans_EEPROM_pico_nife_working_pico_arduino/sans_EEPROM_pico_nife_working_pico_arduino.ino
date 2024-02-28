
// The liquidCrystalRasPiRealWorld variable determines which LCD library to use.M9250Month
// 1 = Setting for Raspberry Pi Pico LCD, 0 = Setup for SimulIDE i2c LCD
#define liquidCrystalRasPiRealWorld 1
#define raspberryPiPicoMicroController 1


#define BAUD_RATE 57600
#define RESPONSE_TIMEOUT 1500  // for example, 1000 milliseconds
#define XDCR_PWR_ON HIGH
#define XDCR_PWR_OFF LOW
#define XDCR_PWR_PIN 22
#include "main_menu_state_index.h"
#include "strike_through.h"
// #include <EEPROM.h>
int SNX = 0;
int SNxX = 0;
int SNxxX = 0;
int SNxxxX = 0;
int M9250Month = 1;
int M9250DayTens = 0;
int M9250DayOnes = 1;
int M9250Year = 2024;
int ModNumSetMode = 0;
int M9250DayAlreadySet = 0;
int monthDayFloatingCharacter = 0;
char* dispSerialNumber = "990000";

// Global variables to store the current menu state and cursor position
MainMenuStateIndex currentMainMenuState = MainMenu;

char textFileRXDX [150000];



#if liquidCrystalRasPiRealWorld == 1
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
#else
#include <LiquidCrystal_AIP31068_I2C.h>
LiquidCrystal_AIP31068_I2C lcd(0x27, 20, 4);  // set the LCD address to 0x3E for a 20 chars and 4 line display
#endif

void initLcd() {
#if liquidCrystalRasPiRealWorld == 1
  lcd.init();
  lcd.backlight();
#else
  lcd.init();
  // lcd.begin(20, 4);
  // lcd.setBacklight(HIGH);
#endif
}

#if raspberryPiPicoMicroController == 1
#include "pico/multicore.h"
#include "hardware/gpio.h"
#include "hardware/uart.h"
#include <string.h>
// #include <LittleFS_Mbed_RP2040.h>
using namespace std;
#define UART_ID uart0
// UART0 TX on GP0 (pin 1 on the Pico)
#define UART_TX_PIN 0
// UART0 RX on GP1 (pin 2 on the Pico)
#define UART_RX_PIN 1
#define UART1_ID uart1
// UART0 TX on GP0 (pin 1 on the Pico)
#define UART1_TX_PIN 8
// UART0 RX on GP1 (pin 2 on the Pico)
#define UART1_RX_PIN 9
// Pin definitions for the buttons
#define BACK_BUTTON_PIN 16    //13
#define LEFT_BUTTON_PIN 26    //10
#define DOWN_BUTTON_PIN 19    //8
#define UP_BUTTON_PIN 18      //9
#define RIGHT_BUTTON_PIN 27   //7
#define SELECT_BUTTON_PIN 17  //6
uart_inst_t* UART_OBJ = UART_ID;

#else
// Pin definitions for the buttons
#define BACK_BUTTON_PIN 13
#define LEFT_BUTTON_PIN 10
#define DOWN_BUTTON_PIN 8
#define UP_BUTTON_PIN 9
#define RIGHT_BUTTON_PIN 7
#define SELECT_BUTTON_PIN 6
HardwareSerial* UART_OBJ = &Serial1;  // Use the desired Serial port (Serial1, Serial2, etc.)
#endif





volatile bool buttonPressed = false;
volatile int cursorPos = 0;

bool backPressed = false;
bool selectPressed = false;
bool upPressed = false;
bool downPressed = false;


const char* optionAD14[] = { "3", "4", "5", "A", "B", "C", "D", "0", "1", "2" };
const char* optionSN09[] = { "9", "0", "1", "2", "3", "4", "5", "6", "7", "8" };
const char* optionCH18[] = { "9424     ", "2 Channel", "4 Channel", "6 Channel", "8 Channel" };
const char* optionMonth[] = { "12", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11" };
const char* optionDayTens[] = { "3", "0", "1", "2" };

int numOptionAD14 = sizeof(optionAD14) / sizeof(optionAD14[0]);
int numOptionSN09 = sizeof(optionSN09) / sizeof(optionSN09[0]);
int numOptionCH18 = sizeof(optionCH18) / sizeof(optionCH18[0]);
int numOptionMonth = sizeof(optionMonth) / sizeof(optionMonth[0]);
int numOptionDayTens = sizeof(optionDayTens) / sizeof(optionDayTens[0]);




void setup() {
  // int main() {
  initLcd();
  pinMode(BACK_BUTTON_PIN, INPUT_PULLUP);
  pinMode(SELECT_BUTTON_PIN, INPUT_PULLUP);
  pinMode(UP_BUTTON_PIN, INPUT_PULLUP);
  pinMode(DOWN_BUTTON_PIN, INPUT_PULLUP);
  pinMode(LEFT_BUTTON_PIN, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON_PIN, INPUT_PULLUP);

  displayMainMenu();

  pinMode(XDCR_PWR_PIN, OUTPUT);
  digitalWrite(XDCR_PWR_PIN, XDCR_PWR_OFF);

  uartInit(BAUD_RATE);

  lcd.createChar(3, strikeC);
  lcd.createChar(4, strikeO);
  lcd.createChar(5, strikeM);
  lcd.createChar(6, strikeS);
}
void loop() {
  //  while (true) {

  handle_button_presses();

}
//  return 0;
// }
