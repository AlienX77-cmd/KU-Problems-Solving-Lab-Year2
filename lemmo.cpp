#include <cstdio>
#include <list>
#include <cstring>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

vector<pair<int, int>> FLR_List;
char MAP[120 + 1][120 + 1];

int Result1 = 0;
int Result2 = 0;

int n, m;

bool Stop_DestPoint = false;
bool visited[120 + 1][120 + 1];
int res[120 + 1][2];
struct Coordinates
{
    int first;
    int second;
    int dirt;
};

Coordinates parent[2][120 + 1][120 + 1];
int Dest_Point[2][120 + 1][120 + 1];
int Count[2][120 + 1][120 + 1];
int Candidates[120 + 1][120 + 1];

Coordinates make_Coordinates(int dirt, int first, int second);

void reset(bool ALL);

Coordinates backtrack(int dirt, int ei, int ej, int res);

bool bfs(int si, int sj, int dirt, char (&MAP)[120 + 1][120 + 1]);

bool bfs(int sj, int sdirt);

bool bfs(int si, int sj, int sdirt);

bool bfs(int sj, int sdirt, char (&MAP)[120 + 1][120 + 1]);

bool bfs(int si, int sj, int sdirt, char (&MAP)[120 + 1][120 + 1]);

Coordinates backtrack(int dirt, int ei, int ej, int res);

Coordinates backtrack(int dirt, int ei, int ej, int res, bool findResult);

void read_input();

int main()
{
    read_input();
    reset(true);

    vector<int> Pos_of_Tunnel;
    int tmp = 0;
    for (int i = 0; i < m; i++)
    {
        tmp = 0;
        if (bfs(i, 0))
        {
            res[i][0] = 1;
            tmp++;
        }
        if (bfs(i, 1))
        {
            res[i][1] = 1;
            tmp++;
        }
        Result1 += tmp;

        if (MAP[n - 1][i] == '@') Pos_of_Tunnel.push_back(i);
    }

    int Num_Tunnel = Pos_of_Tunnel.size();

    Result2 = Result1;
    Stop_DestPoint = true;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (MAP[i][j] != '#') continue;
            if (Dest_Point[0][i][j] == 2 && Dest_Point[1][i][j] == 2) continue;

            tmp = 0;
            if (Dest_Point[0][i][j] != 2 && Result1 + tmp + Count[0][i][j] > Result2 && bfs(i + 1, j, 0)) tmp += Count[0][i][j];
            if (Dest_Point[1][i][j] != 2 && Result1 + tmp + Count[1][i][j] > Result2 && bfs(i + 1, j, 1)) tmp += Count[1][i][j];
            if (Result1 + tmp > Result2) Result2 = Result1 + tmp;
        }
    }

    if (Result2 > m * 2) Result2 = m * 2;
    printf("%d %d", Result1, Result2);
    return 0;
}

void read_input()
{
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", MAP[i]);
    }
}

Coordinates backtrack(int dirt, int ei, int ej, int res, bool findResult)
{
    Coordinates tmp = parent[dirt][ei][ej];
    int ni, nj, ndirt;
    int tick[2][120 + 1][120 + 1] = {};

    if (res != -1)
    {
        Dest_Point[dirt][ei][ej] = res;
        Count[dirt][ei][ej]++;
        tick[dirt][ei][ej] = 1;
    }

    while (tmp.first != -1 && tmp.second != -1)
    {
        ndirt = tmp.dirt;
        ni = tmp.first;
        nj = tmp.second;

        if (res != -1)
        {
            Dest_Point[ndirt][ni][nj] = res;
            if (tick[ndirt][ni][nj] == 0)
            {
                Count[ndirt][ni][nj]++;
                tick[ndirt][ni][nj] = 1;
            }
        }
        else if (findResult)
        {
            if (MAP[ni][nj] == '#' && ni + 1 < n && bfs(ni + 1, nj, ndirt))
                return make_Coordinates(ndirt, ni, nj);
        }
        tmp = parent[tmp.dirt][ni][nj];
    }
    return make_Coordinates(-1, -1, -1);
}

Coordinates backtrack(int dirt, int ei, int ej, int res)
{
    return backtrack(dirt, ei, ej, res, false);
}

bool bfs(int si, int sj, int sdirt, char (&MAP)[120 + 1][120 + 1])
{
    reset(false);

    Coordinates v;
    list<Coordinates> Q;
    Q.push_back(make_Coordinates(sdirt, si, sj));
    while (Q.empty() == false)
    {
        Coordinates u = Q.front();
        Q.pop_front();

        if (Stop_DestPoint)
        {
            switch (Dest_Point[u.dirt][u.first][u.second])
            {
            case 2:
                return true;
            case 1:
                continue;
            default:
                break;
            }
        }

        visited[u.first][u.second] = true;
        vector<Coordinates> adj;
        switch (MAP[u.first][u.second])
        {
        case '$':
            backtrack(u.dirt, u.first, u.second, 2);
            return true;
        case '@':
            backtrack(u.dirt, u.first, u.second, 1);
            continue;
        case '.':
            if (u.first + 1 < n) adj.push_back(make_Coordinates(u.dirt, u.first + 1, u.second));
            break;
        default:
            switch (u.dirt)
            {
            case 0:
                if (u.second - 1 >= 0) adj.push_back(make_Coordinates(u.dirt, u.first, u.second - 1));
                else adj.push_back(make_Coordinates(1, u.first, u.second + 1));
                break;
            case 1:
                if (u.second + 1 < m) adj.push_back(make_Coordinates(u.dirt, u.first, u.second + 1));
                else adj.push_back(make_Coordinates(0, u.first, u.second - 1));
                break;
            }
        }

        int Degrees = adj.size();
        int i = 0;
        while(i < Degrees){
            v = adj[i];
            
            if (MAP[v.first][v.second] == '#')
            {
                if (v.second == m - 1 && v.dirt == 1) v.dirt = 0;
                else if (v.second == 0 && v.dirt == 0) v.dirt = 1;
            }

            if (v.first < n)
            {
                parent[v.dirt][v.first][v.second].first = u.first;
                parent[v.dirt][v.first][v.second].second = u.second;
                parent[v.dirt][v.first][v.second].dirt = u.dirt;
                Q.push_back(v);
            }

            i++;
        }
    }
    return false;
}

Coordinates make_Coordinates(int dirt, int first, int second)
{
    Coordinates tmp;
    tmp.first = first;
    tmp.second = second;
    tmp.dirt = dirt;
    return tmp;
}

void reset(bool ALL)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
            if (ALL)
            {
                parent[0][i][j] = make_Coordinates(-1, -1, -1);
                parent[1][i][j] = make_Coordinates(-1, -1, -1);
            }
        }
    }
}

Coordinates backtrack(int dirt, int ei, int ej, int res);

bool bfs(int si, int sj, int dirt, char (&MAP)[120 + 1][120 + 1]);

bool bfs(int sj, int sdirt)
{
    return bfs(0, sj, sdirt, MAP);
}

bool bfs(int si, int sj, int sdirt)
{
    return bfs(si, sj, sdirt, MAP);
}

bool bfs(int sj, int sdirt, char (&MAP)[120 + 1][120 + 1])
{
    return bfs(0, sj, sdirt, MAP);
}