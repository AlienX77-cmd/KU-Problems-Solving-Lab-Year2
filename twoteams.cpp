#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

struct Node{
    int u, v;
};
Node Inputs[100100];

vector<int> edges[100100];
queue<int> Q;

int Target[100100];
int m, n;
int ANS = 0;

bool BFS(int x);

void BS(int LOW, int HIGH);

int main()
{
    scanf("%d %d", &n, &m);

    for(int M=1; M<=m; ++M) scanf("%d %d", &Inputs[M].u, &Inputs[M].v);

    BS(1, m);

    cout << ANS << endl;

    return 0;
}

bool BFS(int x)
{
    Target[x] = 0;
    Q.push(x);

    while(Q.empty() == false)
    {
        int u = Q.front();

        Q.pop();

        for(int i=0; i<edges[u].size(); i++)
        {
            int v = edges[u][i];

            if(Target[u] == Target[v]) return false;
            if(Target[v] != -1) continue;

            Target[v] = !Target[u];
            Q.push(v);
        }
    }
    return true;
}

void BS(int LOW, int HIGH)
{
    int Middle = (LOW + HIGH) / 2;

    if(LOW > HIGH) return ;

    for(int i=1; i <= n; i++) edges[i].clear();
    for(int j=1; j <= n; j++) Target[j] = -1;

    for(int k=1; k <= Middle; k++)
    {
        int u = Inputs[k].u;
        int v = Inputs[k].v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    bool Checker = true;
    for(int x=1; x<=n; x++) {
        if(Target[x] == -1) Checker &= BFS(x);
    }

    if(!Checker) BS(LOW, Middle-1);
    else
    {
        ANS = Middle;
        BS(Middle+1, HIGH);
    }
}