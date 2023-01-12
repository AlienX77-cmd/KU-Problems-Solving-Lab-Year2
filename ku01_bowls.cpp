#include <iostream>

using namespace std;
int c[310];

int main(void){
    for(int i = 0;i<310;i++)
        c[i] = 0;
    int n = 0;
   cin>>n;
    for(int i = 0;i<n;i++){
        int temp = 0;
        cin>>temp;
        c[temp] += 1;
    }
    int max = c[0];
    for(int i = 0;i<310;i++){
        if(c[i] > max)
            max = c[i];
    }
    cout<<max<<std::endl;
    return 0;
}