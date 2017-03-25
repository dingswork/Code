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

const int MAXN = 1010;

int cache[MAXN], idx = 0;

bool push(int x)
{
    if (idx < MAXN)
    {
        cache[idx++] = x;
        return true;
    }
    return false;
}

void pop()
{
    if (idx > 0) idx--;
}

int top()
{
    if (idx > 0) return cache[idx - 1];
    return -1;
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < 100; i++)
    {
        push(i);
        cout << top() << '\n';
        pop();
    }
}
