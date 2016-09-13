#include "full_p_2.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void guardar_o(double *matriz,int num,int opcion){    // la funcion guardar graba los datos de matriz en un archivo llamado salia-1.dat
  
  if(num==2){
    num=0;
  }
  else{
    num=num/4000;
  }
  FILE *archivo;   // creo el archivo
  char nombre[12];
  char ext[12]=".dat";
  char ruta[22];
  if(opcion==1){
  strncpy(ruta, "./saturacion/", 22);
  }
  if(opcion==2){
  strncpy(ruta, "./presion_1/", 22);
  }
  if(opcion==3){
  strncpy(ruta, "./presion_2/", 22);
  }
  
  sprintf(nombre,"%d",num);
  int largo = strlen(nombre) ;
  strcat(nombre,ext);
  strcat(ruta,nombre);
  //printf("\n  el tam del string es =%i \n",largo);
 
  archivo= fopen(ruta,"w+"); //abro el archivo y le asigno el nombre
  int f=0; 
  int c=0;
  
  for(f=0 ; f<TAM_F ; f++){ //barro todas las filas de la matriz
    for(c=0 ; c<TAM_C ; c++){ //barro todas las columnas de la matriz
      fprintf(archivo,"%.15f	",matriz[TAM_C*f + c]); //guardo un dato y le doy enter
    }
      fprintf(archivo,"\n"); //cuando termino una fila le doy un enter
  }
  
  
  fclose(archivo); //cierro el archivo
}
// El formato con el que guardo los datos es [ fila_i -renglon vacio- fila_i+1 -renglon vacio- fila_i+2 ..... ]   
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void leer_o(double *matriz,int opcion){    // la funcion guardar graba los datos de matriz en un archivo llamado salia-1.dat
  
  
  
  
  
  
  
  FILE *archivo;   // creo el archivo

  

  if(opcion==1){
  archivo= fopen("saturacion.dat","r"); //abro el archivo y le asigno el nombre
  }
  if(opcion==2){
  archivo= fopen("permeabilidad.dat","r"); //abro el archivo y le asigno el nombre  
  }
  int f=0; 
  int c=0;
  int i=0;
  
  for(f=0 ; f<TAM_F ; f++){ //barro todas las filas de la matriz
    for(c=0 ; c<TAM_C ; c++){ //barro todas las columnas de la matriz
      i=fscanf(archivo,"%lf",&matriz[TAM_C*f + c]); //guardo un dato y le doy enter
      //fseek(archivo, 9, SEEK_CUR);
    }
      //fseek(archivo, 10, SEEK_CUR); //cuando termino una fila le doy un enter
  }
  
  
  fclose(archivo); //cierro el archivo
}
// El formato con el que guardo los datos es [ fila_i -renglon vacio- fila_i+1 -renglon vacio- fila_i+2 ..... ] 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void guardar_v(double *vector,int tam){    // la funcion guardar graba los datos de matriz en un archivo llamado salia-1.dat
  
  FILE *archivo;   // creo el archivo
  archivo= fopen("integral.dat","w+"); //abro el archivo y le asigno el nombre
   
  int c=0;
  
  
    for(c=1 ; c<=tam ; c++){ //barro todas las columnas de la matriz
      fprintf(archivo,"%.15f\n",vector[c]); //guardo un dato y le doy enter
    }
    
  
  
  
  fclose(archivo); //cierro el archivo
}
// El formato con el que guardo los datos es [ fila_i -renglon vacio- fila_i+1 -renglon vacio- fila_i+2 ..... ]   
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void guardar_1(double *matriz){    // la funcion guardar graba los datos de matriz en un archivo llamado salia-1.dat
  
  FILE *archivo;   // creo el archivo
  archivo= fopen("salida-1.dat","w+"); //abro el archivo y le asigno el nombre
  int f=0; 
  int c=0;
  
  for(f=0 ; f<TAM_F ; f++){ //barro todas las filas de la matriz
    for(c=0 ; c<TAM_C ; c++){ //barro todas las columnas de la matriz
      fprintf(archivo,"%.15f\n",matriz[TAM_C*f + c]); //guardo un dato y le doy enter
    }
      fprintf(archivo,"\n"); //cuando termino una fila le doy un enter
  }
  
  
  fclose(archivo); //cierro el archivo
}
// El formato con el que guardo los datos es [ fila_i -renglon vacio- fila_i+1 -renglon vacio- fila_i+2 ..... ]   
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void guardar_2(double *matriz){    // la funcion guardar graba los datos de matriz en un archivo llamado salia-1.dat
  
  FILE *archivo;   // creo el archivo
  archivo= fopen("salida-2.dat","w+"); //abro el archivo y le asigno el nombre
  int f=0; 
  int c=0;
  
  for(f=0 ; f<TAM_F ; f++){ //barro todas las filas de la matriz
    for(c=0 ; c<TAM_C ; c++){ //barro todas las columnas de la matriz
      fprintf(archivo,"%.15f\n",matriz[TAM_C*f + c]); //guardo un dato y le doy enter
    }
      fprintf(archivo,"\n"); //cuando termino una fila le doy un enter
  }
  
  
  fclose(archivo); //cierro el archivo
}
// El formato con el que guardo los datos es [ fila_i -renglon vacio- fila_i+1 -renglon vacio- fila_i+2 ..... ]   
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void inicializar_presion(){
  
  int c=0;
  int f=0;
  
   
  for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      presion[TAM_C*f + c]= 0.0 ; 
    }
  }
  
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void inicializar_K(){
  
  int c=0;
  int f=0;
  int barreras=0;
   
  for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      K[TAM_C*f + c]= 1.0 ; 
    }
  }
  
  
  
  if(barreras==1){
    
    for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      if( pow( (c-30)*(c-30) + (f-0)*(f-0) ,0.5)<4 ){
      K[TAM_C*f + c]= 0.00001 ;
      }
    }
  }
  
  
    for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      if( pow( (c-27)*(c-27) + (f-12)*(f-12) ,0.5)<3 ){
      K[TAM_C*f + c]= 0.00001 ;
      }
    }
  }
  
  
    for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      if( pow( (c-21)*(c-21) + (f-21)*(f-21) ,0.5)<3 ){
      K[TAM_C*f + c]= 0.00001 ;
      }
    }
  }
  
  
      for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      if( pow( (c-11)*(c-11) + (f-27)*(f-27) ,0.5)<5 ){
      K[TAM_C*f + c]= 0.00001 ;
      }
    }
  }
 
  
  }
  
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void inicializar_Q_W(){
  
  int c=0;
  int f=0;
  
   
  for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      Q_W[TAM_C*f + c]= 0.0 ; 
    }
  }
  
  
  
   if(CB==0){
      for(f=0 ; f<TAM_F ; f++){
	c=0;
	  Q_W[TAM_C*f + c]= q_w; 
	
      }

  }
  
  
  
  if(CB==1){
      f=0 ;
	c=0 ;
	  Q_W[TAM_C*f + c]= q_w*TAM_F ; 
	
      

  }
  
  
  
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
void inicializar_Q_N(){
  
  int c=0;
  int f=0;
  
   
  for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      Q_N[TAM_C*f + c]= 0.0 ; 
    }
  }
  
  
   if(CB==0){
      for(f=0 ; f<TAM_F ; f++){
	c=TAM_C -1;
	  Q_N[TAM_C*f + c]= -q_n; 
	
      }

  }
  
  
  
  if(CB==1){
      f=TAM_F -1 ;
	c=TAM_C-1 ;
	  Q_N[TAM_C*f + c]= -q_n*TAM_F ; 
	
      

  }
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void inicializar_saturacion(){
  
  int c=0;
  int f=0;
  double alfa=(TAM_C/2) ;
  for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      saturacion[TAM_C*f + c]= 0.0 ; 
    }
  }
  
  
  if(CB==0){
      for(f=0 ; f<TAM_F ; f++){
	for(c=0 ; c<TAM_C ; c++){
	  saturacion[TAM_C*f + c]= 1.0*exp( -(c*c)/(alfa ) ) + 0.0 ; 
	}
      }

  }
  
////////////////////////////////////////////////////////////////
    if(CB==0){
      for(f=8 ; f<11 ; f++){
	for(c=12 ; c<15 ; c++){
	  saturacion[TAM_C*f + c + 3]= saturacion[TAM_C*f + c ] ;
	  saturacion[TAM_C*f + c ]= saturacion[TAM_C*f + c-1 ];
	}
      }

  }
  
      if(CB==0){
      for(f=18 ; f<22 ; f++){
	for(c=12 ; c<18 ; c++){
	  saturacion[TAM_C*f + c + 6]= saturacion[TAM_C*f + c ] ;
	  saturacion[TAM_C*f + c ]= saturacion[TAM_C*f + c-1 ];
	}
      }

  }
  
      if(CB==0){
      for(f=30 ; f<33 ; f++){
	for(c=12 ; c<17 ; c++){
	  saturacion[TAM_C*f + c + 5]= saturacion[TAM_C*f + c ] ;
	  saturacion[TAM_C*f + c ]= saturacion[TAM_C*f + c-1 ];
	}
      }

  }
  
  
      if(CB==0){
      for(f=38 ; f<42 ; f++){
	for(c=12 ; c<16 ; c++){
	  saturacion[TAM_C*f + c + 4]= saturacion[TAM_C*f + c ] ;
	  saturacion[TAM_C*f + c ]= saturacion[TAM_C*f + c-1 ];
	}
      }

  }
  
  
  
  
      if(CB==0){
      for(f=49 ; f<55 ; f++){
	for(c=12 ; c<15 ; c++){
	  saturacion[TAM_C*f + c + 3]= saturacion[TAM_C*f + c ] ;
	  saturacion[TAM_C*f + c ]= saturacion[TAM_C*f + c-1 ];
	}
      }

  }
  
      if(CB==0){
      for(f=63 ; f<69 ; f++){
	for(c=12 ; c<16 ; c++){
	  saturacion[TAM_C*f + c + 4]= saturacion[TAM_C*f + c ] ;
	  saturacion[TAM_C*f + c ]= saturacion[TAM_C*f + c-1 ];
	}
      }

  }
  
      if(CB==0){
      for(f=75 ; f<81 ; f++){
	for(c=12 ; c<17 ; c++){
	  saturacion[TAM_C*f + c + 5]= saturacion[TAM_C*f + c ] ;
	  saturacion[TAM_C*f + c ]= saturacion[TAM_C*f + c-1 ];
	}
      }

  }
  
      if(CB==0){
      for(f=89 ; f<93 ; f++){
	for(c=12 ; c<16 ; c++){
	  saturacion[TAM_C*f + c + 4]= saturacion[TAM_C*f + c ] ;
	  saturacion[TAM_C*f + c ]= saturacion[TAM_C*f + c-1 ];
	}
      }

  }
  
  
  //////////////////////////////////////////////////////////////
  /*
      if(CB==0){
      for(f=85 ; f<89 ; f++){
	for(c=12 ; c<14 ; c++){
	  saturacion[TAM_C*f + c + 2]= saturacion[TAM_C*f + c ] ;
	  saturacion[TAM_C*f + c ]= saturacion[TAM_C*f + c-1 ];
	}
      }

  }
  
  
      if(CB==0){
      for(f=95 ; f<99 ; f++){
	for(c=12 ; c<13 ; c++){
	  saturacion[TAM_C*f + c + 1]= saturacion[TAM_C*f + c ] ;
	  saturacion[TAM_C*f + c ]= saturacion[TAM_C*f + c-1 ];
	}
      }

  }
  
      if(CB==0){
      for(f=106 ; f<110 ; f++){
	for(c=12 ; c<13 ; c++){
	  saturacion[TAM_C*f + c + 1]= saturacion[TAM_C*f + c ] ;
	  saturacion[TAM_C*f + c ]= saturacion[TAM_C*f + c-1 ];
	}
      }

  }
  
      if(CB==0){
      for(f=118 ; f<120 ; f++){
	for(c=12 ; c<13 ; c++){
	  saturacion[TAM_C*f + c + 1]= saturacion[TAM_C*f + c ] ;
	  saturacion[TAM_C*f + c ]= saturacion[TAM_C*f + c-1 ];
	}
      }

  }
  
      if(CB==0){
      for(f=125 ; f<129 ; f++){
	for(c=12 ; c<13 ; c++){
	  saturacion[TAM_C*f + c + 1]= saturacion[TAM_C*f + c ] ;
	  saturacion[TAM_C*f + c ]= saturacion[TAM_C*f + c-1 ];
	}
      }

  }
  
  
  
      if(CB==0){
      for(f=136 ; f<140 ; f++){
	for(c=12 ; c<14 ; c++){
	  saturacion[TAM_C*f + c + 2]= saturacion[TAM_C*f + c ] ;
	  saturacion[TAM_C*f + c ]= saturacion[TAM_C*f + c-1 ];
	}
      }

  }
  
      if(CB==0){
      for(f=145 ; f<149 ; f++){
	for(c=12 ; c<13 ; c++){
	  saturacion[TAM_C*f + c + 1]= saturacion[TAM_C*f + c ] ;
	  saturacion[TAM_C*f + c ]= saturacion[TAM_C*f + c-1 ];
	}
      }

  }
  
      if(CB==0){
      for(f=160 ; f<162 ; f++){
	for(c=12 ; c<13 ; c++){
	  saturacion[TAM_C*f + c + 1]= saturacion[TAM_C*f + c ] ;
	  saturacion[TAM_C*f + c ]= saturacion[TAM_C*f + c-1 ];
	}
      }

  }
  
      if(CB==0){
      for(f=168 ; f<172 ; f++){
	for(c=12 ; c<13 ; c++){
	  saturacion[TAM_C*f + c + 1]= saturacion[TAM_C*f + c ] ;
	  saturacion[TAM_C*f + c ]= saturacion[TAM_C*f + c-1 ];
	}
      }
      }
      
      if(CB==0){
      for(f=180 ; f<183 ; f++){
	for(c=12 ; c<14 ; c++){
	  saturacion[TAM_C*f + c + 2]= saturacion[TAM_C*f + c ] ;
	  saturacion[TAM_C*f + c ]= saturacion[TAM_C*f + c-1 ];
	}
      }
      }
      
      
      if(CB==0){
      for(f=189 ; f<192 ; f++){
	for(c=12 ; c<13 ; c++){
	  saturacion[TAM_C*f + c + 1]= saturacion[TAM_C*f + c ] ;
	  saturacion[TAM_C*f + c ]= saturacion[TAM_C*f + c-1 ];
	}
      }
      }
      
      
  
 */ 
  
  
////////////////////////////////////////////////////////////////  
  
  
  
  
  
  
  
  if(CB==1){
      for(f=0 ; f<TAM_F ; f++){
	for(c=0 ; c<TAM_C ; c++){
	  saturacion[TAM_C*f + c]= 1.0*exp( -(c*c + f*f)/(alfa) ) + 0.0; 
	}
      }

  }
  
 
  
  
} 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calcular_lambda_n(){
 
  int c=0;
  int f=0;
  
  calcular_krn();
  for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      lambda_n[TAM_C*f + c]= (K[TAM_C*f + c]*krn[TAM_C*f + c])/(mu_n) ; 
    }
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calcular_lambda_w(){
  
  int c=0;
  int f=0;
  
  calcular_krw();
  for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      lambda_w[TAM_C*f + c]= (K[TAM_C*f + c]*krw[TAM_C*f + c])/(mu_w) ; 
    }
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calcular_krn(){
  
  int c=0;
  int f=0;
  
  for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      krn[TAM_C*f + c]=  (1.0 - saturacion[TAM_C*f + c])*(1.0 - saturacion[TAM_C*f + c])  ; 
    }
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calcular_krw(){
  
  int c=0;
  int f=0;
  
  for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      krw[TAM_C*f + c]=  ( saturacion[TAM_C*f + c])*( saturacion[TAM_C*f + c])  ; 
    }
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calcular_lambda_t(){
  
  int c=0;
  int f=0;
  
  for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      lambda_t[TAM_C*f + c]= lambda_n[TAM_C*f + c] + lambda_w[TAM_C*f + c]   ; 
      //printf("\n fila =%i  columna=%i lambda total = %f \n",f,c,lambda_t[TAM_C*f + c]);
    }
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calcular_lambda_d(){
  
  int c=0;
  int f=0;
  
  for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      lambda_d[TAM_C*f + c]= lambda_n[TAM_C*f + c] - lambda_w[TAM_C*f + c]   ; 
    }
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calcular_lambda_d_1_2_3_4(){
  
  int c=0;
  int f=0;
  
/*  
  for(f=1 ; f<(TAM_F-1) ; f++){
    for(c=1 ; c<(TAM_C-1) ; c++){
      lambda_d_1[TAM_C*f + c]=(lambda_d[TAM_C*f + (c-1)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c] + cachito); 
      lambda_d_2[TAM_C*f + c]=(lambda_d[TAM_C*f + (c+1)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c] + cachito); 
      lambda_d_3[TAM_C*f + c]=(lambda_d[TAM_C*(f-1) + (c)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c] + cachito); 
      lambda_d_4[TAM_C*f + c]=(lambda_d[TAM_C*(f+1) + (c)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c] + cachito); 
    }
  }
*/ 

  
  
  
   for(f=1 ; f<(TAM_F-1) ; f++){
    for(c=1 ; c<(TAM_C-1) ; c++){
 
      lambda_d_1[TAM_C*f + c]=(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c])/(2.0);
      lambda_d_2[TAM_C*f + c]=(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c])/(2.0); 
      lambda_d_3[TAM_C*f + c]=(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c])/(2.0); 
      lambda_d_4[TAM_C*f + c]=(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c])/(2.0); 
    }
  }
 
  
  
  
  
  
  
 
/* Borde izquierdo   c=0 */ 
 for(f=1 ; f<(TAM_F-1) ; f++){
    c=0;
      lambda_d_1[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c])/(2.0);
      lambda_d_2[TAM_C*f + c]=(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c])/(2.0); 
      lambda_d_3[TAM_C*f + c]=(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c])/(2.0); 
      lambda_d_4[TAM_C*f + c]=(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c])/(2.0);
    
  }
  
  
/* Borde derecho c=TAM_C -1*/  

for(f=1 ; f<(TAM_F-1) ; f++){
    c=TAM_C -1 ;
      lambda_d_1[TAM_C*f + c]=(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c])/(2.0);
      lambda_d_2[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c])/(2.0); 
      lambda_d_3[TAM_C*f + c]=(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c])/(2.0); 
      lambda_d_4[TAM_C*f + c]=(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c])/(2.0);
    
  }
 
/* Borde superior f=0*/ 
 
 
    for(c=1 ; c<(TAM_C-1) ; c++){
      f=0;
      lambda_d_1[TAM_C*f + c]=(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c])/(2.0);
      lambda_d_2[TAM_C*f + c]=(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c])/(2.0); 
      lambda_d_3[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c])/(2.0); 
      lambda_d_4[TAM_C*f + c]=(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c])/(2.0);
    }
  
/* Borde inferior f=TAM_F -1*/
 

    for(c=1 ; c<(TAM_C-1) ; c++){
      f=TAM_F -1 ;
      lambda_d_1[TAM_C*f + c]=(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c])/(2.0);
      lambda_d_2[TAM_C*f + c]=(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c])/(2.0); 
      lambda_d_3[TAM_C*f + c]=(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c])/(2.0); 
      lambda_d_4[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c])/(2.0);
    }
  

/* esquina superior izquierda c=0 f=0*/  
 
 c=0;
 f=0;
 lambda_d_1[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c])/(2.0);
 lambda_d_2[TAM_C*f + c]=(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c])/(2.0); 
 lambda_d_3[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c])/(2.0); 
 lambda_d_4[TAM_C*f + c]=(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c])/(2.0);

/* esquina superior derecha c= TAM_C -1 f=0*/ 
 
 c=TAM_C -1;
 f=0;
 lambda_d_1[TAM_C*f + c]=(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c])/(2.0);
 lambda_d_2[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c])/(2.0); 
 lambda_d_3[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c])/(2.0); 
 lambda_d_4[TAM_C*f + c]=(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c])/(2.0);

 
/* esquina inferior izquierda  c=0  f=TAM_F -1*/ 
 
 c=0;
 f=TAM_F -1;
 lambda_d_1[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c])/(2.0);
 lambda_d_2[TAM_C*f + c]=(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c])/(2.0); 
 lambda_d_3[TAM_C*f + c]=(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c])/(2.0); 
 lambda_d_4[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c])/(2.0);

 
/* esquina inferior derecha c=TAM_C -1  f= TAM_F -1*/ 
 c=TAM_C -1;
 f=TAM_F -1;
 lambda_d_1[TAM_C*f + c]=(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c])/(2.0);
 lambda_d_2[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c])/(2.0); 
 lambda_d_3[TAM_C*f + c]=(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c])/(2.0); 
 lambda_d_4[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c])/(2.0);


}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calcular_lambda_t_1_2_3_4_C(){
  
  int c=0;
  int f=0;
  
  for(f=1 ; f<(TAM_F-1) ; f++){
    for(c=1 ; c<(TAM_C-1) ; c++){
      lambda_t_1[TAM_C*f + c]=(lambda_t[TAM_C*f + (c-1)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*f + (c-1)] + lambda_t[TAM_C*f + c] + cachito); 
      lambda_t_2[TAM_C*f + c]=(lambda_t[TAM_C*f + (c+1)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*f + (c+1)] + lambda_t[TAM_C*f + c] + cachito); 
      lambda_t_3[TAM_C*f + c]=(lambda_t[TAM_C*(f-1) + (c)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*(f-1) + (c)] + lambda_t[TAM_C*f + c] + cachito); 
      lambda_t_4[TAM_C*f + c]=(lambda_t[TAM_C*(f+1) + (c)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*(f+1) + (c)] + lambda_t[TAM_C*f + c] + cachito); 
    }
  }
 
 
/* Borde izquierdo   c=0 */ 
 for(f=1 ; f<(TAM_F-1) ; f++){
    c=0;
      lambda_t_1[TAM_C*f + c]= 0.0 ; //(lambda_t[TAM_C*f + (c-1)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*f + (c-1)] + lambda_t[TAM_C*f + c] + cachito); 
      lambda_t_2[TAM_C*f + c]=(lambda_t[TAM_C*f + (c+1)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*f + (c+1)] + lambda_t[TAM_C*f + c] + cachito); 
      lambda_t_3[TAM_C*f + c]=(lambda_t[TAM_C*(f-1) + (c)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*(f-1) + (c)] + lambda_t[TAM_C*f + c] + cachito); 
      lambda_t_4[TAM_C*f + c]=(lambda_t[TAM_C*(f+1) + (c)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*(f+1) + (c)] + lambda_t[TAM_C*f + c] + cachito); 
    
  }
  
  
/* Borde derecho c=TAM_C -1*/  

for(f=1 ; f<(TAM_F-1) ; f++){
    c=TAM_C -1 ;
      lambda_t_1[TAM_C*f + c]=(lambda_t[TAM_C*f + (c-1)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*f + (c-1)] + lambda_t[TAM_C*f + c] + cachito); 
      lambda_t_2[TAM_C*f + c]=0.0;//(lambda_t[TAM_C*f + (c+1)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*f + (c+1)] + lambda_t[TAM_C*f + c] + cachito); 
      lambda_t_3[TAM_C*f + c]=(lambda_t[TAM_C*(f-1) + (c)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*(f-1) + (c)] + lambda_t[TAM_C*f + c] + cachito); 
      lambda_t_4[TAM_C*f + c]=(lambda_t[TAM_C*(f+1) + (c)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*(f+1) + (c)] + lambda_t[TAM_C*f + c] + cachito); 
    
  }
 
/* Borde superior f=0*/ 
 
 
    for(c=1 ; c<(TAM_C-1) ; c++){
      f=0;
      lambda_t_1[TAM_C*f + c]=(lambda_t[TAM_C*f + (c-1)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*f + (c-1)] + lambda_t[TAM_C*f + c] + cachito); 
      lambda_t_2[TAM_C*f + c]=(lambda_t[TAM_C*f + (c+1)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*f + (c+1)] + lambda_t[TAM_C*f + c] + cachito); 
      lambda_t_3[TAM_C*f + c]=0.0;//(lambda_t[TAM_C*(f-1) + (c)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*(f-1) + (c)] + lambda_t[TAM_C*f + c] + cachito); 
      lambda_t_4[TAM_C*f + c]=(lambda_t[TAM_C*(f+1) + (c)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*(f+1) + (c)] + lambda_t[TAM_C*f + c] + cachito); 
    }
  
/* Borde inferior f=TAM_F -1*/
 

    for(c=1 ; c<(TAM_C-1) ; c++){
      f=TAM_F -1 ;
      lambda_t_1[TAM_C*f + c]=(lambda_t[TAM_C*f + (c-1)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*f + (c-1)] + lambda_t[TAM_C*f + c] + cachito); 
      lambda_t_2[TAM_C*f + c]=(lambda_t[TAM_C*f + (c+1)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*f + (c+1)] + lambda_t[TAM_C*f + c] + cachito); 
      lambda_t_3[TAM_C*f + c]=(lambda_t[TAM_C*(f-1) + (c)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*(f-1) + (c)] + lambda_t[TAM_C*f + c] + cachito); 
      lambda_t_4[TAM_C*f + c]=0.0;//(lambda_t[TAM_C*(f+1) + (c)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*(f+1) + (c)] + lambda_t[TAM_C*f + c] + cachito); 
    }
  

/* esquina superior izquierda c=0 f=0*/  
 
 c=0;
 f=0;
 lambda_t_1[TAM_C*f + c]=0.0;//(lambda_t[TAM_C*f + (c-1)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*f + (c-1)] + lambda_t[TAM_C*f + c] + cachito); 
 lambda_t_2[TAM_C*f + c]=(lambda_t[TAM_C*f + (c+1)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*f + (c+1)] + lambda_t[TAM_C*f + c] + cachito); 
 lambda_t_3[TAM_C*f + c]=0.0;//(lambda_t[TAM_C*(f-1) + (c)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*(f-1) + (c)] + lambda_t[TAM_C*f + c] + cachito); 
 lambda_t_4[TAM_C*f + c]=(lambda_t[TAM_C*(f+1) + (c)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*(f+1) + (c)] + lambda_t[TAM_C*f + c] + cachito); 

/* esquina superior derecha c= TAM_C -1 f=0*/ 
 
 c=TAM_C -1;
 f=0;
 lambda_t_1[TAM_C*f + c]=(lambda_t[TAM_C*f + (c-1)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*f + (c-1)] + lambda_t[TAM_C*f + c] + cachito); 
 lambda_t_2[TAM_C*f + c]=0.0;//(lambda_t[TAM_C*f + (c+1)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*f + (c+1)] + lambda_t[TAM_C*f + c] + cachito); 
 lambda_t_3[TAM_C*f + c]=0.0;//(lambda_t[TAM_C*(f-1) + (c)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*(f-1) + (c)] + lambda_t[TAM_C*f + c] + cachito); 
 lambda_t_4[TAM_C*f + c]=(lambda_t[TAM_C*(f+1) + (c)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*(f+1) + (c)] + lambda_t[TAM_C*f + c] + cachito); 

 
/* esquina inferior izquierda  c=0  f=TAM_F -1*/ 
 
 c=0;
 f=TAM_F -1;
 lambda_t_1[TAM_C*f + c]=0.0;//(lambda_t[TAM_C*f + (c-1)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*f + (c-1)] + lambda_t[TAM_C*f + c] + cachito); 
 lambda_t_2[TAM_C*f + c]=(lambda_t[TAM_C*f + (c+1)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*f + (c+1)] + lambda_t[TAM_C*f + c] + cachito); 
 lambda_t_3[TAM_C*f + c]=(lambda_t[TAM_C*(f-1) + (c)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*(f-1) + (c)] + lambda_t[TAM_C*f + c] + cachito); 
 lambda_t_4[TAM_C*f + c]=0.0;//(lambda_t[TAM_C*(f+1) + (c)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*(f+1) + (c)] + lambda_t[TAM_C*f + c] + cachito); 

 
/* esquina inferior derecha c=TAM_C -1  f= TAM_F -1*/ 
 c=TAM_C -1;
 f=TAM_F -1;
 lambda_t_1[TAM_C*f + c]=(lambda_t[TAM_C*f + (c-1)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*f + (c-1)] + lambda_t[TAM_C*f + c] + cachito); 
 lambda_t_2[TAM_C*f + c]=0.0;//(lambda_t[TAM_C*f + (c+1)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*f + (c+1)] + lambda_t[TAM_C*f + c] + cachito); 
 lambda_t_3[TAM_C*f + c]=(lambda_t[TAM_C*(f-1) + (c)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*(f-1) + (c)] + lambda_t[TAM_C*f + c] + cachito); 
 lambda_t_4[TAM_C*f + c]=0.0;//(lambda_t[TAM_C*(f+1) + (c)]*lambda_t[TAM_C*f + c])/(lambda_t[TAM_C*(f+1) + (c)] + lambda_t[TAM_C*f + c] + cachito); 


}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calcular_presion_capilar(){
  int c=0;
  int f=0;
  
  for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      presion_capilar[TAM_C*f + c]= -po*log(saturacion[TAM_C*f + c] + cachito)   ; 
      //printf("\n fila=%i columna=%i    po=%f  log=%f   total=%f   saturacion=%.32f",f,c,-po,log(saturacion[TAM_C*f + c]+cachito),-po*log(saturacion[TAM_C*f + c]+cachito),saturacion[TAM_C*f + c]);
    }
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calcular_termino_presion_capilar(){
  int c=0;
  int f=0;
  
  double flujo_1=0;
  double flujo_2=0;
  double flujo_3=0;
  double flujo_4=0;
  
/* Recinto interior */  
  for(f=1 ; f<(TAM_F-1) ; f++){
    for(c=1 ; c<(TAM_C-1) ; c++){
      flujo_1 = lambda_d_1[TAM_C*f + c]*(presion_capilar[TAM_C*f + (c-1)] - presion_capilar[TAM_C*f + c]);
      flujo_2 = lambda_d_2[TAM_C*f + c]*(presion_capilar[TAM_C*f + (c+1)] - presion_capilar[TAM_C*f + c]);
      flujo_3 = lambda_d_3[TAM_C*f + c]*(presion_capilar[TAM_C*(f-1) + (c)] - presion_capilar[TAM_C*f + c]);
      flujo_4 = lambda_d_4[TAM_C*f + c]*(presion_capilar[TAM_C*(f+1) + (c)] - presion_capilar[TAM_C*f + c]);
      
      termino_presion_capilar[TAM_C*f + c]=  0.5*( flujo_1 + flujo_2 + flujo_3 +  flujo_4)  ; 
      //printf("\nfila=%i columna=%i termino presion capilar =%f  =%f =%f =%f =%f\n",f,c,termino_presion_capilar[TAM_C*f + c],(presion_capilar[TAM_C*f + (c-1)] - presion_capilar[TAM_C*f + c]),lambda_d_2[TAM_C*f + c],lambda_d_3[TAM_C*f + c],lambda_d_4[TAM_C*f + c]);
    }
  }



/* borde izquierdo c=0 */  
  for(f=1 ; f<(TAM_F-1) ; f++){
    c=0;
      flujo_1 = 0.0;//lambda_d_1[TAM_C*f + c]*(presion_capilar[TAM_C*f + (c-1)] - presion_capilar[TAM_C*f + c]);
      flujo_2 = lambda_d_2[TAM_C*f + c]*(presion_capilar[TAM_C*f + (c+1)] - presion_capilar[TAM_C*f + c]);
      flujo_3 = lambda_d_3[TAM_C*f + c]*(presion_capilar[TAM_C*(f-1) + (c)] - presion_capilar[TAM_C*f + c]);
      flujo_4 = lambda_d_4[TAM_C*f + c]*(presion_capilar[TAM_C*(f+1) + (c)] - presion_capilar[TAM_C*f + c]);
      
      termino_presion_capilar[TAM_C*f + c]=  0.5*( flujo_1 + flujo_2 + flujo_3 +  flujo_4)  ; 
    }
  



/* borde derecho c=TAM_C -1 */  
  for(f=1 ; f<(TAM_F-1) ; f++){
    c=TAM_C -1;
      flujo_1 = lambda_d_1[TAM_C*f + c]*(presion_capilar[TAM_C*f + (c-1)] - presion_capilar[TAM_C*f + c]);
      flujo_2 = 0.0;//lambda_d_2[TAM_C*f + c]*(presion_capilar[TAM_C*f + (c+1)] - presion_capilar[TAM_C*f + c]);
      flujo_3 = lambda_d_3[TAM_C*f + c]*(presion_capilar[TAM_C*(f-1) + (c)] - presion_capilar[TAM_C*f + c]);
      flujo_4 = lambda_d_4[TAM_C*f + c]*(presion_capilar[TAM_C*(f+1) + (c)] - presion_capilar[TAM_C*f + c]);
      
      termino_presion_capilar[TAM_C*f + c]=  0.5*( flujo_1 + flujo_2 + flujo_3 +  flujo_4)  ; 
    }
  



/* borde superior f=0 */  
  
    for(c=1 ; c<(TAM_C-1) ; c++){
      f=0;
      flujo_1 = lambda_d_1[TAM_C*f + c]*(presion_capilar[TAM_C*f + (c-1)] - presion_capilar[TAM_C*f + c]);
      flujo_2 = lambda_d_2[TAM_C*f + c]*(presion_capilar[TAM_C*f + (c+1)] - presion_capilar[TAM_C*f + c]);
      flujo_3 = 0.0;//lambda_d_3[TAM_C*f + c]*(presion_capilar[TAM_C*(f-1) + (c)] - presion_capilar[TAM_C*f + c]);
      flujo_4 = lambda_d_4[TAM_C*f + c]*(presion_capilar[TAM_C*(f+1) + (c)] - presion_capilar[TAM_C*f + c]);
      
      termino_presion_capilar[TAM_C*f + c]=  0.5*( flujo_1 + flujo_2 + flujo_3 +  flujo_4)  ; 
    }
    
    
/* borde inferior f=TAM_F -1 */  
  
    for(c=1 ; c<(TAM_C-1) ; c++){
      f=TAM_F -1;
      flujo_1 = lambda_d_1[TAM_C*f + c]*(presion_capilar[TAM_C*f + (c-1)] - presion_capilar[TAM_C*f + c]);
      flujo_2 = lambda_d_2[TAM_C*f + c]*(presion_capilar[TAM_C*f + (c+1)] - presion_capilar[TAM_C*f + c]);
      flujo_3 = lambda_d_3[TAM_C*f + c]*(presion_capilar[TAM_C*(f-1) + (c)] - presion_capilar[TAM_C*f + c]);
      flujo_4 = 0.0;//lambda_d_4[TAM_C*f + c]*(presion_capilar[TAM_C*(f+1) + (c)] - presion_capilar[TAM_C*f + c]);
      
      termino_presion_capilar[TAM_C*f + c]=  0.5*( flujo_1 + flujo_2 + flujo_3 +  flujo_4)  ; 
    }
  
  
/* Esquina superior izquierda c=0 f=0 */

      c=0;
      f=0;
      flujo_1 = 0.0;//lambda_d_1[TAM_C*f + c]*(presion_capilar[TAM_C*f + (c-1)] - presion_capilar[TAM_C*f + c]);
      flujo_2 = lambda_d_2[TAM_C*f + c]*(presion_capilar[TAM_C*f + (c+1)] - presion_capilar[TAM_C*f + c]);
      flujo_3 = 0.0;//lambda_d_3[TAM_C*f + c]*(presion_capilar[TAM_C*(f-1) + (c)] - presion_capilar[TAM_C*f + c]);
      flujo_4 = lambda_d_4[TAM_C*f + c]*(presion_capilar[TAM_C*(f+1) + (c)] - presion_capilar[TAM_C*f + c]);
      
      termino_presion_capilar[TAM_C*f + c]=  0.5*( flujo_1 + flujo_2 + flujo_3 +  flujo_4)  ; 

      
/* Esquina superior derecha c=TAM_C-1 f=0 */

      c=TAM_C -1;
      f=0;
      flujo_1 = lambda_d_1[TAM_C*f + c]*(presion_capilar[TAM_C*f + (c-1)] - presion_capilar[TAM_C*f + c]);
      flujo_2 = 0.0;//lambda_d_2[TAM_C*f + c]*(presion_capilar[TAM_C*f + (c+1)] - presion_capilar[TAM_C*f + c]);
      flujo_3 = 0.0;//lambda_d_3[TAM_C*f + c]*(presion_capilar[TAM_C*(f-1) + (c)] - presion_capilar[TAM_C*f + c]);
      flujo_4 = lambda_d_4[TAM_C*f + c]*(presion_capilar[TAM_C*(f+1) + (c)] - presion_capilar[TAM_C*f + c]);
      
      termino_presion_capilar[TAM_C*f + c]=  0.5*( flujo_1 + flujo_2 + flujo_3 +  flujo_4)  ;       
   
      
/* Esquina inferior izquierda c=0 f=TAM_F-1 */

      c=0;
      f=TAM_F -1;
      flujo_1 = 0.0;//lambda_d_1[TAM_C*f + c]*(presion_capilar[TAM_C*f + (c-1)] - presion_capilar[TAM_C*f + c]);
      flujo_2 = lambda_d_2[TAM_C*f + c]*(presion_capilar[TAM_C*f + (c+1)] - presion_capilar[TAM_C*f + c]);
      flujo_3 = lambda_d_3[TAM_C*f + c]*(presion_capilar[TAM_C*(f-1) + (c)] - presion_capilar[TAM_C*f + c]);
      flujo_4 = 0.0;//lambda_d_4[TAM_C*f + c]*(presion_capilar[TAM_C*(f+1) + (c)] - presion_capilar[TAM_C*f + c]);
      
      termino_presion_capilar[TAM_C*f + c]=  0.5*( flujo_1 + flujo_2 + flujo_3 +  flujo_4)  ;       
      
      
/* Esquina inferior derecha c=TAM_C-1 f=TAM_F-1 */

      c=TAM_C-1;
      f=TAM_F-1;
      flujo_1 = lambda_d_1[TAM_C*f + c]*(presion_capilar[TAM_C*f + (c-1)] - presion_capilar[TAM_C*f + c]);
      flujo_2 = 0.0;//lambda_d_2[TAM_C*f + c]*(presion_capilar[TAM_C*f + (c+1)] - presion_capilar[TAM_C*f + c]);
      flujo_3 = lambda_d_3[TAM_C*f + c]*(presion_capilar[TAM_C*(f-1) + (c)] - presion_capilar[TAM_C*f + c]);
      flujo_4 = 0.0;//lambda_d_4[TAM_C*f + c]*(presion_capilar[TAM_C*(f+1) + (c)] - presion_capilar[TAM_C*f + c]);
      
      termino_presion_capilar[TAM_C*f + c]=  0.5*( flujo_1 + flujo_2 + flujo_3 +  flujo_4)  ;       
    
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calculo_diferencia(){

  int c=0;
  int f=0;
  double aux=100.0;
  diferencia=0.0;
  
  omp_set_num_threads(np_1);
  #pragma omp parallel for private(c,f,aux) reduction(max:diferencia) 
  for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      aux= fabs( presion[TAM_C*f + c] - presion_N[TAM_C*f + c] );
      
      if(aux>diferencia){
	diferencia=aux;
	//printf("\n .....diferencia = %f \n",*diferencia);
      }
      
    }
  }

  
  /*
     int c=0;
  int f=0;
  double aux=100.0;
  diferencia=0.0;
  
  //omp_set_num_threads(2);
  //#pragma omp parallel for private(c,f) 
  for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      aux= fabs( presion[TAM_C*f + c] - presion_N[TAM_C*f + c] );
      
      if(aux>diferencia){
	diferencia=aux;
	//printf("\n .....diferencia = %f \n",*diferencia);
      }
      
    }
  }
   
   */
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void calcular_presion_n(){
 
  int c=0;
  int f=0;
  
  for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      presion_n[TAM_C*f + c]= presion[TAM_C*f + c] + (presion_capilar[TAM_C*f + c])/(2.0)  ; 
    }
  }
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void calcular_presion_w(){
 
  int c=0;
  int f=0;
  
  for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      presion_w[TAM_C*f + c]= presion[TAM_C*f + c] - (presion_capilar[TAM_C*f + c])/(2.0)  ; 
    }
  }
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void calcular_lambda_n_1_2_3_4(){
  
  
  int c=0;
  int f=0;
  
  for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      lambda_n_1[TAM_C*f + c]= (  lambda_t_1[TAM_C*f + c] + lambda_d_1[TAM_C*f + c] )/(2.0) ;
      lambda_n_2[TAM_C*f + c]= (  lambda_t_2[TAM_C*f + c] + lambda_d_2[TAM_C*f + c] )/(2.0) ;
      lambda_n_3[TAM_C*f + c]= (  lambda_t_3[TAM_C*f + c] + lambda_d_3[TAM_C*f + c] )/(2.0) ;
      lambda_n_4[TAM_C*f + c]= (  lambda_t_4[TAM_C*f + c] + lambda_d_4[TAM_C*f + c] )/(2.0) ;
    }
  }
  
  
} 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void calcular_lambda_w_1_2_3_4(){
 
  int c=0;
  int f=0;
  
  for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      lambda_w_1[TAM_C*f + c]= (  lambda_t_1[TAM_C*f + c] - lambda_d_1[TAM_C*f + c] )/(2.0) ;
      lambda_w_2[TAM_C*f + c]= (  lambda_t_2[TAM_C*f + c] - lambda_d_2[TAM_C*f + c] )/(2.0) ;
      lambda_w_3[TAM_C*f + c]= (  lambda_t_3[TAM_C*f + c] - lambda_d_3[TAM_C*f + c] )/(2.0) ;
      lambda_w_4[TAM_C*f + c]= (  lambda_t_4[TAM_C*f + c] - lambda_d_4[TAM_C*f + c] )/(2.0) ;
    }
  }
  
  
} 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calcular_U_w_1_2_3_4(){
  
  
  int c=0;
  int f=0;
  
  for(f=1 ; f<(TAM_F-1) ; f++){
    for(c=1 ; c<(TAM_C-1) ; c++){
      U_w_1[TAM_C*f + c]= -1.0*(lambda_w_1[TAM_C*f + c])*( presion_w[TAM_C*f + (c-1)] - presion_w[TAM_C*f + c]  )*TAM_C;
      U_w_2[TAM_C*f + c]= -1.0*(lambda_w_2[TAM_C*f + c])*( presion_w[TAM_C*f + (c+1)] - presion_w[TAM_C*f + c]  )*TAM_C;
      U_w_3[TAM_C*f + c]= -1.0*(lambda_w_3[TAM_C*f + c])*( presion_w[TAM_C*(f-1) + c] - presion_w[TAM_C*f + c]  )*TAM_C;
      U_w_4[TAM_C*f + c]= -1.0*(lambda_w_4[TAM_C*f + c])*( presion_w[TAM_C*(f+1) + c] - presion_w[TAM_C*f + c]  )*TAM_C;
    }
  }
 
 
/* Borde izquierdo   c=0 */ 
 for(f=1 ; f<(TAM_F-1) ; f++){
    c=0;
      U_w_1[TAM_C*f + c]=0.0;// -1.0*(lambda_w_1[TAM_C*f + c])*( presion_w[TAM_C*f + (c-1)] - presion_w[TAM_C*f + c]  )*TAM_C;
      U_w_2[TAM_C*f + c]= -1.0*(lambda_w_2[TAM_C*f + c])*( presion_w[TAM_C*f + (c+1)] - presion_w[TAM_C*f + c]  )*TAM_C;
      U_w_3[TAM_C*f + c]= -1.0*(lambda_w_3[TAM_C*f + c])*( presion_w[TAM_C*(f-1) + c] - presion_w[TAM_C*f + c]  )*TAM_C;
      U_w_4[TAM_C*f + c]= -1.0*(lambda_w_4[TAM_C*f + c])*( presion_w[TAM_C*(f+1) + c] - presion_w[TAM_C*f + c]  )*TAM_C;
 
  }
  
  
/* Borde derecho c=TAM_C -1*/  

for(f=1 ; f<(TAM_F-1) ; f++){
    c=TAM_C -1 ;
      U_w_1[TAM_C*f + c]= -1.0*(lambda_w_1[TAM_C*f + c])*( presion_w[TAM_C*f + (c-1)] - presion_w[TAM_C*f + c]  )*TAM_C;
      U_w_2[TAM_C*f + c]=0.0;// -1.0*(lambda_w_2[TAM_C*f + c])*( presion_w[TAM_C*f + (c+1)] - presion_w[TAM_C*f + c]  )*TAM_C;
      U_w_3[TAM_C*f + c]= -1.0*(lambda_w_3[TAM_C*f + c])*( presion_w[TAM_C*(f-1) + c] - presion_w[TAM_C*f + c]  )*TAM_C;
      U_w_4[TAM_C*f + c]= -1.0*(lambda_w_4[TAM_C*f + c])*( presion_w[TAM_C*(f+1) + c] - presion_w[TAM_C*f + c]  )*TAM_C;

  }
 
/* Borde superior f=0*/ 
 
 
    for(c=1 ; c<(TAM_C-1) ; c++){
      f=0;
      U_w_1[TAM_C*f + c]= -1.0*(lambda_w_1[TAM_C*f + c])*( presion_w[TAM_C*f + (c-1)] - presion_w[TAM_C*f + c]  )*TAM_C;
      U_w_2[TAM_C*f + c]= -1.0*(lambda_w_2[TAM_C*f + c])*( presion_w[TAM_C*f + (c+1)] - presion_w[TAM_C*f + c]  )*TAM_C;
      U_w_3[TAM_C*f + c]=0.0;// -1.0*(lambda_w_3[TAM_C*f + c])*( presion_w[TAM_C*(f-1) + c] - presion_w[TAM_C*f + c]  )*TAM_C;
      U_w_4[TAM_C*f + c]= -1.0*(lambda_w_4[TAM_C*f + c])*( presion_w[TAM_C*(f+1) + c] - presion_w[TAM_C*f + c]  )*TAM_C;
    }
  
/* Borde inferior f=TAM_F -1*/
 

    for(c=1 ; c<(TAM_C-1) ; c++){
      f=TAM_F -1 ;
      U_w_1[TAM_C*f + c]= -1.0*(lambda_w_1[TAM_C*f + c])*( presion_w[TAM_C*f + (c-1)] - presion_w[TAM_C*f + c]  )*TAM_C;
      U_w_2[TAM_C*f + c]= -1.0*(lambda_w_2[TAM_C*f + c])*( presion_w[TAM_C*f + (c+1)] - presion_w[TAM_C*f + c]  )*TAM_C;
      U_w_3[TAM_C*f + c]= -1.0*(lambda_w_3[TAM_C*f + c])*( presion_w[TAM_C*(f-1) + c] - presion_w[TAM_C*f + c]  )*TAM_C;
      U_w_4[TAM_C*f + c]= 0.0;//-1.0*(lambda_w_4[TAM_C*f + c])*( presion_w[TAM_C*(f+1) + c] - presion_w[TAM_C*f + c]  )*TAM_C;
    }
  

/* esquina superior izquierda c=0 f=0*/  
 
 c=0;
 f=0;
 U_w_1[TAM_C*f + c]=0.0;// -1.0*(lambda_w_1[TAM_C*f + c])*( presion_w[TAM_C*f + (c-1)] - presion_w[TAM_C*f + c]  )*TAM_C;
 U_w_2[TAM_C*f + c]= -1.0*(lambda_w_2[TAM_C*f + c])*( presion_w[TAM_C*f + (c+1)] - presion_w[TAM_C*f + c]  )*TAM_C;
 U_w_3[TAM_C*f + c]=0.0;// -1.0*(lambda_w_3[TAM_C*f + c])*( presion_w[TAM_C*(f-1) + c] - presion_w[TAM_C*f + c]  )*TAM_C;
 U_w_4[TAM_C*f + c]= -1.0*(lambda_w_4[TAM_C*f + c])*( presion_w[TAM_C*(f+1) + c] - presion_w[TAM_C*f + c]  )*TAM_C;

/* esquina superior derecha c= TAM_C -1 f=0*/ 
 
 c=TAM_C -1;
 f=0;
U_w_1[TAM_C*f + c]= -1.0*(lambda_w_1[TAM_C*f + c])*( presion_w[TAM_C*f + (c-1)] - presion_w[TAM_C*f + c]  )*TAM_C;
U_w_2[TAM_C*f + c]=0.0;// -1.0*(lambda_w_2[TAM_C*f + c])*( presion_w[TAM_C*f + (c+1)] - presion_w[TAM_C*f + c]  )*TAM_C;
U_w_3[TAM_C*f + c]=0.0;// -1.0*(lambda_w_3[TAM_C*f + c])*( presion_w[TAM_C*(f-1) + c] - presion_w[TAM_C*f + c]  )*TAM_C;
U_w_4[TAM_C*f + c]= -1.0*(lambda_w_4[TAM_C*f + c])*( presion_w[TAM_C*(f+1) + c] - presion_w[TAM_C*f + c]  )*TAM_C;

 
/* esquina inferior izquierda  c=0  f=TAM_F -1*/ 
 
 c=0;
 f=TAM_F -1;
 U_w_1[TAM_C*f + c]=0.0;// -1.0*(lambda_w_1[TAM_C*f + c])*( presion_w[TAM_C*f + (c-1)] - presion_w[TAM_C*f + c]  )*TAM_C;
 U_w_2[TAM_C*f + c]= -1.0*(lambda_w_2[TAM_C*f + c])*( presion_w[TAM_C*f + (c+1)] - presion_w[TAM_C*f + c]  )*TAM_C;
 U_w_3[TAM_C*f + c]= -1.0*(lambda_w_3[TAM_C*f + c])*( presion_w[TAM_C*(f-1) + c] - presion_w[TAM_C*f + c]  )*TAM_C;
 U_w_4[TAM_C*f + c]=0.0;// -1.0*(lambda_w_4[TAM_C*f + c])*( presion_w[TAM_C*(f+1) + c] - presion_w[TAM_C*f + c]  )*TAM_C;

 
/* esquina inferior derecha c=TAM_C -1  f= TAM_F -1*/ 
 c=TAM_C -1;
 f=TAM_F -1;
 U_w_1[TAM_C*f + c]= -1.0*(lambda_w_1[TAM_C*f + c])*( presion_w[TAM_C*f + (c-1)] - presion_w[TAM_C*f + c]  )*TAM_C;
 U_w_2[TAM_C*f + c]=0.0;// -1.0*(lambda_w_2[TAM_C*f + c])*( presion_w[TAM_C*f + (c+1)] - presion_w[TAM_C*f + c]  )*TAM_C;
 U_w_3[TAM_C*f + c]= -1.0*(lambda_w_3[TAM_C*f + c])*( presion_w[TAM_C*(f-1) + c] - presion_w[TAM_C*f + c]  )*TAM_C;
 U_w_4[TAM_C*f + c]=0.0;// -1.0*(lambda_w_4[TAM_C*f + c])*( presion_w[TAM_C*(f+1) + c] - presion_w[TAM_C*f + c]  )*TAM_C;

  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calcular_U_n_1_2_3_4(){
  
  
  
  int c=0;
  int f=0;
  
  for(f=1 ; f<(TAM_F-1) ; f++){
    for(c=1 ; c<(TAM_C-1) ; c++){
      U_n_1[TAM_C*f + c]= -1.0*(lambda_n_1[TAM_C*f + c])*( presion_n[TAM_C*f + (c-1)] - presion_n[TAM_C*f + c]  )*TAM_C;
      U_n_2[TAM_C*f + c]= -1.0*(lambda_n_2[TAM_C*f + c])*( presion_n[TAM_C*f + (c+1)] - presion_n[TAM_C*f + c]  )*TAM_C;
      U_n_3[TAM_C*f + c]= -1.0*(lambda_n_3[TAM_C*f + c])*( presion_n[TAM_C*(f-1) + c] - presion_n[TAM_C*f + c]  )*TAM_C;
      U_n_4[TAM_C*f + c]= -1.0*(lambda_n_4[TAM_C*f + c])*( presion_n[TAM_C*(f+1) + c] - presion_n[TAM_C*f + c]  )*TAM_C;
    }
  }
 
 
/* Borde izquierdo   c=0 */ 
 for(f=1 ; f<(TAM_F-1) ; f++){
    c=0;
      U_n_1[TAM_C*f + c]=0.0;// -1.0*(lambda_n_1[TAM_C*f + c])*( presion_n[TAM_C*f + (c-1)] - presion_n[TAM_C*f + c]  )*TAM_C;
      U_n_2[TAM_C*f + c]= -1.0*(lambda_n_2[TAM_C*f + c])*( presion_n[TAM_C*f + (c+1)] - presion_n[TAM_C*f + c]  )*TAM_C;
      U_n_3[TAM_C*f + c]= -1.0*(lambda_n_3[TAM_C*f + c])*( presion_n[TAM_C*(f-1) + c] - presion_n[TAM_C*f + c]  )*TAM_C;
      U_n_4[TAM_C*f + c]= -1.0*(lambda_n_4[TAM_C*f + c])*( presion_n[TAM_C*(f+1) + c] - presion_n[TAM_C*f + c]  )*TAM_C;
 
  }
  
  
/* Borde derecho c=TAM_C -1*/  

for(f=1 ; f<(TAM_F-1) ; f++){
    c=TAM_C -1 ;
      U_n_1[TAM_C*f + c]= -1.0*(lambda_n_1[TAM_C*f + c])*( presion_n[TAM_C*f + (c-1)] - presion_n[TAM_C*f + c]  )*TAM_C;
      U_n_2[TAM_C*f + c]=0.0;// -1.0*(lambda_n_2[TAM_C*f + c])*( presion_n[TAM_C*f + (c+1)] - presion_n[TAM_C*f + c]  )*TAM_C;
      U_n_3[TAM_C*f + c]= -1.0*(lambda_n_3[TAM_C*f + c])*( presion_n[TAM_C*(f-1) + c] - presion_n[TAM_C*f + c]  )*TAM_C;
      U_n_4[TAM_C*f + c]= -1.0*(lambda_n_4[TAM_C*f + c])*( presion_n[TAM_C*(f+1) + c] - presion_n[TAM_C*f + c]  )*TAM_C;

  }
 
/* Borde superior f=0*/ 
 
 
    for(c=1 ; c<(TAM_C-1) ; c++){
      f=0;
      U_n_1[TAM_C*f + c]= -1.0*(lambda_n_1[TAM_C*f + c])*( presion_n[TAM_C*f + (c-1)] - presion_n[TAM_C*f + c]  )*TAM_C;
      U_n_2[TAM_C*f + c]= -1.0*(lambda_n_2[TAM_C*f + c])*( presion_n[TAM_C*f + (c+1)] - presion_n[TAM_C*f + c]  )*TAM_C;
      U_n_3[TAM_C*f + c]=0.0;// -1.0*(lambda_n_3[TAM_C*f + c])*( presion_n[TAM_C*(f-1) + c] - presion_n[TAM_C*f + c]  )*TAM_C;
      U_n_4[TAM_C*f + c]= -1.0*(lambda_n_4[TAM_C*f + c])*( presion_n[TAM_C*(f+1) + c] - presion_n[TAM_C*f + c]  )*TAM_C;
    }
  
/* Borde inferior f=TAM_F -1*/
 

    for(c=1 ; c<(TAM_C-1) ; c++){
      f=TAM_F -1 ;
      U_n_1[TAM_C*f + c]= -1.0*(lambda_n_1[TAM_C*f + c])*( presion_n[TAM_C*f + (c-1)] - presion_n[TAM_C*f + c]  )*TAM_C;
      U_n_2[TAM_C*f + c]= -1.0*(lambda_n_2[TAM_C*f + c])*( presion_n[TAM_C*f + (c+1)] - presion_n[TAM_C*f + c]  )*TAM_C;
      U_n_3[TAM_C*f + c]= -1.0*(lambda_n_3[TAM_C*f + c])*( presion_n[TAM_C*(f-1) + c] - presion_n[TAM_C*f + c]  )*TAM_C;
      U_n_4[TAM_C*f + c]= 0.0;//-1.0*(lambda_n_4[TAM_C*f + c])*( presion_n[TAM_C*(f+1) + c] - presion_n[TAM_C*f + c]  )*TAM_C;
    }
  

/* esquina superior izquierda c=0 f=0*/  
 
 c=0;
 f=0;
 U_n_1[TAM_C*f + c]=0.0;// -1.0*(lambda_n_1[TAM_C*f + c])*( presion_n[TAM_C*f + (c-1)] - presion_n[TAM_C*f + c]  )*TAM_C;
 U_n_2[TAM_C*f + c]= -1.0*(lambda_n_2[TAM_C*f + c])*( presion_n[TAM_C*f + (c+1)] - presion_n[TAM_C*f + c]  )*TAM_C;
 U_n_3[TAM_C*f + c]=0.0;// -1.0*(lambda_n_3[TAM_C*f + c])*( presion_n[TAM_C*(f-1) + c] - presion_n[TAM_C*f + c]  )*TAM_C;
 U_n_4[TAM_C*f + c]= -1.0*(lambda_n_4[TAM_C*f + c])*( presion_n[TAM_C*(f+1) + c] - presion_n[TAM_C*f + c]  )*TAM_C;

/* esquina superior derecha c= TAM_C -1 f=0*/ 
 
 c=TAM_C -1;
 f=0;
U_n_1[TAM_C*f + c]= -1.0*(lambda_n_1[TAM_C*f + c])*( presion_n[TAM_C*f + (c-1)] - presion_n[TAM_C*f + c]  )*TAM_C;
U_n_2[TAM_C*f + c]=0.0;// -1.0*(lambda_n_2[TAM_C*f + c])*( presion_n[TAM_C*f + (c+1)] - presion_n[TAM_C*f + c]  )*TAM_C;
U_n_3[TAM_C*f + c]=0.0;// -1.0*(lambda_n_3[TAM_C*f + c])*( presion_n[TAM_C*(f-1) + c] - presion_n[TAM_C*f + c]  )*TAM_C;
U_n_4[TAM_C*f + c]= -1.0*(lambda_n_4[TAM_C*f + c])*( presion_n[TAM_C*(f+1) + c] - presion_n[TAM_C*f + c]  )*TAM_C;

 
/* esquina inferior izquierda  c=0  f=TAM_F -1*/ 
 
 c=0;
 f=TAM_F -1;
 U_n_1[TAM_C*f + c]=0.0;// -1.0*(lambda_n_1[TAM_C*f + c])*( presion_n[TAM_C*f + (c-1)] - presion_n[TAM_C*f + c]  )*TAM_C;
 U_n_2[TAM_C*f + c]= -1.0*(lambda_n_2[TAM_C*f + c])*( presion_n[TAM_C*f + (c+1)] - presion_n[TAM_C*f + c]  )*TAM_C;
 U_n_3[TAM_C*f + c]= -1.0*(lambda_n_3[TAM_C*f + c])*( presion_n[TAM_C*(f-1) + c] - presion_n[TAM_C*f + c]  )*TAM_C;
 U_n_4[TAM_C*f + c]=0.0;// -1.0*(lambda_n_4[TAM_C*f + c])*( presion_n[TAM_C*(f+1) + c] - presion_n[TAM_C*f + c]  )*TAM_C;

 
/* esquina inferior derecha c=TAM_C -1  f= TAM_F -1*/ 
 c=TAM_C -1;
 f=TAM_F -1;
 U_n_1[TAM_C*f + c]= -1.0*(lambda_n_1[TAM_C*f + c])*( presion_n[TAM_C*f + (c-1)] - presion_n[TAM_C*f + c]  )*TAM_C;
 U_n_2[TAM_C*f + c]=0.0;// -1.0*(lambda_n_2[TAM_C*f + c])*( presion_n[TAM_C*f + (c+1)] - presion_n[TAM_C*f + c]  )*TAM_C;
 U_n_3[TAM_C*f + c]= -1.0*(lambda_n_3[TAM_C*f + c])*( presion_n[TAM_C*(f-1) + c] - presion_n[TAM_C*f + c]  )*TAM_C;
 U_n_4[TAM_C*f + c]=0.0;// -1.0*(lambda_n_4[TAM_C*f + c])*( presion_n[TAM_C*(f+1) + c] - presion_n[TAM_C*f + c]  )*TAM_C;

  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calcular_U_t_1_2_3_4(){
 
  int c=0;
  int f=0;
  
  for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      U_t_1[TAM_C*f + c]= 1.0*(U_n_1[TAM_C*f + c] + U_w_1[TAM_C*f + c]) ;
      U_t_2[TAM_C*f + c]= 1.0*(U_n_2[TAM_C*f + c] + U_w_2[TAM_C*f + c]) ;
      U_t_3[TAM_C*f + c]= 1.0*(U_n_3[TAM_C*f + c] + U_w_3[TAM_C*f + c]) ;
      U_t_4[TAM_C*f + c]= 1.0*(U_n_4[TAM_C*f + c] + U_w_4[TAM_C*f + c]) ;
    }
  }
  
  //printf(" \n U_t_1 = %f    U_t_2 = %f    U_t_3 = %f    U_t_4 = %f",U_t_1[TAM_C*0 + 0],U_t_2[TAM_C*0 + 0],U_t_3[TAM_C*0 + 0],U_t_4[TAM_C*0 + 0]);
  
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calcular_f_w(){
  
  int c=0;
  int f=0;
  double arriba=0.0;
  double abajo=0.0;
  
  for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      arriba= saturacion[TAM_C*f + c]*saturacion[TAM_C*f + c] ;
      abajo= arriba + (((1.0*mu_w)/(1.0*mu_n))*(1-saturacion[TAM_C*f + c])*(1-saturacion[TAM_C*f + c])) ;
      f_w[TAM_C*f + c]= (1.0*arriba)/(1.0*abajo);
    }
  }
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void delta_tiempo(){
  
  double delta_x=1.0/TAM_C;
  delta_t=courant*delta_x*delta_x ;
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void calcular_lambda_t_1_2_3_4_A(){
  
  int c=0;
  int f=0;
  
  for(f=1 ; f<(TAM_F-1) ; f++){
    for(c=1 ; c<(TAM_C-1) ; c++){
            
      lambda_t_1[TAM_C*f + c]= ( lambda_t[TAM_C*(f) + (c-1)] + lambda_t[TAM_C*f + c]    )*0.5 ;
      lambda_t_2[TAM_C*f + c]= ( lambda_t[TAM_C*(f) + (c+1)] + lambda_t[TAM_C*f + c]    )*0.5 ; 
      lambda_t_3[TAM_C*f + c]= ( lambda_t[TAM_C*(f-1) + (c)] + lambda_t[TAM_C*f + c]    )*0.5 ;
      lambda_t_4[TAM_C*f + c]= ( lambda_t[TAM_C*(f+1) + (c)] + lambda_t[TAM_C*f + c]    )*0.5 ;
      //printf("\n fila=%i columna=%i   lambda total 2 =%f",f,c,lambda_t_2[TAM_C*f + c]);
      
      
    }
  }
 
 
/* Borde izquierdo   c=0 */ 
 for(f=1 ; f<(TAM_F-1) ; f++){
    c=0;
      lambda_t_1[TAM_C*f + c]=0.0;// ( lambda_t[TAM_C*(f) + (c-1)] + lambda_t[TAM_C*f + c]    )*0.5 ;
      lambda_t_2[TAM_C*f + c]= ( lambda_t[TAM_C*(f) + (c+1)] + lambda_t[TAM_C*f + c]    )*0.5 ; 
      lambda_t_3[TAM_C*f + c]= ( lambda_t[TAM_C*(f-1) + (c)] + lambda_t[TAM_C*f + c]    )*0.5 ;
      lambda_t_4[TAM_C*f + c]= ( lambda_t[TAM_C*(f+1) + (c)] + lambda_t[TAM_C*f + c]    )*0.5 ;

  }
  
  
/* Borde derecho c=TAM_C -1*/  

for(f=1 ; f<(TAM_F-1) ; f++){
    c=TAM_C -1 ;
      lambda_t_1[TAM_C*f + c]= ( lambda_t[TAM_C*(f) + (c-1)] + lambda_t[TAM_C*f + c]    )*0.5 ;
      lambda_t_2[TAM_C*f + c]=0.0;// ( lambda_t[TAM_C*(f) + (c+1)] + lambda_t[TAM_C*f + c]    )*0.5 ; 
      lambda_t_3[TAM_C*f + c]= ( lambda_t[TAM_C*(f-1) + (c)] + lambda_t[TAM_C*f + c]    )*0.5 ;
      lambda_t_4[TAM_C*f + c]= ( lambda_t[TAM_C*(f+1) + (c)] + lambda_t[TAM_C*f + c]    )*0.5 ;
    
  }
 
/* Borde superior f=0*/ 
 
 
    for(c=1 ; c<(TAM_C-1) ; c++){
      f=0;
      lambda_t_1[TAM_C*f + c]= ( lambda_t[TAM_C*(f) + (c-1)] + lambda_t[TAM_C*f + c]    )*0.5 ;
      lambda_t_2[TAM_C*f + c]= ( lambda_t[TAM_C*(f) + (c+1)] + lambda_t[TAM_C*f + c]    )*0.5 ; 
      lambda_t_3[TAM_C*f + c]=0.0;// ( lambda_t[TAM_C*(f-1) + (c)] + lambda_t[TAM_C*f + c]    )*0.5 ;
      lambda_t_4[TAM_C*f + c]= ( lambda_t[TAM_C*(f+1) + (c)] + lambda_t[TAM_C*f + c]    )*0.5 ;
    }
  
/* Borde inferior f=TAM_F -1*/
 

    for(c=1 ; c<(TAM_C-1) ; c++){
      f=TAM_F -1 ;
      lambda_t_1[TAM_C*f + c]= ( lambda_t[TAM_C*(f) + (c-1)] + lambda_t[TAM_C*f + c]    )*0.5 ;
      lambda_t_2[TAM_C*f + c]= ( lambda_t[TAM_C*(f) + (c+1)] + lambda_t[TAM_C*f + c]    )*0.5 ; 
      lambda_t_3[TAM_C*f + c]= ( lambda_t[TAM_C*(f-1) + (c)] + lambda_t[TAM_C*f + c]    )*0.5 ;
      lambda_t_4[TAM_C*f + c]=0.0;// ( lambda_t[TAM_C*(f+1) + (c)] + lambda_t[TAM_C*f + c]    )*0.5 ;

    }
  

/* esquina superior izquierda c=0 f=0*/  
 
 c=0;
 f=0;
 lambda_t_1[TAM_C*f + c]=0.0;// ( lambda_t[TAM_C*(f) + (c-1)] + lambda_t[TAM_C*f + c]    )*0.5 ;
 lambda_t_2[TAM_C*f + c]= ( lambda_t[TAM_C*(f) + (c+1)] + lambda_t[TAM_C*f + c]    )*0.5 ; 
 lambda_t_3[TAM_C*f + c]=0.0;// ( lambda_t[TAM_C*(f-1) + (c)] + lambda_t[TAM_C*f + c]    )*0.5 ;
 lambda_t_4[TAM_C*f + c]= ( lambda_t[TAM_C*(f+1) + (c)] + lambda_t[TAM_C*f + c]    )*0.5 ;

/* esquina superior derecha c= TAM_C -1 f=0*/ 
 
 c=TAM_C -1;
 f=0;
 lambda_t_1[TAM_C*f + c]= ( lambda_t[TAM_C*(f) + (c-1)] + lambda_t[TAM_C*f + c]    )*0.5 ;
 lambda_t_2[TAM_C*f + c]=0.0;// ( lambda_t[TAM_C*(f) + (c+1)] + lambda_t[TAM_C*f + c]    )*0.5 ; 
 lambda_t_3[TAM_C*f + c]=0.0;// ( lambda_t[TAM_C*(f-1) + (c)] + lambda_t[TAM_C*f + c]    )*0.5 ;
 lambda_t_4[TAM_C*f + c]= ( lambda_t[TAM_C*(f+1) + (c)] + lambda_t[TAM_C*f + c]    )*0.5 ;

 
/* esquina inferior izquierda  c=0  f=TAM_F -1*/ 
 
 c=0;
 f=TAM_F -1;
 lambda_t_1[TAM_C*f + c]=0.0;// ( lambda_t[TAM_C*(f) + (c-1)] + lambda_t[TAM_C*f + c]    )*0.5 ;
 lambda_t_2[TAM_C*f + c]= ( lambda_t[TAM_C*(f) + (c+1)] + lambda_t[TAM_C*f + c]    )*0.5 ; 
 lambda_t_3[TAM_C*f + c]= ( lambda_t[TAM_C*(f-1) + (c)] + lambda_t[TAM_C*f + c]    )*0.5 ;
 lambda_t_4[TAM_C*f + c]=0.0;// ( lambda_t[TAM_C*(f+1) + (c)] + lambda_t[TAM_C*f + c]    )*0.5 ;

 
/* esquina inferior derecha c=TAM_C -1  f= TAM_F -1*/ 
 c=TAM_C -1;
 f=TAM_F -1;
 lambda_t_1[TAM_C*f + c]= ( lambda_t[TAM_C*(f) + (c-1)] + lambda_t[TAM_C*f + c]    )*0.5 ;
 lambda_t_2[TAM_C*f + c]=0.0;// ( lambda_t[TAM_C*(f) + (c+1)] + lambda_t[TAM_C*f + c]    )*0.5 ; 
 lambda_t_3[TAM_C*f + c]= ( lambda_t[TAM_C*(f-1) + (c)] + lambda_t[TAM_C*f + c]    )*0.5 ;
 lambda_t_4[TAM_C*f + c]=0.0;// ( lambda_t[TAM_C*(f+1) + (c)] + lambda_t[TAM_C*f + c]    )*0.5 ;


}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void calculo_velocidad(){
   int f=0;
   int c=0;
  
  
    for(f=0 ; f<(TAM_F) ; f++){
      for(c=0 ; c<(TAM_C) ; c++){
	velocidad[TAM_C*f + c]= pow(U_t_2[TAM_C*f + c]*U_t_2[TAM_C*f + c] + U_t_4[TAM_C*f + c]*U_t_4[TAM_C*f + c],0.5)  ;
      }
    }
    
  
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void calculo_integral(){
  
 
   int f=0;
   int c=0;
   *integral=0.0;
  
    for(f=0 ; f<(TAM_F-1) ; f++){
      for(c=0 ; c<(TAM_C-1) ; c++){
	*integral= *integral + saturacion[TAM_C*f + c]*(1.0/TAM_C)*(1.0/TAM_C)  ;
      }
    }
    
  
  
  
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void alocar_variables(){
  
  


  
  
  presion=malloc(sizeof(double)*TAM_C*TAM_F);
  presion_N=malloc(sizeof(double)*TAM_C*TAM_F);
  presion_capilar=malloc(sizeof(double)*TAM_C*TAM_F);
  
  saturacion=malloc(sizeof(double)*TAM_C*TAM_F);
  saturacion_N=malloc(sizeof(double)*TAM_C*TAM_F);
  
  Q_W=malloc(sizeof(double)*TAM_C*TAM_F);
  Q_N=malloc(sizeof(double)*TAM_C*TAM_F);
  
  K=malloc(8+sizeof(double)*TAM_C*TAM_F);
  
  lambda_n=malloc(sizeof(double)*TAM_C*TAM_F);
  lambda_w=malloc(sizeof(double)*TAM_C*TAM_F);
  
  krn=malloc(sizeof(double)*TAM_C*TAM_F);
  krw=malloc(sizeof(double)*TAM_C*TAM_F);
  
  lambda_t=malloc(sizeof(double)*TAM_C*TAM_F);
  lambda_d=malloc(sizeof(double)*TAM_C*TAM_F);
  
  termino_presion_capilar=malloc(sizeof(double)*TAM_C*TAM_F);
  
  lambda_d_1=malloc(sizeof(double)*TAM_C*TAM_F);
  lambda_d_2=malloc(sizeof(double)*TAM_C*TAM_F);
  lambda_d_3=malloc(sizeof(double)*TAM_C*TAM_F);
  lambda_d_4=malloc(sizeof(double)*TAM_C*TAM_F);

  lambda_t_1=malloc(sizeof(double)*TAM_C*TAM_F);
  lambda_t_2=malloc(sizeof(double)*TAM_C*TAM_F);
  lambda_t_3=malloc(sizeof(double)*TAM_C*TAM_F);
  lambda_t_4=malloc(sizeof(double)*TAM_C*TAM_F);

  presion_n=malloc(sizeof(double)*TAM_C*TAM_F);
  presion_w=malloc(sizeof(double)*TAM_C*TAM_F);
  
  
  lambda_n_1=malloc(sizeof(double)*TAM_C*TAM_F);
  lambda_n_2=malloc(sizeof(double)*TAM_C*TAM_F);
  lambda_n_3=malloc(sizeof(double)*TAM_C*TAM_F);
  lambda_n_4=malloc(sizeof(double)*TAM_C*TAM_F);

  lambda_w_1=malloc(sizeof(double)*TAM_C*TAM_F);
  lambda_w_2=malloc(sizeof(double)*TAM_C*TAM_F);
  lambda_w_3=malloc(sizeof(double)*TAM_C*TAM_F);
  lambda_w_4=malloc(sizeof(double)*TAM_C*TAM_F);
  
  U_w_1=malloc(sizeof(double)*TAM_C*TAM_F);
  U_w_2=malloc(sizeof(double)*TAM_C*TAM_F);
  U_w_3=malloc(sizeof(double)*TAM_C*TAM_F);
  U_w_4=malloc(sizeof(double)*TAM_C*TAM_F);
  
  U_n_1=malloc(sizeof(double)*TAM_C*TAM_F);
  U_n_2=malloc(sizeof(double)*TAM_C*TAM_F);
  U_n_3=malloc(sizeof(double)*TAM_C*TAM_F);
  U_n_4=malloc(sizeof(double)*TAM_C*TAM_F);
  
  U_t_1=malloc(sizeof(double)*TAM_C*TAM_F);
  U_t_2=malloc(sizeof(double)*TAM_C*TAM_F);
  U_t_3=malloc(sizeof(double)*TAM_C*TAM_F);
  U_t_4=malloc(sizeof(double)*TAM_C*TAM_F);
  
  
  vel_1=malloc(sizeof(double)*TAM_C*TAM_F);
  vel_2=malloc(sizeof(double)*TAM_C*TAM_F);
  vel_3=malloc(sizeof(double)*TAM_C*TAM_F);
  vel_4=malloc(sizeof(double)*TAM_C*TAM_F);
  
  
  
  
  
  f_w=malloc(sizeof(double)*TAM_C*TAM_F);
  
  velocidad=malloc(sizeof(double)*TAM_C*TAM_F);
  
  integral=malloc(sizeof(double));
  integral_total=malloc(sizeof(double)*iteraciones); 
  
  
  
}





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void inicializar_variables(){
  inicializar_presion();
  
  /// decido si seteo la saturacion en el programa o la cargo por medio de un archivo externo
  if(saturacion_seteo==0){
  inicializar_saturacion();
  }
  else if(saturacion_seteo==1){
  leer_o(saturacion,1);  
  }
  ///
  
  inicializar_Q_N();
  inicializar_Q_W();
  
  /// decido si seteo la permeabilidad en el programa o la cargo por medio de un archivo externo
  if(permeabilidad_seteo==0){
  inicializar_K();
  }
  else if(permeabilidad_seteo){
  leer_o(K,2);  
  }
  ///
  }


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void calcular_lambdas(){
  
  
  calcular_lambda_w();
  calcular_lambda_n();
  calcular_lambda_t();
  calcular_lambda_d();
  
  calcular_lambda_d_1_2_3_4(); //_C
  calcular_lambda_t_1_2_3_4_A(); //_C
  
  calcular_lambda_n_1_2_3_4();
  calcular_lambda_w_1_2_3_4();
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void calcular_velocidades(){
  
  calcular_U_w_1_2_3_4();
  calcular_U_n_1_2_3_4();
  calcular_U_t_1_2_3_4();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void control_bandera(int columna){
  
  int f=0;
  int c=0;
  //c=control;
  c=columna;
  
      for(f=0 ; f<(TAM_F-1) ; f++){
       if(saturacion[TAM_C*f + (c)]>0.01){
	 bandera=1;
      }
    }
    
  
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calcular_lambda_d_1_2_3_4_C(){
  
  int c=0;
  int f=0;
  
/*  
  for(f=1 ; f<(TAM_F-1) ; f++){
    for(c=1 ; c<(TAM_C-1) ; c++){
      lambda_d_1[TAM_C*f + c]=(lambda_d[TAM_C*f + (c-1)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c] + cachito); 
      lambda_d_2[TAM_C*f + c]=(lambda_d[TAM_C*f + (c+1)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c] + cachito); 
      lambda_d_3[TAM_C*f + c]=(lambda_d[TAM_C*(f-1) + (c)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c] + cachito); 
      lambda_d_4[TAM_C*f + c]=(lambda_d[TAM_C*(f+1) + (c)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c] + cachito); 
    }
  }
*/ 

  
  
//////////////////////////////

   for(f=1 ; f<(TAM_F-1) ; f++){
    for(c=1 ; c<(TAM_C-1) ; c++){
      lambda_d_1[TAM_C*f + c]=(lambda_d[TAM_C*f + (c-1)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c] + cachito); 
      lambda_d_2[TAM_C*f + c]=(lambda_d[TAM_C*f + (c+1)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c] + cachito); 
      lambda_d_3[TAM_C*f + c]=(lambda_d[TAM_C*(f-1) + (c)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c] + cachito); 
      lambda_d_4[TAM_C*f + c]=(lambda_d[TAM_C*(f+1) + (c)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c] + cachito); 
    }
  }
 
  
  
  
  
  
  
 
/* Borde izquierdo   c=0 */ 
 for(f=1 ; f<(TAM_F-1) ; f++){
    c=0;
      /*
      lambda_d_1[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c])/(2.0);
      lambda_d_2[TAM_C*f + c]=(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c])/(2.0); 
      lambda_d_3[TAM_C*f + c]=(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c])/(2.0); 
      lambda_d_4[TAM_C*f + c]=(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c])/(2.0);
      */
      
      lambda_d_1[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*f + (c-1)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c] + cachito); 
      lambda_d_2[TAM_C*f + c]=(lambda_d[TAM_C*f + (c+1)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c] + cachito); 
      lambda_d_3[TAM_C*f + c]=(lambda_d[TAM_C*(f-1) + (c)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c] + cachito); 
      lambda_d_4[TAM_C*f + c]=(lambda_d[TAM_C*(f+1) + (c)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c] + cachito); 

      
      
    
  }
  
  
/* Borde derecho c=TAM_C -1*/  

for(f=1 ; f<(TAM_F-1) ; f++){
    c=TAM_C -1 ;
    /*
      lambda_d_1[TAM_C*f + c]=(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c])/(2.0);
      lambda_d_2[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c])/(2.0); 
      lambda_d_3[TAM_C*f + c]=(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c])/(2.0); 
      lambda_d_4[TAM_C*f + c]=(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c])/(2.0);
      */
    
      lambda_d_1[TAM_C*f + c]=(lambda_d[TAM_C*f + (c-1)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c] + cachito); 
      lambda_d_2[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*f + (c+1)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c] + cachito); 
      lambda_d_3[TAM_C*f + c]=(lambda_d[TAM_C*(f-1) + (c)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c] + cachito); 
      lambda_d_4[TAM_C*f + c]=(lambda_d[TAM_C*(f+1) + (c)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c] + cachito); 

    
  }
 
/* Borde superior f=0*/ 
 
 
    for(c=1 ; c<(TAM_C-1) ; c++){
      f=0;
      /*
      lambda_d_1[TAM_C*f + c]=(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c])/(2.0);
      lambda_d_2[TAM_C*f + c]=(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c])/(2.0); 
      lambda_d_3[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c])/(2.0); 
      lambda_d_4[TAM_C*f + c]=(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c])/(2.0);
      */
      
      lambda_d_1[TAM_C*f + c]=(lambda_d[TAM_C*f + (c-1)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c] + cachito); 
      lambda_d_2[TAM_C*f + c]=(lambda_d[TAM_C*f + (c+1)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c] + cachito); 
      lambda_d_3[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*(f-1) + (c)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c] + cachito); 
      lambda_d_4[TAM_C*f + c]=(lambda_d[TAM_C*(f+1) + (c)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c] + cachito); 

    }
  
/* Borde inferior f=TAM_F -1*/
 

    for(c=1 ; c<(TAM_C-1) ; c++){
      f=TAM_F -1 ;
      /*
      lambda_d_1[TAM_C*f + c]=(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c])/(2.0);
      lambda_d_2[TAM_C*f + c]=(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c])/(2.0); 
      lambda_d_3[TAM_C*f + c]=(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c])/(2.0); 
      lambda_d_4[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c])/(2.0);
      */
      
      lambda_d_1[TAM_C*f + c]=(lambda_d[TAM_C*f + (c-1)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c] + cachito); 
      lambda_d_2[TAM_C*f + c]=(lambda_d[TAM_C*f + (c+1)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c] + cachito); 
      lambda_d_3[TAM_C*f + c]=(lambda_d[TAM_C*(f-1) + (c)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c] + cachito); 
      lambda_d_4[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*(f+1) + (c)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c] + cachito); 

    }
  

/* esquina superior izquierda c=0 f=0*/  
 
 c=0;
 f=0;
 /*
 lambda_d_1[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c])/(2.0);
 lambda_d_2[TAM_C*f + c]=(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c])/(2.0); 
 lambda_d_3[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c])/(2.0); 
 lambda_d_4[TAM_C*f + c]=(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c])/(2.0);
 */
 lambda_d_1[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*f + (c-1)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c] + cachito); 
 lambda_d_2[TAM_C*f + c]=(lambda_d[TAM_C*f + (c+1)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c] + cachito); 
 lambda_d_3[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*(f-1) + (c)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c] + cachito); 
 lambda_d_4[TAM_C*f + c]=(lambda_d[TAM_C*(f+1) + (c)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c] + cachito); 


/* esquina superior derecha c= TAM_C -1 f=0*/ 
 
 c=TAM_C -1;
 f=0;
 /*
 lambda_d_1[TAM_C*f + c]=(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c])/(2.0);
 lambda_d_2[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c])/(2.0); 
 lambda_d_3[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c])/(2.0); 
 lambda_d_4[TAM_C*f + c]=(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c])/(2.0);
 */
 lambda_d_1[TAM_C*f + c]=(lambda_d[TAM_C*f + (c-1)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c] + cachito); 
 lambda_d_2[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*f + (c+1)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c] + cachito); 
 lambda_d_3[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*(f-1) + (c)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c] + cachito); 
 lambda_d_4[TAM_C*f + c]=(lambda_d[TAM_C*(f+1) + (c)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c] + cachito); 


 
/* esquina inferior izquierda  c=0  f=TAM_F -1*/ 
 
 c=0;
 f=TAM_F -1;
 /*
 lambda_d_1[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c])/(2.0);
 lambda_d_2[TAM_C*f + c]=(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c])/(2.0); 
 lambda_d_3[TAM_C*f + c]=(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c])/(2.0); 
 lambda_d_4[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c])/(2.0);
 */
 lambda_d_1[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*f + (c-1)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c] + cachito); 
 lambda_d_2[TAM_C*f + c]=(lambda_d[TAM_C*f + (c+1)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c] + cachito); 
 lambda_d_3[TAM_C*f + c]=(lambda_d[TAM_C*(f-1) + (c)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c] + cachito); 
 lambda_d_4[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*(f+1) + (c)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c] + cachito); 


 
/* esquina inferior derecha c=TAM_C -1  f= TAM_F -1*/ 
 c=TAM_C -1;
 f=TAM_F -1;
 /*
 lambda_d_1[TAM_C*f + c]=(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c])/(2.0);
 lambda_d_2[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c])/(2.0); 
 lambda_d_3[TAM_C*f + c]=(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c])/(2.0); 
 lambda_d_4[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c])/(2.0);
 */
 
 lambda_d_1[TAM_C*f + c]=(lambda_d[TAM_C*f + (c-1)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*f + (c-1)] + lambda_d[TAM_C*f + c] + cachito); 
 lambda_d_2[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*f + (c+1)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*f + (c+1)] + lambda_d[TAM_C*f + c] + cachito); 
 lambda_d_3[TAM_C*f + c]=(lambda_d[TAM_C*(f-1) + (c)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*(f-1) + (c)] + lambda_d[TAM_C*f + c] + cachito); 
 lambda_d_4[TAM_C*f + c]=0.0;//(lambda_d[TAM_C*(f+1) + (c)]*lambda_d[TAM_C*f + c])/(lambda_d[TAM_C*(f+1) + (c)] + lambda_d[TAM_C*f + c] + cachito); 



}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int leer(void){


config_t cfg;
config_setting_t *setting;
const char *str;
 config_init(&cfg);
  
  if(! config_read_file(&cfg, "parametros.cfg"))
  {
    fprintf(stderr, "%s:%d - %s\n", config_error_file(&cfg),
            config_error_line(&cfg), config_error_text(&cfg));
    config_destroy(&cfg);
    return(EXIT_FAILURE);
  }





//#define TAM_C 200
config_lookup_float(&cfg,"cantidad_columnas",TAM_C_p);
//#define TAM_F 200
config_lookup_float(&cfg,"cantidad_filas",TAM_F_p);
//#define CB 1   // 0 para una condicion de borde tipo canal y 1 para una tipo FQS
config_lookup_bool(&cfg,"geometria_tipo_FQS",geo_p);
//#define leer_saturacion 0 // 0 para una saturacion seteada en el programa y 1 para cargar una saturacion desde un archivo
config_lookup_bool(&cfg,"cargar_archivo_saturacion",saturacion_seteo_p);
//#define leer_K 1 // 0 para una permeabilidad seteada en el programa y 1 para cargar una permeabilidad desde un archivo
config_lookup_bool(&cfg,"cargar_archivo_permeabilidad",permeabilidad_seteo_p);

//#define mu_w 1.0
config_lookup_float(&cfg,"viscosidad_agua",mu_w_p);
//#define mu_n 64.0
config_lookup_float(&cfg,"viscosidad_petroleo",mu_n_p);
//#define q_n 0.1
config_lookup_float(&cfg,"caudal_petroleo",q_n_p);
//#define q_w 0.1
config_lookup_float(&cfg,"caudal_agua",q_w_p);
//#define po 0.0 // el grafico esta con 0.5
config_lookup_float(&cfg,"presion_capilar",po_p);

//#define cachito 0.0000000001
//#define error 0.0000000001  //0.0000000001 es lo que venia usando.
config_lookup_float(&cfg,"error",error_p);
//#define error_1 0.0000001
config_lookup_float(&cfg,"error_1",error_1_p);
//#define courant 0.1
config_lookup_float(&cfg,"numero_courant",courant_p);
//#define PI 1.0

//#define iteraciones 10000000
config_lookup_float(&cfg,"cantidad_iteraciones",iteraciones_p);

//#define control 195
config_lookup_float(&cfg,"control",control_p);

config_destroy (&cfg);

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void copiar_parametros(void){
  
  
double TAM_C_a=*TAM_C_p;
TAM_C=(int)TAM_C_a;
double TAM_F_a=*TAM_F_p;
TAM_F=(int)TAM_F_a;
CB=*geo_p;
saturacion_seteo=*saturacion_seteo_p;
permeabilidad_seteo=*permeabilidad_seteo_p;
mu_w=*mu_w_p;
mu_n=*mu_n_p;
q_n=*q_n_p;
q_w=*q_w_p;
po=*po_p;
error=*error_p;
error_1=*error_1_p;
courant=*courant_p;
double iteraciones_a=*iteraciones_p;
iteraciones=(int)iteraciones_a;
double control_a=*control_p;
control=(int)control_a;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void liberar_variables(){
  
  


  
  free(TAM_C_p);
  free(TAM_F_p);
  free(geo_p);
  free(saturacion_seteo_p);
  free(permeabilidad_seteo_p);
  free(mu_w_p);
  free(mu_n_p);
  free(q_n_p);
  free(q_w_p);
  free(po_p);
  free(error_p);
  free(error_1_p);
  free(courant_p);
  free(iteraciones_p);
  free(control_p);
  
  
  
  
  free(presion);
  free(presion_N);
  free(presion_capilar);
  free(saturacion);
  free(saturacion_N);
  free(Q_W);
  free(Q_N);
  free(K);
  free(lambda_n);
  free(lambda_w);
  free(krn);
  free(krw);
  free(lambda_t);
  free(lambda_d);
  free(termino_presion_capilar);
    
  free(lambda_d_1);
  free(lambda_d_2);
  free(lambda_d_3);
  free(lambda_d_4);
  
  free(lambda_t_1);
  free(lambda_t_2);
  free(lambda_t_3);
  free(lambda_t_4);

  free(presion_n);
  free(presion_w);
  
    
  free(lambda_n_1);
  free(lambda_n_2);
  free(lambda_n_3);
  free(lambda_n_4);
  
  free(lambda_w_1);
  free(lambda_w_2);
  free(lambda_w_3);
  free(lambda_w_4);
  
  free(U_w_1);
  free(U_w_2);
  free(U_w_3);
  free(U_w_4);
  
  free(U_n_1);
  free(U_n_2);
  free(U_n_3);
  free(U_n_4);
  
  free(U_t_1);
  free(U_t_2);
  free(U_t_3);
  free(U_t_4);
     
  free(vel_1);
  free(vel_2);
  free(vel_3);
  free(vel_4);
  
  free(f_w);
  free(velocidad);
  free(integral);
  free(integral_total);
  
  
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void alocar_parametros(){
  
  


  TAM_C_p=malloc(sizeof(double));
  TAM_F_p=malloc(sizeof(double));
  geo_p=malloc(sizeof(int));
  saturacion_seteo_p=malloc(sizeof(int));
  permeabilidad_seteo_p=malloc(sizeof(int));
  mu_w_p=malloc(sizeof(double));
  mu_n_p=malloc(sizeof(double));
  q_n_p=malloc(sizeof(double));
  q_w_p=malloc(sizeof(double));
  po_p=malloc(sizeof(double));
  error_p=malloc(sizeof(double));
  error_1_p=malloc(sizeof(double));
  courant_p=malloc(sizeof(double));
  iteraciones_p=malloc(sizeof(double));
  control_p=malloc(sizeof(double));
  
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void print(){
  
  
  printf("\n\n.... Programa full V 2.0 .... Corriendo en %i procesadores\n\n\n",np);
  printf("El tamaño del recinto es %i columnas X %i filas\n",TAM_C,TAM_F);
  printf("mu_w = %f	mu_n = %f\n",mu_w,mu_n);
  printf("La presion capilar es %f \n",po);
  printf("El caudal de petroleo es =%f   y el de agua es=%f\n",q_n,q_w);
  printf("el error tolerado es=%f y el segundo error tolerado es =%f \n",error,error_1);
  printf("El numero de courant es %f \n",courant);
  printf("La cantidad de iteraciones es = %i \n",iteraciones);
  printf("el control esta en = %i \n",control);
  
  if(CB==1){
    printf("La geometria del recinto es tipo FQS\n");
  }
  else if(CB==0){
    printf("La geometria del recinto es tipo CANAL\n");
  }
  
  
  if(saturacion_seteo==1){
    printf("Leo la saturacion inicial de un archivo externo\n");
  }
  else if(CB==0){
    printf("Seteo la saturacion inicial desde el programa\n");
  }

  if(permeabilidad_seteo==1){
    printf("Leo la permeabilidad de un archivo externo\n");
  }
  else if(CB==0){
    printf("Seteo la permeabilidad desde el programa\n");
  }

  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void correr(){
  
  int guardo_x_tiempo=1;
  int t=0;
  int t_aux=0;
  double tiempo_total=0.0;
  int bandera_columna=65;
  int resultado_lectura=0;
    
  
  alocar_parametros();
  resultado_lectura=leer();
  copiar_parametros();
  alocar_variables();
  inicializar_variables();
  
  delta_tiempo();
  tiempo_total=delta_t*iteraciones;
  bandera=0;  
  t=1;
  print();
  
while(bandera==0  ){
  //for(t=1 ; t<= iteraciones ; t++){ // Inicio del FOR
  
  calcular_lambdas();
  calcular_presion_capilar();
  calcular_termino_presion_capilar();
  
  t_aux=0;
  diferencia=0.001;
///////////////////////////////////////// Calculo de presion /////////////////////////////////////////  
  if(t==1){  // Inicio del IF ...... Solo para la primera vez que calculo las presiones
   while(diferencia>error && t_aux<10000000){ 
    calculo_presion_paralelo();
    t_aux = t_aux +1;
    //printf("\n iteracion ==%i     ERROR=%f",t_aux,diferencia);
   }
  }// Fin del IF
  
  
  if(t>1){  // Inicio del IF ....... Para todas las veces restantes
   //np_1=1; 
   while(diferencia>error_1 && t_aux<300){ 
    
    calculo_presion_paralelo();
    t_aux = t_aux +1;
   }
  }  // Fin del IF
//////////////////////////////////////////////////////////////////////////////////////////////////////  
  calcular_presion_w();
  calcular_presion_n();
  calcular_lambdas();
  calcular_velocidades();
  calculo_velocidad();
  calcular_f_w();
  
///////////////////////////////////  Calculo de saturacion  //////////////////////////////////////////  
  calculo_saturacion();
  
//////////////////////////////////////////////////////////////////////////////////////////////////////  
  calculo_integral();
  integral_total[t]=*integral;
  printf("\r T=[%i]  Tiempo= %f/%f [ %.3f %%]  iteraciones= %i ",t,t*delta_t,tiempo_total,(t*delta_t*100)/(tiempo_total),t_aux);
  fflush(stdout);
  t=t+1;
  
  if(guardo_x_tiempo==0){
  control_bandera(bandera_columna);
  if(bandera==1){
    guardar_o(saturacion,bandera_columna,1);
    guardar_o(presion,bandera_columna,2);
    guardar_o(presion_capilar,bandera_columna,3);
    bandera_columna=bandera_columna +1;
    }
  }
  
  if(guardo_x_tiempo==1){
    if(t%4000==0 || t==2){          // AL CAMBIAR ESTE 4000 CAMBIO EL TIEMPO ENTRE GUARDADOS..PERO NO OLVIDAR QUE TAMBIEN HAY QUE CAMBIARLO EN GUARDAR_O
    guardar_o(saturacion,t,1);
    guardar_o(presion,t,2);
    guardar_o(presion_capilar,t,3);      
      
    }
  }
  
  
  
  bandera=0;
  control_bandera(control);
}  // Fin del FOR 
  
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
