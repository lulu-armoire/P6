#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

#define SPI_SCK    13 
#define SPI_MISO   12  
#define SPI_MOSI   11  
#define SPI_CS     10

SPIClass mySPI(HSPI);  
File myFile; 

void setup() 
{ 
  Serial.begin(9600); 
  Serial.print("Iniciando SD ..."); 
  
  mySPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI, SPI_CS);

  if (!SD.begin(SPI_CS,mySPI)) {  // Usamos SPI_CS para CS
    Serial.println("No se pudo inicializar la tarjeta SD");
    return; 
  }

  Serial.println("Inicialización exitosa"); 
    
  myFile = SD.open("archivo.txt");
  if (myFile) { 
    Serial.println("archivo.txt:"); 
    while (myFile.available()) { 
      Serial.write(myFile.read()); 
    } 
    myFile.close(); // Cerramos el archivo 
  } else { 
    Serial.println("Error al abrir el archivo"); 
  } 
} 

void loop() 
{ 
  // Aquí puedes agregar código que necesites ejecutar en el bucle.
}
