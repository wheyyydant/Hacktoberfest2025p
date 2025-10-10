/*
Climbing Stairs Problem
-----------------------
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps.
Your task is to determine how many distinct ways you can climb to the top.

Approach:
---------
Let dp[i] represent the number of distinct ways to reach step i.
Then:
    dp[i] = dp[i-1] + dp[i-2]
Because:
    - From (i-1) you can take one step.
    - From (i-2) you can take two steps.

This is essentially the Fibonacci sequence.

Base Cases:
    dp[1] = 1  (1 way to climb one step)
    dp[2] = 2  (two ways: 1+1 or 2)

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

// Function to compute number of distinct ways to climb 'n' steps
int climbStairs(int n) {
    if (n <= 2) return n; // Base cases

    int prev2 = 1;  // dp[i-2]
    int prev1 = 2;  // dp[i-1]
    int current;

    // Compute ways iteratively
    for (int i = 3; i <= n; ++i) {
        current = prev1 + prev2; // Recurrence relation
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

// -----------------------------
// Example Usage (Runnable Block)
// -----------------------------
int main() {
    int n = 5;  // Example input
    cout << "Number of distinct ways to climb " << n << " steps: " 
         << climbStairs(n) << endl;
    return 0;
}
