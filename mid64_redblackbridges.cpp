#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
#include <vector>
#include <stdio.h>
#include <cmath>

using namespace std;

class Queue_Node{
    public:
    int index;
    int Visited_Bridge;
};

class Node_t{
    public:
    int index;
    int Bridge;
};

class Status_Node{
    public:
    int Visited;
    int Layers;
};

int main(void){
    int N{},M{},S{},T{};
    cin >> N >> M >> S >> T;

    vector<list<Node_t>> Graph{};
    vector<Status_Node> List_Node{};

    for(int i = 0; i<N; i++) List_Node.push_back({0,0});

    Graph.resize(N);

    for(int i = 0; i<M; i++){
        int A{},B{},C{};
        cin >> A >> B >> C;
        Graph.at(A-1).push_back({B-1,C,});
        Graph.at(B-1).push_back({A-1,C,});
    }

//Breadth-First-Search
    queue<Queue_Node> Q{};
    vector<int> Results{};
    Q.push({S-1,0});

    while(Q.empty() == false){
        int Number = Q.front().index;
        if(List_Node.at(Number).Visited == 0){
            List_Node.at(Number).Visited = 1;
            Results.push_back(Number);

            for(auto node : Graph.at(Number)){
                if(Q.front().Visited_Bridge == 0 && node.Bridge == 1 || node.Bridge == 2 ){
                    Q.push({node.index,node.Bridge});
                    List_Node.at(node.index).Layers = List_Node.at(Number).Layers + 1;
                }
                else if(Q.front().Visited_Bridge == 1 && node.Bridge == 1 || node.Bridge == 0){
                    Q.push({node.index,node.Bridge});
                    List_Node.at(node.index).Layers = List_Node.at(Number).Layers + 1;
                }
                else if(Q.front().Visited_Bridge == 2 && node.Bridge == 2 || node.Bridge == 0){
                    Q.push({node.index,node.Bridge});
                    List_Node.at(node.index).Layers = List_Node.at(Number).Layers + 1;
                }
            }
        }
        Q.pop();
    }

    for(int i = 0; i<Results.size(); i++){
        if(Results.at(i) == T - 1){
          cout << List_Node.at(T-1).Layers << endl;
          return 0;
        }
    }
    
  printf("-1");
    
  return 0;
}