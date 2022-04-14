const int relayPin = 2; // la base du transistor s'attache au pin 2
String comdata = "";
int lastLength = 0;

void setup()
{
  pinMode(relayPin, OUTPUT);  // initialise les LED comme sortie
  Serial.begin(9600);  // serial port à 9600 bps
  while (! Serial);
  Serial.println("Please input your command to control this Lamp:");  
                // message sur le moniteur série
}

void loop()
{
 // lis la chaine du moniteur serie
  if(Serial.available()>0)  // vérifie si les données sont envoyé depuis l'ordi
  {  
    comdata = "";
    while (Serial.available() > 0)  
    {        
      comdata += char(Serial.read());
      delay(2);
    }
    Serial.println(comdata);
  }
    if(comdata == "on")
    {
      digitalWrite(relayPin, HIGH);// allume l'ampoule
    }
    else if(comdata == "off")
    {
      digitalWrite(relayPin, LOW);// éteind l'ampoule
    } 
    else
    {
      Serial.println("Please input correct command !");
      delay (20000);
    }
}
