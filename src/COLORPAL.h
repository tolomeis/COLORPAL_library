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
    void readRGB(int &red, int &green, int &blue);
    int readR(void);
    int readG(void);
    int readB(void);
  private:
    int _spin; //piedino di collegamento seriale
    const int sioBaud; // = 4800;
    const int waitDelay; // = 200;
    SoftwareSerial serin;
	SoftwareSerial serout;

};


#endif
