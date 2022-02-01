// Sorta messy...

class Solution {
public:
    int reverse(int x) {
        int original = x;
        vector<int> min_int = {2, 1, 4, 7, 4, 8, 3, 6, 4, 8};
        vector<int> max_int = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
        
        int reversed = 0;
        if (x >= 0) {
            // positive case
            bool overflow_possible = true;
            
            for (int index = 0; index < 10; index++) {
                if (x == 0) { break; }
                
                // grab digit from the number
                int digit = x % 10;
                x /= 10;
                if (original - 1000000000 > 0 && digit > max_int[index] && overflow_possible) {
                    // overflow!!
                    return 0;
                } else if (digit < max_int[index]) {
                    // sigificant digit is less than the max possible value, overflow no longer possible
                    overflow_possible = false;
                }
                
                reversed *= 10;
                reversed += digit;
                
            }
            
        } else if (x <= 0) {
            // negative case
            bool overflow_possible = true;
            
            for (int index = 0; index < 10; index++) {
                if (x == 0) { break; }
                
                // grab digit from the number
                int digit = x % 10;
                x/=10;
                if (digit < 0) { digit *= -1; }
                
                if (original + 1000000000 < 0 && digit > min_int[index] && overflow_possible) {
                    // overflow!!
                    return 0;
                } else if (digit < min_int[index]) {
                    // sigificant digit is less than the max possible value, overflow no longer possible
                    overflow_possible = false;
                }
                reversed *= 10;
                reversed -= digit;
            }
        }
        
        return reversed;
    }
};