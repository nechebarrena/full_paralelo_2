#include "full_p_2.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void guardar_o(double *matriz,int num){    // la funcion guardar graba los datos de matriz en un archivo llamado salia-1.dat
  
  FILE *archivo;   // creo el archivo
  char nombre[12];
  char ext[12]=".dat";
  
  
  
  sprintf(nombre,"%d",num);
  int largo = strlen(nombre) ;
  strcat(nombre,ext);
  //printf("\n  el tam del string es =%i \n",largo);
 
  archivo= fopen(nombre,"w+"); //abro el archivo y le asigno el nombre
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
void guardar_v(double *vector,int tam){    // la funcion guardar graba los datos de matriz en un archivo llamado salia-1.dat
  
  FILE *archivo;   // creo el archivo
  archivo= fopen("salida-v.dat","w+"); //abro el archivo y le asigno el nombre
   
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
  
   
  for(f=0 ; f<TAM_F ; f++){
    for(c=0 ; c<TAM_C ; c++){
      K[TAM_C*f + c]= 1.0 ; 
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
  
  K=malloc(sizeof(double)*TAM_C*TAM_F);
  
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
  inicializar_saturacion();
  inicializar_Q_N();
  inicializar_Q_W();
  inicializar_K();
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





