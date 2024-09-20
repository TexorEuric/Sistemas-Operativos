#include <stdio.h>
#include <pthread.h>

#define ROWS 4       
#define COLS 5       
#define NUM_THREADS 4 

int matriz[ROWS][COLS]; 
int sumas_parciales[NUM_THREADS]; 

void *sumar_fila(void *arg) {
    int fila = *((int *) arg); 
    sumas_parciales[fila] = 0; 

    for (int j = 0; j < COLS; j++) {
        sumas_parciales[fila] += matriz[fila][j];
    }

    pthread_exit(NULL); 
}

int main() {
    pthread_t hilos[NUM_THREADS]; 
    int ids[NUM_THREADS];         
    int suma_total = 0;

    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matriz[i][j] = i + j + 1; 
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i; 
        pthread_create(&hilos[i], NULL, sumar_fila, (void *) &ids[i]); 
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(hilos[i], NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        suma_total += sumas_parciales[i];
    }

    printf("La suma total de la matriz es: %d\n", suma_total);

    return 0;
}
