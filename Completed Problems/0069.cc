class Solution {
public:
    int mySqrt(int x) {
        int i = 0;
        
        while (x >= 0) {
            i++;
            x -= 2*i - 1;
        }
                
        return i - 1;
    }
};