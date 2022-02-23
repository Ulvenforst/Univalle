# Juan Camilo Narváez Tascón 2140112-3743
tableroTriqui = [["", "", ""],["", "", ""],["", "", ""]]

for i in range(3):
  print("Ingrese los datos de la fila", i+1, "correspondientes a X / O:")
  for n in range(3):
    tableroTriqui[i][n] = input("Ingrese los datos de la columna "+ str(n+1)+": ")
    while(len(tableroTriqui[i][n]) != 1 or (tableroTriqui[i][n] != "X" and tableroTriqui[i][n] != "O")):
      print("Valor inválido, asegúrese de ingresar solo una X o una O y en mayúscula.")
      tableroTriqui[i][n] = input("Ingrese los datos de la columna "+ str(n+1)+": ")

def ganador(tableroTriqui):
  ganador = "Empate"

  for n in range(3):
    if(tableroTriqui[n][0]==tableroTriqui[n][1] and tableroTriqui[n][1]==tableroTriqui[n][2]):
      ganador = tableroTriqui[n][0]
    elif(tableroTriqui[0][n]==tableroTriqui[1][n] and tableroTriqui[1][n]==tableroTriqui[2][n]):
      ganador = tableroTriqui[0][n]
    elif((tableroTriqui[0][0]==tableroTriqui[1][1]) and (tableroTriqui[1][1]==tableroTriqui[2][2])):
      ganador = tableroTriqui[0][0]
    elif(tableroTriqui[0][2]==tableroTriqui[1][1] and tableroTriqui[1][1]==tableroTriqui[2][0]):
      ganador = tableroTriqui[0][2]

  return ganador

print("\n",tableroTriqui[0],"\n",tableroTriqui[1],"\n",tableroTriqui[2],"\n")
print("El ganador es:", ganador(tableroTriqui))
