class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans;

        // Custom sort comparator: compare combined results of two numbers
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });

        // Combine sorted numbers into a single string
        for (const int num : nums)
            ans += to_string(num);

        // If the largest number is "0", return "0"
        if (ans[0] == '0') return "0";

        return ans;
    }
};