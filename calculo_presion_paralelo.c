#include "full_p_2.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calculo_presion_paralelo(){

recinto_interno();
borde_izquierdo();
borde_derecho();
borde_superior();
borde_inferior();
esquina_superior_izquierda();
esquina_superior_derecha();
esquina_inferior_izquierda();
esquina_inferior_derecha();
calculo_diferencia();
copiar();

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void recinto_interno(){
  
  
  int c=0;
  int f=0;
  
  double flujo_1=0.0;
  double flujo_2=0.0;
  double flujo_3=0.0;
  double flujo_4=0.0;
  double flujo_5=0.0;
  double suma_lambdas=0.0;
  
  
  omp_set_num_threads(np);
  #pragma omp parallel for private(c,f,flujo_1,flujo_2,flujo_3,flujo_4,flujo_5,suma_lambdas) 
  for(f=1 ; f<(TAM_F-1) ; f++){
     
    for(c=1 ; c<(TAM_C-1) ; c++){
      flujo_1 =  lambda_t_1[TAM_C*f + c]*presion[TAM_C*f + (c-1)] ;
      flujo_2 =  lambda_t_2[TAM_C*f + c]*presion[TAM_C*f + (c+1)] ;
      flujo_3 =  lambda_t_3[TAM_C*f + c]*presion[TAM_C*(f-1) + (c)] ;
      flujo_4 =  lambda_t_4[TAM_C*f + c]*presion[TAM_C*(f+1) + (c)] ;
      flujo_5 = termino_presion_capilar[TAM_C*f + c] + ( ( Q_W[TAM_C*f + c] + Q_N[TAM_C*f + c] )/(1.0*TAM_C) ) ;
      suma_lambdas= lambda_t_1[TAM_C*f + c] + lambda_t_2[TAM_C*f + c] + lambda_t_3[TAM_C*f + c] + lambda_t_4[TAM_C*f + c] + cachito ;
      presion_N[TAM_C*f + c]= (flujo_1 + flujo_2 + flujo_3 +  flujo_4 + flujo_5)/(suma_lambdas);
     
    }
  }
  
  
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void borde_izquierdo(){

/* c = 0*/  
  

  
  int c=0;
  int f=0;
  
  double flujo_1=0.0;
  double flujo_2=0.0;
  double flujo_3=0.0;
  double flujo_4=0.0;
  double flujo_5=0.0;
  double suma_lambdas=0.0;
  
  for(f=1 ; f<(TAM_F-1) ; f++){
    c=0;
      flujo_1 =  0.0;//lambda_t_1[TAM_C*f + c]*presion[TAM_C*f + (c-1)] ;
      flujo_2 =  lambda_t_2[TAM_C*f + c]*presion[TAM_C*f + (c+1)] ;
      flujo_3 =  lambda_t_3[TAM_C*f + c]*presion[TAM_C*(f-1) + (c)] ;
      flujo_4 =  lambda_t_4[TAM_C*f + c]*presion[TAM_C*(f+1) + (c)] ;
      flujo_5 = termino_presion_capilar[TAM_C*f + c] + ( ( Q_W[TAM_C*f + c] + Q_N[TAM_C*f + c] )/(1.0*TAM_C) ) ;
      suma_lambdas= lambda_t_1[TAM_C*f + c] + lambda_t_2[TAM_C*f + c] + lambda_t_3[TAM_C*f + c] + lambda_t_4[TAM_C*f + c] + cachito ;
      presion_N[TAM_C*f + c]= (flujo_1 + flujo_2 + flujo_3 +  flujo_4 + flujo_5)/(suma_lambdas);
    
  }  

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void borde_derecho(){
  
/* c= TAM_C -1*/


  
  int c=0;
  int f=0;
  
  double flujo_1=0.0;
  double flujo_2=0.0;
  double flujo_3=0.0;
  double flujo_4=0.0;
  double flujo_5=0.0;
  double suma_lambdas=0.0;
  
  for(f=1 ; f<(TAM_F-1) ; f++){
      c=TAM_C -1;
      flujo_1 =  lambda_t_1[TAM_C*f + c]*presion[TAM_C*f + (c-1)] ;
      flujo_2 =  0.0;//lambda_t_2[TAM_C*f + c]*presion[TAM_C*f + (c+1)] ;
      flujo_3 =  lambda_t_3[TAM_C*f + c]*presion[TAM_C*(f-1) + (c)] ;
      flujo_4 =  lambda_t_4[TAM_C*f + c]*presion[TAM_C*(f+1) + (c)] ;
      flujo_5 = termino_presion_capilar[TAM_C*f + c] + ( ( Q_W[TAM_C*f + c] + Q_N[TAM_C*f + c] )/(1.0*TAM_C) ) ;
      suma_lambdas= lambda_t_1[TAM_C*f + c] + lambda_t_2[TAM_C*f + c] + lambda_t_3[TAM_C*f + c] + lambda_t_4[TAM_C*f + c] + cachito;
      presion_N[TAM_C*f + c]= (flujo_1 + flujo_2 + flujo_3 +  flujo_4 + flujo_5)/(suma_lambdas);
    
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void borde_superior(){


/* f= 0*/  


  
  int c=0;
  int f=0;
  
  double flujo_1=0.0;
  double flujo_2=0.0;
  double flujo_3=0.0;
  double flujo_4=0.0;
  double flujo_5=0.0;
  double suma_lambdas=0.0;
  
  
    for(c=1 ; c<(TAM_C-1) ; c++){
      f=0;
      flujo_1 =  lambda_t_1[TAM_C*f + c]*presion[TAM_C*f + (c-1)] ;
      flujo_2 =  lambda_t_2[TAM_C*f + c]*presion[TAM_C*f + (c+1)] ;
      flujo_3 = 0.0;//  lambda_t_3[TAM_C*f + c]*presion[TAM_C*(f-1) + (c)] ;
      flujo_4 =  lambda_t_4[TAM_C*f + c]*presion[TAM_C*(f+1) + (c)] ;
      flujo_5 = termino_presion_capilar[TAM_C*f + c] + ( ( Q_W[TAM_C*f + c] + Q_N[TAM_C*f + c] )/(1.0*TAM_C) ) ;
      suma_lambdas= lambda_t_1[TAM_C*f + c] + lambda_t_2[TAM_C*f + c] + lambda_t_3[TAM_C*f + c] + lambda_t_4[TAM_C*f + c] + cachito;
      presion_N[TAM_C*f + c]= (flujo_1 + flujo_2 + flujo_3 +  flujo_4 + flujo_5)/(suma_lambdas);
    }
    

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void borde_inferior(){
  
  
/* f= TAM_F -1*/  
  int c=0;
  int f=0;
  
  double flujo_1=0.0;
  double flujo_2=0.0;
  double flujo_3=0.0;
  double flujo_4=0.0;
  double flujo_5=0.0;
  double suma_lambdas=0.0;
  
  
    for(c=1 ; c<(TAM_C-1) ; c++){
      f=TAM_F-1;
      flujo_1 =  lambda_t_1[TAM_C*f + c]*presion[TAM_C*f + (c-1)] ;
      flujo_2 =  lambda_t_2[TAM_C*f + c]*presion[TAM_C*f + (c+1)] ;
      flujo_3 =  lambda_t_3[TAM_C*f + c]*presion[TAM_C*(f-1) + (c)] ;
      flujo_4 =  0.0;//lambda_t_4[TAM_C*f + c]*presion[TAM_C*(f+1) + (c)] ;
      flujo_5 = termino_presion_capilar[TAM_C*f + c] + ( ( Q_W[TAM_C*f + c] + Q_N[TAM_C*f + c] )/(1.0*TAM_C) ) ;
      suma_lambdas= lambda_t_1[TAM_C*f + c] + lambda_t_2[TAM_C*f + c] + lambda_t_3[TAM_C*f + c] + lambda_t_4[TAM_C*f + c] + cachito;
      presion_N[TAM_C*f + c]= (flujo_1 + flujo_2 + flujo_3 +  flujo_4 + flujo_5)/(suma_lambdas);
    }
  
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void esquina_superior_izquierda(){
  
/* c=0 f=0*/
  int c=0;
  int f=0;
  
  double flujo_1=0.0;
  double flujo_2=0.0;
  double flujo_3=0.0;
  double flujo_4=0.0;
  double flujo_5=0.0;
  double suma_lambdas=0.0;
  
      c=0;
      f=0;
      flujo_1 = 0.0;// lambda_t_1[TAM_C*f + c]*presion[TAM_C*f + (c-1)] ;
      flujo_2 =  lambda_t_2[TAM_C*f + c]*presion[TAM_C*f + (c+1)] ;
      flujo_3 = 0.0;// lambda_t_3[TAM_C*f + c]*presion[TAM_C*(f-1) + (c)] ;
      flujo_4 =  lambda_t_4[TAM_C*f + c]*presion[TAM_C*(f+1) + (c)] ;
      flujo_5 = termino_presion_capilar[TAM_C*f + c] + ( ( Q_W[TAM_C*f + c] + Q_N[TAM_C*f + c] )/(1.0*TAM_C) ) ;
      suma_lambdas= lambda_t_1[TAM_C*f + c] + lambda_t_2[TAM_C*f + c] + lambda_t_3[TAM_C*f + c] + lambda_t_4[TAM_C*f + c] + cachito;
      presion_N[TAM_C*f + c]= (flujo_1 + flujo_2 + flujo_3 +  flujo_4 + flujo_5)/(suma_lambdas);
      //printf("\n Presion ==> flujo 2=%f      flujo 4=%f     flujo 5=%f\n",lambda_t_2[TAM_C*f + c]*(presion[TAM_C*f + (c+1)]-presion[TAM_C*f + (c)]),lambda_t_2[TAM_C*f + c]*(presion[TAM_C*(f+1) + (c)]-presion[TAM_C*f + (c)]),flujo_5);

  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void esquina_superior_derecha(){
  
/* c=TAM_C -1 f=0*/

  int c=0;
  int f=0;
  
  double flujo_1=0.0;
  double flujo_2=0.0;
  double flujo_3=0.0;
  double flujo_4=0.0;
  double flujo_5=0.0;
  double suma_lambdas=0.0;
  
      c=TAM_C-1;
      f=0;
      flujo_1 =  lambda_t_1[TAM_C*f + c]*presion[TAM_C*f + (c-1)] ;
      flujo_2 = 0.0;// lambda_t_2[TAM_C*f + c]*presion[TAM_C*f + (c+1)] ;
      flujo_3 = 0.0;//lambda_t_3[TAM_C*f + c]*presion[TAM_C*(f-1) + (c)] ;
      flujo_4 =  lambda_t_4[TAM_C*f + c]*presion[TAM_C*(f+1) + (c)] ;
      flujo_5 = termino_presion_capilar[TAM_C*f + c] + ( ( Q_W[TAM_C*f + c] + Q_N[TAM_C*f + c] )/(1.0*TAM_C) ) ;
      suma_lambdas= lambda_t_1[TAM_C*f + c] + lambda_t_2[TAM_C*f + c] + lambda_t_3[TAM_C*f + c] + lambda_t_4[TAM_C*f + c] + cachito;
      presion_N[TAM_C*f + c]= (flujo_1 + flujo_2 + flujo_3 +  flujo_4 + flujo_5)/(suma_lambdas);

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void esquina_inferior_izquierda(){

/* c=0 f=TAM_F-1*/

  int c=0;
  int f=0;
  
  double flujo_1=0.0;
  double flujo_2=0.0;
  double flujo_3=0.0;
  double flujo_4=0.0;
  double flujo_5=0.0;
  double suma_lambdas=0.0;
  
      c=0;
      f=TAM_F-1;
      flujo_1 = 0.0;// lambda_t_1[TAM_C*f + c]*presion[TAM_C*f + (c-1)] ;
      flujo_2 =  lambda_t_2[TAM_C*f + c]*presion[TAM_C*f + (c+1)] ;
      flujo_3 =  lambda_t_3[TAM_C*f + c]*presion[TAM_C*(f-1) + (c)] ;
      flujo_4 =  0.0;//lambda_t_4[TAM_C*f + c]*presion[TAM_C*(f+1) + (c)] ;
      flujo_5 = termino_presion_capilar[TAM_C*f + c] + ( ( Q_W[TAM_C*f + c] + Q_N[TAM_C*f + c] )/(1.0*TAM_C) ) ;
      suma_lambdas= lambda_t_1[TAM_C*f + c] + lambda_t_2[TAM_C*f + c] + lambda_t_3[TAM_C*f + c] + lambda_t_4[TAM_C*f + c] + cachito;
      presion_N[TAM_C*f + c]= (flujo_1 + flujo_2 + flujo_3 +  flujo_4 + flujo_5)/(suma_lambdas);

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void esquina_inferior_derecha(){
  
  
/* c= TAM_C -1 f=TAM_F-1*/

  int c=0;
  int f=0;
  
  double flujo_1=0.0;
  double flujo_2=0.0;
  double flujo_3=0.0;
  double flujo_4=0.0;
  double flujo_5=0.0;
  double suma_lambdas=0.0;
  
      c=TAM_C-1;
      f=TAM_F-1;
      flujo_1 =  lambda_t_1[TAM_C*f + c]*presion[TAM_C*f + (c-1)] ;
      flujo_2 = 0.0;//  lambda_t_2[TAM_C*f + c]*presion[TAM_C*f + (c+1)] ;
      flujo_3 =  lambda_t_3[TAM_C*f + c]*presion[TAM_C*(f-1) + (c)] ;
      flujo_4 =  0.0;//lambda_t_4[TAM_C*f + c]*presion[TAM_C*(f+1) + (c)] ;
      flujo_5 = termino_presion_capilar[TAM_C*f + c] + ( ( Q_W[TAM_C*f + c] + Q_N[TAM_C*f + c] )/(1.0*TAM_C)) ;
      suma_lambdas= lambda_t_1[TAM_C*f + c] + lambda_t_2[TAM_C*f + c] + lambda_t_3[TAM_C*f + c] + lambda_t_4[TAM_C*f + c] + cachito;
      presion_N[TAM_C*f + c]= (flujo_1 + flujo_2 + flujo_3 +  flujo_4 + flujo_5)/(suma_lambdas);

  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void copiar(){

  int c=0;
  int f=0;
  
  omp_set_num_threads(np_1);
  #pragma omp parallel for private(c,f) 
  for(f=0 ; f<(TAM_F) ; f++){
    for(c=0 ; c<(TAM_C) ; c++){
       presion[TAM_C*f + c]= presion_N[TAM_C*f + c];

    }
  }
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
