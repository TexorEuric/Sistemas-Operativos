#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // Para usar sleep()

// Estructura para simular un proceso (hilo)
typedef struct {
    int id;
    int tiempo_ejecucion; // Tiempo que tomará el proceso en completarse
} Proceso;

// Función que simula la ejecución de un proceso
void* ejecutar_proceso(void* arg) {
    Proceso* p = (Proceso*)arg;
    printf("Tarea %d: Iniciando, tiempo de ejecución: %d segundos\n", p->id, p->tiempo_ejecucion);
    sleep(p->tiempo_ejecucion); // Simula el tiempo de ejecución
    printf("Tarea %d: Finalizada\n", p->id);
    return NULL;
}

int main() {
    pthread_t hilos[3];  // Tres procesos para este ejemplo
    Proceso procesos[3]; // Arreglo de estructuras Proceso

    // Inicializar los procesos
    for (int i = 0; i < 3; ++i) {
        procesos[i].id = i + 1;
        procesos[i].tiempo_ejecucion = (i + 1) * 2; // Diferentes tiempos de ejecución para cada proceso
    }

    // Crear los hilos (procesos) y ejecutarlos
    for (int i = 0; i < 3; ++i) {
        pthread_create(&hilos[i], NULL, ejecutar_proceso, (void*)&procesos[i]);
    }

    // Esperar a que todos los hilos terminen
    for (int i = 0; i < 3; ++i) {
        pthread_join(hilos[i], NULL);
    }

    printf("Todas las tareas han finalizado\n");
    return 0;
}