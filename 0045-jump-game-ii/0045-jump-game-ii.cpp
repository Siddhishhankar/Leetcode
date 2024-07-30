
class Solution {
public:
    int jump(vector<int>& nums) {
        // Number of jumps made
        int jumps = 0;
        
        // The end of the range for the current jump
        int currentEnd = 0;
        
        // The farthest index we can reach in the next jump
        int farthest = 0;

        // Loop through each index of the array up to the second-to-last index
        for (int i = 0; i < nums.size() - 1; i++) {
            // Update farthest to be the maximum of its current value and the farthest index we can reach from the current index
            farthest = max(farthest, nums[i] + i);

            // If the current index reaches currentEnd, we need to make another jump
            if (i == currentEnd) {
                jumps++; // Increment the number of jumps
                currentEnd = farthest; // Update currentEnd to farthest

                // If currentEnd reaches or exceeds the last index, we can break out of the loop
                if (currentEnd >= nums.size() - 1) {
                    break;
                }
            }
        }

        // Return the number of jumps
        return jumps;
    }
};