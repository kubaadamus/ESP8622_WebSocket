void Print(String Input){
  Input += '|';
  Serial.print(Input);
}
void Print(int Input){
  String InputString = String(Input);
  InputString += '|';
  Serial.print(InputString);
}

String Przytnij(String Input){
Input.remove(Input.length()-1);
Input.trim();
return Input;
}

