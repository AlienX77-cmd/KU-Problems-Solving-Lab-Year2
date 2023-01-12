#include <cstdio>
#include <list>
#include <vector>

#define NMAX  100000

using namespace std;

int n,m;
vector<int> Adj[NMAX];
int Deg[NMAX];
int Levels[NMAX];
bool Visited[NMAX];

void ReadInput()
{
  scanf("%d %d",&n,&m);
  for(int i=0; i<n; i++) {
    Deg[i] = 0;
    Adj[i].clear();
  }
  for(int i=0; i<m; i++) {
    int a,b;
    scanf("%d %d",&a,&b); a--; b--;
    Adj[a].push_back(b);
    Adj[b].push_back(a);
    Deg[a]++;
    Deg[b]++;
  }
}

void init()
{
  for(int i=0; i<n; i++)
    Visited[i] = false;
}

bool BFS(int a)
{
  Visited[a] = true;
  Levels[a] = 0;
  list<int> Q;
  Q.push_back(a);

  while(!Q.empty()) {
    int tmp = Q.front();
    Q.pop_front();

    for(int i=0; i<Deg[tmp]; i++) {
      int tmpp = Adj[tmp][i];

      if(!Visited[tmpp]) {
        Visited[tmpp] = true;
        Levels[tmpp] = Levels[tmp] + 1;
        Q.push_back(tmpp);        
      } 
      else {
          if(Levels[tmp] == Levels[tmpp]){
            //   printf("Mom(%d): %d Child(%d): %d\n", tmp+1, Levels[tmp], tmpp+1,Levels[tmpp]);
              return false;
          }
      }
    }
  }
  return true;
}

int main(){
    int x;
    bool Res;
    scanf("%d", &x);
    for(int i=0; i<x; i++){
        Res = true;
        ReadInput();
        init();
        for(int j=0; j<n; j++){
            if(Visited[j])continue;
            // printf("i: %d j:%d\n", i, j);
            if(!BFS(j)){
                Res = false;
                break;
            }
        }
        if(Res)
          printf("yes\n");
        else 
          printf("no\n");
    }
    return 0;
}