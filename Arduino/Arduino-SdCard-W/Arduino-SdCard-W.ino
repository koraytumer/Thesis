#include <SPI.h>               //Synchronous serial communication library that Ardiuno supports
#include <SD.h>                              //Required for SD card module
const int chipSelect = 4;       //Checking the SD card module
const int gunes = A0;      //Identifying analog input terminals of modules
const int isi = A1;
const int motor = A2;
void setup()
{
  Serial.begin(9600);
  Serial.print("Waiting for SD CARD...");
  if (!SD.begin(chipSelect))   //SD card definitions are made here.
  {
    Serial.println("SD Card not showing up or working");
    return;
  }
  Serial.println("SD card is recognized...");
  
}
void loop()
{
  String dataString1 = "";          //Analog values are read and they are written to variables.
  String dataString2 = "";               
  String dataString3 = "";               
  int sensor1 = analogRead(gunes);
  int sensor2 = analogRead(isi);
  int sensor3 = analogRead(motor);
  dataString1 += String(sensor1);
  dataString2 += String(sensor2);
  dataString3 += String(sensor3);
  delay(1000);                    // Wait 1 second
 
  File dataFile = SD.open("tezim.txt", FILE_WRITE); //Creating file called “tezim.txt” in SD card

  if (dataFile) 
  {
    dataFile.println(dataString1);     //Writing the value from dataString variable to the file
    dataFile.println(dataString2);
    dataFile.println(dataString3);
    dataFile.close();
    Serial.println(dataString1);       //Sending the value from dataString variable to the serial   monitor                                                                                                              
    Serial.println(dataString2);
    Serial.println(dataString3);
  }
  else 
  {
    Serial.println("dosya acma hatasi datalog.txt");    //If file cannot be found, error will be written.
  }
}
