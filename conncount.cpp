#include <cstdio>
#include <list>
#include <vector>

#define NMAX 100000

using namespace std;

int m,n;
vector<int> Adj[NMAX];
int Deg[NMAX];
bool Explored[NMAX];
int Levels[NMAX];

void ReadInput()
{
  scanf("%d %d",&n,&m);
  for(int i=0; i<n; i++) {
    Deg[i] = 0;
  }
  for(int i=0; i<m; i++) {
    int a,b;
    scanf("%d %d",&a,&b); 
    a--; 
    b--;
    Adj[a].push_back(b);
    Adj[b].push_back(a);
    Deg[a]++;
    Deg[b]++;
  }
}

bool Visited[NMAX];

void init()
{
  for(int i=0; i<n; i++)
    Visited[i] = false;
}

void DFS(int a)
{
  Visited[a] = true;
  for(int i=0; i<Deg[a]; i++) {
    int b = Adj[a][i];
    if(!Visited[b]) {
      DFS(b);
    }
  }
}

void BFS(int s)
{
  Explored[s] = true;
  Levels[s] = 0;
  list<int> Q;
  Q.push_back(s);

  while(!Q.empty()) {
    int tmp = Q.front();
    Q.pop_front();

    for(int i=0; i<Deg[tmp]; i++) {
      int tmpp = Adj[tmp][i];

      if(!Explored[tmpp]) {
        Explored[tmpp] = true;
        Levels[tmpp] = Levels[tmp] + 1;
        Q.push_back(tmpp);        
      }
    }
  }
}

int main(){
    ReadInput();
    init();
    int Group_Count=0;
    for(int i=0; i<n; i++){
        if(!Explored[i]){
            BFS(i);
            ++Group_Count;
        }
    }
    printf("%d\n", Group_Count);
    return 0;
}