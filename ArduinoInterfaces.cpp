#include <LiquidCrystal_I2C.h> //Libreria para el LCD

#include <SPI.h> //Librerias para la SD

#include <SD.h>

#include <TMRpcm.h> //Libreria para el altavoz

LiquidCrystal_I2C lcd(0x27, 16, 2); //Inicializamos el LCD
TMRpcm Sonido; //Creamos un objeto de tipo TMRpcm para utilizar la libreria
#
define pinSD 10 //Pin en el que conectamos la entrada CS al arduino
const int s0 = 6;
const int s1 = 5;
const int s2 = 4; //Inicializamos las conexiones del sensor de colores
const int s3 = 3;
const int out = 2;
int rojo = 0;
int verde = 0; //Creamos variables que luegos nos serviran para almacenar los valores reconocidos por el sensor
int azul = 0;
void setup() {
   Serial.begin(9600);
   if (SD.begin(pinSD)) { //Comprobamos si la SD se ha leido correctamente
      Serial.print(“Ha funcionado correctamente”);
   } else {
      Serial.print(“Tarjeta no ha funcionado”);
   }
   Sonido.speakerPin = 9; //Entrada en la que debemos conectar el altavoz
   Sonido.setVolume(5); //Ponemos el volumen al que debe sonar el altavoz
   Sonido.quality(1); // Calidad de sonido del altavoz, puede ser 0 o 1
   pinMode(s0, OUTPUT);
   pinMode(s1, OUTPUT);
   pinMode(s2, OUTPUT);
   pinMode(s3, OUTPUT);
   pinMode(out, INPUT);
   digitalWrite(s0, HIGH);
   digitalWrite(s1, HIGH);
   lcd.init();
   lcd.backlight();
   lcd.clear();
   lcd.setCursor(0, 0); //Inicializamos la pantalla y ponemos el texto inicial ” Forcelduino Grupo 7 “
   lcd.print(“Forcelduino”);
   lcd.setCursor(0, 1);
   lcd.print(“Grupo 7”);
   //delay(800);
}
void loop() {
   color(); //Metodo que sirve para obtener los valores de los colores
   Serial.print(“Rojo = ”);
   Serial.print(rojo, DEC);
   Serial.print(“Verde = “);
   Serial.print(verde, DEC); //Escribir por consola los valores registrados
   Serial.print(“Azul = “);
   Serial.print(azul, DEC);
   Serial.print(“t”);
   //Dependiendo del valor leido por el sensor nos meteremos en un if u otro para que haga una cosa u otra
   if ((rojo > 5 && rojo < 10) && (azul > 17 && azul < 20) && (verde > 18 && verde < 24)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(“El color es: ”);
      lcd.setCursor(0, 1); //En el caso del color rojo, nos sacara por el LCD “El color es: Color rojo”
      lcd.print(“Rojo”); //Escribira rojo por consola
      Serial.println(”–(Color rojo)”);
      Sonido.play(“rojo.wav”); //Reproducira el audio guardado en la SD que se llama “rojo.wav”
   }
   if ((rojo > 2 && rojo < 7) && (azul > 8 && azul < 13) && (verde > 4 && verde < 9)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(“El color es: ”);
      lcd.setCursor(0, 1);
      lcd.print(“Amarillo”);
      Serial.println(”–(Color amarillo)”);
      Sonido.play(“amarillo.wav”);
   }
   if ((rojo > 10 && rojo < 16) && (azul > 3 && azul < 8) && (verde > 5 && verde < 9)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(“El color es: ”);
      lcd.setCursor(0, 1);
      lcd.print(“Azul”);
      Serial.println(”–(Color azul)”);
      Sonido.play(“azul.wav”);
   }
   if ((rojo > 19 && rojo < 27) && (azul > 15 && azul < 23) && (verde > 12 && verde < 19)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(“El color es: ”);
      lcd.setCursor(0, 1);
      lcd.print(“Verde”);
      Serial.println(”–(Color verde)”);
      Sonido.play(“verde.wav”);
   }
   if ((rojo > 5 && rojo < 9) && (azul > 7 && azul < 12) && (verde > 12 && verde < 17)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(“El color es: ”);
      lcd.setCursor(0, 1);
      lcd.print(“Rosa”);
      Serial.println(”–(Color rosita)”);
      Sonido.play(“rosa.wav”);
   }
   if ((rojo > 28 && rojo < 34) && (azul > 27 && azul < 33) && (verde > 33 && verde < 38)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(“El color es: ”);
      lcd.setCursor(0, 1);
      lcd.print(“Negro”);
      Serial.println(”–(Color negro)”);
      Sonido.play(“negro.wav”);
   }
   if ((rojo > 25 && rojo < 30) && (azul > 9 && azul < 14) && (verde > 22 && verde < 27)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(“El color es: ”);
      lcd.setCursor(0, 1);
      lcd.print(“Azul marino”);
      Serial.println(”–(Color azul marino)”);
      Sonido.play(“azul_marino.wav”);
   }
   if ((rojo > 2 && rojo < 7) && (azul > 1 && azul < 6) && (verde > 2 && verde < 7)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(“El color es: ”);
      lcd.setCursor(0, 1);
      lcd.print(“Blanco”);
      Serial.println(”–(Color blanco)”);
      Sonido.play(“blaco.wav”);
   }
   if ((rojo > 2 && rojo < 7) && (azul > 12 && azul < 17) && (verde > 10 && verde < 15)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(“El color es: ”);
      lcd.setCursor(0, 1);
      lcd.print(“Naranja”);
      Serial.println(”–(Color naranja)”);
      Sonido.play(“naranja.wav”);
   }
   Serial.println();
   delay(5000);
}
void color() //Lee y registra un valor entre 0 y 30 y dependiendo de una configuracion u otra te dar aun color u otro
{
   digitalWrite(s2, LOW);
   digitalWrite(s3, LOW);
   rojo = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
   digitalWrite(s3, HIGH);
   azul = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
   digitalWrite(s2, HIGH);
   verde = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
   Serial.print(rojo);
   Serial.print(azul); //Nos imprime los valores recibidos por consola
   Serial.print(verde);
}