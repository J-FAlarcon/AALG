#-----------------------
# IMPORTANTE: Los valores de los parametros de los ejercicio?_test deben ajustarse.
# Se asume que los ficheros fuente se llaman ejercicio1.c, ejercicio2.c,...,ordenar.h
#-----------------------

CC = gcc -ansi -pedantic
CFLAGS = -Wall
EXE = ejercicio1 ejercicio2 ejercicio3 ejercicio4 ejercicio5 P3ejercicio1 P3ejercicio2

all : $(EXE)

.PHONY : clean
clean :
	rm -f *.o core $(EXE)
	rm *.log
	

$(EXE) : % : %.o ordenacion.o tiempos.o permutaciones.o busqueda.o
	@echo "#---------------------------"
	@echo "# Generando $@ "
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -o $@ $@.o ordenacion.o tiempos.o permutaciones.o busqueda.o

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

busqueda.o : busqueda.c busqueda.h
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
	@./ejercicio5 -num_min 1 -num_max 10 -incr 1 -numP 100 -fichSalida ejercicio5.log	



P3ejercicio1_test:
	@echo Ejecutando ejercicio1
	@./P3ejercicio1 -tamanio 20 -clave 13
	
P3ejercicio2_test:
	@echo Ejecutando ejercicio2
	@./P3ejercicio2 -num_min 1 -num_max 100 -incr 2 -n_veces 100 -fichSalida ejercicio2.log


ejercicio2_bin:
	@echo Ejecutando ejercicio2
	@./ejercicio2 -num_min 1 -num_max 100 -incr 1 -n_veces 1 -fichSalida BinarySearch1.log
	@./ejercicio2 -num_min 1 -num_max 100 -incr 1 -n_veces 100 -fichSalida BinarySearch2.log
	@./ejercicio2 -num_min 1 -num_max 100 -incr 1 -n_veces 10000 -fichSalida BinarySearch3.log


ejercicio2_linauto:
	@echo Ejecutando ejercicio2
	@./ejercicio2 -num_min 1 -num_max 100 -incr 1 -n_veces 1 -fichSalida LinearAutoSearch1.log
	@./ejercicio2 -num_min 1 -num_max 100 -incr 1 -n_veces 100 -fichSalida LinearAutoSearch2.log
	@./ejercicio2 -num_min 1 -num_max 100 -incr 1 -n_veces 10000 -fichSalida LinearAutoSearch3.log

# histograma_tiempo:
# 	@./ejercicio2 -num_min 1 -num_max 50 -incr 1 -n_veces 1 -fichSalida test.txt
# 	@gnuplot -p -e "set style data histograms; plot 'test.txt' using 2, '' using 4"

histograma_bin_obmedio:
	@gnuplot -p -e "set xlabel 'Tamanio diccionario (N)'; set ylabel 'OBs'; set key left top; set title 'OBs medio BBin para diferentes n\_veces'; plot 'BinarySearch1.log' using 2:6 title 'OBS medio BBin n\_veces=1' w l, 'BinarySearch2.log' using 2:6 title 'OBs BBin n\_veces=100' w l, 'BinarySearch3.log' using 2:6 title 'OBs BBin n\_veces=10.000' w l"
	
histograma_linauto_obmedio:
	@gnuplot -p -e "set xlabel 'Tamanio diccionario (N)'; set ylabel 'OBs medio (s)'; set key left top; set title 'OBs medio BLin auto para diferentes n\_veces'; plot 'LinearAutoSearch1.log' using 2:6 title 'OBs medio BLin_auto n\_veces=1' w l, 'LinearAutoSearch2.log' using 2:6 title 'OBs medio BLin_auto n\_veces=100' w l, 'LinearAutoSearch3.log' using 2:6 title 'OBs medio BLin_auto n\_veces=10.000' w l"
	
histograma_bin_obmin:
	@gnuplot -p -e "set xlabel 'Tamanio diccionario (N)'; set ylabel 'OBs'; set key left top; set title 'OBs min BBin para diferentes n\_veces'; plot 'BinarySearch1.log' using 2:8 title 'OBS min BBin n\_veces=1' w l, 'BinarySearch2.log' using 2:8 title 'OBs min BBin n\_veces=100' w l, 'BinarySearch3.log' using 2:8 title 'OBs min BBin n\_veces=10.000' w l"

histograma_linauto_obmin:
	@gnuplot -p -e "set xlabel 'Tamanio diccionario (N)'; set ylabel 'OBs'; set key left top; set title 'OBs min BLin_Auto para diferentes n\_veces'; plot 'LinearAutoSearch1.log' using 2:8 title 'OBS min BLinAuto n\_veces=1' w l, 'LinearAutoSearch2.log' using 2:8 title 'OBs min BLinAuto n\_veces=100' w l, 'LinearAutoSearch3.log' using 2:8 title 'OBs min BLinAuto n\_veces=10.000' w l"

histograma_bin_obmax:
	@gnuplot -p -e "set xlabel 'Tamanio diccionario (N)'; set ylabel 'OBs'; set key left top; set title 'OBs max BBin para diferentes n\_veces'; plot 'BinarySearch1.log' using 2:10 title 'OBS max BBin n\_veces=1' w l, 'BinarySearch2.log' using 2:10 title 'OBs max BBin n\_veces=100' w l, 'BinarySearch3.log' using 2:10 title 'OBs max BBin n\_veces=10.000' w l"

histograma_linauto_obmax:
	@gnuplot -p -e "set xlabel 'Tamanio diccionario (N)'; set ylabel 'OBs'; set key left top; set title 'OBs max BLin_Auto para diferentes n\_veces'; plot 'LinearAutoSearch1.log' using 2:10 title 'OBS max BLinAuto n\_veces=1' w l, 'LinearAutoSearch2.log' using 2:10 title 'OBs max BLinAuto n\_veces=100' w l, 'LinearAutoSearch3.log' using 2:10 title 'OBs max BLinAuto n\_veces=10.000' w l"

histograma_bin_tiempo:
	@gnuplot -p -e "set xlabel 'Tamanio diccionario (N)'; set ylabel 'Tiempo (s)'; set key left top; set title 'Tiempo medio BBin para diferentes n\_veces'; plot 'BinarySearch1.log' using 2:4 title 'Tiempo medio BBin n\_veces=1' w l, 'BinarySearch2.log' using 2:4 title 'Tiempo medio BBinary n\_veces=100' w l, 'BinarySearch3.log' using 2:4 title 'Tiempo medio BBinary n\_veces=10.000' w l"

histograma_linauto_tiempo:
	@gnuplot -p -e "set xlabel 'Tamanio diccionario (N)'; set ylabel 'Tiempo (s)'; set key left top; set title 'Tiempo medio BLin_Auto para diferentes n\_veces'; plot 'LinearAutoSearch1.log' using 2:4 title 'Tiempo medio BLinAuto n\_veces=1' w l, 'LinearAutoSearch2.log' using 2:4 title 'Tiempo medio BLinAuto n\_veces=100' w l, 'LinearAutoSearch3.log' using 2:4 title 'Tiempo medio BLinAuto n\_veces=10.000' w l"
	


histograma_min_1:
	@gnuplot -p -e "set xlabel 'Tamanio diccionario (N)'; set ylabel 'OBs'; set key left top; set title 'OBs míminas para BBin y BLin_Auto en n\_veces=1'; plot 'BinarySearch1.log' using 2:8 title 'OBS min BBin n\_veces=1' w l,'LinearAutoSearch1.log' using 2:8 title 'OBS min BLinAuto n\_veces=1' w l"

histograma_max_1:
	@gnuplot -p -e "set xlabel 'Tamanio diccionario (N)'; set ylabel 'OBs'; set key left top; set title 'OBs máximas para BBin y BLin_Auto en n\_veces=1'; plot 'BinarySearch1.log' using 2:10 title 'OBS max BBin n\_veces=1' w l,'LinearAutoSearch1.log' using 2:10 title 'OBS max BLinAuto n\_veces=1' w l"

histograma_medio_1:
	@gnuplot -p -e "set xlabel 'Tamanio diccionario (N)'; set ylabel 'OBs'; set key left top; set title 'OBs medias para BBin y BLin_Auto en n\_veces=1'; plot 'BinarySearch1.log' using 2:6 title 'OBS medio BBin n\_veces=1' w l,'LinearAutoSearch1.log' using 2:6 title 'OBS medio BLinAuto n\_veces=1' w l"

histograma_tiempo_1:
	@gnuplot -p -e "set xlabel 'Tamanio diccionario (N)'; set ylabel 'Tiempo (s)'; set key left top; set title 'Tiempos medios para BBin y BLin_Auto en n\_veces=1'; plot 'BinarySearch1.log' using 2:4 title 'Tiempo medio BBin n\_veces=1' w l,'LinearAutoSearch1.log' using 2:4 title 'Tiempo medio BLinAuto n\_veces=1' w l"

histograma_min_100:
	@gnuplot -p -e "set xlabel 'Tamanio diccionario (N)'; set ylabel 'OBs'; set key left top; set title 'OBs míminas para BBin y BLin_Auto en n\_veces=100'; plot 'BinarySearch2.log' using 2:8 title 'OBS min BBin n\_veces=100' w l,'LinearAutoSearch2.log' using 2:8 title 'OBS min BLinAuto n\_veces=100' w l"

histograma_max_100:
	@gnuplot -p -e "set xlabel 'Tamanio diccionario (N)'; set ylabel 'OBs'; set key left top; set title 'OBs máximas para BBin y BLin_Auto en n\_veces=100'; plot 'BinarySearch2.log' using 2:10 title 'OBS max BBin n\_veces=100' w l,'LinearAutoSearch2.log' using 2:10 title 'OBS max BLinAuto n\_veces=100' w l"

histograma_medio_100:
	@gnuplot -p -e "set xlabel 'Tamanio diccionario (N)'; set ylabel 'OBs'; set key left top; set title 'OBs medias para BBin y BLin_Auto en n\_veces=100'; plot 'BinarySearch2.log' using 2:6 title 'OBS medio BBin n\_veces=100' w l,'LinearAutoSearch2.log' using 2:6 title 'OBS medio BLinAuto n\_veces=100' w l"

histograma_tiempo_100:
	@gnuplot -p -e "set xlabel 'Tamanio diccionario (N)'; set ylabel 'Tiempo (s)'; set key left top; set title 'Tiempos medios para BBin y BLin_Auto en n\_veces=100'; plot 'BinarySearch2.log' using 2:4 title 'Tiempo medio BBin n\_veces=100' w l,'LinearAutoSearch2.log' using 2:4 title 'Tiempo medio BLinAuto n\_veces=100' w l"

histograma_min_10000:
	@gnuplot -p -e "set xlabel 'Tamanio diccionario (N)'; set ylabel 'OBs'; set key left top; set title 'OBs míminas para BBin y BLin_Auto en n\_veces=10000'; plot 'BinarySearch3.log' using 2:8 title 'OBS min BBin n\_veces=10000' w l,'LinearAutoSearch3.log' using 2:8 title 'OBS min BLinAuto n\_veces=10000' w l"

histograma_max_10000:
	@gnuplot -p -e "set xlabel 'Tamanio diccionario (N)'; set ylabel 'OBs'; set key left top; set title 'OBs máximas para BBin y BLin_Auto en n\_veces=10000'; plot 'BinarySearch3.log' using 2:10 title 'OBS max BBin n\_veces=10000' w l,'LinearAutoSearch3.log' using 2:10 title 'OBS max BLinAuto n\_veces=10000' w l"

histograma_medio_10000:
	@gnuplot -p -e "set xlabel 'Tamanio diccionario (N)'; set ylabel 'OBs'; set key left top; set title 'OBs medias para BBin y BLin_Auto en n\_veces=10000'; plot 'BinarySearch3.log' using 2:6 title 'OBS medio BBin n\_veces=10000' w l,'LinearAutoSearch3.log' using 2:6 title 'OBS medio BLinAuto n\_veces=10000' w l"

histograma_tiempo_10000:
	@gnuplot -p -e "set xlabel 'Tamanio diccionario (N)'; set ylabel 'Tiempo (s)'; set key left top; set title 'Tiempos medios para BBin y BLin_Auto en n\_veces=10000'; plot 'BinarySearch3.log' using 2:4 title 'Tiempo medio BBin n\_veces=10000' w l,'LinearAutoSearch3.log' using 2:4 title 'Tiempo medio BLinAuto n\_veces=10000' w l"





