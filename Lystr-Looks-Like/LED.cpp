//#include "Arduino.h"
#include "LED.h"




LED::LED(uint8_t redPin, uint8_t greenPin, uint8_t bluePin)
{
//  pinMode(redPin, OUTPUT);
//  pinMode(greenPin, OUTPUT);
//  pinMode(bluePin, OUTPUT);

  _redPin = RED_PIN;
  _greenPin = GREEN_PIN;
  _bluePin = BLUE_PIN;
  
  _lastEventTime = 0;
  _currentTime = 0;

  _redState = LOW;
  _blueState = LOW;
  _greenState = LOW;
}

void LED::flash(color ledColor, double pulseLength)
{
  double timeDif = 0;
  double currentTime = millis();

  timeDif = currentTime - _lastEventTime;

  Serial.println(timeDif);
  

  if(timeDif >= pulseLength)
  {
        if( (AH_LED && _ledState) || (!AH_LED && !_ledState) )
        {
          turnOff();
          _lastEventTime = millis();
        }
        else
        {
          setColor(ledColor);
          _lastEventTime = millis();
        } 
  }
  
}

void LED::turnOff(void)
{
  if(AH_LED)
  {
    analogWrite(_redPin, 0);
    analogWrite(_greenPin, 0);
    analogWrite(_bluePin, 0);

    Serial.println("HELLO2");

    _ledState = 0;
  }
  else
  {
    analogWrite(_redPin, 255);
    analogWrite(_greenPin, 255);
    analogWrite(_bluePin, 255);

    _ledState = 0;
  }
}

void LED::setColor(color ledColor)
{

  switch(ledColor)
  {
    case RED :
    {
      if(AH_LED)
      {
        analogWrite(_redPin, 100);
        analogWrite(_greenPin, 0);
        analogWrite(_bluePin, 0);
      }
      else
      {
        analogWrite(_redPin, 155);
        analogWrite(_greenPin, 255);
        analogWrite(_bluePin, 255);
      }
    }

    break;

    case GREEN :
    {
      if(AH_LED)
      {
        analogWrite(_redPin, 0);
        analogWrite(_greenPin, 255);
        analogWrite(_bluePin, 0);
      }
      else
      {
        analogWrite(_redPin, 255);
        analogWrite(_greenPin, 0);
        analogWrite(_bluePin, 255);
      }

    }

    break;

    case BLUE :
    {
      if(AH_LED)
      {
        analogWrite(_redPin, 0);
        analogWrite(_greenPin, 0);
        analogWrite(_bluePin, 255);
      }
      else
      {
        analogWrite(_redPin, 255);
        analogWrite(_greenPin, 255);
        analogWrite(_bluePin, 0);
      }
    }

    break;

    case YELLOW :
    {
      if(AH_LED)
      {
        analogWrite(_redPin, 255);
        analogWrite(_greenPin, 255);
        analogWrite(_bluePin, 0);
      }
      else
      {
        analogWrite(_redPin, 0);
        analogWrite(_greenPin, 0);
        analogWrite(_bluePin, 255);
      }
    }

    break;

    case PURPLE :
    {
      if(AH_LED)
      {
        analogWrite(_redPin, 255);
        analogWrite(_greenPin, 0);
        analogWrite(_bluePin, 255);
      }
      else
      {
        analogWrite(_redPin, 0);
        analogWrite(_greenPin, 255);
        analogWrite(_bluePin, 0);
      }
    }

    break;
  }

  _ledState = 1;
  
}

void LED::pulse(color ledColor, int pulseDelay)
{
  switch(ledColor)
  {
    case RED :
    {
      if(AH_LED)
      {
        for(int i = 0; i < 255; i++)
        {
          analogWrite(_redPin, i);
          analogWrite(_bluePin, 0);
          analogWrite(_greenPin, 0);
          delay(pulseDelay);
         }

         for(int i = 255; i > 0; i--)
         {
          analogWrite(_redPin, i);
          analogWrite(_greenPin, 0);
          analogWrite(_bluePin, 0);
          delay(pulseDelay);
         }        
      }
      else
      {
        for(int i = 255; i > 0; i--)
        {
          analogWrite(_redPin, i);
          analogWrite(_bluePin, 255);
          analogWrite(_greenPin, 255);
          delay(pulseDelay);
         }

         for(int i = 0; i < 255; i++)
         {
          analogWrite(_redPin, i);
          analogWrite(_greenPin, 255);
          analogWrite(_bluePin, 255);
          delay(pulseDelay);
         } 
        }  
     }
   
   case GREEN :
    {
      if(AH_LED)
      {
        for(int i = 0; i < 255; i++)
        {
          analogWrite(_redPin, 0);
          analogWrite(_bluePin, 0);
          analogWrite(_greenPin, i);
          delay(pulseDelay);
         }

         for(int i = 255; i > 0; i--)
         {
          analogWrite(_redPin, 0);
          analogWrite(_greenPin, i);
          analogWrite(_bluePin, 0);
          delay(pulseDelay);
         }        
      }
      else
      {
        for(int i = 255; i > 0; i--)
        {
          analogWrite(_redPin, 255);
          analogWrite(_bluePin, 255);
          analogWrite(_greenPin, i);
          delay(pulseDelay);
         }

         for(int i = 0; i < 255; i++)
         {
          analogWrite(_redPin, 255);
          analogWrite(_greenPin, i);
          analogWrite(_bluePin, 255);
          delay(pulseDelay);
         } 
        }  
     }

  case BLUE :
    {
      if(AH_LED)
      {
        for(int i = 0; i < 255; i++)
        {
          analogWrite(_redPin, 0);
          analogWrite(_bluePin, i);
          analogWrite(_greenPin, 0);
          delay(pulseDelay);
         }

         for(int i = 255; i > 0; i--)
         {
          analogWrite(_redPin, 0);
          analogWrite(_greenPin, 0);
          analogWrite(_bluePin, i);
          delay(pulseDelay);
         }        
      }
      else
      {
        for(int i = 255; i > 0; i--)
        {
          analogWrite(_redPin, 255);
          analogWrite(_bluePin, i);
          analogWrite(_greenPin, 255);
          delay(pulseDelay);
         }

         for(int i = 0; i < 255; i++)
         {
          analogWrite(_redPin, 255);
          analogWrite(_greenPin, 255);
          analogWrite(_bluePin, i);
          delay(pulseDelay);
         } 
        }  
     }    
   }   
}
