int ledPin = 13;                // choisi le pin pour la LED
int inputPin = 7;               // choisi l'entrée du pin (pour le PIR sensor)
int pirState = LOW;             // on commence sur aucun mouvemement détécté
int val = 0;                    // variable pour lire le statut du pin
 
void setup() {
  pinMode(ledPin, OUTPUT);      // déclare LED comme sorti
  pinMode(inputPin, INPUT);     // déclare le détécteur comme entrée
 
  Serial.begin(9600);
}
 
void loop(){
  val = digitalRead(inputPin);  // lis la valeur d'entrée
  if (val == HIGH) {            // vérifie si l'entrée est HIGH
    digitalWrite(ledPin, HIGH);  // met la LED sur ON
    if (pirState == LOW) {
      // on a simplement mis sur ON
      Serial.println("Motion detected!");
      // on veut seulement imprimer le changement de la sortie, pas de l'état
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // met les LED sur OFF
    if (pirState == HIGH){
      // on veut simplement mettre sur OFF
      Serial.println("Motion ended!");
      // on veut seulement imprimer le changement de la sortie, pas de l'état
      pirState = LOW;
    }
  }
}
