// Global variables:

// LoRaWAN end-device address (DevAddr)

static const u4_t DEVADDR = 0x260BDD8C;

// LoRaWAN NwkSKey, network session key
// This is the default Semtech key, which is used by the early prototype TTN
// network.
static const PROGMEM u1_t NWKSKEY[16] = {  0x89, 0x49, 0x1F, 0xA9, 0x71, 0x6F, 0xAF, 0x2F, 0x88, 0x84, 0x1E, 0xB6, 0xBE, 0xD4, 0x97, 0x56 };


// LoRaWAN AppSKey, application session key
// This is the default Semtech key, which is used by the early prototype TTN
// network.
static const u1_t PROGMEM APPSKEY[16] = {  0xF4, 0x11, 0x66, 0x8B, 0x72, 0x52, 0x6B, 0xAF, 0x85, 0xE1, 0xAC, 0xD0, 0x01, 0x37, 0x94, 0x37 };

void setup() {
   pinMode(3, OUTPUT);
   pinMode(2, INPUT);
   Serial.begin(9600);
}

void loop() {
   Serial.println(analogRead(A0));
   Serial.print("Présence : ");
   Serial.println(digitalRead(2));
   if (digitalRead(A0) == HIGH && digitalRead(2) == HIGH) {
      digitalWrite(3, 0);
      delay(5000);
   }
   else
   {
    digitalWrite(3, 1);
   }  
   delay(10);
}
