import math, subprocess
import pandas as pd
import numpy as np
from IPython.display import display, clear_output

def leer_instancia(path_instancia):
    with open(path_instancia, "r") as f:
        return f.read()

df_random_bf = pd.read_csv("instancias/random-bf/indice.csv")
#df_densidad_baja = pd.read_csv("instancias/densidad-baja/indice.csv");
#df_mejor_caso_bt = pd.read_csv("instancias/mejor-caso-bt/indice.csv");
#df_peor_caso_bt = pd.read_csv("instancias/peor-caso-bt/indice.csv");
#df_dinamica = pd.read_csv("instancias/dinamica/indice.csv");
leer_instancia('instancias/random-bf/BF-10.txt')

def correr_experimento(metodo, archivo_instancia):
    # Leer archivo de la instancia.
    instancia = leer_instancia(archivo_instancia)
    
    # Crear proceso para ejecutar el codigo.
    process = subprocess.Popen(["..\main", metodo], stderr=subprocess.PIPE, stdout=subprocess.PIPE, stdin=subprocess.PIPE, universal_newlines = True, shell=True)
    
    
    # Poner la instancia en la entrada estandar.
    process.stdin.write(instancia)
    process.stdin.flush()

    # Correr experimento.
    exit_code = process.wait()

    # Verificar que el proceso no fallo.
    if exit_code != 0: 
        print(exit_code)
        raise RuntimeError("Hubo un error.")
    # Leer salida de STDERR con los tiempos de ejecucion de cada metodo.
    tiempo_de_ejecucion = float(process.stderr.read())
    
    process.stdin.close()
    process.stdout.close()
    process.stderr.close()
    
    return tiempo_de_ejecucion

#correr_experimento('FB', experimentos[9][4])

experimentos = []

for n in range(0, 30):
    fila_n = df_random_bf.iloc[n]
    experimentos.append([fila_n["dataset"], n, fila_n["M"], "FB", fila_n["archivo"]])

columnas = ["dataset", "n", "M", "metodo", "tiempo"]
filas = []
numero = 1
T = 5 # Numero de veces que se ejecuta cada experimento (para mayor fidelidad del tiempo).
for experimento in experimentos:
    # Voy mostrando que experimento se esta ejecutando.
    clear_output(wait=True)
    display('Experimento: ' + str(numero) + "/" + str(len(experimentos)))
    numero += 1
    
    # Ejecutamos el experimento T veces y obtenemos la mediana.
    tiempos = []
    for i in range(0, T):
        tiempos.append(correr_experimento(experimento[3], experimento[4]))
    tiempo = np.median(tiempos)
    filas.append([experimento[0], experimento[1], experimento[2], experimento[3], tiempo])
df_resultado = pd.DataFrame(filas, columns=columnas)
df_resultado.to_csv("resultados/resultado.csv", index=False, header=True)