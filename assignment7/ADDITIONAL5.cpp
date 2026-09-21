#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxIceCream(vector<int>& costs, long long coins) {
    int maxCost = *max_element(costs.begin(), costs.end());
    vector<int> count(maxCost + 1, 0);

    for (int cost : costs) {
        count[cost]++;
    }

    int iceCreams = 0;
    for (int cost = 1; cost <= maxCost; cost++) {
        if (count[cost] == 0) continue;
        if (coins < (long long)cost * count[cost]) {
            int canBuy = coins / cost;
            iceCreams += canBuy;
            break;
        }
        coins -= (long long)cost * count[cost];
        iceCreams += count[cost];
    }
    return iceCreams;
}

int main() {
    vector<int> costs = {1, 3, 2, 4, 1};
    long long coins = 7;
    cout << "Maximum Ice Cream Bars: " << maxIceCream(costs, coins) << endl;
    return 0;
}