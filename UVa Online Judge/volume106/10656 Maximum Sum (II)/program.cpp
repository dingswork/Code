// Maximum Sum (II)
// UVa ID: 10656
// Verdict: Accepted
// Submission Date: 2017-12-04
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

    int n, number;
    
    while (cin >> n, n > 0)
    {
        int printed = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> number;
            if (number)
            {
                if (printed++) cout << ' ';
                cout << number;
            }
        }
        if (!printed) cout << 0;
        cout << '\n';
    }

    return 0;
}
