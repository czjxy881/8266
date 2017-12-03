#include <IRremoteESP8266.h>

#include <IRsend.h>
#include <IRrecv.h>
#include <IRutils.h>




uint16_t stopAir[]={0x235A,0x1130,0x1C2,0x6D6,0x1C2,0x6D6,0x1F4,0x28A,0x1C2,0x2BC,0x1C2,0x2BC,0x190,0x2BC,0x1C2,0x2BC,0x15E,0x73A,0x190,0x73A,0x15E,0x2EE,0x190,0x2EE,0x15E,0x2EE,0x190,0x320,0x12C,0x76C,0x12C,0x320,0x15E,0x320,0x15E,0x2EE,0x15E,0x320,0x15E,0x2EE,0x15E,0x320,0x15E,0x320,0x15E,0x2EE,0x15E,0x320,0x15E,0x2EE,0x190,0x73A,0x15E,0x320,0x15E,0x73A,0x15E,0x76C,0x15E,0x76C,0x15E,0x2EE,0x15E,0x320,0x12C,0x320,0x190,0x2EE,0x12C,0x76C,0x15E,0x73A,0x15E,0x320,0x15E,0x76C,0x15E,0x73A,0x15E,0x320,0x15E,0x2EE,0x190,0x2EE,0x15E,0x320,0x15E,0x73A,0x15E,0x76C,0x15E,0x320,0x12C,0x320,0x15E,0x2EE,0x15E,0x320,0x15E,0x320,0x15E,0x320,0x12C,0x320,0x15E,0x320,0x15E,0x320,0x12C,0x320,0x15E,0x320,0x12C,0x320,0x15E,0x320,0x15E,0x2EE,0x15E,0x320,0x15E,0x2EE,0x190,0x2EE,0x15E,0x320,0x15E,0x2EE,0x15E,0x320,0x15E,0x320,0x15E,0x2EE,0x15E,0x73A,0x15E,0x76C,0x190,0x2EE,0x15E,0x320,0x12C,0x320,0x15E,0x320,0x15E};
uint16_t startWith24Heat[]={0x22C4,0x11F8,0x12C,0x76C,0x15E,0x73A,0x15E,0x320,0x12C,0x76C,0x15E,0x320,0x15E,0x2EE,0x15E,0x320,0x12C,0x76C,0x15E,0x76C,0x12C,0x320,0x15E,0x320,0x12C,0x320,0x15E,0x320,0x12C,0x76C,0x15E,0x2EE,0x15E,0x320,0x15E,0x320,0x15E,0x2EE,0x15E,0x320,0x15E,0x2EE,0x190,0x2EE,0x15E,0x320,0x15E,0x2EE,0x15E,0x320,0x15E,0x320,0x15E,0x2EE,0x15E,0x320,0x15E,0x2EE,0x190,0x2EE,0x15E,0x73A,0x15E,0x320,0x15E,0x2EE,0x190,0x2EE,0x12C,0x76C,0x15E,0x76C,0x12C,0x320,0x15E,0x76C,0x15E,0x73A,0x15E,0x320,0x15E,0x2EE,0x190,0x2EE,0x15E,0x320,0x15E,0x73A,0x15E,0x76C,0x15E,0x320,0x15E,0x2EE,0x15E,0x2EE,0x15E,0x320,0x15E,0x320,0x15E,0x2EE,0x15E,0x320,0x15E,0x2EE,0x190,0x2EE,0x15E,0x320,0x15E,0x2EE,0x15E,0x320,0x15E,0x320,0x15E,0x2EE,0x15E,0x320,0x15E,0x2EE,0x190,0x2EE,0x15E,0x320,0x15E,0x2EE,0x15E,0x2EE,0x190,0x320,0x15E,0x2EE,0x15E,0x73A,0x15E,0x73A,0x1C2,0x2EE,0x15E,0x2EE,0x190,0x2EE,0x15E,0x2EE,0x190};


IRsend irsend(4);
void setup() {
  // put your setup code here, to run once:
  irsend.begin();
  Serial.begin(115200,SERIAL_8N1);

}

void sendCode(uint16_t rawCodes[]){

  irsend.sendRaw(rawCodes, 147, 38);
  Serial.println("Sent!");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    if(Serial.read()=='1'){
      sendCode(startWith24Heat);
      Serial.println("start!");
    }else{
      sendCode(stopAir);
      Serial.println("stop!");
      }
      
  }
}
