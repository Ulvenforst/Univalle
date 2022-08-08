# La Barca.

## Objetivo:
Implementar un juego de lógica usando C++ con metodología de programación orientada a objetos.

El juego consiste en lo siguiente: hay un robot que debe transportar un zorro, un conejo y
una lechuga desde un lado del río hasta la otra orilla, usando una barca. En la barca solo
cabe uno de los tres individuos, además del robot. El problema es que si el robot deja
solos al zorro y el conejo, el zorro se comerá el conejo. Y si deja solos al conejo y la
lechuga, el conejo se comerá la lechuga. El jugador debe controlar que órdenes dar, para
lograr que el robot transporte los tres individuos a la otra orilla, sanos y salvos.
<br>
A continuación puede observar el menú principal del juego:<br>
![image](https://user-images.githubusercontent.com/66099723/183514978-a4c71f2a-c083-45e2-bbb4-9246be4a5665.png)
<br>
El juego está diseñado de manera que incluir un personaje nuevo sea sumamente fácil, por defecto
la clase Lugar tiene un aforo de 6 personajes, en el caso de querer añadir más de 6 modifique esta
opción en aforo por defecto de Lugar.cpp, lo mismo aplica para la barca que es un Lugar.
<br>
El siguiente fragmento de código muestra el arreglo de personajes principales, y es ahí donde 
podemos añadir nuevos personajes, como se ve en los comentarios:<br>
![image](https://user-images.githubusercontent.com/66099723/183515598-2a069daa-70fb-4c10-b358-86326e2423db.png)
<br>
Una vez añadidos los personajes puede colocarlos en un lugar y asignar las reglas del juego: <br>
![image](https://user-images.githubusercontent.com/66099723/183515773-85cf803f-f5e2-4b60-8a0c-c5a1c8f041b2.png)
<br>
Todo esto en el main.cpp
<br><br>
Los posibles estados de juego son:
