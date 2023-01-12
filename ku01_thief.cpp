#include <iostream>
#include <limits.h>


using namespace std;

int main(void) {
    int N,T,K, i = 1, c = 0;
    cin >> N >> K >> T;
    while (true){
      if (c > 0){
        if (i == T){
            c++;
            //cout << "i == T: " << c << endl;
            break;
        }
        else if (i == 1){
            //cout << "i == 1: " << c << endl;
            break;
        }
      }
      
      i = i + K;
      if (i > N) {
        i = i - N;
        c++;
        //cout << "i > N: " << c << endl;
      }
      else{
        c++;
        //cout << "i < N: " << c << endl;
      }
    }
    cout << c << endl;
    return 0;
}