#include <SD.h>
#include <SPI.h> 
File dosya;
int i = 0;
char x = 0;
void setup()
{
  Serial.begin(9600);
   while (!Serial) {       //wait for serial input
    ; 
  }
  pinMode(10, INPUT);
  if (!SD.begin(4)) {       //SD kartı görüyormu sorgula
    Serial.println("SD CARD - Error!");
    return;
  }
  File dosya = SD.open("tezim.txt",FILE_READ);  //get data from tezim.txt
  if(dosya) 
  {
   while(i<dosya.size())
   {
     x=dosya.read(); //dosyayı oku ve x'e at
     Serial.print(x); //Read the data and see on the serial monitor 
     delay(50);
     i++;
   }
  }
  else 
  {
    Serial.print("Fail to open file...");
  }  
}
void loop()
{
}
