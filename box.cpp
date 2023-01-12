#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int n;
int m;

bool MAP[30][30];
bool Explored[30][30];

void Is_Init();
bool Fit(int x, int y);
bool ISEXPLORED(int x, int y);
void SetExploring(int x, int y);
bool Exploring(int x, int y);

int main(){
    char COMMAND;
    cin >> n >> m;
    Is_Init();
    for(int i = 0; i <= n-1; i++){
        scanf("\n");
        for(int j = 0; j <= m-1; j++){
            cin >> COMMAND;
            if(COMMAND == '.') MAP[i][j] = true;
            else if(COMMAND == '#') MAP[i][j] = false;
        }
    }
    for(int k = 0; k < m-1; k++){
        if(Explored[0][k] == false){
            if(Exploring(0, k) == true) return 0;
        }
    }

    cout << "no" << endl;

    return 0;
}

void Is_Init(){
    for(int i = 0; i <= 31; i++){
        for(int j = 0; j <= 31; j++){
            if(i<m && i<n) Explored[i][j] = false;
            else Explored[i][j] = true;
        }
    }
}

bool Fit(int x, int y){
    bool CONDITION = true;
    CONDITION &= MAP[x][y];
    CONDITION &= MAP[x][y+1];
    CONDITION &= MAP[x+1][y];
    CONDITION &= MAP[x+1][y+1];
    CONDITION &= y + 1 < m;
    CONDITION &= x + 1 < n;
    return CONDITION;
}

bool ISEXPLORED(int x, int y){
    bool CONDITION = true;
    CONDITION &= Explored[x][y];
    return CONDITION;
}

void SetExploring(int x, int y){
    Explored[x][y] = true;
}

bool Exploring(int x, int y){
    if(Fit(x, y) == false) return false;

    int yy;
    int xx;
    
    list<int> L1;
    list<int> L2;
    L1.push_back(x);
    L2.push_back(y);

    while(L1.empty() == false){
        xx = L1.front(); L1.pop_front();
        yy = L2.front(); L2.pop_front();

        SetExploring(xx, yy);

        if( xx+2 == n ){
            cout << "yes" << endl;
            return true;
        }

        if( (ISEXPLORED(xx-1, yy) == false) && (xx-1 >= 0) && (xx-1 < n) ){
            if(Fit(xx-1, yy)){
                L1.push_back(xx-1);
                L2.push_back(yy);
            }
        }
        if( (ISEXPLORED(xx+1, yy) == false) && (xx+1 < n) && (xx+1 >= 0) ){
            if(Fit(xx+1, yy)){
                L1.push_back(xx+1);
                L2.push_back(yy);
            }
        }
        if( (ISEXPLORED(xx, yy-1) == false) && (yy-1 >= 0) && (yy-1 < m) ){
            if(Fit(xx, yy-1)){
                L1.push_back(xx);
                L2.push_back(yy-1);
            }
        }
        if( (ISEXPLORED(x, y+1) == false) && (yy+1 >= 0) && (yy+1 < m) ) {
            if(Fit(xx, yy+1)){
                L1.push_back(xx);
                L2.push_back(yy+1);
            }
        }
    }
    return false;
}