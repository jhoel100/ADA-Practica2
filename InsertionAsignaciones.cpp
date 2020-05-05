
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

using namespace std;

float insertionSort(int arr[], int n)  
{  
    int i, key, j;
	 int numero=0;
  
    for (i = 1; i < n; i++) 
    {  
		  //inicia con la posicion 1 (segundo espacio), para correr n-1 posiciones del arreglo
        key = arr[i];
		  //j es un valor anterior al en estudio 
        j = i - 1;  
  
		  //va retrocediendo hasta llegar al inicio posicion 0

        while (j >= 0 && arr[j] > key) 
        {  
			  if(j!=0){
			 		 numero++;
				}
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }
	 return numero;

}  


int main(){

	 int NUM_ELEMENTOS=100;
	 int paso=10;
	 int NUM_PUNTOS=NUM_ELEMENTOS/paso;
	 int NUM_COMANDOS=4;
    // X, Y valores de los puntos a graficar
    double valoresX[NUM_PUNTOS];
    double valoresY[NUM_PUNTOS];
    register int i=0;

	 for(int n=1;n<=NUM_PUNTOS;n++){
		 valoresX[n-1] =n*paso;

		 int arr[n*paso];
		 for(int i=1;i<=n*paso;i++){
			arr[i-1]=n*paso-i+1;
		 }
		 int nn = sizeof(arr) / sizeof(arr[0]);
	    valoresY[n-1]=insertionSort(arr, nn);
		 

		 
	 }



	 //Lee el archivo puntosGraficar par aguardar los valores
    FILE * archivoPuntos = fopen("puntosGraficar.txt", "w");

    /*Guardar los puntos x,y en el archivo de texto creado y abierto previamente*/
    for (i=0;i<NUM_PUNTOS;i++){
 		 fprintf(archivoPuntos, "%lf %lf \n", valoresX[i], valoresY[i]);
 	 }
 
    /*lista de comandos para visualizacion con gnuplot*/
    char * configGnuplot[] = {"set title \"Grafica Insertion Sort(Asignaciones) : NroDatos VS Coste\"", 
                                "set ylabel \"Coste\"",
                                "set xlabel \"NroDatos\"",
                                "plot \"puntosGraficar.txt\" using 1:2 with lines"
                               };

    /*Se crea el archivo para graficar*/
    FILE * ventanaGnuplot = popen ("gnuplot -persist", "w");

    // Ejecuta los comandos del GNU Plot uno por uno
    for (i=0;i<NUM_COMANDOS;i++){
		 fprintf(ventanaGnuplot, "%s \n", configGnuplot[i]);
	 }
 	 
    fclose(archivoPuntos);

    return 0;

}
