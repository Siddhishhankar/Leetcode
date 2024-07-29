class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
           // Edge case: if amount is 0, no coins are needed
    if (amount == 0) return 0;

    // Create a DP array with size amount+1, initialized to a large number
    vector<int> dp(amount + 1, amount + 1);
    // Base case: No coins needed to make amount 0
    dp[0] = 0;

    // Iterate over all amounts from 1 to amount
    for (int i = 1; i <= amount; ++i) {
        // Check each coin to see if it can contribute to the current amount i
        for (int coin : coins) {
            // If the coin can be used (i.e., coin is less than or equal to i)
            if (coin <= i) {
                // Update dp[i] to the minimum of its current value or the value of dp[i - coin] + 1
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // If dp[amount] is still amount+1, it means amount cannot be made up by any combination of the coins
    return dp[amount] > amount ? -1 : dp[amount];
}

};