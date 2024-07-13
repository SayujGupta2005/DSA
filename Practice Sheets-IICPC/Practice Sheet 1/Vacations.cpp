#include <bits/stdc++.h>
using namespace std;

int n;
int dp[101][3];
vector<int> v;

int func(int x, int last_activity) {
    if (x == n) {
        return 0;
    }
    
    if (dp[x][last_activity] != -1) {
        return dp[x][last_activity];
    }

    int rest_days = 1 + func(x + 1, 0);

    if ((v[x] == 1 || v[x] == 3) && last_activity != 1) {
        rest_days = min(rest_days, func(x + 1, 1));
    }

    if ((v[x] == 2 || v[x] == 3) && last_activity != 2) {
        rest_days = min(rest_days, func(x + 1, 2));
    }

    return dp[x][last_activity] = rest_days;
}

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << func(0, 0) << endl;
    return 0;
}
