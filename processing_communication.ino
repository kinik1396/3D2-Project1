int led = 13;

void setup() {
  pinMode(led, OUTPUT); 
  Serial.begin(9600);//inializes the serial
}
void loop(){
  if(Serial.available() > 0) {
    char ledState = Serial.read();//reads the serial coming from processing
  
    if(ledState == '1'){// if the serial reads 1 turn light on
      digitalWrite(led, HIGH);
    }
    if(ledState == '0'){// if the serial reads 0 turn light off
      digitalWrite(led, LOW);
    }
  }
}
//https://howtomechatronics.com/tutorials/arduino/processing/
//edited for use without the button
