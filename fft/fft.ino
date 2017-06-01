/*
  Blink

*/

// DISPLAY

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//#include <adafruit_feather.h>

// FFT
#define LOG_OUT 1 // use the log output function
#define FFT_N 256 // set to 256 point fft 
#include <FFT.h> // include the library
#define MicPin A5

// OLED
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
unsigned long time1 = 0;
unsigned long time2 = 0;
// ADC Definitions to set the conversion time
// Just copy them as they are here


#define BUFFERSIZE FFT_N

//uint16_t fft_input[BUFFERSIZE];
int k = 0;

// The different settings set the ADC clock frequency, the conversion time
// and the equivalent number of bits

// ADC_TIME_104    f=125kHz   Tconv=104us    ENOB > 9
// ADC_TIME_52     f=250kHz   Tconv=52us     ENOB > 9
// ADC_TIME_26     f=500kHz   Tconv=26us     ENOB > 9
// ADC_TIME_13     f=1MHz     Tconv=13us     ENOB > 8

/*************************************************************************/


// Test program that converts A0 four times using the
// four timming options
//
// Pin 3 (PD0) is at high level during each conversion so that
// the conversion time can be measured on a scope
// The toggle of pin 3 only consumes one clock cycle (62ns)
// so it is negligible



// the setup function runs once when you press reset or power the board
void setup() {
  Serial.println("Bonjour");
  Serial.println("C'est la carte Arduino qui parle");



  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  //TIMSK0 = 0; // turn off timer0 for lower jitter
  ADCSRA = 0xe5; // set the adc to free running mode
  ADMUX = 0x40; // use adc0
  // DIDR0 = 0x01; // turn off the digital input for adc0



  // Display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("== Test starting == ");
  display.display();
  digitalWrite(13, LOW);
  delay(2000);
}

// the loop function runs over and over again forever
void loop() {

  while (Serial.available()) {
    int lu = Serial.read() - 48;
    display.println(lu);
    display.display();
    if (lu == 1) {
      display.println("Lu == 1");
      display.display();
      transmit();
    }
lu = 0;
  }
  delay(1000);





}


void transmit()
{

  int i = 0;

  int l = 0;



  digitalWrite(13, HIGH);
  // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for a second



  // ADC_TIME_52; // Normal Aduino Setting (52us)
  i = 0;
  time1 = micros();
  while (i < FFT_N) {
    //fft_input[i << 1] = analogRead(A5);
    while (!(ADCSRA & 0x10)); // wait for adc to be ready
    ADCSRA = 0xf5; // restart adc
    byte m = ADCL; // fetch adc data
    byte j = ADCH;
    int k = (j << 8) | m; // form into an int
    k -= 0x0200; // form into a signed int
    k <<= 6; // form into a 16b signed int
    fft_input[i << 1] = k;
    i++;
  }
    time2 = micros();



    fft_window();
    fft_reorder(); // reorder the data before doing the fft
    fft_run(); // process the data in the fft

    int  high = 0;

    Serial.print("Line ");Serial.print(time1);Serial.print(" "); Serial.print(time2); Serial.print(" ");
    l = 0;
    while (l < FFT_N) {
      high = ((unsigned int)sq(fft_input[l << 1]) + (unsigned int)sq(fft_input[(l << 1) + 1])) >> 1; //the bin value really = sqrt(sq(re) + sq(im)) but this is faster and is still easy to read

      Serial.print(high);
      Serial.print(";");
      l++;
    }
  
  Serial.println("EOF");
  int value = 0;
  i = 0;
  display.clearDisplay();


  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(200);              // wait for a second

}

