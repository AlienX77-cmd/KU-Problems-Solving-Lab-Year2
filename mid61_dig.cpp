#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <list>
#include <queue>
#include <vector>

using namespace std;
struct Paths{
  int first;
  int second;
  int Costs;
};

int Start_i, Start_j;
int End_i, End_j, c, r;

int Dest_Point[51][51];
int Costs[51][51];

char map[51][51];

pair<int,int> Parents[51][51];

Paths MakePaths(int i, int j, int Costs);

int* allow(int a,int b, int c);

int BFS(int si, int sj, int initCosts, int allow[3]);

int main() {

  scanf("%d %d",&r,&c);
  scanf("%d %d %d %d", &Start_i, &Start_j, &End_i, &End_j);

  Start_i-=1; 
  Start_j-=1; 
  End_i-=1; 
  End_j-=1;

  for(int x=0; x<r; x++) scanf("%s",&map[x]);
  
  int NOT_ALLOWED[3] = {-1,-1,-1};

  int TMP_ANSWER = BFS(Start_i,Start_j,0, NOT_ALLOWED); 
  
  int TMP;
  int res = TMP_ANSWER;

  for(int i=1; i<r-1; i++) {
    for(int j=1; j<c-1; j++) {
      if(map[i][j]!='*') continue;
      TMP = -1;

      map[i][j] = '|';
      TMP = BFS(Start_i,Start_j,0,NOT_ALLOWED);
      if(TMP != -1 && (TMP < res || res ==-1)) res = TMP;
      
      map[i][j] = '-';
      TMP = BFS(Start_i,Start_j,0,NOT_ALLOWED);
      if(TMP != -1 && (TMP < res || res ==-1 )) res = TMP;

      map[i][j] = '*';
    }
  }

  printf("%d",res);
  return 0;  
}

Paths MakePaths(int i, int j, int Costs) {
  Paths n;
  n.first = i;
  n.second = j;
  n.Costs = Costs;
  return n;
}

int* allow(int a,int b, int c){
  int RESULT[3] = {a,b,c};
  return RESULT;
}

int BFS(int si, int sj, int initCosts, int allow[3]) {
  
  bool visited[51][51] = {{false}};
  list< Paths > Q;

  Q.push_back(MakePaths(si,sj,initCosts));
  Paths u;
  pair<int,int> v;
  vector< pair<int,int> > adj;

  while(!Q.empty()) {
    u = Q.front();
    Q.pop_front();
    if(visited[u.first][u.second]) continue;

    visited[u.first][u.second] = true;
    if(Costs[u.first][u.second]==0 || u.Costs < Costs[u.first][u.second]) Costs[u.first][u.second] = u.Costs;
    if(u.first==End_i && u.second==End_j) return u.Costs;

    adj.push_back(make_pair(u.first-1,u.second));
    adj.push_back(make_pair(u.first+1,u.second));
    adj.push_back(make_pair(u.first,u.second-1));
    adj.push_back(make_pair(u.first,u.second+1));

    for(int i=0;i<adj.size();i++) {
      v = adj[i];
      if(v.first<0 || v.first >= r || v.second < 0 || v.second >= c) continue;

      Parents[v.first][v.second] = make_pair(u.first,u.second);

      if(map[v.first][v.second]=='#') continue;

      bool IS_GO = true;
      if(map[v.first][v.second]=='*') {
        
        if(allow[0]==-1 || allow[0]!=v.first || allow[1]!=v.second) IS_GO = false;
        //same ROW
        if(allow[2]==0 && v.first!=u.first) IS_GO = false;
        //same COLUMN
        if(allow[2]==1 && v.second!=u.second) IS_GO = false; 
        
      } 
      else if(map[v.first][v.second]=='|') {
        if(v.second!=u.second) IS_GO = false;
      } 
      else if(map[v.first][v.second]=='-') {
        if(v.first!=u.first) IS_GO = false;
      }
      
      if(!IS_GO) {
        if(Costs[v.first][v.second]==0 || u.Costs+1<Costs[v.first][v.second]) Costs[v.first][v.second] = u.Costs+1;
        continue;
      }
      Q.push_back(MakePaths(v.first, v.second, u.Costs+1));
    }


  }
  return -1;
}