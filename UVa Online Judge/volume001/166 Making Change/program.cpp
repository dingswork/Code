#include <iostream>
#include <limits>
#include <algorithm>
#include <iomanip>

using namespace std;

// 面值除以 5 转换后便于处理。
int denominations[6] = { 1, 2, 4, 10, 20, 40 };
int coins[6], usedCoins[6];
const int MAX_INT = numeric_limits < int >::max();
const int MIN_INT = numeric_limits < int >::min();

// 卖家找零钱，由于有足够的硬币数量，总是可以给出找零方案。
int findSellerChange(int money)
{
    int count = 0;
    while (money > 0)
    {
        for (int i = 5; i >= 0; i--)
            if (denominations[i] <= money)
            {
                count++;
                money -= denominations[i];
            }
    }
    return count;
}

// 买家找零钱，由于硬币数量有限制，可能无法找零钱。
int findBuyerChange(int money)
{
    int count = 0;
    fill(usedCoins, usedCoins + 6, 0);
    while (true)
    {
        bool found = false;
        for (int i = 5; i >= 0; i--)
            if (denominations[i] <= money && usedCoins[i] < coins[i])
            {
                money -= denominations[i];
                usedCoins[i]++;
                found = true;
                count++;
                break;
            }

        if (money == 0)
            return count;

        if (found == false && money > 0)
            return MIN_INT;
    }
}

void findMinimalCoins(int money)
{
    int moneyOfTotal = 0;
    for (int i = 0; i < 6; i++)
        moneyOfTotal += coins[i] * denominations[i];

    // 搜索所有可能的找零方案，寻找最小易手硬币数量。
    int minCoins = MAX_INT;
    for (int i = 0; i <= moneyOfTotal; i++)
    {
        int coinsOfBuyer = findBuyerChange(money + i);
        if (coinsOfBuyer == MIN_INT)
            continue;
        minCoins = min(minCoins, (coinsOfBuyer + findSellerChange(i)));
    }

    cout << setw(3) << right << minCoins << endl;
}

int main(int argc, char *argv[])
{
    while (true)
    {
        // 读入顾客的硬币数量。
        int zero = 0;
        for (int i = 0; i < 6; i++)
        {
            cin >> coins[i];
            zero += coins[i] == 0;
        }
        if (zero == 6)
            break;

        // 将钱的数量转换成整数便于处理。
        double money;
        cin >> money;
        findMinimalCoins((int)(money * 100.0 + 0.5) / 5);
    }

    return 0;
}
