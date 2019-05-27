/*COLORPAL library, per interfacciamento al parallax COLORPAL
 * Distribuita da Simone Tolomei
*/

#include "Arduino.h"
#include "COLORPAL.h"

Colorpal::Colorpal(int spin):sioBaud(4800),waitDelay(200), serin(spin,255), serout(255,spin){
  _spin = spin;
}

void Colorpal::init(){
  //funzione di reset (da datasheet)
    delay(200);
    pinMode(_spin, OUTPUT);
    digitalWrite(_spin, LOW);
    pinMode(_spin, INPUT);
    while (digitalRead(_spin) != HIGH);
    pinMode(_spin, OUTPUT);
    digitalWrite(_spin, LOW);
    delay(80);
    pinMode(_spin, INPUT);
    delay(waitDelay);
  // *****
  serout.begin(sioBaud);
  pinMode(_spin, OUTPUT);
  serout.print("= (00 $ m) !"); // imposta al colorpal la trasmissione sequenziale (da datasheet)
  serout.end();              // Disattiva trasmissione
  //serin.begin(sioBaud);      // Inizializza ricezione
  pinMode(_spin, INPUT);
}


void Colorpal::readRGB(int &red, int &green, int &blue){
    serin.begin(sioBaud);      // Inizializza ricezione
    char buffer[32];
    while(serin.available() == 0);
    // attendo carattere $, leggo 3 dati esadecimali (da datasheet)
    buffer[0] = serin.read();
    if (buffer[0] == '$') {
        int i;
        for(i = 0; i < 9; i++) {
            while (serin.available() == 0);     // attendo i prossimi dati e memorizzo nel buffer
            buffer[i] = serin.read();
            if (buffer[i] == '$') i=0;               //se trovo $ è errore e riparto.
        }
    sscanf (buffer, "%3x%3x%3x", &red, &green, &blue);  //estraggo le componenti in 3 interi, ritorno.
                              
    }
    serin.end();
}
    
    

int Colorpal::readR(){
    int red,green,blue;
    this->readRGB(red,green,blue);
    return red;
}

int Colorpal::readG(){
    int red,green,blue;
    this->readRGB(red,green,blue);
    return green;
}

int Colorpal::readB(){
    int red,green,blue;
    this->readRGB(red,green,blue);
    return blue;
}
