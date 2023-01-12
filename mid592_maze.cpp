#include <cstdio>
#include <list>
#include <vector>
#include <utility>

#define MAXN 20
using namespace std;
char map[MAXN + 1][MAXN + 1];

int N;
int q;

bool bfs(int si, int sj, int ei, int ej);

int main()
{
    scanf("%d %d", &N, &q);
    for (int i = 0; i < N; i++) scanf("%s", &map[i]);

    int x1, y1, x2, y2;

    for (int p = 0; p < q; p++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if (bfs(x1 - 1, y1 - 1, x2 - 1, y2 - 1)) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}

bool bfs(int si, int sj, int ei, int ej)
{
    list<pair<pair<int, int>, int>> Q;
    Q.push_back(make_pair(make_pair(si, sj), 0));
    pair<pair<int, int>, int> front;
    pair<int, int> u;
    bool visited[MAXN + 1][MAXN + 1] = {{false}};
    while (!Q.empty())
    {
        front = Q.front();
        Q.pop_front();
        u = front.first;

        if (visited[u.first][u.second]) continue;

        visited[u.first][u.second] = true;
        
        if (u.first == ei && u.second == ej) return true;

        vector<pair<int, int>> adj;
        if (u.first + 1 < N) adj.push_back(make_pair(u.first + 1, u.second));
        if (u.first - 1 >= 0) adj.push_back(make_pair(u.first - 1, u.second));
        if (u.second + 1 < N) adj.push_back(make_pair(u.first, u.second + 1));
        if (u.second - 1 >= 0) adj.push_back(make_pair(u.first, u.second - 1));

        int key = 0;

        for (int i = 0; i <= adj.size()-1; i++)
        {
            if (visited[adj[i].first][adj[i].second] || map[adj[i].first][adj[i].second] == '#') continue;
            if (map[adj[i].first][adj[i].second] == 'O')
            {
                if (front.second == 1) continue;
                key = 1;
            }
            else key = front.second;

            Q.push_back(make_pair(adj[i], key));
        }
    }
    return false;
}