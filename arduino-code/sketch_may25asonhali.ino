int esikDegeri = 150;               // Gaz eşik değerini belirliyoruz.
int buzzerPin = 9;                  // Buzzer'ın takılacağı pin
int fanPin = 11;                    // Fan'ın takılacağı pin
int deger;                          // Sensörden okunan değer

void setup() {
  pinMode(buzzerPin, OUTPUT);       // Buzzer pinimizi çıkış olarak ayarlıyoruz.
  pinMode(fanPin, OUTPUT);          // Fan pinimizi çıkış olarak ayarlıyoruz.
}

void loop() {
  deger = analogRead(A0);           // Sensörden analog değer okuyoruz.
  
  if(deger > esikDegeri){           // Değer eşik değerden büyükse:
    digitalWrite(buzzerPin, HIGH);  // Buzzer çalışır
    digitalWrite(fanPin, HIGH);     // Fan çalışır
    delay(75);
    digitalWrite(buzzerPin, LOW);   // Buzzer kapanır
    delay(75);
  }
  else{                             // Değer eşik değerin altındaysa:
    digitalWrite(buzzerPin, LOW);   // Buzzer kapalı kalır
    digitalWrite(fanPin, LOW);      // Fan kapalı kalır
  }
}
