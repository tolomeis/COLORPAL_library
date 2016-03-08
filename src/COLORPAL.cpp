/*COLORPAL library, per interfacciamento al parallax COLORPAL
 * Distribuita da Simone Tolomei
*/

#include "Arduino.h"
#include "COLORPAL.h"

Colorpal::Colorpal(int spin):sioBaud(4800),waitDelay(200), serin(spin,255), serout(255,spin){
  _spin = spin;
}

void Colorpal::init(){
  //funzione di reset
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
  // Send reset to ColorPal
  serout.begin(sioBaud);
  pinMode(_spin, OUTPUT);
  serout.print("= (00 $ m) !"); // Loop print values, see ColorPAL documentation
  serout.end();              // Discontinue serial port for transmitting

  serin.begin(sioBaud);            // Set up serial port for receiving
  pinMode(_spin, INPUT);
}

int Colorpal::readRGB(int &red, int &green, int &blue){
	int i;
  do{
    i = testLettura(red,green,blue);
  }while(i);
}

int Colorpal::testLettura(int &red, int &green, int &blue){
  char buffer[32];
  if (serin.available() > 0) { //se dati disponibili allora esegui
    // Wait for a $ character, then read three 3 digit hex numbers
    buffer[0] = serin.read();
    if (buffer[0] == '$') {
      for(int i = 0; i < 9; i++) {
        while (serin.available() == 0);     // Wait for next input character
        buffer[i] = serin.read();
        if (buffer[i] == '$')               // Return early if $ character encountered
          return 0;
      }
      sscanf (buffer, "%3x%3x%3x", &red, &green, &blue);
      return 1;
    }
  }

}