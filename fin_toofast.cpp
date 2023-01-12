#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct Node{
    int e, w, ex;

    bool operator<(const Node a)const
    {
        return w > a.w;
    }
};

priority_queue<Node> q;
vector<Node> v[1010];

int Distance[1010][2];
bool Is_Relaxing[1010][2];

int main()
{
    int n, m;
    int s, e;
    int w, ex, u, k;
    scanf("%d %d", &n, &m);

    while(m--)
    {
        scanf("%d %d %d %d", &s, &e, &w, &ex);
        v[s].push_back(Node{e,w,ex});
        v[e].push_back(Node{s,w,ex});
    }

    q.push(Node{1, 0, 0});
    Is_Relaxing[1][0] = true;

    while(!q.empty())
    {
        e = q.top().e;
        w = q.top().w;
        k = q.top().ex;
        q.pop();

        for(int i=0; i < v[e].size(); i++)
        {
            u = v[e][i].e;
            ex = v[e][i].ex;

            if(Is_Relaxing[u][k] == false) {
                if(k == 0 && ex == 1)
                {
                    q.push(Node{u, w+v[e][i].w, 1});
                    Distance[u][1] = w+v[e][i].w;
                    Is_Relaxing[u][1] = true;
                }
                else if((k == 1 && ex == 1) == false)
                {
                    q.push(Node{u, w + v[e][i].w, k});
                    Distance[u][k] = w + v[e][i].w;
                    Is_Relaxing[u][k] = true;
                }
            }
        }
    }
    if(!Is_Relaxing[n][1]) printf("-1\n");
    else printf("%d\n", Distance[n][1]);

    return 0;
}