#include <Adafruit_CircuitPlayground.h>

// DOCUMENTATION //

// Creator: 
//    James Byrnes
//    Steven Rupert
//    Sabrina Yuchasz
// Last Update:
//    4/18/2017
// Description:
//    This was created for the use in a car for pet owners to monitor the heat while away.
// Functions:
//    switchstate() - Used to switch the on/off states for the device.


// Variables
/////////////////////
bool leftButtonPressed;
bool rightButtonPressed;
int lightSensorValue;
bool onoff = false;
int SoundSensorValue;
int TemperatureSensorValue;
int TemperatureAlarmValue = 28;

// Runs on startup of the program
void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  CircuitPlayground.playTone(100,100);
  pinMode(1,OUTPUT);
}

// Switchstate- Switches the state of the onoff variable for the program to turn on/off on the device
void switchstate(){
  if(onoff == true){
    onoff = false;  
    Serial.println("State OFF");
  }else{
    onoff = true;
    Serial.println("State ON");  
  }
}


// Infinite loop - Everything monitored in this section lights/sounds turn on with this point.
void loop() {
  leftButtonPressed = CircuitPlayground.leftButton();
  rightButtonPressed = CircuitPlayground.rightButton();
  lightSensorValue = CircuitPlayground.lightSensor();
  SoundSensorValue = CircuitPlayground.soundSensor();
  TemperatureSensorValue = CircuitPlayground.temperature();

  Serial.print("Temperature: ");
  Serial.println(TemperatureSensorValue);

  if(leftButtonPressed == true){
      switchstate();
  }
  if(rightButtonPressed == true){
      if(TemperatureAlarmValue == 28){
          TemperatureAlarmValue = 30; 
          CircuitPlayground.playTone(400,100); 
      }else{
          if(TemperatureAlarmValue == 30){
            TemperatureAlarmValue = 32;  
            CircuitPlayground.playTone(600,100);
          }else{
            if(TemperatureAlarmValue == 32){
              TemperatureAlarmValue = 28;  
              CircuitPlayground.playTone(200,100);
            }  
          }  
       }
      
      
  }

if(onoff == true){  // If on then allow program to continue else turn all the lights off to save power and also not run the alarm when temperature reached.
  if(TemperatureSensorValue >= TemperatureAlarmValue){
    CircuitPlayground.playTone(100,200);
    digitalWrite(1,HIGH);
  }else{
    digitalWrite(1,LOW);
  }
  
  if(TemperatureSensorValue >= 10){
    CircuitPlayground.setPixelColor(0,0,0,255);  
  }
  
  if(TemperatureSensorValue >= 12){
    CircuitPlayground.setPixelColor(1,0,255,0);  
  }else{CircuitPlayground.setPixelColor(1,0,0,0);}
  
  if(TemperatureSensorValue >= 17){
    CircuitPlayground.setPixelColor(2,0,255,0);  
  }else{CircuitPlayground.setPixelColor(2,0,0,0);}
  
  if(TemperatureSensorValue >= 20){
    CircuitPlayground.setPixelColor(3,0,255,0);  
  }else{CircuitPlayground.setPixelColor(3,0,0,0);}
  
  if(TemperatureSensorValue >= 22){
    CircuitPlayground.setPixelColor(4,200,55,0);  
  }else{CircuitPlayground.setPixelColor(4,0,0,0);}
  
  if(TemperatureSensorValue >= 24){
    CircuitPlayground.setPixelColor(5,220,55,0);  
  }else{CircuitPlayground.setPixelColor(5,0,0,0);}
  
  if(TemperatureSensorValue >= 26){
    CircuitPlayground.setPixelColor(6,230,55,0);  
  }else{CircuitPlayground.setPixelColor(6,0,0,0);}
  
  if(TemperatureSensorValue >= 28){
    CircuitPlayground.setPixelColor(7,255,0,0);  
  }else{CircuitPlayground.setPixelColor(7,0,0,0);}
  
  if(TemperatureSensorValue >= 30){
    CircuitPlayground.setPixelColor(8,255,0,0);  
  }else{CircuitPlayground.setPixelColor(8,0,0,0);}
  
  if(TemperatureSensorValue >= 32){
    CircuitPlayground.setPixelColor(9,255,0,0);  
  }else{CircuitPlayground.setPixelColor(9,0,0,0);}
}else{
  CircuitPlayground.setPixelColor(0,0,0,0);
  CircuitPlayground.setPixelColor(1,0,0,0);
  CircuitPlayground.setPixelColor(2,0,0,0);
  CircuitPlayground.setPixelColor(3,0,0,0);
  CircuitPlayground.setPixelColor(4,0,0,0);
  CircuitPlayground.setPixelColor(5,0,0,0);
  CircuitPlayground.setPixelColor(6,0,0,0);
  CircuitPlayground.setPixelColor(7,0,0,0);
  CircuitPlayground.setPixelColor(8,0,0,0);
  CircuitPlayground.setPixelColor(9,0,0,0);
  digitalWrite(1,LOW);
  }
  delay(300);
}
