# COLORPAL_library
Libreria NON UFFICIALE per il sensore di colore COLORPAL, costruito dalla PARALLAX

Attualmente è possibile solo la lettura del colore, che si può effettuare in due modi:
Con un'unica funzione che scrive le tre componenti Rosso Verde e Blu
``` 
leggiRGB(int& rosso, int& verde, int& blu);
```
Al termine della funzione, i 3 parametri conterranno le componenti RGB rilevate.
O alternativamente con 3 funzioni separate, ognuna che ritorna il valore della componente scelta:
``` 
int rosso = readR();
int verde = readG();
int blu = readB();
```
Per l'inizializzazione del sensore, è sufficiente specificare il pin nella definizione
``` 
Colorpal colorp(pin);
```
E chiamare la funzione di inizializzazione
``` 
colorp.init();
```

Simone Tolomei
