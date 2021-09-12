import random

def generar_row():
    return f'{random.randint(1, 100)} {random.randint(1, 100)}'

for i in range(4240):
    print(generar_row())

# python generador-random.py >> random-numbers.txt