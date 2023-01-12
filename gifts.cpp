#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int main() 
{
	int x,n,sum = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
	   cin >> x;
	   if (x > -1) {
	       sum += x;
	   }
	}
	cout << sum;
	return 0;
}