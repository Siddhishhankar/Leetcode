class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        // Frequency map to count each task
        unordered_map<char, int> countMap;
        for (int i = 0; i < tasks.size(); i++) {
            countMap[tasks[i]]++;
        }
        
        // Get the maximum frequency
        int maxFreq = 0;
        for (auto& entry : countMap) {
            maxFreq = max(maxFreq, entry.second);
        }
        
        // Count how many tasks have the maximum frequency
        int maxFreqCount = 0;
        for (auto& entry : countMap) {
            if (entry.second == maxFreq) {
                maxFreqCount++;
            }
        }
        
        // Calculate the minimum time slots needed
        int minSlots = (maxFreq - 1) * (n + 1) + maxFreqCount;
        
        // The result is the maximum between the calculated minimum slots and the total number of tasks
        return max(minSlots, size);
    }
};
