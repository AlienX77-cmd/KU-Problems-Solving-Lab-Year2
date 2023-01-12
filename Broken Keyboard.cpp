#include <iostream>
#include <fstream>
#include <list>
#include <cctype>
#include <stdio.h>

using namespace std;

void PrintList(list<char> LST){
	for(auto chr : LST) putchar(chr);
	puts("");
}

int main(void){
	char chr {};

	list<char> LST{};
	list<char>::iterator Iterator = LST.begin();
  
	while((chr = getchar()) != EOF){
		if(chr == '\n' || chr == ' ' ){
			PrintList(LST);
			LST.clear();
			Iterator = LST.begin();
			continue;
		}
		if(chr == '['){
			Iterator = LST.begin();
			continue;
		}
    else if(chr == ']'){
			Iterator = LST.end();
			continue;
		}
    else LST.insert(Iterator,chr);
			
	}
	for(auto chr : LST) putchar(chr);
	
  return 0;
}