#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() 
{
	string num;
	getline(cin,num);
	istringstream iss(num);

	int i = 0;
	int sum = 0;
	while (iss >> i) {
		sum += i;
	}

	cout << sum;
	return 0;
}