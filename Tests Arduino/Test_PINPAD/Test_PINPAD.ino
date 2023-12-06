#include "SoftwareSerial.h"
#include <ChainableLED.h>

#define NUM_LEDS 2
#define DATA_PIN D7 // Broche de données du LED
#define CLOCK_PIN D8 // Broche d'horloge du LED
#define RX1 D5 // Broche RX du 1er UART émulé
#define TX1 D6 // Broche TX du 1er UART émulé
#define RX2 D1 // Broche RX du 2ème UART émulé
#define TX2 D2 // Broche TX du 2ème UART émulé

ChainableLED leds(DATA_PIN, CLOCK_PIN, NUM_LEDS);

SoftwareSerial mySerial(RX1,TX1);
SoftwareSerial mySerial2(RX2, TX2);

#define TRANS_SERIAL  mySerial
#define TRANS_SERIAL2 mySerial2


//RX=2,TX=3(D2) Software Serial Port

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  mySerial2.begin(9600);
  leds.init();
  leds.setColorRGB(0, 255, 255, 255);
  leds.setColorRGB(1, 255, 255, 255);
}

void loop() {
    printData();
}


void printData() {
  // PINPAD 1 D5 D6
    while(TRANS_SERIAL.available()) {
        uint8_t data = TRANS_SERIAL.read();
        switch(data) {
                case 0xE1 : // TOUCHE 1
                    leds.setColorRGB(1, 0, 255, 255);
                    break;
                case 0xE2 : // TOUCHE 2
                    leds.setColorRGB(1, 255, 0, 255);
                    break;
                case 0xE3 : // TOUCHE 3
                    leds.setColorRGB(1, 255, 255, 0);
                    break;
                case 0xE4 : // TOUCHE 4
                    leds.setColorRGB(1, 255, 0, 0);
                    break;
                case 0xE5 : // TOUCHE 5
                    leds.setColorRGB(1, 0, 0, 255);
                    break;
                case 0xE6 : // TOUCHE 6
                    leds.setColorRGB(1, 0, 255, 0);
                    break;
                case 0xE7 : // TOUCHE 7
                    leds.setColorRGB(1, 128, 128, 255);
                    break;
                case 0xE8 : // TOUCHE 8
                    leds.setColorRGB(1, 255, 255, 128);
                    break;
                case 0xE9 : // TOUCHE 9
                    leds.setColorRGB(1, 128, 255, 255);
                    break;
                case 0xEA : // TOUCHE *
                    leds.setColorRGB(1, 255, 128, 255);
                    break;
                case 0xEB : // TOUCHE 0
                    leds.setColorRGB(1, 128, 0, 255);
                    break;
                case 0xEC : // TOUCHE #
                    leds.setColorRGB(1, 255, 128, 0);
                    break;
                default:
                    break;
            }
    }

    // PINPAD 2 D1 D2
    while(TRANS_SERIAL2.available()) {
        uint8_t data = TRANS_SERIAL2.read();
        switch(data) {
                case 0xE1 : // TOUCHE 1
                    leds.setColorRGB(0, 0, 255, 255);
                    break;
                case 0xE2 : // TOUCHE 2
                    leds.setColorRGB(0, 255, 0, 255);
                    break;
                case 0xE3 : // TOUCHE 3
                    leds.setColorRGB(0, 255, 255, 0);
                    break;
                case 0xE4 : // TOUCHE 4
                    leds.setColorRGB(0, 255, 0, 0);
                    break;
                case 0xE5 : // TOUCHE 5
                    leds.setColorRGB(0, 0, 0, 255);
                    break;
                case 0xE6 : // TOUCHE 6
                    leds.setColorRGB(0, 0, 255, 0);
                    break;
                case 0xE7 : // TOUCHE 7
                    leds.setColorRGB(0, 128, 128, 255);
                    break;
                case 0xE8 : // TOUCHE 8
                    leds.setColorRGB(0, 255, 255, 128);
                    break;
                case 0xE9 : // TOUCHE 9
                    leds.setColorRGB(0, 128, 255, 255);
                    break;
                case 0xEA : // TOUCHE *
                    leds.setColorRGB(0, 255, 128, 255);
                    break;
                case 0xEB : // TOUCHE 0
                    leds.setColorRGB(0, 128, 0, 255);
                    break;
                case 0xEC : // TOUCHE #
                    leds.setColorRGB(0, 255, 128, 0);
                    break;
                default:
                    break;
            }
    }

}

