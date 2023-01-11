#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
  char R[105];
  int x = 0;
  int y = 0;
  cin >> R;
  //cout << sizeof(R);
  for(int i = 0; i < sizeof(R); i++){
    if (R[i] == 'N') {
        y++;
    }
    else if(R[i] == 'S') {
        y--;
    }
    else if(R[i] == 'E') {
        x++;
    }
    else if(R[i] == 'W'){
        x--;
    }
    else if(R[i] == 'Z'){
        x = 0;
        y = 0;
    }
  }
  cout << x << " " << y;
  
  return 0;
}