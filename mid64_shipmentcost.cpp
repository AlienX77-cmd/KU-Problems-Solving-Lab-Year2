#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <cmath>
#include <map>

using namespace std;
class Node{
    public:
    int Visited;
};

int main(void){
    int N{};
    int M{};
    int S{};
    int T{};
    cin >> N >> M >> S >> T;

    vector<list<int>> Graph{};
    Graph.resize(N);

    for(int i = 0; i<M; i++){
        int A{};
        int B{};
        cin >> A >> B;

        Graph.at(A-1).push_back(B-1);
        Graph.at(B-1).push_back(A-1);
    }

    vector<int> WareHouses{};

    for(int j = 0; j < S; j++){
        int INPUTS{};
        cin >> INPUTS; 
        WareHouses.push_back(INPUTS-1);
    }

    vector<int> Factories{};
    for(int k = 0; k < T; k++){
        int INPUTS{};
        cin >> INPUTS; 
        Factories.push_back(INPUTS-1);
    }

    vector<vector<int>> Results{};
    Results.resize(N);

    for(int i = 0; i<S; i++){
        vector<int> Shortest_Paths{};
        
        Shortest_Paths.resize(N);
 
        queue<int> Q{};
        vector<int> Visited{};
        Visited.resize(N);
        Q.push(WareHouses.at(i));
        while(Q.empty() == false){
            int u = Q.front();
            if(Visited.at(u) == 0){
                Visited.at(u) = 1;
                for(auto Nodes : Graph.at(u)){
                    if(Visited.at(Nodes) == 0){
                        if(Shortest_Paths.at(Nodes) == 0){
                            int new_Shortest_Paths = Shortest_Paths.at(u) + 1;
                            Shortest_Paths.at(Nodes)  = new_Shortest_Paths;
                        }

                        Q.push(Nodes);
                    }
                }
            }
            Q.pop();
        }
        Results.at(WareHouses.at(i)) = Shortest_Paths;

    }

    for(int x = 0; x < T; x++){
        int Find_MIN = 999999999;
        for(int y = 0; y < S; y++){
            int FromA2B = Results.at(WareHouses.at(y)).at(Factories.at(x));
            if(FromA2B < Find_MIN) Find_MIN = FromA2B;
        }
        cout << Find_MIN <<endl;
    }

    return 0;
}