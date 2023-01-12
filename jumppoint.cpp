#include <stdio.h>
#include <cmath>
#include <iostream>
#include <math.h>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

struct Position
{
    int X;
    int Y;
    bool Is_Explored {false};
};

int N;
int R_2;

Position Points[1010];
list<int> CONNECTORS[1010];

int Is_Exploring();

int main(){
    cin >> N >> R_2;
    R_2 = pow(R_2, 2);
    

    int i,j;
    for(i = 0; i <= N-1; i++){
        scanf("\n%d %d", &Points[i].X, &Points[i].Y);

        for(int j=0; j <= i-1 ; j++){
            if (R_2 >= (pow(Points[j].X-Points[i].X,2) + pow(Points[j].Y-Points[i].Y,2)))
            {
                CONNECTORS[i].push_back(j);
                CONNECTORS[j].push_back(i);
            }
            
        }
    }

    Points[N].X = 0;
    Points[N].Y = 0;
    Points[N+1].X = 100;
    Points[N+1].Y = 100;
    
    int k,m;
    for(k = 0; k <= N-1; k++){
        if (R_2 >= ( pow(Points[k].Y-Points[N].Y,2) + pow(Points[k].X-Points[N].X,2) ))
        {
            CONNECTORS[N].push_back(k);
            CONNECTORS[k].push_back(N);
        }
        
    }
    for(m = 0; m < N+1; m++){
        if (R_2 >= ( pow(Points[m].Y-Points[N+1].Y,2) + pow(Points[m].X-Points[N+1].X,2) ))
        {
            CONNECTORS[N+1].push_back(m);
            CONNECTORS[m].push_back(N+1);
        }
        
    }


    if(true) cout << Is_Exploring() << endl;
    else{
        for(int ii = 0; ii <= N+1; ii++){
            cout << Points[ii].X << " " << Points[ii].Y << ":";
            while(CONNECTORS[ii].empty() == false){
                printf(" (%d,%d)", Points[CONNECTORS[ii].front()].X, Points[CONNECTORS[ii].front()].Y);
                CONNECTORS[ii].pop_front();
            }
            cout << "\n";
        }
    }

    return 0;
}

int Is_Exploring(){
    int LEVELS[1010];
    int i = N;
    
    list<int> LIST;
    LIST.push_back(N);
    LEVELS[N] = 0;
    Points[N].Is_Explored = true;
    
    while(LIST.empty() == false){
        i = LIST.front();
        LIST.pop_front();

        if(i == N+1) return LEVELS[N+1];

        while(CONNECTORS[i].empty() == false){
            if( Points[CONNECTORS[i].front()].Is_Explored == false){
                LIST.push_back(CONNECTORS[i].front());
                LEVELS[CONNECTORS[i].front()] = LEVELS[i] + 1;
                Points[CONNECTORS[i].front()].Is_Explored = true;
            }
            CONNECTORS[i].pop_front();
        }
    }
    return -1;
}