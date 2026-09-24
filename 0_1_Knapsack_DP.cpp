#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weight(n + 1);
    vector<int> value(n + 1);

    cout << "Enter weight and value of each item:\n";

    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Create DP table
    vector<vector<int>> dp(n + 1,
                           vector<int>(capacity + 1, 0));

    // Build DP table
    for (int i = 1; i <= n; i++) {

        for (int w = 1; w <= capacity; w++) {

            if (weight[i] <= w) {
                dp[i][w] = max(
                    value[i] + dp[i - 1][w - weight[i]],
                    dp[i - 1][w]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Display DP table
    cout << "\nDP Table:\n\n";

    cout << "     ";

    for (int w = 0; w <= capacity; w++) {
        cout << w << " ";
    }

    cout << endl;

    for (int i = 0; i <= n; i++) {

        cout << "I" << i << "   ";

        for (int w = 0; w <= capacity; w++) {
            cout << dp[i][w] << " ";
        }

        cout << endl;
    }

    // Create solution vector
    vector<int> solution(n, 0);

    int w = capacity;

    // Trace the DP table
    for (int i = n; i >= 1; i--) {

        if (dp[i][w] != dp[i - 1][w]) {

            solution[i - 1] = 1;

            w = w - weight[i];
        }
    }

    // Display solution vector
    cout << "\nSolution Vector:\n";

    for (int i = 0; i < n; i++) {
        cout << solution[i] << " ";
    }

    cout << endl;

    // Display selected items
    int totalWeight = 0;

    cout << "\nSelected Items:\n";

    for (int i = 0; i < n; i++) {

        if (solution[i] == 1) {

            cout << "Item " << i + 1
                 << " - Weight: " << weight[i + 1]
                 << ", Value: " << value[i + 1]
                 << endl;

            totalWeight += weight[i + 1];
        }
    }

    cout << "\nTotal Weight: "
         << totalWeight << endl;

    cout << "Maximum Value: "
         << dp[n][capacity] << endl;

    return 0;
}
