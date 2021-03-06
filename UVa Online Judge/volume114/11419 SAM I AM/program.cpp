// SAM I AM
// UVa ID: 11419
// Verdict: Accepted
// Submission Date: 2017-10-09
// UVa Run Time: 0.210s
//
// 版权所有（C）2017，邱秋。metaphysis # yeah dot net

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAXV = 1010;

int g[MAXV][MAXV], visited[MAXV], cx[MAXV], cy[MAXV], tx, ty;
int inx[MAXV], iny[MAXV], mx[MAXV], my[MAXV];

int dfs(int u)
{
    for (int v = 1; v <= ty; v++)
        if (g[u][v] && !visited[v])
        {
            visited[v] = 1;
            if (!cy[v] || dfs(cy[v]))
            {
                cx[u] = v, cy[v] = u;
                return 1;
            }
        }
    return 0;
}

// 匈牙利算法求最大匹配数。
int hungarian()
{
    int matches = 0;
    memset(cx, 0, sizeof(cx)); memset(cy, 0, sizeof(cy));
    for (int i = 1; i <= tx; i++)
        if (!cx[i])
        {
            memset(visited, 0, sizeof(visited));
            matches += dfs(i);
        }
    return matches;
}

void mark(int u)
{
    mx[u] = 1;
    for (int v = 1; v <= ty; v++)
        if (g[u][v] && !visited[v])
        {
            visited[v] = 1, my[v] = 1;
            mark(cy[v]);
        }
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int r, c, n, x, y;
    while (cin >> r >> c >> n, r > 0)
    {
        tx = r, ty = c;

        memset(g, 0, sizeof g);
        memset(inx, 0, sizeof inx); memset(iny, 0, sizeof iny);
        for (int i = 1; i <= n; i++)
        {
            cin >> x >> y;
            g[x][y] = 1;
            inx[x] = iny[y] = 1;
        }
        
        cout << hungarian();
        
        memset(mx, 0, sizeof mx); memset(my, 0, sizeof my);
        for (int u = 1; u <= tx; u++)
            if (inx[u] && !cx[u])
            {
                memset(visited, 0, sizeof visited);
                mark(u);
            }
        
        for (int i = 1; i <= tx; i++)
            if (inx[i] && !mx[i]) cout << " r" << i;
        for (int i = 1; i <= ty; i++)
            if (iny[i] && my[i]) cout << " c" << i;

        cout << '\n';
    }

    return 0;
}
