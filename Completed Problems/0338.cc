class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i < n + 1; i++) {
            ans.push_back(countBitsSingle(i));
        }
        return ans;
    }
    
private:
    int countBitsSingle(int n) {
        int total = 0;
        while (n > 0) {
            
            total += n & 1;
            n >>= 1;
        }
        return total;
    }
};
