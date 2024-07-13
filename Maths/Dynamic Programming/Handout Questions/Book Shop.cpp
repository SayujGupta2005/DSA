#include <bits/stdc++.h>
using namespace std;

int n, b;
int p[1001], no[1001];

void knapsack(int x, int w, vector<int>& dp) {
    for (int i = 0; i < x; i++) {
        for (int j = w; j >= p[i]; j--) {
            dp[j] = max(dp[j], dp[j - p[i]] + no[i]);
        }
    }
}

int main() {
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> no[i];
    }
    vector<int> dp(b + 1, 0);
    knapsack(n, b, dp);
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
