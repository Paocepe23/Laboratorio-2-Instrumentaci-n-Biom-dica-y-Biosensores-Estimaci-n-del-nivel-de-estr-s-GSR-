#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
const int gsrPin = 4; // Pin de lectura analógica del sensor GSR (D4)

void setup() {
  // Comunicación Serie por cable (USB) para depurar si fuera necesario
  Serial.begin(115200);
  
  // Nombre Bluetooth visible en Windows
  SerialBT.begin("ESP32_GSR_BT"); 
  
  // Resolución de 12 bits para el ADC (valores de 0 a 4095)
  analogReadResolution(12);
  
  Serial.println("ESP32 Lista. Transmitiendo por Bluetooth...");
}

void loop() {
  int lectura = analogRead(gsrPin);
  
  // Envía la lectura por Bluetooth hacia MATLAB
  SerialBT.println(lectura);
  
  // Muestreo a 20 Hz (cada 50 milisegundos)
  delay(50); 
}
