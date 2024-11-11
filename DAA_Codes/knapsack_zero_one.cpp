#include <iostream>
#include <vector>
using namespace std;

int knapsackZeroOne(int index, int sackWt, vector<int>& wt, vector<int>& val) {
    if (index == 0) {
        if (wt[0] <= sackWt) {
            return val[0];
        } else {
            return 0;
        }
    }

    int notTaken = 0 + knapsackZeroOne(index - 1, sackWt, wt, val);

    int taken = INT_MIN;
    if (wt[index] <= sackWt) {
        taken = val[index] + knapsackZeroOne(index - 1, sackWt - wt[index], wt, val);
    }

    return max(notTaken, taken);
}

int main() {
    vector<int> wt = {3, 2, 5};
    vector<int> val = {30, 40, 60};
    int n = 3;
    
    cout << knapsackZeroOne(n - 1, 6, wt, val) << endl;

    return 0;
}