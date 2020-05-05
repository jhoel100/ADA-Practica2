
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

using namespace std;

void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

// An optimized version of Bubble Sort 
double bubbleSort(int arr[], int n) { 
	bool swapped;
   int numero=0;

	for (int i = 0; i < n-1; i++) 
	{ 
		swapped = false; 
		for (int j = 0; j < n-i-1; j++) 
		{ 
			numero++;
			
			if (arr[j] > arr[j+1]) 
			{ 
			swap(&arr[j], &arr[j+1]); 
			swapped = true; 
			} 
		}
	// IF no two elements were swapped by inner loop, then break 
		if (swapped == false) 
			break; 
	}
	return numero;
} 

int main(){

	 int NUM_ELEMENTOS=500;
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
	    valoresY[n-1]=bubbleSort(arr, nn);
		 

		 
	 }



	 //Lee el archivo puntosGraficar par aguardar los valores
    FILE * archivoPuntos = fopen("puntosGraficar.txt", "w");

    /*Guardar los puntos x,y en el archivo de texto creado y abierto previamente*/
    for (i=0;i<NUM_PUNTOS;i++){
 		 fprintf(archivoPuntos, "%lf %lf \n", valoresX[i], valoresY[i]);
 	 }
 
    /*lista de comandos para visualizacion con gnuplot*/
    char * configGnuplot[] = {"set title \"Grafica Bubble Sort(Comparaciones) : NroDatos VS Coste\"", 
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
