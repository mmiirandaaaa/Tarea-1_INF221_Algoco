GW = g++ -Wall

out: Matrices.o Ordenamiento.o
	$(GW) -o out Benchmark.cpp Matrices.o Ordenamiento.o

Matrices.o:
	$(GW) -c Matrices.cpp Matrices.h

Ordenamiento.o:
	$(GW) -c Ordenamiento.cpp Ordenamiento.h

.PHONY: clean
clean:
	rm -rf *.o out *.h.gch