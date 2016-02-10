lista = full_p_2.c funciones_p_2.c calculo_presion_paralelo.c calculo_saturacion.c full_p_2.h
all: $(lista)
	gcc $(lista) -O3  -lm -o programa_p_2 -fopenmp
	#gcc $(lista) -O3 -lm -o programa_p_2

clean:
	rm -f *.o


############################################################################## calculo_presion_paralelo.c
##############################################################################
# Compila con gcc de GNU
##############################################################################
##############################################################################

