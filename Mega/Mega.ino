#include <SD.h>
#include <SPI.h>
#include <Servo.h>
String InputFromESP=""; //Dane ESP -> MEGA
String InputFromCOM=""; //Dane Serial -> MEGA
//DEKLARACJE SERWOMECHANIZMÓW//
Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo s5;
//------//



void setup() {
Serial1.begin(115200); //Serial pomiędzy ESP - MEGA
Serial.begin(115200); //Serial pomiędzy PC - MEGA
pinMode(LED_BUILTIN,OUTPUT); //dioda wbudowana - debug
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);

//SETUP SERWOMECHANIZMÓW//
s1.attach(2);
s2.attach(3);
s3.attach(4);
s4.attach(5);
s5.attach(6);
//---------------------//
delay(1000);

}

void loop() {


//============= M E G A  C Z Y T A  Z  E S P =======================//

while(Serial1.available() > 0)  //Jeśli zauwazysz czekający pakiet danych przychodzących od ESP
{
    int inChar = Serial1.read();    //Zdejmuj z tego pakietu po jednym bajcie
    InputFromESP += (char)inChar;   //Zmień ten bajt na chara i dodaj go do zmiennej
    if (inChar == '|')              //Gdy napotkasz bajt kończący przekaz
    {
    InputFromESP = Przytnij(InputFromESP);  //Obetnij bajt kończący bo zawadza
    Serial.print("MEGA odbiera z ESP:");        //Pokaż mi na serialu co odebrałes
    Serial.println(InputFromESP);           
    //======== METODY OBSŁUGUJĄCE INPUT Z ESP=====// //Obsłuż dane przychodzące z ESP

    obsluga_zdarzenESP(InputFromESP);
    
    //===========================================//
    InputFromESP="";
    }
}

////////////////////////////////////////////////////////////////////



//========= M E G A  C Z Y T A  Z  P C===========================//

while(Serial.available() > 0)
{
    int inChar = Serial.read();
    InputFromCOM += (char)inChar;
    if (inChar == '\n') 
    {
    Serial.print("MEGA odbiera z COM:");
    InputFromCOM = Przytnij(InputFromCOM);  //Obetnij bajt kończący bo zawadza
    Serial.println(InputFromCOM);
    //======== METODY OBSŁUGUJĄCE INPUT Z PC=====//
      obsluga_zdarzenCOM(InputFromCOM);
      Print(InputFromCOM);
    //============================================//
    InputFromCOM="";
    }
}

////////////////////////////////////////////////////////////////////



}
