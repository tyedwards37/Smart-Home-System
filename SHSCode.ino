 /***********************************************************
File name: T_Edwards_SmartHomeSystem
Description: The ultrasonic sensor detects the distance,
changes the color of the RGB LED accordingly, and displays
the distance on the LCD. When the object is a certain distance
away the buzzer will sound.

E-mail: tyedwards@chapman.edu
Author: Tyler Edwards
Date: 12/04/2021

-extension of Lessons 4, 5, & 20 
***********************************************************/
#include <LiquidCrystal.h>
int redPin = 4;   // R petal on RGB LED module connected to digital pin 4
int greenPin = 3; // G petal on RGB LED module connected to digital pin 3 
int bluePin = 2;   // B petal on RGB LED module connected to digital pin 2
const int echoPin = 5;  // pin connected to Echo Pin in the ultrasonic distance sensor
const int trigPin  = 6; // pin connected to trig Pin in the ultrasonic distance sensor
int buzzerPin = 22; //definition digital 8 pins as pin to control the buzzer

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);   
/*
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
*/
void setup() 
{
   pinMode(echoPin, INPUT); //Set the connection pin output mode Echo pin
   pinMode(trigPin, OUTPUT);//Set the connection pin output mode trog pin
   pinMode(redPin, OUTPUT);   // sets the redPin to be an output 
   pinMode(greenPin, OUTPUT); // sets the greenPin to be an output 
   pinMode(bluePin, OUTPUT);  // sets the bluePin to be an output 
   pinMode(buzzerPin,OUTPUT); //Set digital 22 port mode, the OUTPUT for the output
   lcd.begin(16, 2);        //set up the LCD's number of columns and rows: 
   lcd.clear();             //Clears the LCD screen and positions the cursor in the upper-left corner 
   delay(1000);             //delay 1000ms
} 

void loop() 
{ 
   int cm = ping(echoPin) ;
   lcd.setCursor(0, 0);          // set the cursor to column 0, line 0
   lcd.print("distance: ");      // Print a message of "Temp: "to the LCD.
   lcd.print(cm);                // Print a centigrade temperature to the LCD. 
   lcd.print(" cm    ");         // Print the unit of the centigrade temperature to the LCD.
   if(cm <= 5) 
   {
    color(255, 0, 0);
      digitalWrite(buzzerPin,HIGH); //Set PIN 8 feet as HIGH = 5 v 
   }
   else if(cm <= 10 && cm > 5) 
    {
     color(255, 30, 0);
      digitalWrite(buzzerPin,HIGH); //Set PIN 8 feet as HIGH = 5 v 
      delay(1000);                   //Set the delay time，2000ms 
      digitalWrite(buzzerPin,LOW);  //Set PIN 8 feet for LOW = 0 v 
      delay(100); 
    }
   else if(cm <= 15 && cm > 10) 
   {
    color(255, 127, 0);
      digitalWrite(buzzerPin,HIGH); //Set PIN 8 feet as HIGH = 5 v 
      delay(1000);                   //Set the delay time，2000ms 
      digitalWrite(buzzerPin,LOW);  //Set PIN 8 feet for LOW = 0 v 
      delay(2000); 
   }
   else if(cm <= 20 && cm > 15) 
   {
    color(0, 0, 255);
      digitalWrite(buzzerPin,LOW);  //Set PIN 8 feet for LOW = 0 v 
   }
   else if(cm <= 25 && cm > 20) 
   {
    color(127, 0, 255);
      digitalWrite(buzzerPin,LOW);  //Set PIN 8 feet for LOW = 0 v 
   }
   else 
   { 
    color(0, 255, 0);
      digitalWrite(buzzerPin,LOW);  //Set PIN 8 feet for LOW = 0 v 
   }
    delay(500);
}
     
int ping(int echoPin) 
{ 
   // establish variables for duration of the ping, 
   // and the distance result in inches and centimeters: 
   long duration, cm; 
   // The PING))) is triggered by a HIGH pulse of 2 or more microseconds. 
   // Give a short LOW pulse beforehand to ensure a clean HIGH pulse: 
   pinMode(trigPin, OUTPUT); 
   digitalWrite(trigPin, LOW); 
   delayMicroseconds(2); 
   digitalWrite(trigPin, HIGH); 
   delayMicroseconds(5); 
   digitalWrite(trigPin, LOW); 

   pinMode(echoPin, INPUT); 
   duration = pulseIn(echoPin, HIGH); 

   // convert the time into a distance 
   cm = microsecondsToCentimeters(duration); 
   return cm ; 
} 

long microsecondsToCentimeters(long microseconds) 
{ 
   // The speed of sound is 340 m/s or 29 microseconds per centimeter. 
   // The ping travels out and back, so to find the distance of the 
   // object we take half of the distance travelled. 
   return microseconds / 29 / 2; 
} 

void color (unsigned char red, unsigned char green, unsigned char blue)// the color generating function  
{    
     analogWrite(redPin, red);     // PWM signal output   
     analogWrite(greenPin, green); // PWM signal output
     analogWrite(bluePin, blue);   // PWM signal output
}   

        
        
        
        
      
