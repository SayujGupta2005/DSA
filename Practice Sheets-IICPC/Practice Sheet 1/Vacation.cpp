#include<bits/stdc++.h>
using namespace std;

long long int n, a[100009], b[100009], c[100009];
long long int dp[100009][4];

long long int solve(int x, int prev) {
    if (x == n)
        return 0;

    if (dp[x][prev] != -1)
        return dp[x][prev];

    long long int ans = INT_MIN;

    if (prev == 0) {
        ans = max(ans, b[x] + solve(x + 1, 1));
        ans = max(ans, c[x] + solve(x + 1, 2));
    } else if (prev == 1) {
        ans = max(ans, a[x] + solve(x + 1, 0));
        ans = max(ans, c[x] + solve(x + 1, 2));
    } else if (prev == 2) {
        ans = max(ans, b[x] + solve(x + 1, 1));
        ans = max(ans, a[x] + solve(x + 1, 0));
    } else {
        ans = max(ans, c[x] + solve(x + 1, 2));
        ans = max(ans, b[x] + solve(x + 1, 1));
        ans = max(ans, a[x] + solve(x + 1, 0));
    }

    return dp[x][prev] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    long long int ans = solve(0, 3);

    cout << ans << endl;
}
