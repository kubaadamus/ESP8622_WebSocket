int CS_PIN = 53;
File file;
String sd_read(){
  initializeSD();
  SD.open("wifi.txt");
  String wifi_coordinates = readLine();
  closeFile();
  return wifi_coordinates;
}

void initializeSD()
{
  //Serial.println("Initializing SD card...");
  pinMode(CS_PIN, OUTPUT);

  if (SD.begin())
  {
    //Serial.println("SD card is ready to use.");
  } else
  {
    //Serial.println("SD card initialization failed");
    return;
  }
}

int createFile(char filename[])
{
  file = SD.open(filename, FILE_WRITE);

  if (file)
  {
    //Serial.println("File created successfully.");
    return 1;
  } else
  {
    //Serial.println("Error while creating file.");
    return 0;
  }
}

int writeToFile(char text[])
{
  if (file)
  {
    file.println(text);
    //Serial.println("Writing to file: ");
    //Serial.println(text);
    return 1;
  } else
  {
    //Serial.println("Couldn't write to file");
    return 0;
  }
}

void closeFile()
{
  if (file)
  {
    file.close();
    //Serial.println("File closed");
  }
}


String readLine()
{
  String received = "";
  char ch;
  while (file.available())
  {
    ch = file.read();
    if (ch == '\n')
    {
      return String(received);
    }
    else
    {
      received += ch;
    }
  }
  return "";
}
