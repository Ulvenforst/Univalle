Votación alcaldía versión 1.
Grupo:
Juan Camilo Narváez Tascón. 2140112-3743
Carol Sofía Macarena Rubiano Valderrama. 2181025-3743
Natan Gabriel Medina Corea. 2178208-3743

1. Para usar el programa solo debe de ejecutarlo y seguir las instrucciones que le indica. 
(Para visualizar demo mire https://www.youtube.com/watch?v=RACDoRak-M0)

Nota: (https://youtu.be/EFqNT1tvcFY) Se ha dejado las impresiones de terminal con el objetivo de comprobar la información suministrada y el 
comportamiento de la aplicación. Teniendo en cuenta la labor de revisión de la actividad. Esto se puede quitar
eliminando o comentando los print() respectivos:
Líneas:
57
58
73
84
85
89
92
95
100
103
106
296
380

Nota: Cada sesión del código está separada por un comentario.

**Fallos solucionados:**
Datos de entrada no deseados: Al momento de ingresar la cédula el votante podía ingresar cualquier cosa que deseara,
se solucionó creando un filtro a la hora de registrar los valores en la matriz referente.

Empate en candidato ganador: se observaba un comportamiento no deseado cuando habían dos candidatos diferentes votados,
se seleccionaba como ganador al primer candidato encontrado en la matriz. Solucionado por medio de la librería Counter
y una modificación en la función que compare los dos primeros valores más votados de la matriz.

Multiples elecciones a la hora de votar, o voto de tipo 'None': Se encontró un bug a la hora de ingresar a la sesión
donde se puede seleccionar el tarjetón preferente; en este se podría votar multiples veces antes de volver al inicio,
o ingresar a un tarjetón y no seleccionar nada. Se solucionó por medio de funciones condicionales que deshabilitaran 
los botones referentes a cada acción en el momento correcto.

Actualización de labels: Se podía observar un comportamiento desactualizado en las labels de error al momento de 
realizar acciones; se actualizó configurando sus valores en momentos oportunos.

**Cosas a implementar:**
1. Mejorar el aspecto visual:
	Incluir imagenes de los candidatos,
	Colores más llamativos.
	Mejorar estructura visual.


