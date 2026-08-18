// --- Monitor GSR (Respuesta Galvánica de la Piel) ---
const int gsrPin = A0;
const int numMuestras = 10;      // suavizado
unsigned long tBaseline = 0;
float baseline = 0;

void setup() {
  Serial.begin(9600);
  // Calibración inicial: promedia 3 segundos en reposo
  long suma = 0;
  for (int i = 0; i < 100; i++) {
    suma += analogRead(gsrPin);
    delay(30);
  }
  baseline = suma / 100.0;
}

void loop() {
  long suma = 0;
  for (int i = 0; i < numMuestras; i++) {
    suma += analogRead(gsrPin);
    delay(5);
  }
  float lectura = suma / (float)numMuestras;
  float voltaje = lectura * (5.0 / 1023.0);

  // Nivel de estrés relativo al baseline (ajustar umbrales tras la Parte B.2)
  float delta = lectura - baseline;
  String nivel;
  if (delta < 15) nivel = "BAJO";
  else if (delta < 40) nivel = "MODERADO";
  else nivel = "ALTO";

  // Enviamos CSV: tiempo_ms, lectura_cruda, voltaje, nivel
  Serial.print(millis());
  Serial.print(",");
  Serial.print(lectura);
  Serial.print(",");
  Serial.print(voltaje, 3);
  Serial.print(",");
  Serial.println(nivel);

  delay(100); // ~10 Hz, suficiente para EDA (que es lenta, <1 Hz de contenido útil)
}
