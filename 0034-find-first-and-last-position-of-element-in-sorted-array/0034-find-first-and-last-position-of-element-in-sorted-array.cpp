class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> res(2, -1); // Initialize result vector with -1, -1

        // Find the first occurrence of target
        int left = 0, right = nums.size() - 1;
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) 
            {
                right = mid - 1;
            } 
            else 
            {
                left = mid + 1;
            }
        }
        
        if (left >= nums.size() || nums[left] != target) 
        {
            return res; // target not found
        }
        res[0] = left; // first occurrence

        // Find the last occurrence of target
        right = nums.size() - 1; // reset right pointer
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) 
            {
                left = mid + 1;
            } 
            else 
            {
                right = mid - 1;
            }
        }
        res[1] = right; // last occurrence

        return res;
    }
};
