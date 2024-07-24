class Solution {
public:
    string reverseWords(string s) {
        int start = 0;  // Pointer to the start of the string
        int end = s.size() - 1;  // Pointer to the end of the string
        
        // Remove leading spaces by moving the start pointer to the right
        while (start <= end && s[start] == ' ') start++;
        // Remove trailing spaces by moving the end pointer to the left
        while (end >= start && s[end] == ' ') end--;
        
        vector<string> words;  // Vector to store individual words
        string word;  // Temporary string to build each word
        
        // Extract words from the string within the bounds of start and end
        for (int i = start; i <= end; i++) {  // Loop through the string from start to end
            if (s[i] != ' ') {  // If the current character is not a space
                word += s[i];  // Add the character to the current word
            } else if (s[i] == ' ' && !word.empty()) {  // If a space is encountered and the current word is not empty
                words.push_back(word);  // Add the current word to the vector
                word = "";  // Reset the word to start building the next word
            }
        }
        
        // Add the last word if it's not empty (this handles the last word in the string)
        if (!word.empty()) {
            words.push_back(word);
        }
        
        // Reverse the order of the words in the vector
        reverse(words.begin(), words.end());
        string ans;  // String to build the final result
        
        // Concatenate the reversed words into the result string
        for (int i = 0; i < words.size(); i++) {
            ans += words[i];  // Add the current word to the result string
            if (i != words.size() - 1) {  // If it's not the last word, add a space after it
                ans += " ";
            }
        }
        return ans;  // Return the final reversed string
    }
};















// class Solution {
// public:
//     string reverseWords(string s) {
//         string result;  // This will store the final reversed words
//         int i = 0;  // Start index for traversing the string
//         int n = s.length();  // Length of the input string

//         while (i < n) {
//             // Skip spaces to find the start of a word
//             while (i < n && s[i] == ' ') i++;
//             if (i >= n) break;  // If we reach the end of the string, break the loop

//             // Find the end of the current word
//             int j = i + 1;  // Start looking from the next character
//             while (j < n && s[j] != ' ') j++;

//             // Extract the current word
//             string sub = s.substr(i, j - i);

//             // If result is empty, this is the first word
//             if (result.length() == 0) {
//                 result = sub;
//             } else {
//                 // Prepend the current word to the result
//                 result = sub + " " + result;
//             }

//             // Move i to the next character after the current word
//             i = j + 1;
//         }
        
//         return result;  // Return the reversed words
//     }
// };