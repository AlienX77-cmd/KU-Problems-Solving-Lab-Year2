#include <cstdio>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

list<int> Counts;
list<int> Stations;

int main(){

    int NUM;
    int Trains;

    bool FUCK = true;

    while(FUCK){
        cin >> NUM;
        if(NUM == 0) break;

        while(FUCK){
            Counts.clear();
            Stations.clear();
            cin >> Trains;
            
            if(Trains == 0) break;

            Counts.push_back(Trains);

            int i,j;
            for(i = 1; i <= NUM-1; i++){
                scanf(" %d", &Trains);
                Counts.push_back(Trains);
            }
            for(int j = 1; j <= NUM; j++){
                Stations.push_back(j);
                while( (Stations.empty() == false) && ( Counts.front() == Stations.back() )){
                    Counts.pop_front();
                    Stations.pop_back();
                }
            }

            if(Stations.empty() == true) cout << "Yes" << endl;
            else cout << "No" << endl;

        }
        
        cout << "\n";

    }

    return 0;
}