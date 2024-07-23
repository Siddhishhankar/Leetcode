class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1); // Initialize result vector with -1, -1

        // Find the first occurrence of target
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                res[0] = i;
                break;
            }
        }

        // If the first occurrence is not found, return [-1, -1]
        if (res[0] == -1) {
            return res;
        }

        // Find the last occurrence of target
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] == target) {
                res[1] = i;
                break;
            }
        }

        return res;
    }
};
