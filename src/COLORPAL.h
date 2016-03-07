/*COLORPAL library, per interfacciamento al parallax COLORPAL
 * Distribuita da Simone Tolomei
 */

#ifndef COLORPAl_h
#define COLORPAL_h

#include "Arduino.h"
#include <SoftwareSerial.h>

class Colorpal{
  public:
    Colorpal(int spin = 2);
    void init(void);
    int readRGB(int &red, int &green, int &blue);
  private:
    int _spin;
    const int sioBaud; // = 4800;
    const int waitDelay; // = 200;
    SoftwareSerial serin;
	  SoftwareSerial serout;
    int errore;
    int testLettura(int &red, int &green, int &blue);
};


#endif