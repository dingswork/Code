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
#include <vector>

using namespace std;

const int MAXV = 1010;

struct edge
{
    int from, to, weight;
    edge (int from = 0, int to = 0, int weight = 0): from(from), to(to), weight(weight) {}
    bool operator<(const edge& x) const {
        return weight < x.weight;
    }
};

edge edges[MAXV * MAXV];
int parent[MAXV], ranks[MAXV];
int numberOfVertices, numberOfEdges;

void makeSet()
{
    for (int i = 0; i < numberOfVertices; i++) {
        parent[i] = i; ranks[i] = 0;
    }
}

int findSet(int x)
{
    return (parent[x] == x ? x : parent[x] = findSet(parent[x]));
}

bool unionSet(int x, int y)
{
    x = findSet(x), y = findSet(y);
    if (x != y) {
        if (ranks[x] > ranks[y]) parent[y] = x;
        else {
            parent[x] = y;
            if (ranks[x] == ranks[y]) ranks[y]++;
        }
        return true;
    }
    return false;
}

int kruskal()
{
    int minWeightSum = 0;

    makeSet();
    sort(edges, edges + numberOfEdges);

    for (int i = 0; i < numberOfEdges; i++)
        if (unionSet(edges[i].from, edges[i].to))
            minWeightSum += edges[i].weight;

    return minWeightSum;
}

int main(int argc, char *argv[])
{
    cout << kruskal() << endl;
 
    return 0;   
}
