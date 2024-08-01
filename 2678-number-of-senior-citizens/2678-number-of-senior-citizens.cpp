class Solution {
public:
   int countSeniors(vector<string>& details) {
        int seniorCount = 0;

        // Iterate over each passenger's details
        for (const string& detail : details) {
            // Extract the age part of the string (12th and 13th characters)
            string ageStr = detail.substr(11, 2);

            // Convert the age string to an integer
            int age = stoi(ageStr);

            // Check if the age is greater than 60
            if (age > 60) {
                seniorCount++;
            }
        }

        return seniorCount;
    }
};