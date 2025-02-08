#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

int main() {
	int i;
	clock_t cpu_timer;
	time_t time_mark;
	cout << "[ Analisis de Eficiencia ]" << endl
	     << "-> N: 15000000" << endl
		 << "-> Num. de hilos: 12" << endl << endl;

	// CLOCK()
	cout << "1) Tiempos de CPU" << endl << endl;

	cpu_timer = clock();
	system("./estimate_taylor 15000000");
	cpu_timer = clock() - cpu_timer;
	cout << "	Metodo de Taylor: " << cpu_timer << endl;

	cpu_timer = clock();
	system("./estimate_montecarlo_pthreads 12 15000000");
	cpu_timer = clock() - cpu_timer;
	cout << "	Metodo de Monte Carlo (con hilos): " << cpu_timer << endl;

	cpu_timer = clock();
	system("./estimate_montecarlo_nothreads 15000000");
	cpu_timer = clock() - cpu_timer;
	cout << "	Metodo de Monte Carlo (sin hilos): " << cpu_timer << endl << endl;

	// TIME()
	cout << "2) Tiempos de wall-clock (segundos)" << endl << endl;

	time_mark = time(NULL);
	system("./estimate_taylor 15000000");
	time_mark = time(NULL) - time_mark;
	cout << "	Método de Taylor: " << time_mark << "s" << endl;

	time_mark = time(NULL);
	system("./estimate_montecarlo_pthreads 12 15000000");
	time_mark = time(NULL) - time_mark;
	cout << "	Método de Monte Carlo (con hilos): " << time_mark << "s" << endl;

	time_mark = time(NULL);
	system("./estimate_montecarlo_nothreads 15000000");
	time_mark = time(NULL) - time_mark;
	cout << "	Método de Monte Carlo (sin hilos): " << time_mark << "s" << endl << endl;

	return 0;
}
