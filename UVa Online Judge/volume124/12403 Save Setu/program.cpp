// Save Setu
// UVa ID: 12403
// Verdict: Accepted
// Submission Date: 2017-12-17
// UVa Run Time: 0.000s
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

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int n, k;
    string command;

    while (cin >> n)
    {
        int donates = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> command;
            if (command == "report") cout << donates << '\n';
            else
            {
                cin >> k;
                donates += k;
            }
        }
    }

    return 0;
}
