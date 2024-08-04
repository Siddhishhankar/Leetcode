class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // Modulo constant
        const int MOD = 1e9 + 7;

        // Vector to store all subarray sums
        vector<int> subarraySums;

        // Generate all subarray sums
        for (int i = 0; i < nums.size(); ++i) {
            int currentSum = 0;
            for (int j = i; j < nums.size(); ++j) {
                currentSum += nums[j];
                subarraySums.push_back(currentSum);
            }
        }

        // Sort the subarray sums
        sort(subarraySums.begin(), subarraySums.end());

        // Calculate the sum from the left-th to the right-th smallest sums
        int result = 0;
        for (int i = left - 1; i <= right - 1; ++i) {
            result = (result + subarraySums[i]) % MOD;
        }

        return result;
    }
};
