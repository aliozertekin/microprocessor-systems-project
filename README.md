
# Zehirli Soba Gazı Tespiti ve Tahliye Sistemi

Bu proje, ortamda tehlikeli seviyeye ulaşan gazı algılayarak kullanıcıyı sesli (buzzer) ve fiziksel (fan) olarak uyaran bir sistemdir. Sistem, Arduino Uno ve gaz sensörü kullanılarak geliştirilmiştir. Gaz seviyesi eşik değeri aştığında buzzer uyarısı verir ve fan otomatik olarak çalışarak ortamı havalandırır.

 Proje, “Mikroişlemcili Sistemler ve Laboratuvarları” dersi kapsamında gerçekleştirilmiştir.
##  Proje Amacı

Gaz kaçağı riski olan kapalı alanlarda zehirli gaz tespiti yaparak:

- Kullanıcıyı sesli olarak uyarmak
    
- Ortamı otomatik olarak havalandırmak
    

Proje, basit ve düşük maliyetli donanım bileşenleriyle güvenli bir sistem sunmayı amaçlamaktadır.

##  Kullanılan Malzemeler

|Bileşen|Açıklama|
|---|---|
|Arduino Uno|Mikrodenetleyici kart|
|MQ-x Gaz Sensörü|Ortamdaki gazı algılar (örneğin MQ-2, MQ-7)|
|5V DC Fan|Ortamı havalandırmak için kullanılır|
|Aktif Buzzer|Gaz tespiti durumunda sesli uyarı verir|
|TIP120 Transistör|Fanı Arduino üzerinden güvenli şekilde kontrol etmek için|
|1N4007 Diyot|Fan kapatıldığında oluşabilecek geri akımı önlemek için|
|220 Ohm Direnç|Transistör base ucundaki akımı sınırlamak için|
|Jumper Kablolar|Bağlantılar için|
|Breadboard|Lehim gerektirmeden devre kurmak için|

##  Sistem Mantığı

- Gaz sensörü ortamdan sürekli analog veri okur.
    
- Okunan değer eşik değerden büyükse:
    
    - Buzzer aktif olur (sesli uyarı verir).
        
    - Fan devreye girer (havalandırma başlar).
        
- Gaz seviyesi normale döndüğünde sistem otomatik olarak kapanır.
    

## Arduino Kodu

Aşağıda sistemin temel çalışma mantığını içeren örnek Arduino kodu yer almaktadır:

```C

int esikDegeri = 150;
int buzzerPin = 9;
int fanPin = 11;
int deger;
void setup() 
{
    pinMode(buzzerPin, OUTPUT);
    pinMode(fanPin, OUTPUT);
    }  
    void loop() {
        deger = analogRead(A0);
        if(deger > esikDegeri){     
            digitalWrite(buzzerPin, HIGH);
            digitalWrite(fanPin, HIGH);
            delay(15);
            digitalWrite(buzzerPin, LOW);
            delay(15);  
       }
        else {     
            digitalWrite(buzzerPin, LOW);
            digitalWrite(fanPin, LOW);   
    } 
}

```

## Lisans

Bu proje eğitim amacıyla yapılmıştır. Her türlü kullanım serbesttir.
