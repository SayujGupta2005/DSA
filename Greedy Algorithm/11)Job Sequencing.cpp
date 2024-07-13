#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        // Sort the tastiness values of the cakes
        sort(a.begin(), a.end());
        
        set<int> aliceEaten;
        int aliceCount = 0;
        
        for (int i = 0; i < n; ++i) {
            // Alice's turn
            if (aliceEaten.empty() || a[i] > *aliceEaten.rbegin()) {
                // Alice can eat this cake
                aliceEaten.insert(a[i]);
                aliceCount++;
            } else {
                // Bob's turn (skip this cake)
            }
        }
        
        cout << aliceCount << endl;
    }

    return 0;
}
