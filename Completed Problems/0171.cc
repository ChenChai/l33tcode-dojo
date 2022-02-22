class Solution {
public:
    int titleToNumber(string columnTitle) {
        int total = columnTitle[0] - 'A' + 1;
        
        for (int i = 1; i < columnTitle.size(); i++) {
            total *= 26;
            
            total += columnTitle[i] - 'A' + 1;
        }
        
        return total;
    }
};
