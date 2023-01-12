#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

int N;
int M;
int Skip_U = -1;
int Skip_V = -1;

vector<int> Adj[3010];
bool Visited[3010];
int Levels[3010];
int Degrees[3010];
int Pairs[3010][2];

void Initial();

bool bfs(int s);

void Read_Input();

int main()
{
  bool Res;
  Read_Input();
  for (int i = -1; i < M; i++)
  {
    Res = true;

    if(i != -1){
      Skip_U = Pairs[i][0];
      Skip_V = Pairs[i][1];
    }

    Initial();

    for (int j = 0; j < N; j++)
    {
      if (Visited[j]) continue;
      if (bfs(j) == false)
      {
        Res = false;
        break;
      }
    }

    if(Res && i != -1){
      printf("%d %d", Skip_U+1, Skip_V+1);
      break;
    }
  }
  return 0;
}

void Initial()
{
  for (int i = 0; i < N; i++) Visited[i] = false;
}

void Read_Input()
{
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++)
  {
    Degrees[i] = 0;
    Adj[i].clear();
  }
  for (int i = 0; i < M; i++)
  {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    Pairs[i][0] = u;
    Pairs[i][1] = v;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
    Degrees[u]++;
    Degrees[v]++;
  }
}

bool bfs(int s)
{
  Visited[s] = true;
  Levels[s] = 0;
  list<int> Q;
  Q.push_back(s);

  while (Q.empty() == false)
  {
    int u = Q.front();
    Q.pop_front();

    for (int i = 0; i < Degrees[u]; i++)
    {
      int v = Adj[u][i];

      if((u == Skip_U && v == Skip_V) || (v == Skip_U && u == Skip_V)) continue;

      if (!Visited[v])
      {
        Visited[v] = true;
        Levels[v] = Levels[u] + 1;
        Q.push_back(v);
      }
      else if (Levels[u] == Levels[v]) return false;
    }
  }
  return true;
}