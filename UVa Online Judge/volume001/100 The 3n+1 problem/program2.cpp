#include <iostream>

using namespace std;

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

const int MAX_SIZE = 1000000;

int cache[MAX_SIZE];

int cycle(long long int n)
{
    if (n == 1) return 1;
    n = (n & 1) ? (n + (n << 1) + 1) : (n >> 1);
    if (n < MAX_SIZE)
    {
        if (!cache[n]) cache[n] = cycle(n);
        return (1 + cache[n]);
    }
    return (1 + cycle(n));
}

string space(int number)
{
    return string(number, ' ');
}

int main(int ac, char *av[])
{
    cout << "#include <iostream>\n";
    cout << "#define min(a, b) (((a) < (b)) ? (a) : (b))\n";
    cout << "#define max(a, b) (((a) > (b)) ? (a) : (b))\n";
    cout << "using namespace std;\n";
    cout << "int main(int ac, char *av[])\n";
    cout << "{\n";
    cout << space(4) << "int cln[1000000] = {0\n";
    for (int i = 1; i < 1000000; i++)
    {
        cout << "," << cycle(i);
        if (i % 1000 == 0)
        {
            cout << "\n";
        }
    }
    cout << space(4) << "};\n";
    cout << space(4) << "int first, second;\n";
    cout << space(4) << "while (cin >> first >> second)\n";
    cout << space(4) << "{\n";
    cout << space(8) << "int maxLength = 0;\n";
    cout << space(8);
    cout << "for (int i = min(first, second); i <= max(first, second); i++)\n";
    cout << space(12) << "if (cln[i] > maxLength)\n";
    cout << space(16) << "maxLength = cln[i];\n";
    cout << space(8);
    cout << "cout << first << \" \" << second << \" \" << maxLength << endl;\n";
    cout << space(4) << "}\n";
    cout << space(4) << "return 0;\n";
    cout << "}\n";
    return 0;
}
