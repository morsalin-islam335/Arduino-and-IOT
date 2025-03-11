// purpose: to detect a thief using a PIR sensor and sound an alarm using a buzzer
const int buzzerInputPin = 13;
const int PIROutputPin = 12;


void setup(){
   

    pinMode(buzzerInputPin, OUTPUT);
    pinMode(PIROutputPin, INPUT);
    
}

void loop(){
    if (digitalRead(PIROutputPin)){
        digitalWrite(buzzerInputPin, HIGH);
        delay(5000);
        digitalWrite(buzzerInputPin, LOW);
    }
    else digitalWrite(buzzerInputPin, LOW);
}   

// rest day