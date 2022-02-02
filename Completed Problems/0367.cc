class Solution {
public:
    bool isPerfectSquare(int num) {
        long x = num;
        while (x*x > num) {
            // x = x - ((x*x - num) / (2*x)); // doesn't hit the target number due to integer division not working out??
            x = (x + num/x) / 2; // re-arranged newton's method that hits target number with integer division
        }
        
        return x*x == num;
    }
};