void obsluga_zdarzenESP(String InputFromESP)
{
//===== L E D  B U I L T I N =======//
//digitalWrite(LED_BUILTIN,InputFromESP.substring(5,6).toInt());
//===== S E R V O =======//
  //s1.write(InputFromESP.substring(0,1).toInt()*20);
  //s2.write(InputFromESP.substring(1,2).toInt()*20);
  //s3.write(InputFromESP.substring(2,3).toInt()*20);
  //s4.write(InputFromESP.substring(3,4).toInt()*20);
  //s5.write(InputFromESP.substring(4,5).toInt()*20);
  s1.write(InputFromESP.toInt());
  Serial.print("Ustawiam serwo na: ");
  Serial.println(InputFromESP.toInt());
}
void obsluga_zdarzenCOM(String InputFromCOM){
if(InputFromCOM=="test"){
  Serial.print("MEGA mówi:");
  Serial.println("DZIAŁA!");
  Print("pisz");
}
}
