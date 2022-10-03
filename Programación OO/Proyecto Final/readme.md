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
<br>
<div style="text-align=center"> 
d
</div>

![image](https://user-images.githubusercontent.com/66099723/183516188-3a25ed70-d9ca-4c40-9a22-d26689e99397.png)
<br>
![image](https://user-images.githubusercontent.com/66099723/183516295-2580cedd-7532-43e4-978e-f3f55ae90f75.png)
<br>
![image](https://user-images.githubusercontent.com/66099723/183516390-f5e9e8dc-7a9d-4fdd-8079-ae3d1252fe78.png)
<br>
![image](https://user-images.githubusercontent.com/66099723/183516581-b8953f9a-0946-46a8-98c7-573e6650b801.png)
<br><br>
El programa es capaz de adaptarse a la cantidad de personajes que se desee con las reglas indicadas.
<br>
Tenga en la cuenta, que aunque los destructores fueron implementados, estos no fueron revisados con Valgrind,
por lo que puede que hayan memery leaks.
