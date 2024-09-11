import numpy as np

# Generar datos de listas para ordenar (ordenadas, semi ordenadas, aleatoreamente ordenados)

# Genera un arreglo ordenado de menor a mayor: np.arange(1,N,1)
# Genera un arreglo aleatorio: np.random.randint(100, size=N)
# Genera un arreglo ordenado de mayor a menor: np.arange(N-1,0,-1)

def generar_arreglos(archivo, N):
	arch_ord.write(str(N)+"\n")
	np.arange(1,N+1,1).tofile(archivo, sep=" ", format='%s')
	arch_ord.write("\n")
	np.arange(N,0,-1).tofile(archivo, sep=" ", format='%s')
	arch_ord.write("\n")
	np.random.randint(N, size=N).tofile(archivo, sep=" ", format='%s')

# def generar_matrices_cuadr(archivo, M, N):
# 	for()

arch_ord = open("Ordenamiento_Dataset.txt", "w")
for i in range(1,11):
	generar_arreglos(arch_ord, 10000*i)
	arch_ord.write("\n")
arch_ord.close()

