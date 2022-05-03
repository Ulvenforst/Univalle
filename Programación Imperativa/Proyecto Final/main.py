# Narváez.
# Importes:
from tkinter import *
from itertools import chain
from collections import Counter
root = Tk()
root.title("Votaciones")
root.geometry("400x500")
root.resizable(False, False)

def show_frame(frame):
    frame.tkraise()

# Frames de páginas:
principal_f = Frame(root)
eleccion_f = Frame(root)
candidato1_f = Frame(root)
candidato2_f = Frame(root)
estadistica_f = Frame(root)

# Variables a usar.
candidatos1 = []
total_votantes1 = 0
hombres_votantes1 = 0
mujeres_votantes1 = 0
candidatos2 = []
total_votantes2 = 0
hombres_votantes2 = 0
mujeres_votantes2 = 0
cedulas = []
sexos = []

# Funciones
def accion_registrarVoto():
    try:
        # Validaciones
        numero_cedula = int(cedula_e.get())
        global sexos
        if (sexo.get()=='None'):
            mensaje_errorl.config(text="Debe de seleccionar un sexo biológico.\n", fg="red")
        elif (str(numero_cedula) in cedulas):
            mensaje_errorl.config(text="La cédula ya fue registrada.\n", fg="red")
        else:
            cedulas.append(cedula_e.get())
            sexos.append(sexo.get())
            mensaje_errorl.config(text="Votación envíada.\n", fg="green")
            mensaje_errorl1.config(text="")
            mensaje_errorl2.config(text="")
            show_frame(eleccion_f)
            cedula_e.delete(0, END)
            sexo.set("None")

    except ValueError:
        mensaje_errorl.config(text="Número de cédula no válido, recuerde digitar solo números enteros.", fg="red", wraplength=300)

    # Mensajes de prueba
    print(cedulas)
    print(sexos)

ganador_candidatos1 = ""
ganador_candidatos2 = ""
voto_blanco1 = ""
voto_blanco2 = ""
promedio_mujeres = "" 
promedio_hombres = "" 

def accion_estadistica():
    if len(candidatos1) == 0 and len(candidatos2)==0:
        global ganador_candidatos1
        global ganador_candidatos2
        ganador_candidatos1 = "Sin votos registrados."
        ganador_candidatos2 = "Sin votos registrados."
        print("Sin datos")
    else:
        global voto_blanco1
        global voto_blanco2
        global promedio_hombres
        global promedio_mujeres
        candidatos1_moda = Counter(candidatos1)
        voto_blanco1 = str(candidatos1.count("Voto en Blanco"))
        voto_blanco2 = str(candidatos2.count("Voto en Blanco"))
        promedio_hombres = str(int((sexos.count("masculino")/len(sexos))*100))+"%"
        promedio_mujeres = str(int((sexos.count("femenino")/len(sexos))*100))+"%"
        print(promedio_hombres)
        print(promedio_mujeres)
        if len(candidatos1) >= 2:
            if len(candidatos1_moda.most_common(2)) == 2 and candidatos1_moda.most_common(2)[0][1] == candidatos1_moda.most_common(2)[1][1]:
                ganador_candidatos1 = "Hay un empate en los candidatos."
                print(ganador_candidatos1)
            else:
                ganador_candidatos1 = candidatos1_moda.most_common(1)[0][0]
                print("El ganador 1 es:", ganador_candidatos1)
        elif len(candidatos1)==1:
            ganador_candidatos1 = candidatos1_moda.most_common(1)[0][0]
            print("El ganador 1 es:", ganador_candidatos1)
        candidatos2_moda = Counter(candidatos2)
        if len(candidatos2) >= 2:
            if len(candidatos2_moda.most_common(2)) == 2 and candidatos2_moda.most_common(2)[0][1] == candidatos2_moda.most_common(2)[1][1]:
                ganador_candidatos2 = "Hay un empate en los candidatos."
                print(ganador_candidatos2)
            else:
                ganador_candidatos2 = candidatos2_moda.most_common(1)[0][0]
                print("El ganador 2 es:", ganador_candidatos2)
        elif len(candidatos2)==1:
            ganador_candidatos2 = candidatos2_moda.most_common(1)[0][0]
            print("El ganador 2 es:", ganador_candidatos2)
    show_frame(estadistica_f)
    ganador1.config(text="Ganador: "+ganador_candidatos1)
    ganador2.config(text="Ganador: "+ganador_candidatos2)
    votos_blancos1.config(text="Votos en blanco: "+voto_blanco1)
    votos_blancos2.config(text="Votos en blanco: "+voto_blanco2)
    hombres.config(text="Porcentaje de hombres: "+str(promedio_hombres))
    mujeres.config(text="Porcentaje de mujeres: "+str(promedio_mujeres))

    #
    if total_votantes1 != 0:
        total_votantes1_l.config(text="Total de vontantes: "+str(total_votantes1))
        total_mujeres1_l.config(text="Total de mujeres: "+str(mujeres_votantes1)+" — "+ str(int((mujeres_votantes1/total_votantes1)*100))+"%")
        total_hombres1_l.config(text="Total de hombres: "+str(hombres_votantes1)+" — "+ str(int((hombres_votantes1/total_votantes1)*100))+"%")
    
    if total_votantes2 != 0:
        total_votantes2_l.config(text="Total de vontantes: "+str(total_votantes2))
        total_mujeres2_l.config(text="Total de mujeres: "+str(mujeres_votantes2)+" — "+ str(int((mujeres_votantes2/total_votantes2)*100))+"%")
        total_hombres2_l.config(text="Total de hombres: "+str(hombres_votantes2)+" — "+ str(int((hombres_votantes2/total_votantes2)*100))+"%")

    votos_totales_l.config(text="Votos totales: "+str(len(sexos)))

# ----- INICIO -----
# Frames
informacion_f = Frame(principal_f)
informacion_f.grid(column=0, row=0, padx=50, pady=20)
informacion_f.columnconfigure(0, weight=0)
informacion_f.rowconfigure(0, weight=0)

entradas = Frame(principal_f)
entradas.grid(column=0, row=1, padx=50, pady=0)
entradas.columnconfigure(0, weight=0)
entradas.rowconfigure(0, weight=0)

botones = Frame(principal_f) # Frame no necesario, pero usado por comodidad.
botones.grid(column=0, row=2, padx=0, pady=20)
botones.columnconfigure(2, weight=0)
botones.rowconfigure(0, weight=0)

# Mensajes de introducción
titulo_l = Label(informacion_f, text="Votaciones.", font=("Times New Roman", 16)).pack()
descripcion_l = Label(informacion_f, 
                        text="A continuación podrá registrarsen para votar las elecciones de dos candidaturas diferentes, las instrucciones son:\n\n1. Introduzca su cédula: Recuerde que la cédula solo puede ser registrada una vez, por ende asegúrese de votar bien.\n\n2. Una vez haya registrado la cédula podrá votar por dos candidaturas de su preferencia.", wraplength=300, justify=LEFT).pack()

cedula_l = Label(entradas, text="Ingrese su cédula:").pack()
cedula_e = Entry(entradas)
cedula_e.pack(pady=(0,10))

# Botón radio
sexo = StringVar()
Label(entradas, 
        text="""Seleccione su sexo biológico:""",
        justify = LEFT,
        padx = 20).pack()

Radiobutton(entradas, 
               text="Masculino",
               padx = 20, 
               variable=sexo, 
               value="masculino").pack()

Radiobutton(entradas, 
               text="Femenino",
               padx = 20, 
               variable=sexo, 
               value="femenino").pack()

sexo.set("None")

# Botones
mensaje_errorl = Label(entradas, text="\n")
mensaje_errorl.pack()
registrarVoto_b = Button(botones, text="Registrar Voto", command=accion_registrarVoto, padx=10, pady=5)
registrarVoto_b.pack(side=RIGHT, padx=50)
estadistica_b = Button(botones, text="Estadísticas", command=accion_estadistica, padx=10, pady=5).pack(side=LEFT, padx=50)
# ----- FIN INICIO -----

# --- ELECCIÓN VOTO ----
# Frames
informacionE_f = Frame(eleccion_f)
informacionE_f.grid(column=0, row=0, padx=50, pady=20)
informacionE_f.columnconfigure(0, weight=0)
informacionE_f.rowconfigure(0, weight=0)

entradasE = Frame(eleccion_f)
entradasE.grid(column=0, row=1, padx=50, pady=0)
entradasE.columnconfigure(0, weight=0)
entradasE.rowconfigure(0, weight=0)

botonesE = Frame(eleccion_f) # Frame no necesario, pero usado por comodidad.
botonesE.grid(column=0, row=2, padx=0, pady=20)
botonesE.columnconfigure(2, weight=0)
botonesE.rowconfigure(0, weight=0)

candidatura1_b = Button(entradasE, text="Tarjetón de Alcaldía", command=lambda:show_frame(candidato1_f), padx=10, pady=10)
candidatura1_b.pack(padx=10, pady=10)
candidatura2_b = Button(entradasE, text="Tarjetón de Governación", command=lambda:show_frame(candidato2_f), padx=10, pady=10)
candidatura2_b.pack(padx=10, pady=10)

# Mensajes de introducción
titulo_l = Label(informacionE_f, text="Tarjetones Disponibles.", font=("Times New Roman", 16)).pack()
descripcion_l = Label(informacionE_f, 
                        text="Dispone de los siguientes tarjetones de votaciones, debe votar por aquel de su preferencia. De manera opcional, si ambos son de su preferencia puede votar por ambos.", wraplength=300, justify=LEFT).pack()

def accion_inicio_estadistica():
    boton_inicio_eleccion["state"]=["disabled"]
    candidatura1_b["state"]="normal"
    candidatura2_b["state"]="normal"
    show_frame(principal_f)

boton_inicio_eleccion= Button(botonesE, text="Finalizar", state="disabled",command=accion_inicio_estadistica)
boton_inicio_eleccion.pack()
# - FIN ELECCIÓN VOTO --

# --PÁGINA CANDIDATO 1--
# Frames
informacion1_f = Frame(candidato1_f)
informacion1_f.grid(column=0, row=0, padx=50, pady=20)
informacion1_f.columnconfigure(0, weight=0)
informacion1_f.rowconfigure(0, weight=0)

entradas1 = Frame(candidato1_f)
entradas1.grid(column=0, row=1, padx=50, pady=0)
entradas1.columnconfigure(0, weight=0)
entradas1.rowconfigure(0, weight=0)

botones1 = Frame(candidato1_f) # Frame no necesario, pero usado por comodidad.
botones1.grid(column=0, row=2, padx=0, pady=20)
botones1.columnconfigure(2, weight=0)
botones1.rowconfigure(0, weight=0)

# Mensajes de introducción
titulo_l = Label(informacion1_f, text="Candidatura de Alcaldía.", font=("Times New Roman", 16)).pack()
descripcion_l = Label(informacion1_f, 
                        text="A continuación tiene una lista de la candidatura de la alcaldía, seleccione aquel candidato preferente y consiguiente clickee \"Votar\" para votar por su candidato preferente.", wraplength=300, justify=LEFT).pack()

# Botón radio
candidato1 = StringVar()
Label(entradas1, 
        text="""Seleccione el candidato de la alcaldía:""",
        justify = LEFT,
        padx = 20).pack()

Radiobutton(entradas1, 
               text="Jorge Iván Ospina",
               padx = 20, 
               variable=candidato1, 
               value="Jorge Iván Ospina").pack()

Radiobutton(entradas1, 
               text="Roberto Ortiz",
               padx = 20, 
               variable=candidato1, 
               value="Roberto Ortiz").pack()

Radiobutton(entradas1, 
               text="Álvaro David",
               padx = 20, 
               variable=candidato1, 
               value="Álvaro David").pack()

Radiobutton(entradas1, 
               text="Voto en blanco",
               padx = 20, 
               variable=candidato1, 
               value="Voto en Blanco").pack()

candidato1.set("None")

# Función
def accion_registrarCandidato1():
    global mujeres_votantes1
    global hombres_votantes1
    global total_votantes1
    if candidato1.get()!="None":
        candidatos1.append(candidato1.get())
        show_frame(eleccion_f)
        candidato1.set("None")
        candidatura1_b["state"]="disabled"
        boton_inicio_eleccion["state"]="normal"
        if sexos[-1]=="femenino":
            mujeres_votantes1 +=1
        elif sexos[-1]=="masculino":
            hombres_votantes1 +=1 
        total_votantes1 = mujeres_votantes1+hombres_votantes1 
    else:
        mensaje_errorl1.config(text="Asegúrese de selccionar un candidato", wraplength=300, fg="red")


    # Mensajes de prueba
    print(candidatos1)

mensaje_errorl1 = Label(entradas1, text="")
mensaje_errorl1.pack()

boton_candidatura1= Button(botones1, text="Votar", command=accion_registrarCandidato1)
boton_candidatura1.pack()
# FIN PÁGINA CANDIDATO 1

# --PÁGINA CANDIDATO 2--
# Frames
informacion2_f = Frame(candidato2_f)
informacion2_f.grid(column=0, row=0, padx=50, pady=20)
informacion2_f.columnconfigure(0, weight=0)
informacion2_f.rowconfigure(0, weight=0)

entradas2 = Frame(candidato2_f)
entradas2.grid(column=0, row=1, padx=50, pady=0)
entradas2.columnconfigure(0, weight=0)
entradas2.rowconfigure(0, weight=0)

botones2 = Frame(candidato2_f) # Frame no necesario, pero usado por comodidad.
botones2.grid(column=0, row=2, padx=0, pady=20)
botones2.columnconfigure(2, weight=0)
botones2.rowconfigure(0, weight=0)

# Mensajes de introducción
titulo_l = Label(informacion2_f, text="Candidatura Governación.", font=("Times New Roman", 16)).pack()
descripcion_l = Label(informacion2_f, 
                        text="A continuación tiene una lista de la candidatura de la governación, seleccione aquel candidato preferente y consiguiente clickee \"Votar\" para votar por su candidato preferente.", wraplength=300, justify=LEFT).pack()

# Botón radio
candidato2 = StringVar()
Label(entradas2, 
        text="""Seleccione el candidato de la Governación:""",
        justify = LEFT,
        padx = 20).pack()

Radiobutton(entradas2, 
               text="Natan Medina",
               padx = 20, 
               variable=candidato2, 
               value="Natan Medina").pack()

Radiobutton(entradas2, 
               text="Juan Narváez",
               padx = 20, 
               variable=candidato2, 
               value="Juan Narváez").pack()

Radiobutton(entradas2, 
               text="Carol Rubiano",
               padx = 20, 
               variable=candidato2, 
               value="Carol Rubiano").pack()

Radiobutton(entradas2, 
               text="Voto en blanco",
               padx = 20, 
               variable=candidato2, 
               value="Voto en Blanco").pack()

candidato2.set("None")

# Función
def accion_registrarCandidato2():
    global mujeres_votantes2
    global hombres_votantes2
    global total_votantes2
    if candidato2.get()!="None":
        candidatos2.append(candidato2.get())
        show_frame(eleccion_f)
        candidato2.set("None")
        candidatura2_b["state"]="disabled"
        boton_inicio_eleccion["state"]="normal"
        if sexos[-1]=="femenino":
            mujeres_votantes2 += 1
        elif sexos[-1]=="masculino":
            hombres_votantes2 += 1
        total_votantes2 = mujeres_votantes2+hombres_votantes2 
    else:
        mensaje_errorl2.config(text="Asegúrese de selccionar un candidato", wraplength=300, fg="red")

    # Mensajes de prueba
    print(candidatos2)

mensaje_errorl2 = Label(entradas2, text="")
mensaje_errorl2.pack()

boton_candidatura2= Button(botones2, text="Votar", command=accion_registrarCandidato2)
boton_candidatura2.pack()
# FIN PÁGINA CANDIDATO 2

# --PÁGINA ESTADÍSTICA--
titulo_estadistica = Frame(estadistica_f)
titulo_estadistica.grid(row=0,column=0, sticky='nsew', padx=70, pady=20)
datos_primerCorporacion = Frame(estadistica_f, borderwidth=1, relief=SOLID)
datos_primerCorporacion.grid(row=1,column=0)
datos_segundaCorporacion = Frame(estadistica_f, borderwidth=1, relief=SOLID)
datos_segundaCorporacion.grid(row=2,column=0)
datos_generales = Frame(estadistica_f, borderwidth=1, relief=SOLID)
datos_generales.grid(row=3, column=0)
botones_estadistica = Frame(estadistica_f)
botones_estadistica.grid(row=4,column=0)

titulo_l = Label(titulo_estadistica, text="Estadísticas de las Votaciones.", font=("Times New Roman", 16)).pack()

corporacionName1 = Label(datos_primerCorporacion, font=("Times New Roman", 14), text="Datos del Alcaldía:").pack()
ganador1 = Label(datos_primerCorporacion, text="Ganador: "+str(ganador_candidatos1))
ganador1.pack()
votos_blancos1 = Label(datos_primerCorporacion, text="Votos en blanco: "+str(voto_blanco1))
votos_blancos1.pack()
total_votantes1_l = Label(datos_primerCorporacion, text="Total de vontantes: "+str(total_votantes1))
total_votantes1_l.pack()
total_mujeres1_l = Label(datos_primerCorporacion, text="Total de mujeres: 0 — 0% ")
total_mujeres1_l.pack()
total_hombres1_l= Label(datos_primerCorporacion, text="Total de hombres: 0 — 0%")
total_hombres1_l.pack()

corporacionName2 = Label(datos_segundaCorporacion, font=("Times New Roman", 14), text="Datos de Governación:").pack()
ganador2 = Label(datos_segundaCorporacion, text="Ganador: "+ganador_candidatos2)
ganador2.pack()
votos_blancos2 = Label(datos_segundaCorporacion, text="Votos en blanco: "+str(voto_blanco2))
votos_blancos2.pack()
total_votantes2_l = Label(datos_segundaCorporacion, text="Total de vontantes: "+str(total_votantes2))
total_votantes2_l.pack()
total_mujeres2_l = Label(datos_segundaCorporacion, text="Total de mujeres: 0 — 0%")
total_mujeres2_l.pack()
total_hombres2_l= Label(datos_segundaCorporacion, text="Total de hombres: 0 — 0%")
total_hombres2_l.pack()

datos_generalesTitulo = Label(datos_generales, font=("Times New Roman", 14), text="Porcentaje de Hombres y Mujeres:").pack()
votos_totales_l = Label(datos_generales, text="Votos totales: 0")
votos_totales_l.pack()
hombres = Label(datos_generales, text="Porcentaje de hombres: "+str(promedio_hombres))
hombres.pack()
mujeres = Label(datos_generales, text="Porcentaje de mujeres: "+str(promedio_mujeres))
mujeres.pack()

boton_inicio = Button(botones_estadistica, text="Ir al inicio", command=lambda:show_frame(principal_f))
boton_inicio.pack(pady=20)
# -- FIN ESTADÍSTICA ---

# Impresión:
for frame in (principal_f, eleccion_f, candidato1_f, candidato2_f, estadistica_f):
    frame.grid(row=0,column=0,sticky='nsew')

show_frame(principal_f)
root.mainloop()
