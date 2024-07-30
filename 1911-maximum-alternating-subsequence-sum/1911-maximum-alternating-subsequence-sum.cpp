class Solution {
 public:
  long long maxAlternatingSum(vector<int>& nums) {
    long even = 0;  // the maximum alternating sum ending in an even index
    long odd = 0;   // the maximum alternating sum ending in an odd index

    // Iterate through each number in the array
    for (const int num : nums) {
      // Update 'even' to be the maximum of its current value or 'odd + num'
      even = max(even, odd + num);
      // Update 'odd' to be the value of 'even - num'
      odd = even - num;
    }

    // The maximum alternating sum is stored in 'even'
    return even;
  }
};