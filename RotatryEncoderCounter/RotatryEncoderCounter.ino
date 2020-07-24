 #define outputA 12
 #define outputB 11
 #define outputZ 10

//Encoder Configuration
int totalPulse = 2048;
int totalDevices = 10;

//Led pin configuration
int led1=2;
int led2=3;
int led3=4;
int led4=5;

void toBinaryPins(int val)
{
  if(val == 0)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if(val == 1)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if(val == 2)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if(val == 3)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if(val == 4)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  else if(val == 5)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  else if(val == 6)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  else if(val == 7)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  else if(val == 8)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  }
  else if(val == 9)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  }
  else if(val == 10)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  }
  else if(val == 11)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  }
  else if(val == 12)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
  else if(val == 13)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
  else if(val == 14)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
  else if(val == 15)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
}
 
 int counter = 0;
 int previousPulseCounter = 0;
 int pulseCounter = 0;
 int aState;
 int aLastState;  
 int zState;
 bool isHome = false;
 
 void updateState()
 {
  if(digitalRead(outputZ))
  {
    pulseCounter = 0;
    isHome = true;
    return;
  }
  
  if(isHome == true)
  {
    aState = digitalRead(outputA);
  if (aState != aLastState){     
    if (digitalRead(outputB) != aState) {
      previousPulseCounter = pulseCounter;
      pulseCounter ++;
      if(abs(pulseCounter) == (totalPulse*(float)1/4) || abs(pulseCounter) == (totalPulse*(float)3/4))
      {
        if(previousPulseCounter != pulseCounter)
        {
          counter++;
          toBinaryPins(counter);
          Serial.println(counter);
        }
      }
     } 
     else 
     {
       previousPulseCounter = pulseCounter;
       pulseCounter --;
       if(abs(pulseCounter) == (totalPulse*(float)1/4) || abs(pulseCounter) == (totalPulse*(float)3/4))
       {
        if(previousPulseCounter != pulseCounter)
        {
          counter--;
          toBinaryPins(counter);
          Serial.println(counter);
        }
       }
     } 
   }
   aLastState = aState;  
  }
 }
 
 void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   pinMode (outputZ,INPUT);
   pinMode (led1, OUTPUT);
   pinMode (led2, OUTPUT);
   pinMode (led3, OUTPUT);
   pinMode (led4, OUTPUT);
   pinMode(LED_BUILTIN, OUTPUT);
   
   Serial.begin (115200);
   aLastState = digitalRead(outputA);   
 }
 
 void loop() { 
    updateState();
 }
