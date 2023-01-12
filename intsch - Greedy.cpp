#include <iostream>
#include<stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

class Work{
    public:
        int Fs;
        int Ff;
};

bool Compare_Works(Work x,Work y);

int main(void){
    int N{};
    scanf("%d", &N);

    vector<Work> Works_Vectors{};

    for(int i = 0; i<N; i++){
        int s{},t{};
        cin>>s>>t;
        Works_Vectors.push_back({s,t});
    }

    sort(Works_Vectors.begin(),Works_Vectors.end(),Compare_Works);
    
    int Count = 1;
    Work Last = Works_Vectors.at(0);

    for(int j = 1; j<N; j++){
        if(Last.Ff <= Works_Vectors.at(j).Fs){
            Last = Works_Vectors.at(j);
            Count++;
        }
    }
    printf("%d", Count);
}

bool Compare_Works(Work x,Work y){
    return x.Ff < y.Ff;
}