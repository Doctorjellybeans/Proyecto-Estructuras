![277210360-421cc7c9-bd59-4d76-bce8-baab96296b87](https://github.com/Doctorjellybeans/Proyecto-Estructuras/assets/142541831/31d90350-8b85-43e7-ad12-5102e25a7e43)



# TDA-OH!
![tdaoh_logo](https://github.com/Doctorjellybeans/Proyecto-Estructuras/assets/142177428/de86cb8f-448d-451b-bcf3-958360765f95)

## Descripción

TDA-Oh! es un juego de cartas educativo que fusiona la emoción de los duelos con la oportunidad de aprender sobre estructuras de datos y Tipos de Datos Abstractos (TDAs). Destaca por su enfoque único en la gestión de barras de vida utilizando TDAs como listas, colas y pilas. Los jugadores eligen estratégicamente acciones basadas en operaciones de TDAs asociadas a cartas, que además de tener puntajes, proporcionan descripciones educativas.

## Instrucciones de compilacion

 1- Abre una terminal y ejecute el comando:

  ```mkdir build && cd build && cmake -G "MinGW Makefiles"```

 2- Compila el proyecto.

  ```mingw32-make```

Una vez ejecutado, se desplegara un menu con 3 botones distintos "Jugar", "Como jugar?" y "Salir". Si presionamos el boton "Jugar", se cerrara la ventana principal y ,a la vez, se desplegaran 2 ventanas nuevas siendo cada una de ellas un jugador. Si se presiona el boton "Como jugar?", sobre la ventana principal se proyectara un menu que no se logro concretar. Si presionamos el boton salir se abandonara la aplicacion.

## Intrucciones de movimiento
Teclas del Jugador 1:
 para deslazarnos entre las cartas que representan la mano del jugador:
  - Q: izquerda
  - W: derecha
    
Teclas del Jugador 2:
 para deslazarnos entre las cartas que representan la mano del jugador:
  - O: izquerda
  - P: derecha
 


## Contribución
 - Matias Nuñez    : Contribuye tanto en el desarrollo e implementacion de cada TDA / Estructura de datos como en las funciones de interfaz principales del juego
 - Vicente Rosales : Contribuye tanto en el desarrollo e implementacion de cada TDA / Estructura de datos como en las funciones principales del juego.
 - Alex Alfaro     : Contribuye en el diseño de Imagenes que se visualizan dentro del juego


## Estado del Proyecto

A pesar de que cada funcion principal se ejecuta correctamente por separado muchas de las funciones que teniamos planeadas para desarrollar una interfaz grafica mediante librerias externas como SDL no dieron a la luz, , entre estas estan:
 1- No se puede visualizar el jugar una carta.
 2- No se logro implementar un sistema turnos, por lo que los jugadores pueden desplzarse a la vez.
 3- No se puede visualizar detalles de la barra de vida (puntos de vida actual / TDA).
 4- No se pueden visualizar las operaciones de cada carta.

En conclusion se subestimo el tiempo en el aprendizaje de C++ (OOP) y SDL.  

## Autores
Matias Nuñez
Vicente Rosales
Alex Alfaro

## Autoevaluacion en terminos de codigo
A continuacion los niveles de contribucion de cada integrante (0 - 10):
 - Matias Nuñez    : 10
 - Vicente Rosales : 6.5
 - Alex Alfaro     : 1
