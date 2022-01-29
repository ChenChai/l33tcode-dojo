class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) { return s; }
        // pre-initialize the array
        string ans(s.size(), 0);
        
        int currentIndex = 0;
        
        for (int row = 0; row < numRows; row++) {
        
            // Increment by amount we need to get the right character
            int i = row;
            while (i < s.size()) {
                
                if (row != numRows - 1) {
                    ans[currentIndex] = s[i];
                    i += 2*(numRows - row - 1); // move to next index going  over "bottom part" of zigzag
                    currentIndex++;
                }
                if (i >= s.size()) {break;}
                
                if (row != 0) {
                    ans[currentIndex] = s[i];
                    i+= 2*(row); // move to next index going over "top part" of zigzag
                    currentIndex++;
                }
                
            }
        }
        
        return ans;
    }
};