class Solution {
public:
     bool lemonadeChange(vector<int>& bills) {
        int count5 = 0; // Count of $5 bills
        int count10 = 0; // Count of $10 bills
        
        for (int bill : bills) {
            if (bill == 5) {
                // Customer pays with $5 bill, no change needed
                count5++;
            } else if (bill == 10) {
                // Customer pays with $10 bill, give one $5 bill as change
                if (count5 == 0) {
                    return false; // Not enough $5 bills for change
                }
                count5--;
                count10++;
            } else { // bill == 20
                // Customer pays with $20 bill
                if (count10 > 0 && count5 > 0) {
                    // Give one $10 bill and one $5 bill as change
                    count10--;
                    count5--;
                } else if (count5 >= 3) {
                    // Give three $5 bills as change
                    count5 -= 3;
                } else {
                    return false; // Not enough bills for change
                }
            }
        }
        
        return true; // All customers received correct change
    }
};