// Friends
// UVa ID: 10608
// Verdict: Accepted
// Submission Date: 2018-01-08
// UVa Run Time: 0.010s
//
// 版权所有（C）2018，邱秋。metaphysis # yeah dot net

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

const int MAXV = 30010;

int parent[MAXV], ranks[MAXV], cnt[MAXV];

void makeSet()
{
    for (int i = 0; i < MAXV; i++) parent[i] = i, ranks[i] = 1;
}

// 带路径压缩的查找，使用递归实现。
int findSet1(int x)
{
    return (x == parent[x] ? x : parent[x] = findSet1(parent[x]));
}

// 带路径压缩的查找，使用迭代实现。
int findSet2(int x)
{
    int ancestor = x, temp;

    while (ancestor != parent[ancestor]) ancestor = parent[ancestor];
    while (x != ancestor) {
        temp = parent[x];
        parent[x] = ancestor;
        x = temp;
    }

    return x;
}

//  集合的按秩合并。
bool unionSet(int x, int y)
{
    x = findSet1(x), y = findSet1(y);
    
    if (x != y) {
        if (ranks[x] > ranks[y]) parent[y] = x, ranks[x] += ranks[y];
        else parent[x] = y, ranks[y] += ranks[x];
        return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int cases;
    cin >> cases;

    for (int c = 1; c <= cases; c++)
    {
        int N, M, A, B;

        makeSet();

        cin >> N >> M;
        for (int i = 1; i <= M; i++)
        {
            cin >> A >> B;
            unionSet(A, B);
        }
        
        cout << *max_element(ranks, ranks + N + 1) << '\n';
    }

    return 0;
}
