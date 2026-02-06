#include <iostream>
#include <string>
#include <cctype>
#include <climits>
#include <cmath>
using namespace std;
bool is_valid_number(string str);
unsigned long long int pow(unsigned int a, unsigned int b);
long long sum_of_digits(unsigned long long int number);
vector<int> vectorize_digits(unsigned long long n);
long long sum_vector(vector<int> v);
int main(){
	unsigned long long int power;
	long sum;
	
	string a;
	string b;//String allows for checking if it is a valid entry
	
	cout << "Base: ";
	cin >> a;
	cout << "Exponent: ";
	cin >> b;
	bool a_is_valid_number = is_valid_number(a);
	bool b_is_valid_number = is_valid_number(b);
	if (stoi(b) * log10(stoi(a)) > 64 * log10(2)){//2^64 is the largest number that can be contained in c++
		cout << "Numbers too large!" << endl;
		}
	else if(a_is_valid_number && b_is_valid_number){//Both of them must be valid
		power = pow(stoi(a), stoi(b));//used stoi to change string to int
		cout << a << "^" << b << "=" << power << endl;
		sum = sum_of_digits(power);
		cout << "Sum of digits: " << sum << endl;
		}
	return 0;
}

bool is_valid_number(string str){
	if(str.at(0) == '-'){//The number will be lead by a - if it is negative
		cout << "No negative numbers, please!" << endl;
		return false;
		}
	int i;
	for(i = 0; i < str.length(); ++i){
		if(str.at(i) == '.'){//Catches attempts to input decimals
			cout << "Only integers, please!" << endl;
			return false;
			}
		else if(!isdigit(str.at(i))){//Anything else is just a mistake
			cout << "No letters/nonnumeric characters, please!" << endl;
			return false;
			}
		}
		return true;
	}

unsigned long long int pow(unsigned int a_initial, unsigned int b){
	unsigned long long int a = a_initial;//Stores the actual base
	int i;
	if (b == 0){
		return 1;
	}
	if(a_initial == 0){
		return 0;
		}
	for(i = 1; i < b; ++i){
		a = a * a_initial;//And then multiplies it the required # of times
	}
	return a;
}

long long sum_of_digits(unsigned long long int number){
	vector<int> numbers = vectorize_digits(number);
	long long sum;
	sum = sum_vector(numbers);
	return sum;
}

vector<int> vectorize_digits(unsigned long long n){
	vector<int> digits;
	
	// Handle the case where n is 0
    if (n == 0) {
        return {0};
    }
    
    // Extract digits from right to left
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    
    // Reverse to get the correct order
    reverse(digits.begin(), digits.end());
    
    return digits;
	}

long long sum_vector(vector<int> v) {
    int sum = 0;
    // Iterate through the vector using a for loop
    for (int number : v) {
        sum += number;
    }
    return sum;
}

string vec_to_string(vector<int> vec) {
    string result = "[";

    for (size_t i = 0; i < vec.size(); ++i) {
        // Append the current number
        result += to_string(vec[i]);

        // If it's not the last element, append a comma and a space
        if (i < vec.size() - 1) {
            result += ", ";
        }
    }

    result += "]";
    return result;
}
