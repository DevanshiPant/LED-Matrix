#include <Wire.h>
#include "RTClib.h"

#define BA {B01110000,B10001000,B10001000,B11111000,B10001000,B10001000}
#define BB {B11110000,B10001000,B10001000,B11110000,B10001000,B11111000}
#define BC {B11111000,B10000000,B10000000,B10000000,B10000000,B11111000}
#define BD {B11110000,B10001000,B10001000,B10001000,B10001000,B11110000}
#define BE {B11111000,B10000000,B10000000,B11110000,B10000000,B11111000}
#define BF {B11111000,B10000000,B10000000,B11110000,B10000000,B10000000}
#define BG {B01110000,B10001000,B10000000,B10011000,B10001000,B01110000}
#define BH {B10001000,B10001000,B11111000,B10001000,B10001000,B10001000}
#define BI {B11111000,B00100000,B00100000,B00100000,B00100000,B11111000}
#define BJ {B00111000,B00010000,B00010000,B00010000,B10010000,B01100000}
#define BM {B10001000,B11011000,B10101000,B10101000,B10001000,B10001000}
#define BN {B10001000,B11001000,B10101000,B10101000,B10011000,B10001000}
#define BL {B10000000,B10000000,B10000000,B10000000,B10000000,B11111000}
#define BO {B01110000,B10001000,B10001000,B10001000,B10001000,B01110000}
#define BP {B11110000,B10001000,B10001000,B11110000,B10000000,B10000000}
#define BQ {B01110000,B10001000,B10101000,B10011000,B01111000,B00001000}
#define BR {B11110000,B10001000,B10001000,B11110000,B10001000,B10001000}
#define BS {B01110000,B10001000,B01100000,B00010000,B10001000,B01110000}
#define BK {B10001000,B10010000,B11100000,B11100000,B10010000,B10001000}
#define BT {B11111000,B00100000,B00100000,B00100000,B00100000,B00100000}
#define BU {B10001000,B10001000,B10001000,B10001000,B10001000,B01110000}
#define BV {B10001000,B10001000,B10001000,B10001000,B01010000,B00100000}
#define BW {B10001000,B10001000,B10101000,B10101000,B10101000,B01010000}
#define BX {B10001000,B01010000,B00100000,B00100000,B01010000,B10001000}
#define BY {B10001000,B01010000,B00100000,B00100000,B00100000,B00100000}
#define BZ {B11111000,B00001000,B00110000,B01100000,B10000000,B11111000}
#define LA{B00000000,B01110000,B00001000,B01111000,B10001000,B01111000}
#define LB{B10000000,B10000000,B10110000,B11001000,B10001000,B11110000}
#define LC{B00000000,B01110000,B10000000,B10000000,B10001000,B01110000}
#define LD{B00001000,B00001000,B01111000,B10001000,B10001000,B01111000}
#define LE{B00000000,B01110000,B10001000,B11111000,B10000000,B01110000}
#define LF{B00110000,B01001000,B01000000,B11100000,B01000000,B01000000}
#define LG{B00000000,B01111000,B10001000,B01111000,B00001000,B01110000}
#define LH{B10000000,B10000000,B10110000,B11001000,B10001000,B10001000}
#define LI{B00100000,B00000000,B01100000,B00100000,B00100000,B01111000}
#define LJ{B00010000,B00000000,B00111000,B00010000,B10010000,B01100000}
#define LK{B10000000,B10010000,B10100000,B11000000,B10100000,B10010000}
#define LL{B01100000,B00100000,B00100000,B00100000,B00100000,B01111000}
#define LM{B00000000,B00000000,B11010000,B10101000,B10101000,B10001000}
#define LN{B00000000,B00000000,B10110000,B11001000,B10001000,B10001000}
#define LO{B00000000,B01110000,B10001000,B10001000,B10001000,B01110000}
#define LP{B00000000,B11110000,B10001000,B11110000,B10000000,B10000000}
#define LQ{B00000000,B01101000,B10011000,B01111000,B00001000,B00001000}
#define LR{B00000000,B00000000,B10110000,B11001000,B10000000,B10000000}
#define LS{B00000000,B01110000,B10000000,B01110000,B00001000,B11110000}
#define LT{B01000000,B01000000,B11100000,B01000000,B01001000,B00110000}
#define LU{B00000000,B00000000,B10001000,B10001000,B10011000,B01101000}
#define LV{B00000000,B00000000,B10001000,B10001000,B01010000,B00100000}
#define LW{B00000000,B00000000,B10001000,B10101000,B10101000,B01010000}
#define LX{B00000000,B10001000,B01010000,B00100000,B01010000,B10001000}
#define LY{B00000000,B10001000,B10001000,B01111000,B00001000,B01110000}
#define LZ{B00000000,B11111000,B00010000,B00100000,B01000000,B11111000}
#define SPACE{B00000000,B00000000,B00000000,B00000000,B00000000,B00000000}
#define NUM0{B01110000,B10011000,B10101000,B10101000,B11001000,B01110000}
#define NUM1{B00100000,B01100000,B10100000,B00100000,B00100000,B01110000}
#define NUM2{B01110000,B10001000,B00001000,B01110000,B10000000,B11111000}
#define NUM3{B11110000,B00001000,B00001000,B01111000,B00001000,B11110000}
#define NUM4{B10001000,B10001000,B10001000,B11111000,B00001000,B00001000}
#define NUM5{B11111000,B10000000,B11110000,B00001000,B10001000,B01110000}
#define NUM6{B11111000,B10000000,B11111000,B10001000,B10001000,B11111000}
#define NUM7{B11111000,B00001000,B00001000,B01111000,B00001000,B00001000}
#define NUM8{B11111000,B10001000,B11111000,B10001000,B10001000,B11111000}
#define NUM9{B11111000,B10001000,B11111000,B00001000,B00001000,B11111000}
#define DEVIDE{B00001000,B00010000,B00100000,B00100000,B01000000,B10000000}
#define TWODOTS{B01100000,B01100000,B00000000,B00000000,B01100000,B01100000}
#define DOT{B00000000,B00000000,B00000000,B00000000,B01100000,B01100000}
#define COMA{B00000000,B00000000,B00000000,B00110000,B00110000,B01100000}
#define LINE{B00000000,B00000000,B11111000,B11111000,B00000000,B00000000}
#define QUASTION{B01110000,B10001000,B00010000,B00100000,B00000000,B00100000}
#define MARK{B00100000,B01110000,B01110000,B00100000,B00000000,B00100000}

#include <Wire.h>
#include "RTClib.h"

int latchPin = 10;
int clockPin = 13;
int dataPin = 11;
int clock = 9;
int Reset = 8;
int latchPinPORTB = latchPin - 8;
int clockPinPORTB = clockPin - 8;
int dataPinPORTB = dataPin - 8;
int i = 0;
long scrolling_word[6];
int array_turn=0;
const int buttonPin = 2;
const int thermistorPin = A0;

// --- State ---
volatile int displayMode = 0; // 0=time, 1=date, 2=temp
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 200; // ms

// --- RTC ---
RTC_DS3231 rtc;

// --- Font macro arrays for copying ---
const byte NUMS[10][6] = {NUM0, NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9};
const byte TWODOTS_ARR[6] = TWODOTS;
const byte DEVIDE_ARR[6] = DEVIDE;
const byte SPACE_ARR[6] = SPACE;
const byte BC_ARR[6] = BC; // 'C' for Celsius
const byte MARK_ARR[6] = MARK; // '-' sign

void setup(){
  Serial.begin(9600);
  pinMode(dataPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(latchPin,OUTPUT);
  pinMode(clock,OUTPUT);
  pinMode(Reset,OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(Reset,HIGH);
  digitalWrite(Reset,LOW);
  setupSPI();

  Wire.begin();
  rtc.begin();

  // Optionally set RTC time once:
  //rtc.adjust(DateTime(F(_DATE), F(TIME_)));

  attachInterrupt(digitalPinToInterrupt(buttonPin), changeDisplayMode, FALLING);
}

// --- Main loop ---
void loop() {
  byte displayBuf[8][6]; // up to 8 patterns (max for your display)
  if (displayMode == 0) {
    // Show time (HH:MM)
    DateTime now = rtc.now();
    int hour = now.hour();
    int minute = now.minute();
    fillTimeBuffer(displayBuf, hour, minute);
    display_word(1, displayBuf, 5, 15);
  } else if (displayMode == 1) {
    // Show date (DD/MM)
    DateTime now = rtc.now();
    int day = now.day();
    int month = now.month();
    fillDateBuffer(displayBuf, day, month);
    display_word(1, displayBuf, 5, 15);
  } else if (displayMode == 2) {
    // Show temperature (e.g. 25C)
    int tempC = readThermistorC();
    fillTempBuffer(displayBuf, tempC);
    display_word(1, displayBuf, 3, 15);
  }
}

// --- Interrupt: button press changes display mode ---
void changeDisplayMode() {
  unsigned long currentMillis = millis();
  if (currentMillis - lastDebounceTime > debounceDelay) {
    displayMode = (displayMode + 1) % 3;
    lastDebounceTime = currentMillis;
  }
}

// --- Buffer filling helpers ---
void fillTimeBuffer(byte buf[8][6], int hour, int minute) {
  // Format: [H][H][colon][M][M]
  for (int i = 0; i < 6; i++) {
    buf[0][i] = (hour >= 10) ? NUMS[hour/10][i] : SPACE_ARR[i];
    buf[1][i] = NUMS[hour%10][i];
    buf[2][i] = TWODOTS_ARR[i];
    buf[3][i] = NUMS[minute/10][i];
    buf[4][i] = NUMS[minute%10][i];
  }
}

void fillDateBuffer(byte buf[8][6], int day, int month) {
  // Format: [D][D][slash][M][M]
  for (int i = 0; i < 6; i++) {
    buf[0][i] = NUMS[day/10][i];
    buf[1][i] = NUMS[day%10][i];
    buf[2][i] = DEVIDE_ARR[i];
    buf[3][i] = NUMS[month/10][i];
    buf[4][i] = NUMS[month%10][i];
  }
}

void fillTempBuffer(byte buf[8][6], int tempC) {
  // Format: [T][T]['C']
  tempC = constrain(tempC, -9, 99); // Clamp for display
  int tens = (tempC < 0) ? 0 : tempC/10;
  int ones = abs(tempC) % 10;
  for (int i = 0; i < 6; i++) {
    buf[0][i] = (tempC < 0) ? MARK_ARR[i] : NUMS[tens][i]; // Use '-' sign (MARK) for negative
    buf[1][i] = NUMS[ones][i];
    buf[2][i] = BC_ARR[i];
  }
}

// --- Thermistor reading (Beta equation) ---
int readThermistorC() {
  int analogValue = analogRead(thermistorPin);
  float R0 = 10000.0;
  float B = 3950.0;
  float T0 = 298.15; // 25C in Kelvin
  float R = R0 * (1023.0 / analogValue - 1.0);
  float tempK = 1.0 / (1.0 / T0 + 1.0 / B * log(R / R0));
  float tempC = tempK - 273.15;
  return (int)tempC;
}

// --- Your unchanged display functions below ---

void display_word(int loops,byte word_print[][6],int num_patterns,int delay_langth){// this function displays your symbols
  i = 0;// resets the counter fot the 4017
  for(int g=0;g<6;g++)//resets the the long int where your word goes
    scrolling_word[g] = 0;
  for(int x=0;x<num_patterns;x++){//main loop, goes over your symbols
   // you will need to find a better way to make the symbols scroll my way is limited for 24 columns

   for(int r=0;r<6;r++)//puts the buildes the first symbol
      scrolling_word[r] |= word_print[x][r]; 
    for (int z=0;z<6;z++){//the sctolling action
        for(int p=0;p<6;p++)
          scrolling_word[p] = scrolling_word[p] << 1;
// end of the scrolling funcion
      for(int t=0;t<delay_langth;t++){// delay function, it just loops over the same display
        for(int y=0;y<6;y++){// scaning the display
          if(i == 6){// counting up to 6 with the 4017
            digitalWrite(Reset,HIGH);
            digitalWrite(Reset,LOW);
            i = 0;
          }
          latchOff();
          spi_transfer(make_word(0x01000000,y));// sending the data
          spi_transfer(make_word(0x00010000,y));
          spi_transfer(make_word(0x00000100,y));
          latchOn();
          delayMicroseconds(800);//waiting a bit
          latchOff();
          spi_transfer(0);// clearing the data
          spi_transfer(0);
          spi_transfer(0);
          latchOn();
          digitalWrite(clock,HIGH);//counting up with the 4017
          digitalWrite(clock,LOW);
          i++;
        }
      }
    }
  }
  finish_scroll(delay_langth);
}

void finish_scroll(int delay_scroll){// this function is the same as the funcion above, it just finishing scrolling
  for (int n=0;n<24;n++){
        for(int h=0;h<6;h++)
          scrolling_word[h] = scrolling_word[h] << 1;
      for(int w=0;w<delay_scroll;w++){
        for(int k=0;k<6;k++){
          if(i == 6){
            digitalWrite(Reset,HIGH);
            digitalWrite(Reset,LOW);
            i = 0;
          }
          latchOff();
          spi_transfer(make_word(0x01000000,k));
          spi_transfer(make_word(0x00010000,k));
          spi_transfer(make_word(0x00000100,k));
          latchOn();
          delayMicroseconds(800);
          latchOff();
          spi_transfer(0);
          spi_transfer(0);
          spi_transfer(0);
          latchOn();
          digitalWrite(clock,HIGH);
          digitalWrite(clock,LOW);
          i++;
        }
      }
    }
}

byte make_word (long posistion,byte turn){
  byte dummy_word = 0;
  for(int q=0;q<8;q++){
    if(scrolling_word[turn] & (posistion<<q))
      dummy_word |= 0x01<<q;
  }
  return dummy_word;
}   

void latchOn(){
  bitSet(PORTB,latchPinPORTB);
}

void latchOff(){
  bitClear(PORTB,latchPinPORTB);
}

void setupSPI(){
  byte clr;
  SPCR |= ( (1<<SPE) | (1<<MSTR) ); // enable SPI as master
  SPCR &= ~( (1<<SPR1) | (1<<SPR0) ); // clear prescaler bits
  clr=SPSR; // clear SPI status reg
  clr=SPDR; // clear SPI data reg
  SPSR |= (1<<SPI2X); // set prescaler bits
  delay(10);
}
byte spi_transfer(byte data)
{
  SPDR = data;			  // Start the transmission
  while (!(SPSR & (1<<SPIF)))     // Wait the end of the transmission
  {
  };
  return SPDR;			  // return the received byte, we don't need that
}

