#include <iostream>
#include <vector>
using namespace std;

double knapsackFractional(vector<pair<int, int>> sack, int sackWt) {
    double maxProfit = 0;

    for (int i = 0; i < sack.size(); i++) {
        int profit = sack[i].first;
        int weight = sack[i].second;

        if (weight <= sackWt) {
            maxProfit += profit;
            sackWt -= weight;
        } else {
            // Calculate fractional part
            double ratio = (double) sackWt / weight;
            maxProfit += ratio * profit;
            break;  
        }
    }

    return maxProfit;
}

int main() {
    vector<pair<int, int>> sack = {{60, 10}, {100, 20}, {120, 30}};
    int sackWt = 50;

    cout << knapsackFractional(sack, sackWt) << endl;

    return 0;
}