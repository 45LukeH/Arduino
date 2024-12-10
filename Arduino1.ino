#include <Servo.h>
const int pushButton = 7;
const int pushButtons = 8;
const int ledPins[] = {3, 4, 5, 6};
int ledIndex = 0;
unsigned long previousMillis = 0;
const long interval = 200;
Servo servo;
Servo servo2;
int pos=0;

void setup() {
    Serial.begin(9600);
    pinMode(pushButton, INPUT);
    pinMode(pushButtons, INPUT);
    servo.attach(9,500,2500);
    servo2.attach(10,500,2500);
    
    for(int i = 0; i < 4; i++) {
        pinMode(ledPins[i], OUTPUT);
    }
}

void loop() {
    int buttonState = digitalRead(pushButton);
    Serial.println(buttonState);
    if(buttonState == 0) {
        // 持续循环，直到按钮2被按下
        servo.write(90);
        servo2.write(0);
        while(digitalRead(pushButtons) != 0) {
          
            unsigned long currentMillis = millis();
            if(currentMillis - previousMillis >= interval) {
                previousMillis = currentMillis;
                digitalWrite(ledPins[ledIndex], LOW);
                ledIndex = (ledIndex + 1) % 4;
                digitalWrite(ledPins[ledIndex], HIGH);
            }
        }
        anotherFunction();

    }
}

void anotherFunction() {
    Serial.println("按钮2被按下，进入另一个功能");
    for(int i = 0; i < 4; i++) {
        digitalWrite(ledPins[i], LOW);
    }
      servo2.write(90);
      delay(700);
      servo.write(0);
      delay(1);
    
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
     delay(100);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
     delay(100);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
     delay(100);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    delay(6000);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    return;
}