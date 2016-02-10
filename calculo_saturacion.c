#include "full_p_2.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calculo_saturacion(){
  int k=0;

  if(CB==1){
  recinto_interno_s();
  borde_izquierdo_s();
  borde_derecho_s();
  borde_superior_s();
  borde_inferior_s();
  //esquina_superior_izquierda_s();
  saturacion_N[TAM_C*0 + (0)]=1.0;
  esquina_superior_derecha_s();
  esquina_inferior_izquierda_s();
  esquina_inferior_derecha_s();
  }
  else if(CB==0){
  recinto_interno_s(); 
  borde_derecho_s();
  borde_superior_s();
  borde_inferior_s();
  esquina_superior_derecha_s();
  esquina_inferior_derecha_s();
  
  for(k=0 ; k< TAM_F ; k++){
  saturacion_N[TAM_C*k + 0]=1.0;  
  }
  
  
  /*
  borde_izquierdo_s();
  esquina_inferior_izquierda_s();
  esquina_superior_izquierda_s();
  */ 
  }
 
  copiar_s();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void recinto_interno_s(){

  int c=0;
  int f=0;
  
  double f_w_1=0.0;
  double f_w_2=0.0;
  double f_w_3=0.0;
  double f_w_4=0.0;
  
  double lambda_n_1_a=0.0;
  double lambda_n_2_a=0.0;
  double lambda_n_3_a=0.0;
  double lambda_n_4_a=0.0;
  
  double gama=0.0;
  double epsilon=0.0;
  
  for(f=1 ; f<(TAM_F-1) ; f++){
    for(c=1 ; c<(TAM_C-1) ; c++){
     
      if(U_t_1[TAM_C*f + c] < 0.0){ //si es negativa va para "adelante"
	f_w_1=f_w[TAM_C*f + (c-1)] ;
	lambda_n_1_a=lambda_n_1[TAM_C*f + (c-1)] ;
      }
      else if(U_t_1[TAM_C*f + c] > 0.0){ // si es positiva va para "atras"
        f_w_1=f_w[TAM_C*f + (c)] ;
	lambda_n_1_a=lambda_n_1[TAM_C*f + (c)] ;
      }
      else if(U_t_1[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_1=0.0 ;
	lambda_n_1_a=0.0 ;
      }
      
           
      
      if(U_t_3[TAM_C*f + c] < 0.0){ //si es negativa va para "adelante"
	f_w_3=f_w[TAM_C*(f-1) + (c)] ;
	lambda_n_3_a=lambda_n_3[TAM_C*(f-1) + (c)] ;
      }
      else if(U_t_3[TAM_C*f + c] > 0.0){ // si es positiva va para "atras"
        f_w_3=f_w[TAM_C*f + (c)] ;
	lambda_n_3_a=lambda_n_3[TAM_C*(f) + (c)] ;
      }
      else if(U_t_3[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_3=0.0 ;
	lambda_n_3_a=0.0;
      }
      
      
      if(U_t_2[TAM_C*f + (c)] > 0.0  ){ //si es positiva va para "adelante"
        f_w_2=f_w[TAM_C*f + (c)] ;
	lambda_n_2_a=lambda_n_2[TAM_C*(f) + (c)] ;
      }
      else if(U_t_2[TAM_C*f + (c)] < 0.0){ //si es negativa va para "atras"
	f_w_2=f_w[TAM_C*f + (c+1)] ;
	lambda_n_2_a=lambda_n_2[TAM_C*(f) + (c+1)] ;
      }
      else if(U_t_2[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_2=0.0 ;
	lambda_n_2_a=0.0 ;
      }
      
      
      if(U_t_4[TAM_C*f + (c)] > 0.0  ){ //si es positiva va para "adelante"
        f_w_4=f_w[TAM_C*f + (c)] ;
	lambda_n_4_a=lambda_n_4[TAM_C*(f) + (c)] ;
      }
      else if(U_t_4[TAM_C*f + (c)] < 0.0){ //si es negativa va para "atras"
	f_w_4=f_w[TAM_C*(f+1) + (c)] ;
	lambda_n_4_a=lambda_n_4[TAM_C*(f+1) + (c)] ;
      }
      else if(U_t_4[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_4=0.0 ;
	lambda_n_4_a=0.0;
      }
      

      
      epsilon=  f_w_1*U_t_1[TAM_C*f + (c)] + f_w_2*U_t_2[TAM_C*f + (c)] + f_w_3*U_t_3[TAM_C*f + (c)] + f_w_4*U_t_4[TAM_C*f + (c)] ;
      
      
      /*
      gama= f_w_1*lambda_n_1[TAM_C*f + (c)]*(presion_capilar[TAM_C*f + (c-1)] - presion_capilar[TAM_C*f + (c)]) 
      + f_w_2*lambda_n_2[TAM_C*f + (c)]*(presion_capilar[TAM_C*f + (c+1)] - presion_capilar[TAM_C*f + (c)])
      + f_w_3*lambda_n_3[TAM_C*f + (c)]*(presion_capilar[TAM_C*(f-1) + (c)] - presion_capilar[TAM_C*f + (c)])
      + f_w_4*lambda_n_4[TAM_C*f + (c)]*(presion_capilar[TAM_C*(f+1) + (c)] - presion_capilar[TAM_C*f + (c)]);
      */
      
      gama= f_w_1*lambda_n_1_a*(presion_capilar[TAM_C*f + (c-1)] - presion_capilar[TAM_C*f + (c)]) 
      + f_w_2*lambda_n_2_a*(presion_capilar[TAM_C*f + (c+1)] - presion_capilar[TAM_C*f + (c)])
      + f_w_3*lambda_n_3_a*(presion_capilar[TAM_C*(f-1) + (c)] - presion_capilar[TAM_C*f + (c)])
      + f_w_4*lambda_n_4_a*(presion_capilar[TAM_C*(f+1) + (c)] - presion_capilar[TAM_C*f + (c)]);

      saturacion_N[TAM_C*f + (c)] = saturacion[TAM_C*f + (c)] + 1.0*courant*( ((-1.0*epsilon -1.0*gama)/(1.0*TAM_C)) + ( (Q_W[TAM_C*f + (c)])/(1.0*TAM_C*TAM_C) ));       
      
      //printf("\n el termino de presion capilar es =%f y el termino de la velocidad es=%f \n",gama,epsilon);
   
      
      
      
      
    }
  }
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void borde_izquierdo_s(){

  int c=0;
  int f=0;
  
  double f_w_1=0.0;
  double f_w_2=0.0;
  double f_w_3=0.0;
  double f_w_4=0.0;
  
  double f_1=0.0;
  double f_2=0.0;
  double f_3=0.0;
  double f_4=0.0;
  
  double gama=0.0;
  double epsilon=0.0;
  
  for(f=1 ; f<(TAM_F-1) ; f++){
    c=0;
     
     f_w_1=0.0;
      
      
      
      if(U_t_3[TAM_C*f + c] < 0.0){ //si es negativa va para "adelante"
	f_w_3=f_w[TAM_C*(f-1) + (c)] ;
      }
      else if(U_t_3[TAM_C*f + c] > 0.0){ // si es positiva va para "atras"
        f_w_3=f_w[TAM_C*f + (c)] ;
      }
      else if(U_t_3[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_3=0.0 ;
      }
      
      
      if(U_t_2[TAM_C*f + (c)] > 0.0  ){ //si es positiva va para "adelante"
        f_w_2=f_w[TAM_C*f + (c)] ;
      }
      else if(U_t_2[TAM_C*f + (c)] < 0.0){ //si es negativa va para "atras"
	f_w_2=f_w[TAM_C*f + (c+1)] ;
      }
      else if(U_t_2[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_2=0.0 ;
      }
      
      if(U_t_4[TAM_C*f + (c)] > 0.0  ){ //si es positiva va para "adelante"
        f_w_4=f_w[TAM_C*f + (c)] ;
      }
      else if(U_t_4[TAM_C*f + (c)] < 0.0){ //si es negativa va para "atras"
	f_w_4=f_w[TAM_C*(f+1) + (c)] ;
      }
      else if(U_t_4[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_4=0.0 ;
      }

      
      epsilon=  f_w_1*U_t_1[TAM_C*f + (c)] + f_w_2*U_t_2[TAM_C*f + (c)] + f_w_3*U_t_3[TAM_C*f + (c)] + f_w_4*U_t_4[TAM_C*f + (c)] ;
      
      gama= f_w_1*lambda_n_1[TAM_C*f + (c)]*(presion_capilar[TAM_C*f + (c-1)] - presion_capilar[TAM_C*f + (c)]) 
      + f_w_2*lambda_n_2[TAM_C*f + (c)]*(presion_capilar[TAM_C*f + (c+1)] - presion_capilar[TAM_C*f + (c)])
      + f_w_3*lambda_n_3[TAM_C*f + (c)]*(presion_capilar[TAM_C*(f-1) + (c)] - presion_capilar[TAM_C*f + (c)])
      + f_w_4*lambda_n_4[TAM_C*f + (c)]*(presion_capilar[TAM_C*(f+1) + (c)] - presion_capilar[TAM_C*f + (c)]);
      
      
      saturacion_N[TAM_C*f + (c)] = saturacion[TAM_C*f + (c)] + 1.0*courant*( ((-1.0*epsilon -1.0*gama)/(1.0*TAM_C)) + ( (Q_W[TAM_C*f + (c)])/(1.0*TAM_C*TAM_C) ));       
  
 
      
      
  }
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void borde_derecho_s(){

  int c=0;
  int f=0;
  
  double f_w_1=0.0;
  double f_w_2=0.0;
  double f_w_3=0.0;
  double f_w_4=0.0;
  
  double gama=0.0;
  double epsilon=0.0;
  
  for(f=1 ; f<(TAM_F-1) ; f++){
    c=TAM_C-1;
     
      if(U_t_1[TAM_C*f + c] < 0.0){ //si es negativa va para "adelante"
	f_w_1=f_w[TAM_C*f + (c-1)] ;
      }
      else if(U_t_1[TAM_C*f + c] > 0.0){ // si es positiva va para "atras"
        f_w_1=f_w[TAM_C*f + (c)] ;
      }
      else if(U_t_1[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_1=0.0 ;
      }
      
      
      
      if(U_t_3[TAM_C*f + c] < 0.0){ //si es negativa va para "adelante"
	f_w_3=f_w[TAM_C*(f-1) + (c)] ;
      }
      else if(U_t_3[TAM_C*f + c] > 0.0){ // si es positiva va para "atras"
        f_w_3=f_w[TAM_C*f + (c)] ;
      }
      else if(U_t_3[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_3=0.0 ;
      }
      
      
     f_w_2=0.0;
      
      
      if(U_t_4[TAM_C*f + (c)] > 0.0  ){ //si es positiva va para "adelante"
        f_w_4=f_w[TAM_C*f + (c)] ;
      }
      else if(U_t_4[TAM_C*f + (c)] < 0.0){ //si es negativa va para "atras"
	f_w_4=f_w[TAM_C*(f+1) + (c)] ;
      }
      else if(U_t_4[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_4=0.0 ;
      }
 
      
      epsilon=  f_w_1*U_t_1[TAM_C*f + (c)] + f_w_2*U_t_2[TAM_C*f + (c)] + f_w_3*U_t_3[TAM_C*f + (c)] + f_w_4*U_t_4[TAM_C*f + (c)] ;
     
      gama= f_w_1*lambda_n_1[TAM_C*f + (c)]*(presion_capilar[TAM_C*f + (c-1)] - presion_capilar[TAM_C*f + (c)]) 
      + f_w_2*lambda_n_2[TAM_C*f + (c)]*(presion_capilar[TAM_C*f + (c+1)] - presion_capilar[TAM_C*f + (c)])
      + f_w_3*lambda_n_3[TAM_C*f + (c)]*(presion_capilar[TAM_C*(f-1) + (c)] - presion_capilar[TAM_C*f + (c)])
      + f_w_4*lambda_n_4[TAM_C*f + (c)]*(presion_capilar[TAM_C*(f+1) + (c)] - presion_capilar[TAM_C*f + (c)]);

      saturacion_N[TAM_C*f + (c)] = saturacion[TAM_C*f + (c)] + 1.0*courant*( ((-1.0*epsilon -1.0*gama)/(1.0*TAM_C)) + ( (Q_W[TAM_C*f + (c)])/(1.0*TAM_C*TAM_C) ));       
      
    
  }
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void borde_superior_s(){

  int c=0;
  int f=0;
  
  double f_w_1=0.0;
  double f_w_2=0.0;
  double f_w_3=0.0;
  double f_w_4=0.0;
  
  double f_1=0.0;
  double f_2=0.0;
  double f_3=0.0;
  double f_4=0.0;
  
  double gama=0.0;
  double epsilon=0.0;
  
  
    for(c=1 ; c<(TAM_C-1) ; c++){
      f=0;
      
      if(U_t_1[TAM_C*f + c] < 0.0){ //si es negativa va para "adelante"
	f_w_1=f_w[TAM_C*f + (c-1)] ;
      }
      else if(U_t_1[TAM_C*f + c] > 0.0){ // si es positiva va para "atras"
        f_w_1=f_w[TAM_C*f + (c)] ;
      }
      else if(U_t_1[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_1=0.0 ;
      }
      
      
      
      f_w_3=0.0;

      
      
      if(U_t_2[TAM_C*f + (c)] > 0.0  ){ //si es positiva va para "adelante"
        f_w_2=f_w[TAM_C*f + (c)] ;
      }
      else if(U_t_2[TAM_C*f + (c)] < 0.0){ //si es negativa va para "atras"
	f_w_2=f_w[TAM_C*f + (c+1)] ;
      }
      else if(U_t_2[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_2=0.0 ;
      }
      
      if(U_t_4[TAM_C*f + (c)] > 0.0  ){ //si es positiva va para "adelante"
        f_w_4=f_w[TAM_C*f + (c)] ;
      }
      else if(U_t_4[TAM_C*f + (c)] < 0.0){ //si es negativa va para "atras"
	f_w_4=f_w[TAM_C*(f+1) + (c)] ;
      }
      else if(U_t_4[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_4=0.0 ;
      }

      
      epsilon=  f_w_1*U_t_1[TAM_C*f + (c)] + f_w_2*U_t_2[TAM_C*f + (c)] + f_w_3*U_t_3[TAM_C*f + (c)] + f_w_4*U_t_4[TAM_C*f + (c)] ;
     
      gama= f_w_1*lambda_n_1[TAM_C*f + (c)]*(presion_capilar[TAM_C*f + (c-1)] - presion_capilar[TAM_C*f + (c)]) 
      + f_w_2*lambda_n_2[TAM_C*f + (c)]*(presion_capilar[TAM_C*f + (c+1)] - presion_capilar[TAM_C*f + (c)])
      + f_w_3*lambda_n_3[TAM_C*f + (c)]*(presion_capilar[TAM_C*(f-1) + (c)] - presion_capilar[TAM_C*f + (c)])
      + f_w_4*lambda_n_4[TAM_C*f + (c)]*(presion_capilar[TAM_C*(f+1) + (c)] - presion_capilar[TAM_C*f + (c)]);

      saturacion_N[TAM_C*f + (c)] = saturacion[TAM_C*f + (c)] + 1.0*courant*( ((-1.0*epsilon -1.0*gama)/(1.0*TAM_C)) + ( (Q_W[TAM_C*f + (c)])/(1.0*TAM_C*TAM_C) ));       
      

    
  }
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void borde_inferior_s(){

  int c=0;
  int f=0;
  
  double f_w_1=0.0;
  double f_w_2=0.0;
  double f_w_3=0.0;
  double f_w_4=0.0;
  
  double gama=0.0;
  double epsilon=0.0;
  
  
    for(c=1 ; c<(TAM_C-1) ; c++){
      f=TAM_F-1;
     
      if(U_t_1[TAM_C*f + c] < 0.0){ //si es negativa va para "adelante"
	f_w_1=f_w[TAM_C*f + (c-1)] ;
      }
      else if(U_t_1[TAM_C*f + c] > 0.0){ // si es positiva va para "atras"
        f_w_1=f_w[TAM_C*f + (c)] ;
      }
      else if(U_t_1[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_1=0.0 ;
      }
      
      
      
      if(U_t_3[TAM_C*f + c] < 0.0){ //si es negativa va para "adelante"
	f_w_3=f_w[TAM_C*(f-1) + (c)] ;
      }
      else if(U_t_3[TAM_C*f + c] > 0.0){ // si es positiva va para "atras"
        f_w_3=f_w[TAM_C*f + (c)] ;
      }
      else if(U_t_3[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_3=0.0 ;
      }
      
      
      if(U_t_2[TAM_C*f + (c)] > 0.0  ){ //si es positiva va para "adelante"
        f_w_2=f_w[TAM_C*f + (c)] ;
      }
      else if(U_t_2[TAM_C*f + (c)] < 0.0){ //si es negativa va para "atras"
	f_w_2=f_w[TAM_C*f + (c+1)] ;
      }
      else if(U_t_2[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_2=0.0 ;
      }
      
     f_w_4=0.0;
      

      
      epsilon=  f_w_1*U_t_1[TAM_C*f + (c)] + f_w_2*U_t_2[TAM_C*f + (c)] + f_w_3*U_t_3[TAM_C*f + (c)] + f_w_4*U_t_4[TAM_C*f + (c)] ;
      
      gama= f_w_1*lambda_n_1[TAM_C*f + (c)]*(presion_capilar[TAM_C*f + (c-1)] - presion_capilar[TAM_C*f + (c)]) 
      + f_w_2*lambda_n_2[TAM_C*f + (c)]*(presion_capilar[TAM_C*f + (c+1)] - presion_capilar[TAM_C*f + (c)])
      + f_w_3*lambda_n_3[TAM_C*f + (c)]*(presion_capilar[TAM_C*(f-1) + (c)] - presion_capilar[TAM_C*f + (c)])
      + f_w_4*lambda_n_4[TAM_C*f + (c)]*(presion_capilar[TAM_C*(f+1) + (c)] - presion_capilar[TAM_C*f + (c)]);

      saturacion_N[TAM_C*f + (c)] = saturacion[TAM_C*f + (c)] + 1.0*courant*( ((-1.0*epsilon -1.0*gama)/(1.0*TAM_C)) + ( (Q_W[TAM_C*f + (c)])/(1.0*TAM_C*TAM_C) ));       
      
    
  }
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void esquina_superior_izquierda_s(){

  int c=0;
  int f=0;
  
  double f_w_1=0.0;
  double f_w_2=0.0;
  double f_w_3=0.0;
  double f_w_4=0.0;
  
  double f_1=0.0;
  double f_2=0.0;
  double f_3=0.0;
  double f_4=0.0;
  
  double gama=0.0;
  double epsilon=0.0;
  
      c=0;
      f=0;
     
     f_w_1=0.0;
     
     f_w_3=0.0;

      
      
      if(U_t_2[TAM_C*f + (c)] > 0.0  ){ //si es positiva va para "adelante"
        f_w_2=f_w[TAM_C*f + (c)] ;
      }
      else if(U_t_2[TAM_C*f + (c)] < 0.0){ //si es negativa va para "atras"
	f_w_2=f_w[TAM_C*f + (c+1)] ;
      }
      else if(U_t_2[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_2=0.0 ;
      }
      
      if(U_t_4[TAM_C*f + (c)] > 0.0  ){ //si es positiva va para "adelante"
        f_w_4=f_w[TAM_C*f + (c)] ;
      }
      else if(U_t_4[TAM_C*f + (c)] < 0.0){ //si es negativa va para "atras"
	f_w_4=f_w[TAM_C*(f+1) + (c)] ;
      }
      else if(U_t_4[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_4=0.0 ;
      }

      
      epsilon=  f_w_1*U_t_1[TAM_C*f + (c)] + f_w_2*U_t_2[TAM_C*f + (c)] + f_w_3*U_t_3[TAM_C*f + (c)] + f_w_4*U_t_4[TAM_C*f + (c)] ;
      
      gama= f_w_1*lambda_n_1[TAM_C*f + (c)]*(presion_capilar[TAM_C*f + (c-1)] - presion_capilar[TAM_C*f + (c)]) 
      + f_w_2*lambda_n_2[TAM_C*f + (c)]*(presion_capilar[TAM_C*f + (c+1)] - presion_capilar[TAM_C*f + (c)])
      + f_w_3*lambda_n_3[TAM_C*f + (c)]*(presion_capilar[TAM_C*(f-1) + (c)] - presion_capilar[TAM_C*f + (c)])
      + f_w_4*lambda_n_4[TAM_C*f + (c)]*(presion_capilar[TAM_C*(f+1) + (c)] - presion_capilar[TAM_C*f + (c)]);
      
      saturacion_N[TAM_C*f + (c)] = saturacion[TAM_C*f + (c)] + 1.0*courant*( ((-1.0*epsilon -1.0*gama)/(1.0*TAM_C)) + ( (Q_W[TAM_C*f + (c)])/(1.0*TAM_C*TAM_C) ));       

      
      //printf("\n saturacion=%f epsilon=%f gama=%f\n",saturacion_N[TAM_C*f + (c)],epsilon,gama);

  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void esquina_superior_derecha_s(){

  int c=0;
  int f=0;
  
  double f_w_1=0.0;
  double f_w_2=0.0;
  double f_w_3=0.0;
  double f_w_4=0.0;
  
  double gama=0.0;
  double epsilon=0.0;
  
      c=TAM_C -1;
      f=0;
     
      if(U_t_1[TAM_C*f + c] < 0.0){ //si es negativa va para "adelante"
	f_w_1=f_w[TAM_C*f + (c-1)] ;
      }
      else if(U_t_1[TAM_C*f + c] > 0.0){ // si es positiva va para "atras"
        f_w_1=f_w[TAM_C*f + (c)] ;
      }
      else if(U_t_1[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_1=0.0 ;
      }
      
      
      
      f_w_3=0.0;

      
      
      f_w_2=0.0;
      
      
      if(U_t_4[TAM_C*f + (c)] > 0.0  ){ //si es positiva va para "adelante"
        f_w_4=f_w[TAM_C*f + (c)] ;
      }
      else if(U_t_4[TAM_C*f + (c)] < 0.0){ //si es negativa va para "atras"
	f_w_4=f_w[TAM_C*(f+1) + (c)] ;
      }
      else if(U_t_4[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_4=0.0 ;
      }

      
      
      epsilon=  f_w_1*U_t_1[TAM_C*f + (c)] + f_w_2*U_t_2[TAM_C*f + (c)] + f_w_3*U_t_3[TAM_C*f + (c)] + f_w_4*U_t_4[TAM_C*f + (c)] ;
      
      gama= f_w_1*lambda_n_1[TAM_C*f + (c)]*(presion_capilar[TAM_C*f + (c-1)] - presion_capilar[TAM_C*f + (c)]) 
      + f_w_2*lambda_n_2[TAM_C*f + (c)]*(presion_capilar[TAM_C*f + (c+1)] - presion_capilar[TAM_C*f + (c)])
      + f_w_3*lambda_n_3[TAM_C*f + (c)]*(presion_capilar[TAM_C*(f-1) + (c)] - presion_capilar[TAM_C*f + (c)])
      + f_w_4*lambda_n_4[TAM_C*f + (c)]*(presion_capilar[TAM_C*(f+1) + (c)] - presion_capilar[TAM_C*f + (c)]);

      saturacion_N[TAM_C*f + (c)] = saturacion[TAM_C*f + (c)] + 1.0*courant*( ((-1.0*epsilon -1.0*gama)/(1.0*TAM_C)) + ( (Q_W[TAM_C*f + (c)])/(1.0*TAM_C*TAM_C) ));       
      

  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void esquina_inferior_izquierda_s(){

  int c=0;
  int f=0;
  
  double f_w_1=0.0;
  double f_w_2=0.0;
  double f_w_3=0.0;
  double f_w_4=0.0;
  
  double gama=0.0;
  double epsilon=0.0;
  
      c=0;
      f=TAM_F-1;
  
      f_w_1=0.0;
      
      
      
      if(U_t_3[TAM_C*f + c] < 0.0){ //si es negativa va para "adelante"
	f_w_3=f_w[TAM_C*(f-1) + (c)] ;
      }
      else if(U_t_3[TAM_C*f + c] > 0.0){ // si es positiva va para "atras"
        f_w_3=f_w[TAM_C*f + (c)] ;
      }
      else if(U_t_3[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_3=0.0 ;
      }
      
      
      if(U_t_2[TAM_C*f + (c)] > 0.0  ){ //si es positiva va para "adelante"
        f_w_2=f_w[TAM_C*f + (c)] ;
      }
      else if(U_t_2[TAM_C*f + (c)] < 0.0){ //si es negativa va para "atras"
	f_w_2=f_w[TAM_C*f + (c+1)] ;
      }
      else if(U_t_2[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_2=0.0 ;
      }
      
     f_w_4=0.0;
      

      
      epsilon=  f_w_1*U_t_1[TAM_C*f + (c)] + f_w_2*U_t_2[TAM_C*f + (c)] + f_w_3*U_t_3[TAM_C*f + (c)] + f_w_4*U_t_4[TAM_C*f + (c)] ;
     
      gama= f_w_1*lambda_n_1[TAM_C*f + (c)]*(presion_capilar[TAM_C*f + (c-1)] - presion_capilar[TAM_C*f + (c)]) 
      + f_w_2*lambda_n_2[TAM_C*f + (c)]*(presion_capilar[TAM_C*f + (c+1)] - presion_capilar[TAM_C*f + (c)])
      + f_w_3*lambda_n_3[TAM_C*f + (c)]*(presion_capilar[TAM_C*(f-1) + (c)] - presion_capilar[TAM_C*f + (c)])
      + f_w_4*lambda_n_4[TAM_C*f + (c)]*(presion_capilar[TAM_C*(f+1) + (c)] - presion_capilar[TAM_C*f + (c)]);

      saturacion_N[TAM_C*f + (c)] = saturacion[TAM_C*f + (c)] + 1.0*courant*( ((-1.0*epsilon -1.0*gama)/(1.0*TAM_C)) + ( (Q_W[TAM_C*f + (c)])/(1.0*TAM_C*TAM_C) ));       
      

  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void esquina_inferior_derecha_s(){

  int c=0;
  int f=0;
  
  double f_w_1=0.0;
  double f_w_2=0.0;
  double f_w_3=0.0;
  double f_w_4=0.0;
  
  double gama=0.0;
  double epsilon=0.0;
  
      c=TAM_C -1;
      f=TAM_F -1;
     
      if(U_t_1[TAM_C*f + c] < 0.0){ //si es negativa va para "adelante"
	f_w_1=f_w[TAM_C*f + (c-1)] ;
      }
      else if(U_t_1[TAM_C*f + c] > 0.0){ // si es positiva va para "atras"
        f_w_1=f_w[TAM_C*f + (c)] ;
      }
      else if(U_t_1[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_1=0.0 ;
      }
      
      
      
      if(U_t_3[TAM_C*f + c] < 0.0){ //si es negativa va para "adelante"
	f_w_3=f_w[TAM_C*(f-1) + (c)] ;
      }
      else if(U_t_3[TAM_C*f + c] > 0.0){ // si es positiva va para "atras"
        f_w_3=f_w[TAM_C*f + (c)] ;
      }
      else if(U_t_3[TAM_C*f + c] == 0.0){ // si es cero hago cero la funcion
        f_w_3=0.0 ;
      }
      
      
     f_w_2=0.0;
     
     f_w_4=0.0;
      

      
      
      
      epsilon=  f_w_1*U_t_1[TAM_C*f + (c)] + f_w_2*U_t_2[TAM_C*f + (c)] + f_w_3*U_t_3[TAM_C*f + (c)] + f_w_4*U_t_4[TAM_C*f + (c)] ;
      
      gama= f_w_1*lambda_n_1[TAM_C*f + (c)]*(presion_capilar[TAM_C*f + (c-1)] - presion_capilar[TAM_C*f + (c)]) 
      + f_w_2*lambda_n_2[TAM_C*f + (c)]*(presion_capilar[TAM_C*f + (c+1)] - presion_capilar[TAM_C*f + (c)])
      + f_w_3*lambda_n_3[TAM_C*f + (c)]*(presion_capilar[TAM_C*(f-1) + (c)] - presion_capilar[TAM_C*f + (c)])
      + f_w_4*lambda_n_4[TAM_C*f + (c)]*(presion_capilar[TAM_C*(f+1) + (c)] - presion_capilar[TAM_C*f + (c)]);

      saturacion_N[TAM_C*f + (c)] = saturacion[TAM_C*f + (c)] + 1.0*courant*( ((-1.0*epsilon -1.0*gama)/(1.0*TAM_C)) + ( (Q_W[TAM_C*f + (c)])/(1.0*TAM_C*TAM_C) ));       
      

  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void copiar_s(){

  int c=0;
  int f=0;
  

  
  for(f=0 ; f<(TAM_F) ; f++){
    for(c=0 ; c<(TAM_C) ; c++){
       saturacion[TAM_C*f + c]= saturacion_N[TAM_C*f + c];
    }
  }
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
