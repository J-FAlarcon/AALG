#-----------------------
# IMPORTANTE: Los valores de los parametros de los ejercicio?_test deben ajustarse.
# Se asume que los ficheros fuente se llaman ejercicio1.c, ejercicio2.c,...,ordenar.h
#-----------------------

CC = gcc -ansi -pedantic 
CFLAGS = -Wall 
EXE = ejercicio1 ejercicio2 ejercicio3 ejercicio4 ejercicio5

all : $(EXE)

.PHONY : clean
clean :
	rm -f *.o core $(EXE)
	rm *.txt
# 	rm *.log
	

$(EXE) : % : %.o ordenacion.o tiempos.o permutaciones.o
	@echo "#---------------------------"
	@echo "# Generando $@ "
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -o $@ $@.o ordenacion.o tiempos.o permutaciones.o

permutaciones.o : permutaciones.c permutaciones.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<

ordenacion.o : ordenacion.c ordenacion.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<

tiempos.o : tiempos.c tiempos.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<
	
ejercicio1_test:
	@echo Ejecutando ejercicio1
	@./ejercicio1 -limInf 1 -limSup 5 -numN 10
	@cat file.txt

ejercicio2_test:
	@echo Ejecutando ejercicio2
	@./ejercicio2 -tamanio 5 -numP 1

ejercicio3_test:
	@echo Ejecutando ejercicio3
	@./ejercicio3 -tamanio 5 -numP 5

ejercicio4_test:
	@echo Ejecutando ejercicio4
	@./ejercicio4 -tamanio 5

ejercicio5_test:
	@echo Ejecutando ejercicio5
	@./ejercicio5 -num_min 1 -num_max 5 -incr 1 -numP 100000 -fichSalida ejercicio5.log

histograma:
	@./ejercicio1 -limInf 1 -limSup 5 -numN 10
	@cat file.txt | sort -n | uniq -c
	@cat file.txt | sort -n | uniq -c > file2.txt
	@gnuplot -p -e "set style data histograms; plot './file2.txt' using 1:xtic(2)"
	
	

