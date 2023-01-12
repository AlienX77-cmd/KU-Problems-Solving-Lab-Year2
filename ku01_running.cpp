#include <iostream>

using namespace std;
long K;

int main(void){
    
    long n = 0;
    cin>>n>>K;
    long N[100000];
    for(long j = 0;j<n;j++){
        long temp = 0;
        cin>>temp;
        N[j] = temp;
    }
    
    long min = N[0];
    for(long i = 0;i<n;i++){
        if(N[i] < min)
            min = N[i];
    }
    
    long res = n;
    for (long k = 0; k<n; k++){
        if (N[k] * (K-1) >= min * K ){
            res -= 1;
        }
    }
    cout << res;
    return 0;
}