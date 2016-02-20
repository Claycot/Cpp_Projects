#include <iostream>

using namespace std;

bool is_prime(long long int num_to_check);

int main () {
	const long long int input_num = 600851475143;
	long long int factor_to_check;
	
	//Loop through all integers between 2 and the input number
	for (long long int i = 2; i < input_num; i++) {
		//If the input number can be evenly divided by the integer
		if (input_num % i == 0){
			//Make a variable to store the newly discovered factor
			factor_to_check = input_num / i;
			//Check if the factor is prime
			if (is_prime(factor_to_check)) {
				//Output the factor if prime and end program
				cout << factor_to_check;
				return 0;
			}
		}
	}
}

//Check if integer is prime
bool is_prime(long long int num_to_check) {
	//Loop through all integers between 2 and factor
	for (long long int i = 2; i < num_to_check; i++) {
		//If factor can be evenly divided by the integer
		if (num_to_check % i == 0) {
			//Return false (not a prime number, divisible by i)
			return false;
		}
	}
	//If not divisible by any i where i < integer
	//Return true (yes a prime number)
	return true;
}
