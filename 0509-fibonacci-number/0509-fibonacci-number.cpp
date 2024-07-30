class Solution {
 public:
  int fib(int n) {
    // Base case: if n is less than 2, return n (0 or 1)
    if (n < 2)
      return n;

    // Initialize a vector with three elements to store the last two Fibonacci numbers and the current one
    vector<int> dp{0, 0, 1};

    // Iterate from 2 to n to calculate the Fibonacci numbers
    for (int i = 2; i <= n; ++i) {
      // Shift the last two Fibonacci numbers: dp[0] becomes the previous dp[1]
      dp[0] = dp[1];
      // dp[1] becomes the previous dp[2]
      dp[1] = dp[2];
      // Calculate the current Fibonacci number and store it in dp[2]
      dp[2] = dp[0] + dp[1];
    }

    // Return the n-th Fibonacci number, which is stored in dp[2]
    return dp.back();
  }
};
