#include <cstdio>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int COUNT_IN_EDGES[100];
bool CONDITIONS[100][100];
int m;
int n;

list<int> ANSWER;

void CLEAR_CONDITIONS();

int main(){

    int X;
    int Y;
    int TEMP_NODE;
    list<int> LIST;

    bool FUCK = true;
    while(FUCK){
        cin >> n >> m;
        if( n == m && n == 0 ) break;
        
        CLEAR_CONDITIONS();
        LIST.clear();
        ANSWER.clear();

        int i;
        for(i = 0; i <= m-1; i++){
            scanf("%d %d", &X, &Y);
            if( CONDITIONS[X-1][Y-1] == false){
                CONDITIONS[X-1][Y-1] = true;
                COUNT_IN_EDGES[Y-1] = COUNT_IN_EDGES[Y-1] + 1;
            }
        }


        for(int j = 0; j <= n-1; j++){
            if(COUNT_IN_EDGES[j] == 0) LIST.push_back(j);
        }

        while(LIST.empty() == false){
            TEMP_NODE = LIST.front();
            LIST.pop_front();
            ANSWER.push_back(TEMP_NODE);

            for(int k = 0; k <= n-1; k++){
                if(CONDITIONS[TEMP_NODE][k] == false) continue;
                CONDITIONS[TEMP_NODE][k] = false;
                COUNT_IN_EDGES[k]-=1;
                if(COUNT_IN_EDGES[k] == 0) LIST.push_back(k);
            }
        }

        cout << ANSWER.front()+1;
        ANSWER.pop_front();

        while(ANSWER.empty() == false){
            cout << " " << ANSWER.front()+1;
            ANSWER.pop_front();
        }
        cout << "\n";
    }

    return 0;
}

void CLEAR_CONDITIONS(){
    int i,j;
    for (i = 0; i <= n-1; i++){
        for (j = 0; j <= n-1; j++) 
        CONDITIONS[i][j] = false;
        COUNT_IN_EDGES[i] = 0;
    }
}