#include <Arduino.h>


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