# InstalElectric

**Requisitos**

1. visual studio

2. extencion de platformIO

3. librerias a añadir en platformIO
   
   1. DHT sensor library

***Reparto de carpetas***

<img title="" src="file:///C:/Users/angel/AppData/Roaming/marktext/images/2023-03-31-02-33-30-image.png" alt="" data-align="left">src y src2 son las carpetas que contienen el codigo fuente que tendran los arduinos, src supone el esclavo y src2 el maestro

![](C:\Users\angel\AppData\Roaming\marktext\images\2023-03-31-02-34-49-image.png)

En .pio se almacenan automaticamente las librerias de terceros que utiliza el proyecto, en este caso hasta el momento solo se a utilizado DHT `#include <DHT.h>` como libreria de terceros, de ahi en fuera todo esta en `#include <Arduino.h>`
