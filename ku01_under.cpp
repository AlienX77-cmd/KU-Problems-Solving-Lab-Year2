#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <array>

using namespace std;

int main(void){
	int L {}, N{};
	cin >> L >> N;

	array<int,320> Array{};

	for(int i = 0; i<N; i++){
		int X{},Y{};
		cin >> X >> Y;
		for(int j = X; j<Y; j++) Array.at(j) += 1;
	}

	auto Iterator = Array.begin();
	cout << *max_element(Iterator,Iterator + 309);
	
  return 0;
}