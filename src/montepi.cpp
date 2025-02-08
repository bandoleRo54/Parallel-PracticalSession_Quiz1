#include <iostream>
#include <cstdlib>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

// Generacion de valores aleatorios en el rango [-1, 1]
double random_double_generator() {
	return (static_cast<double>(rand()) / RAND_MAX) * 2.0 - 1.0;
}

double approximate_pi(int num_of_tosses) {
	int i;
	int toss_landed_in_circle = 0;
	double rand_x, rand_y, distance_from_circle_center;

	for (i = 0; i < num_of_tosses; i++) {
		rand_x = random_double_generator();
		rand_y = random_double_generator();

		// r**2 = (x-h)**2 + (y-k)**2
		distance_from_circle_center = (rand_x*rand_x) + (rand_y*rand_y);
		if (distance_from_circle_center <= 1.0) { toss_landed_in_circle++; }
	}

	double pi_approx = 4.0 * toss_landed_in_circle / num_of_tosses;
	return pi_approx;
}

int main(int argc, char* argv[]) {
	int num_of_tosses = atoi(argv[1]);
	srand(time(NULL));

	if (num_of_tosses > 0) {
		double pi_value = approximate_pi(num_of_tosses);
		cout << "Approximated value of pi after " << num_of_tosses << " tosses: " << pi_value << endl;
	}

	return 0;
}

