#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Estructura para pasar múltiples argumentos a la función del hilo
typedef struct {
    int thread_id;
    int* data;
    int start_index;
    int end_index;
    long result; // Almacena el resultado de la operación realizada por el hilo
} ThreadArgs;

// Mutex para evitar condiciones de carrera al acceder a datos compartidos
pthread_mutex_t mutex;

// Función que se ejecutará en cada hilo para sumar un segmento de datos
void* processData(void* args) {
    ThreadArgs* thread_args = (ThreadArgs*)args;
    long local_sum = 0;

    // Procesar el segmento de datos
    for (int i = thread_args->start_index; i <= thread_args->end_index; ++i) {
        local_sum += thread_args->data[i];
    }

    // Protección con mutex para evitar condiciones de carrera
    pthread_mutex_lock(&mutex);
    thread_args->result = local_sum;
    pthread_mutex_unlock(&mutex);

    printf("Hilo %d: suma parcial desde índice %d hasta %d es %ld\n", 
           thread_args->thread_id, thread_args->start_index, thread_args->end_index, local_sum);

    pthread_exit(NULL); // Terminar el hilo
}

int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Datos a procesar
    int data_size = sizeof(data) / sizeof(data[0]);
    int num_threads = 2; // Número de hilos a utilizar
    pthread_t threads[num_threads];
    ThreadArgs thread_args[num_threads];
    int chunk_size = data_size / num_threads; // Dividir los datos en segmentos

    // Inicializar mutex
    pthread_mutex_init(&mutex, NULL);

    // Crear los hilos y asignar segmentos de datos
    for (int i = 0; i < num_threads; i++) {
        thread_args[i].thread_id = i + 1;
        thread_args[i].data = data;
        thread_args[i].start_index = i * chunk_size;
        thread_args[i].end_index = (i == num_threads - 1) ? data_size - 1 : (i + 1) * chunk_size - 1;
        thread_args[i].result = 0;

        if (pthread_create(&threads[i], NULL, processData, (void*)&thread_args[i]) != 0) {
            perror("Error al crear el hilo");
            exit(EXIT_FAILURE);
        }
    }

    // Esperar a que los hilos terminen su ejecución
    long total_sum = 0;
    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Error al unir el hilo");
            exit(EXIT_FAILURE);
        }
        total_sum += thread_args[i].result;
    }

    // Destruir el mutex
    pthread_mutex_destroy(&mutex);

    // Imprimir resultado final
    printf("Hilo principal: La suma total es %ld\n", total_sum);

    return 0;
}

