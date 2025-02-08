#include <iostream>
#include <cstdlib>
#include <cmath>
#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;

struct ThreadData {
    int tosses_per_thread;
    int points_inside_circle;
};

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int total_points_inside_circle = 0;

// Generacion de valores aleatorios en el rango [-1, 1]
double random_double_generator() {
	return (static_cast<double>(rand()) / RAND_MAX) * 2.0 - 1.0;
}

// Operaciones de los hilos
void* monte_carlo_simulation(void* arg) {
    ThreadData* data = static_cast<ThreadData*>(arg);
    int local_points_inside_circle = 0;

    for (int i = 0; i < data->tosses_per_thread; ++i) {
        double rand_x = random_double_generator();
        double rand_y = random_double_generator();

        if ((rand_x * rand_x) + (rand_y * rand_y) <= 1.0) {
            local_points_inside_circle++;
        }
    }

    pthread_mutex_lock(&mutex);
    total_points_inside_circle += local_points_inside_circle;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(int argc, char* argv[]) {
	int num_threads = atoi(argv[1]);
	int num_tosses = atoi(argv[2]);
	srand(time(NULL));

	if (num_threads > 0 && num_tosses > 0) {
		int tosses_per_thread = num_tosses / num_threads;
		pthread_t threads[num_threads];
		ThreadData thread_data[num_threads];

		int i;
		// Creación y ejecución de calculos con hilos
		for (i = 0; i < num_threads; i++) {
			thread_data[i].tosses_per_thread = tosses_per_thread;
			thread_data[i].points_inside_circle = 0;
			pthread_create(&threads[i], NULL, monte_carlo_simulation, &thread_data[i]);
		}
		// Unión de hilos
		for (i = 0; i < num_threads; i++) {
			pthread_join(threads[i], NULL);
		}

		// Calculate and display the approximation of pi
		double pi_value = 4.0 * total_points_inside_circle / num_tosses;
		cout << "(Using " << num_threads << " threads)" << endl
		     << "Approx. value of pi after " << num_tosses << " tosses: " << pi_value << endl;
		pthread_mutex_destroy(&mutex);
	}

	return 0;
}
