class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Create two frequency arrays to store counts of each character ('a' to 'z')
        vector<int> s1hash(26, 0); // For storing frequency of characters in s1
        vector<int> s2hash(26, 0); // For storing frequency of characters in the current window of s2
        
        int s1len = s1.size(); // Length of s1
        int s2len = s2.size(); // Length of s2

        // If s1 is longer than s2, s1's permutation can't be a substring of s2
        if (s1len > s2len)
            return false;
        
        int left = 0, right = 0;

        // Initialize the frequency arrays with the first window of size s1len
        while (right < s1len) {
            s1hash[s1[right] - 'a'] += 1; // Count characters in s1
            s2hash[s2[right] - 'a'] += 1; // Count characters in the initial window of s2
            right += 1; // Expand the window to the right
        }

        right -= 1;  // Adjust right to point to the last character in the initial window

        // Slide the window over s2
        while (right < s2len) {
            // Check if the current window's character counts match s1's character counts
            if (s1hash == s2hash)
                return true; // If they match, return true

            // Move the window one character to the right
            right += 1;
            
            // Check if the window is within bounds
            if (right != s2len)
                s2hash[s2[right] - 'a'] += 1; // Add the new character to the frequency count of the current window
            
            // Remove the frequency count of the leftmost character that is no longer in the window
            s2hash[s2[left] - 'a'] -= 1;
            left += 1; // Move the left boundary of the window to the right
        }

        // If no permutation of s1 is found in s2, return false
        return false;
    }
};
