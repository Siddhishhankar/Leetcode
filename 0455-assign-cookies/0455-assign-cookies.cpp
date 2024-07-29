class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort the greed factors of children and the sizes of cookies
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0; // Index for children
        int j = 0; // Index for cookies

        // Iterate through both vectors
        while (i < g.size() && j < s.size()) {
            // If the current cookie can satisfy the current child's greed
            if (s[j] >= g[i]) {
                i++; // Move to the next child
            }
            j++; // Move to the next cookie
        }
        
        // The number of satisfied children is 'i'
        return i;
    }
};