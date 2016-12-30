/*---------------------------------------
 *  Lystr "Looks Like" Firmware
 *  
 *  Written By:
 *  Neil Kumar
 ---------------------------------------*/

#include "LED.h"

#define RED_RING    6
#define BLUE_RING   4
#define GREEN_RING  3
#define BUZZER      5
#define PROX        7

#define RED_LED     9

LED led(RED_RING, GREEN_RING, BLUE_RING);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  //initialize ring LED Pins as output (will be managed by LED Class)
  Serial.println("Initializing LED Ring"); 
  pinMode(RED_RING, OUTPUT);
  pinMode(BLUE_RING, OUTPUT);
  pinMode(GREEN_RING, OUTPUT);

  //initialize barcode scanner fake led
  Serial.println("Initializing Barcode Scanner");
  pinMode(RED_LED, OUTPUT);

  //initialize buzzer pin
  Serial.println("Initializing Buzzer");
  pinMode(BUZZER, OUTPUT);

  //initialize prox sensor pin
  Serial.println("Initializing Proximity Sensor");
  pinMode(PROX, INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  int proxStatus = 1;

  proxStatus = digitalRead(PROX);

  //enter if proximity sensor is triggered
  if(proxStatus == 0){

    //turn on red LED for 2.5 seconds to fake barcode scanner
    digitalWrite(RED_LED, HIGH);
    delay(2500);


    //turn on buzzer beep 
    analogWrite(BUZZER, 255);
    delay(250);
    analogWrite(BUZZER, 0);
    delay(100);

    //pulse ring green three times
    for(int i = 0; i < 3; i++)
    {
      led.pulse(GREEN, 25);
    }
  }


}






























