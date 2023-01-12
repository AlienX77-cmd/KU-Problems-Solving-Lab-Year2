#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;
long status_checker[100010];

int main(void){
    int N = 0;
    cin >> N;
    vector<long> V;
    int max = INT_MIN;
    for(int i = 0; i<N; i++){
        int temp = 0;
        cin >> temp;
        V.push_back(temp);
    }
    for(int j = 0; j<N; j++){
        if(status_checker[V.at(j)] == -1){
            continue;
        }
        int count = 0;
        long index_checker = j;
        
        count++;
        status_checker[j] = -1;
        index_checker = V.at(index_checker) - 1;
        
        while(index_checker != j){
            count++;
            status_checker[j] = -1;
            index_checker = V.at(index_checker) - 1;
        }
        
        if (count > max){
            max = count;
        }
        
    }
    cout << max << endl;
    
    return 0;

}