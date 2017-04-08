//Modified from: https://learn.adafruit.com/using-an-infrared-library/hardware-needed

#include <IRLib.h>

 
//Create a receiver object to listen on pin 11
IRrecv My_Receiver(11);
 
//Create a decoder object
IRdecode My_Decoder;

int POWER = 0;
int ENGINE = 0;
int ENGINE_LEVEL = 0;
int DIRECTION = 0;
int TURN_RATE = 4;

void powerButton(){
  if (POWER) {
    POWER = 0;
    digitalWrite(2, LOW);
    ENGINE_LEVEL = 0;
  }
  else {
    POWER = 1;
    digitalWrite(2, HIGH);
  }
}

void changeDirection(int value){
  DIRECTION = value;
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  if (DIRECTION == 1){
    digitalWrite(3, HIGH);
  }
  if (DIRECTION == 2){
    digitalWrite(4, HIGH);
  }
}

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  My_Receiver.enableIRIn(); // Start the receiver
}

void loop() {
//Continuously look for results. When you have them pass them to the decoder
  if (My_Receiver.GetResults(&My_Decoder)) {
    My_Decoder.decode();
    
    if (My_Decoder.value==1637937167){
      powerButton();
    }
    
    if (My_Decoder.value==1637875967){
      ENGINE_LEVEL = 1;
    }
    
    if (My_Decoder.value==1637908607){
      ENGINE_LEVEL = 2;
    }
    
    if (My_Decoder.value==1637892287){
      ENGINE_LEVEL = 3;
    }
    
    if (My_Decoder.value==1637924927){
      ENGINE_LEVEL = 4;
    }
    
    if (My_Decoder.value==1637884127){
      ENGINE_LEVEL = 5;
    }
    
    if (My_Decoder.value==1637916767){
      ENGINE_LEVEL = 6;
    }
    
    if (My_Decoder.value==1637900447){
      ENGINE_LEVEL = 7;
    }
    
    if (My_Decoder.value==1637933087){
      ENGINE_LEVEL = 8;
    }
    
    if (My_Decoder.value==1637880047){
      ENGINE_LEVEL = 9;
    }
    
    if (My_Decoder.value==1637912687){
      ENGINE_LEVEL = 0;
    }
    
    if (My_Decoder.value==1637882087){
      changeDirection(0);
    }

    if (My_Decoder.value==1637920847){
      changeDirection(1);
    }
    if (My_Decoder.value==1637888207){
      changeDirection(2);
    }

    //analogWrite(3, 1023 * ENGINE_LEVEL / 9);  
    analogWrite(5, (255 * ENGINE_LEVEL) / 9);
    //Serial.println(My_Decoder.value==1637882087);M
    Serial.println(My_Decoder.value);
    Serial.println(ENGINE_LEVEL);    
    My_Receiver.resume(); 		//Restart the receiver
    Serial.println((255 * ENGINE_LEVEL) / 9);
    delay(5);
  }
}
