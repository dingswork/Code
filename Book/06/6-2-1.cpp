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

int main(int argc, char *argv[])
{
    string s = "ABCDE", t = "CEADB";
    
    int indexer = 1;
    do {
        if (s == t) {
            cout << indexer << '\n';
            break;
        }
        indexer++;
    } while (next_permutation(s.begin(), s.end()));
    
    return 0;
}
