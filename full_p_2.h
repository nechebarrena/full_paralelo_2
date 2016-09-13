#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <omp.h>
#include <libconfig.h>
#include <stdbool.h>
#include <sys/stat.h>



///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
/* Definicion de parametros globales  */
/*
#define TAM_C 200
#define TAM_F 200
#define CB 1   // 0 para una condicion de borde tipo canal y 1 para una tipo FQS
#define leer_saturacion 0 // 0 para una saturacion seteada en el programa y 1 para cargar una saturacion desde un archivo
#define leer_K 0 // 0 para una permeabilidad seteada en el programa y 1 para cargar una permeabilidad desde un archivo

#define mu_w 1.0
#define mu_n 64.0

#define q_n 0.1
#define q_w 0.1
#define po 0.0 // el grafico esta con 0.5


#define error 0.0000000001  //0.0000000001 es lo que venia usando.
#define error_1 0.0000001

#define courant 0.1
#define PI 1.0

#define iteraciones 10000000

#define control 195
*/
#define cachito 0.0000000001

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
/* Definicion de variables globales                                              */

double *TAM_C_p;
double *TAM_F_p;
int *geo_p;
int *saturacion_seteo_p;
int *permeabilidad_seteo_p;
double *mu_w_p;
double *mu_n_p;
double *q_n_p;
double *q_w_p;
double *po_p;
double *error_p;
double *error_1_p;
double *courant_p;
double *iteraciones_p;
double *control_p;

int TAM_C;
int TAM_F;
int CB;
int saturacion_seteo;
int permeabilidad_seteo;
double mu_w;
double mu_n;
double q_n;
double q_w;
double po;
double error;
double error_1;
double courant;
int iteraciones;
int control;



double *presion;
double *presion_N;
double *presion_capilar;

double *saturacion;
double *saturacion_N;

double *K;
double *Q_W;
double *Q_N;

double *lambda_n;
double *lambda_w;

double *krn;
double *krw;

double *lambda_t;
double *lambda_d;

double *termino_presion_capilar;

double *lambda_t_1;
double *lambda_t_2;
double *lambda_t_3;
double *lambda_t_4;

double *lambda_d_1;
double *lambda_d_2;
double *lambda_d_3;
double *lambda_d_4;

double diferencia;

double *presion_n;
double *presion_w;

double *lambda_n_1;
double *lambda_n_2;
double *lambda_n_3;
double *lambda_n_4;

double *lambda_w_1;
double *lambda_w_2;
double *lambda_w_3;
double *lambda_w_4;

double *U_w_1;
double *U_w_2;
double *U_w_3;
double *U_w_4;

double *U_n_1;
double *U_n_2;
double *U_n_3;
double *U_n_4;

double *U_t_1;
double *U_t_2;
double *U_t_3;
double *U_t_4;

double *f_w;

double delta_t;

double *velocidad;

double *integral;
double *integral_total;


double *vel_1;
double *vel_2;
double *vel_3;
double *vel_4;

int bandera;
int np;
int np_1;



///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
/* Funciones del archivo funciones_p_2.c                                         */
void guardar_o(double *matriz,int num,int opcion);
void guardar_v(double *vector,int tam);
void guardar_1(double *matriz);
void guardar_2(double *matriz);
void inicializar_presion();
void inicializar_saturacion();
void inicializar_K();
void inicializar_Q_W();
void inicializar_Q_N();
void calcular_lambda_n();
void calcular_lambda_w();
void calcular_krw();
void calcular_krn();
void calcular_lambda_t();
void calcular_lambda_d();
void calcular_lambda_t_1_2_3_4_C();

void calcular_lambda_t_1_2_3_4_A();

void calcular_lambda_d_1_2_3_4();
void calcular_lambda_d_1_2_3_4_C();
void calcular_presion_capilar();
void calcular_termino_presion_capilar();
void calculo_diferencia();
void calcular_presion_n();
void calcular_presion_w();
void calcular_lambda_n_1_2_3_4();
void calcular_lambda_w_1_2_3_4();
void calcular_U_n_1_2_3_4();
void calcular_U_w_1_2_3_4();
void calcular_U_t_1_2_3_4();
void calcular_f_w();
void delta_tiempo();

void calculo_velocidad();
void alocar_variables();
void inicializar_variables();
void calcular_lambdas();
void calcular_velocidades();
void control_bandera(int columna);

void leer_o(double *matriz,int opcion);
int leer(void);
void copiar_parametros(void);
void liberar_variables();
void alocar_parametros();
void print();
void correr();
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
/*  Funciones del archivo calculo_presion.c                                      */
void calculo_presion();
void recinto_interno();
void borde_izquierdo();
void borde_derecho();
void borde_superior();
void borde_inferior();
void esquina_superior_izquierda();
void esquina_superior_derecha();
void esquina_inferior_izquierda();
void esquina_inferior_derecha();
void copiar();
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
/* Funciones del archivo calculo_saturacion                                      */
void calculo_saturacion();
void recinto_interno_s();
void borde_izquierdo_s();
void borde_derecho_s();
void borde_superior_s();
void borde_inferior_s();
void esquina_superior_izquierda_s();
void esquina_superior_derecha_s();
void esquina_inferior_izquierda_s();
void esquina_inferior_derecha_s();
void copiar_s();
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

