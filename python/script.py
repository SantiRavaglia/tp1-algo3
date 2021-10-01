import pandas as pd
import numpy as np
import os
import time

def leer_instancia(path_instancia):
    with open(path_instancia, "r") as f:
        return f.read()

# df_random_bf = pd.read_csv("instancias/random-bf/indice.csv")
#df_densidad_baja = pd.read_csv("instancias/densidad-baja/indice.csv")
#df_mejor_caso_bt = pd.read_csv("instancias/mejor-caso-bt/indice.csv")
#df_peor_caso_bt = pd.read_csv("instancias/peor-caso-bt/indice.csv")
df_dinamica = pd.read_csv("instancias/dinamica/indice.csv")
# leer_instancia('instancias/random-bf/BF-10.txt')

def correr_experimento(metodo, archivo_instancia):
    
    start = time.time_ns()
    os.system("../src/main {} < {}".format(metodo, archivo_instancia))
    end = time.time_ns()
    diff = (end - start)/1000000
    
    return diff

# correr_experimento('BF', '../python/instancias/bf-test.txt')

experimentos = []

for i, row in df_dinamica.iterrows():
    # fila_n = df_dinamica.iloc[n]
    experimentos.append([row.dataset, row.instancia, row.n, row.M, row.archivo])

print(experimentos)

columnas = ["dataset", "n", "M", "metodo", "tiempo"]
filas = []
numero = 1
T = 5 # Numero de veces que se ejecuta cada experimento (para mayor fidelidad del tiempo).
for i, row in df_dinamica.iterrows():
    print("=======>" + str(row.n) + " " + str(row.M))
    # Voy mostrando que experimento se esta ejecutando.
    numero += 1
    
    # Ejecutamos el experimento T veces y obtenemos la mediana.
    tiempos = []
    for i in range(0, T):
        tiempos.append(correr_experimento('DP', row.archivo))
    tiempo = np.median(tiempos)
    filas.append([row.n, row.M, tiempo])
df_resultado = pd.DataFrame(filas, columns=columnas)
df_resultado.to_csv("resultados/resultado.csv", index=False, header=True)