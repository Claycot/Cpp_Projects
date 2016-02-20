#include <iostream>

using namespace std;

void fibonacci_fill(long long int fibonacci[], int size_fibo);

int main() {
	long long int sum = 0;
	long long int fibonacci[32] = {1, 2};
	fibonacci_fill(fibonacci, 32);
	
	for (int i = 0; i < 32; i++) {
		cout << fibonacci[i] << endl;
	}
	
	for (int i = 0; i < 32; i++) {
		if (fibonacci[i] % 2 == 0) { 
			sum += fibonacci[i];
		}
	}
	
	cout << "The sum is: " << sum;
	
	return 0;
}

void fibonacci_fill(long long int fibonacci[], int size_fibo) {
	for (int i = 2; i < size_fibo; i++) {
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}
}
