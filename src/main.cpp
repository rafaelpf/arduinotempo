#include <Arduino.h>
#include <PiscaLed.cpp>
#include <DS1307.h>

#define PIN_LED1 7
#define PIN_LED2 13
/*
class Led{
  private:
      byte _pino;
      long _time1;
      long _time2;
      boolean ledState = LOW;
      long nextChangeTime = 0;          
      
  public:

    Led(byte pino, long time1, long time2){
      _pino = pino;
      _time1 = time1;
      _time2 = time2;  
      pinMode(_pino, OUTPUT);
      }
  
  void acendeLed() {
      long currentTime = millis();
        if(currentTime >= nextChangeTime) {
          if(ledState) {
           // LED is currently turned On. Turn Off LED.
            ledState = LOW;
            nextChangeTime = currentTime + _time2;
          }
          else{
            // LED is currently turned Off. Turn On LED.
            ledState = HIGH;
            nextChangeTime = currentTime + _time1;
          }
          digitalWrite(_pino, ledState);
        }
      
      }


      void acendeLed2() {
        digitalWrite(_pino, HIGH);
        delay(_time1);
        digitalWrite(_pino, LOW);
        delay(_time2);
      }
      
  };

*/

int resul=0;
int botao1 = 2;
int botao2 = 8;
String a;

byte leda = PIN_LED1;

DS1307 rtc(A4, A5);

Led led1(leda,100,100);
Led led2(PIN_LED2,3000,3000);
  


void setup() {
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);

}

void loop() {
  //resul = digitalRead(botao1);
  if (digitalRead(botao1) == LOW){
    led1.acendeLed2();      
    
  }
  if (digitalRead(botao2) == LOW){
     led2.acendeLed2(); 
  }
  a = rtc.getTimeStr();
  if ((a >= "19:55:00")and (a < "22:00:00")){
         led1.acendeLed2();
  }

}