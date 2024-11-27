// 0/1 Knapsack

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const vector<int> values = {300, 200, 400, 500};
const vector<int> weights = {2, 1, 5, 3};
const int capacity = 10;

int knapsackTabulation() {
    int n = values.size();
    vector<vector<int>> tab(n+1, vector<int>(capacity + 1,0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i-1] <= w) {
                int includetem = values[i - 1]+tab[i-1][w-weights[i-1]];
                int excludeItem = tab[i-1][w];
                tab[i][w] = max(includetem, excludeItem);
            }else {
                tab[i][w] = tab[i-1][w];
            }
        }
    }

    cout << "Items included: ";
    int w = capacity;
    for (int i = n; i>0;i--) {
        if (tab[i][w] != tab[i-1][w]) {
            cout << i << " ";
            w -= weights[i-1];
        }
    }
    cout << endl;

    return tab[n][capacity];
}

int main() {
    cout << "Maximum value in Knapsack = " <<knapsackTabulation() << endl;
    return 0;
}