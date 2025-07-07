#include <iostream>
#include <vector>
#include <numeric>

// For faster I/O in C++
void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

// The main logic for solving a single test case
void solve() {
    long long n, k, x;
    std::cin >> n >> k >> x;
    std::vector<long long> a(n);
    long long sum_a = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        sum_a += a[i];
    }

    // Precompute the suffix sums of `a`.
    // `suffix_sum_a[i]` will store the sum of `a[i...n-1]`.
    std::vector<long long> suffix_sum_a(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        suffix_sum_a[i] = suffix_sum_a[i + 1] + a[i];
    }

    long long total_valid_l = 0;

    // Iterate through all possible starting positions `i` within a block (0-indexed).
    // For each `i`, count how many block indices `q` (from `0` to `k-1`) result in a valid `l`.
    for (int i = 0; i < n; ++i) {
        long long current_suffix_sum = suffix_sum_a[i];
        
        // We need to find the number of q's in [0, k-1] satisfying:
        // current_suffix_sum + (k - 1 - q) * sum_a >= x
        
        long long rem = x - current_suffix_sum;
        
        // Case 1: The suffix sum from `i` itself is enough.
        if (rem <= 0) {
            // The condition is met for any `q`, as `(k - 1 - q) * sum_a` is non-negative.
            // All `k` blocks for this `i` are valid.
            total_valid_l += k;
            continue;
        }
        
        // Case 2: We need more sum from the full blocks.
        // All a_i > 0, so sum_a > 0.
        // We need (k - 1 - q) * sum_a >= rem.
        if (sum_a <= 0) {
            // This case is impossible given constraints, but for robustness:
            // If sum_a is not positive, we can't get the positive `rem`. No `q` works.
            continue;
        }

        // We need `k - 1 - q >= ceil(rem / sum_a)`.
        // `ceil(A/B)` for positive `A, B` is `(A + B - 1) / B` using integer division.
        long long num_blocks_needed = (rem + sum_a - 1) / sum_a;
        
        // The condition on `q` becomes: `q <= k - 1 - num_blocks_needed`.
        // Since `q >= 0`, we count integers `q` in `[0, k - 1 - num_blocks_needed]`.
        long long max_q = k - 1 - num_blocks_needed;
        
        if (max_q >= 0) {
            // The number of values for `q` is `max_q - 0 + 1`.
            total_valid_l += (max_q + 1);
        }
    }
    
    std::cout << total_valid_l << std::endl;
}

int main() {
    fast_io();
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}