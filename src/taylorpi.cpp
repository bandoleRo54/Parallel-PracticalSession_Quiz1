#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

double approximate_pi(int upper_bound) {
    double pi_approximation = 0.0;
    int sign = 1;

    for (int n = 0; n < upper_bound; ++n) {
        pi_approximation += sign * (1.0 / (2 * n + 1));
        sign *= -1;
    }

    return pi_approximation * 4;
}

int main(int argc, char* argv[]) {
    int upper_bound = atoi(argv[1]);

    if (upper_bound > 0) {
		double pi_value = approximate_pi(upper_bound);
		cout << "Approx. value of pi after " << upper_bound << " iterations: " << pi_value << endl;
    }

    return 0;
}
