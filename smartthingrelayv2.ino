// A Spark function to parse the commands
int relay1(String command);
int relay2(String command);
int relay3(String command);
int relay4(String command);
int relay5(String command);
int relay6(String command);
int relay7(String command);
int relay8(String command);

// We name pins 
int r1 = D0; 
int r2 = D1;
int r3 = D2;
int r4 = D3;
int r5 = D4;
int r6 = D5;
int r7 = D6;
int r8 = D7;

int r1s = 0; 
int r2s = 0;
int r3s = 0;
int r4s = 0;
int r5s = 0;
int r6s = 0;
int r7s = 0;
int r8s = 0;
char myCharSSID[64];



// This routine runs only once upon reset
void setup() 
{
    
    
  //Register Spark functions
  Spark.function("strelay1", relay1);  
  Spark.function("strelay2", relay2);
  Spark.function("strelay3", relay3);
  Spark.function("strelay4", relay4);
  Spark.function("strelay5", relay5);
  Spark.function("strelay6", relay6);
  Spark.function("strelay7", relay7);
  Spark.function("strelay8", relay8);
  
  
  
  //
Spark.variable("r1",&r1s, INT);
Spark.variable("r2",&r2s, INT);
Spark.variable("r3",&r3s, INT);
Spark.variable("r4",&r4s, INT);
Spark.variable("r5",&r5s, INT);
Spark.variable("r6",&r6s, INT);
Spark.variable("r7",&r7s, INT);
Spark.variable("r8",&r8s, INT); 
Spark.variable("Wifi",myCharSSID, STRING); 
  
  // Initialize output pins
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);
  pinMode(r5, OUTPUT);
  pinMode(r6, OUTPUT);
  pinMode(r7, OUTPUT);
  pinMode(r8, OUTPUT);
  
  // take control of the LED
  RGB.control(true);
  

}



// This routine loops forever 
void loop()
{
  // nothing here
  if (Particle.connected() == false) {
    Particle.connect();
      // the following sets the RGB LED to red:
  RGB.color(100, 0, 0);
  }
  
    // the following sets the RGB LED to light green:
  RGB.color(0, 100, 0);
  
strcpy(myCharSSID, WiFi.SSID());
}



//acts based on messages from spark cloud
int relay1(String command)
{
  if (command == "1") 
    {   
    digitalWrite(r1, HIGH);   // Turn ON the relay
    r1s = 1; 
    return 1;
    } 
  else 
    {               
    digitalWrite(r1, LOW);    // Turn OFF the relay
    r1s = 0; 
    return 0;
    }
}

int relay2(String command)
{
  if (command == "1") 
    {   
    digitalWrite(r2, HIGH);   // Turn ON the relay
    r2s = 1; 
    return 1;
    } 
  else 
    {               
    digitalWrite(r2, LOW);    // Turn OFF the relay
    r2s = 0; 
    return 0;
    }
}

int relay3(String command)
{
  if (command == "1") 
    {   
    digitalWrite(r3, HIGH);   // Turn ON the relay
    r3s = 1; 
    return 1;
    } 
  else 
    {               
    digitalWrite(r3, LOW);    // Turn OFF the relay
    r3s = 0; 
    return 0;
    }
}

int relay4(String command)
{
  if (command == "1") 
    {   
    digitalWrite(r4, HIGH);   // Turn ON the relay
    r4s = 1; 
    return 1;
    } 
  else 
    {               
    digitalWrite(r4, LOW);    // Turn OFF the relay
    r4s = 0; 
    return 0;
    }
}

int relay5(String command)
{
  if (command == "1") 
    {   
    digitalWrite(r5, HIGH);   // Turn ON the relay
    r5s = 1; 
    return 1;
    } 
  else 
    {               
    digitalWrite(r5, LOW);    // Turn OFF the relay
    r5s = 0; 
    return 0;
    }
}

int relay6(String command)
{
  if (command == "1") 
    {   
    digitalWrite(r6, HIGH);   // Turn ON the relay
    r6s = 1; 
    return 1;
    } 
  else 
    {               
    digitalWrite(r6, LOW);    // Turn OFF the relay
    r6s = 0; 
    return 0;
    }
}

int relay7(String command)
{
  if (command == "1") 
    {   
    digitalWrite(r7, HIGH);   // Turn ON the relay
    r7s = 1; 
    return 1;
    } 
  else 
    {               
    digitalWrite(r7, LOW);    // Turn OFF the relay
    r7s = 0; 
    return 0;
    }
}

int relay8(String command)
{
  if (command == "1") 
    {   
    digitalWrite(r8, HIGH);   // Turn ON the relay
    r8s = 1; 
    return 1;
    } 
  else 
    {               
    digitalWrite(r8, LOW);    // Turn OFF the relay
    r8s = 0; 
    return 0;
    }
}
