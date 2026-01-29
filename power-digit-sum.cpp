#include <iostream>
#include <string>
#include <cctype>
#include <climits>
using namespace std;
bool is_valid_number(string str);
long long pow(int a, int b);
int sum_of_digits(string str);
int main(){
	long long power;
	int sum;
	string a;
	string b;//String allows for checking if it is a valid entry
	
	cout << "Base: ";
	cin >> a;
	cout << "Exponent: ";
	cin >> b;
	bool a_is_valid_number = is_valid_number(a);
	bool b_is_valid_number = is_valid_number(b);
	if(a_is_valid_number && b_is_valid_number){//Both of them must be valid
		power = pow(stoi(a), stoi(b));//used stoi to change string to int
		cout << a << "^" << b << "=" << power << endl;
		sum = sum_of_digits(to_string(power));
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
	if(stoi(str) < SHRT_MAX){//value too large if it is bigger than SHRT_MAX
		return true;
	}else{
		cout << "Number too large!" << endl;
		return false;
		}
	}

long long pow(int a_initial, int b){
	long long a = a_initial;//Stores the actual base
	int i;
	for(i = 1; i < b; ++i){
	a = a * a_initial;//And then multiplies it the required # of times
	}
	return a;
}

int sum_of_digits(string str){
	int adder = 0;
	for(char c : str){//iterates across the string
		adder = adder + (c - '0');//this line converts each char back to its numeric value
		}
	return adder;
	}
