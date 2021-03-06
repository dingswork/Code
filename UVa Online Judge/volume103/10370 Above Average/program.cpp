// Above Average
// UVa ID: 10370
// Verdict: Accepted
// Submission Date: 2018-02-15
// UVa Run Time: 0.000s
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

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int cases, n, grade[1010], sum;
    cin >> cases;
    for (int c = 1; c <= cases; c++)
    {
        cin >> n;
        sum = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> grade[i];
            sum += grade[i];
            grade[i] *= n;
        }
        int t = 0;
        for (int i = 1; i <= n; i++)
            if (grade[i] > sum)   
                t++;
        cout << fixed << setprecision(3) << (t * 100.0 / n) << "%\n";
    }

    return 0;
}
