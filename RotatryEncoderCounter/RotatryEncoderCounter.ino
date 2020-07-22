 #define outputA 12
 #define outputB 11
 #define outputZ 10
 
 int totalPulse = 2048;
 
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
   
   Serial.begin (115200);
   aLastState = digitalRead(outputA);   
 }
 
 void loop() { 
    updateState();
 }
