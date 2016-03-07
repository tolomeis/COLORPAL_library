/************************************************
 * SKETCH DI ESEMPIO DELLA LIBRERIA COLORPAL
 * DISTRIBUITA SOTTO CC-BY-SA DA SIMONE TOLOMEI
 ************************************************/
#include <COLORPAL.h>
//**** CREO LE 3 VARIABILI IN CUI MEMORIZZARE LE COMPONENTI RGB
int rosso;
int blu;
int verde;

//******* CREO LA COLORPAL CON IL PIN sig COLLEGATO AL PIN 2 ****
Colorpal colorp(2);

void setup() {
  //************
  //**INIZIALIZZO LA COLORPAL*****
  colorp.init();
  Serial.begin(9600);
}

void loop() {
  /******** CHIAMO LA FUNZIONE readRGB
   *  la funzione deve avere come 3 argomenti le 3 variabili (int)
   *  su cui memorizzare le componeni, gli argomento sono nell'ordine: rosso, verde, blu
   *  alla fine della funzione questi 3 interi conterranno i rispettivi valori, dei colori.
   */
  colorp.readRGB(rosso, verde, blu);
  //stampo le 3 componenti
  Serial.print("R:");
  Serial.print(rosso);
  Serial.print("  B:");
  Serial.print(blu);
  Serial.print("  G:");
  Serial.println(verde);
  delay(100);
}
