class Solution {
public:
    int myAtoi(string s) 
    {
        if (s.length() == 0) return 0;
        int i = 0;

        // Skipping leading whitespaces
        while (i < s.size() && s[i] == ' ')   
        {
            i++;
        } 
        
        // Extracting the sign
        int sign = 1;
        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i++] == '-') ? -1 : 1;
        }

        long ans = 0;

        // Processing digits
        while (i < s.length() && isdigit(s[i]))
        {
            ans = ans * 10 + (s[i++] - '0');

            // Checking for overflow
            if (sign == -1 && -1 * ans < INT_MIN) return INT_MIN;
            if (sign == 1 && ans > INT_MAX) return INT_MAX;
        }

        return (int)(sign * ans);
    }
};