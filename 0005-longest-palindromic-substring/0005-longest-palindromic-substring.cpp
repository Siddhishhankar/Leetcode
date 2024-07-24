class Solution {
public:
    // Helper function to expand around the center and find the longest palindrome
    string expandAroundCenter(const string& s, int left, int right) {
        // Expand outwards while the characters at left and right are the same
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            --left;    // Move left pointer to the left
            ++right;   // Move right pointer to the right
        }
        // When the loop ends, left and right are one position outside the valid palindrome
        // The valid palindrome substring is s[left + 1, right - left - 1]
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";  // If the input string is empty, return an empty string

        string longest;  // To keep track of the longest palindromic substring found

        // Iterate through each character in the string
        for (int i = 0; i < s.length(); ++i) {
            // Check for odd-length palindromes centered at i
            // A single character is the center of a potential palindrome
            string oddPalindrome = expandAroundCenter(s, i, i);
            if (oddPalindrome.length() > longest.length()) {
                longest = oddPalindrome;  // Update the longest palindrome if needed
            }

            // Check for even-length palindromes centered between i and i + 1
            // Two characters are the center of a potential palindrome
            string evenPalindrome = expandAroundCenter(s, i, i + 1);
            if (evenPalindrome.length() > longest.length()) {
                longest = evenPalindrome;  // Update the longest palindrome if needed
            }
        }

        return longest;  // Return the longest palindromic substring found
    }
};
