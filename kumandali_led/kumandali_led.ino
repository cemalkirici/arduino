#include <IRremote.h>

int RECV_PIN = 11;
int led = 8;
int role = 3;

IRrecv irrecv(RECV_PIN);
decode_results results;

int parlaklik = 255;

#define yukari  0xFF18E7
#define asagi  0xFF30CF

void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(role,OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) 
  {
    if(results.value == yukari){
    parlaklik = parlaklik + 25;
    digitalWrite(role,HIGH);
    }

    if(results.value == asagi){
    parlaklik = parlaklik - 25;
    digitalWrite(role,LOW);
    }
    
    if(parlaklik >= 255)
    parlaklik = 255;

    if(parlaklik <= 0)
    parlaklik = 0;
    
    Serial.println(parlaklik);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
