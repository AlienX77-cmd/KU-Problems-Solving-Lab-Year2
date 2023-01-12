#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <list>

using namespace std;

int main(void){
	int CMD{};

	list<int> DECK{};

  bool x = true;
	while(x){
		cin >> CMD;

		if(CMD == 0)break;

		DECK.resize(CMD);
		list<int>::iterator Iterator = DECK.begin();

		for(int i = 1; Iterator != DECK.end(); i++){
			*Iterator = i;
			Iterator++;
		}

		cout << "Discarded cards:";

		while((int)DECK.size() > 1){
			int TMP {};
			TMP = DECK.front();

			cout<<" "<<TMP;
			DECK.pop_front();

			TMP = DECK.front();
			DECK.push_back(TMP);
			DECK.pop_front();

			if(DECK.size() > 1) cout<<",";
		}
		cout << endl << "Remaining card: " << DECK.front() << endl;

	}
}