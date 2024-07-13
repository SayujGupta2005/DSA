#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int limit = sqrt(n) + 1;
    vector<bool> is_prime(limit, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i < limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // Collect primes up to sqrt(n)
    vector<int> primes;
    for (int i = 2; i < limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    // Step 2: Segmented Sieve for range [2, n]
    int segment_size = limit;
    vector<bool> segment(segment_size, true);
    int count = 0;

    for (int low = 2; low < n; low += segment_size) {
        fill(segment.begin(), segment.end(), true);

        int high = min(low + segment_size, n);

        for (int prime : primes) {
            int start = max(prime * prime, (low + prime - 1) / prime * prime);
            for (int j = start; j < high; j += prime) {
                segment[j - low] = false;
            }
        }

        for (int i = low; i < high; i++) {
            if (segment[i - low]) {
                count++;
            }
        }
    }

    cout << count;

    return 0;

}