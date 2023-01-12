#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <list>
#include <stdio.h>

using namespace std;

int IN_Degree[100010];

int main(void){
    int N{},M{};
    cin >> N >> M;

    vector<list<int>> Graph{};
    Graph.resize(N);
    int Total_Node_Graph = N;

    for(int i = 0; i<M; i++){
        int u{},v{};
        cin >> u >> v;
        Graph.at(u-1).push_back(v-1);
        IN_Degree[v-1] += 1;
    }
    
    ////////////////////////////////////
    int j = 0;
    queue<int> Q{};
    bool Is_topo = false;
  
    while(j < N){
        if(IN_Degree[j] == 0){
            Q.push(j);
            Is_topo = true;
        }
        j++;
    }
    ////////////////////////////////////

    if(Is_topo == false){
        cout<<"no\n"<<endl;
        return 0;
    }

    vector<int> Result{};

    while(Total_Node_Graph != 0){

        int u = Q.front();
        Q.pop();

        for(auto node : Graph.at(u)){
            IN_Degree[node] -= 1;
            if(IN_Degree[node] == 0) Q.push(node);
        }

        Result.push_back(u);
        Total_Node_Graph--;

    }
    for(auto num : Result) cout << num + 1 <<endl;
    return 0;
}