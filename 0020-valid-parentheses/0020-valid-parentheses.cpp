class Solution {
public:
    bool isValid(string s) {
        // Stack to keep track of opening brackets
        stack<char> st;

        // Iterate through each character in the string
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            // If the character is an opening bracket, push it onto the stack
            if (ch == '{' || ch == '[' || ch == '(') {
                st.push(ch);
            } 
            else { // If the character is a closing bracket
                // Check if the stack is not empty
                if (!st.empty()) {
                    // Check if the top of the stack is the matching opening bracket
                    if ((ch == '}' && st.top() == '{') || 
                        (ch == ']' && st.top() == '[') || 
                        (ch == ')' && st.top() == '(')) {
                        st.pop(); // If it matches, pop the top of the stack
                    } 
                    else {
                        return false; // If it doesn't match, the string is invalid
                    }
                } 
                else {
                    return false; // If stack is empty and we encounter a closing bracket, string is invalid
                }
            }
        }

        // After iterating through the string, check if the stack is empty
        if (st.empty()) {
            return true; // If stack is empty, all brackets were matched correctly
        } 
        else {
            return false; // If stack is not empty, there are unmatched opening brackets
        }
    }
};
