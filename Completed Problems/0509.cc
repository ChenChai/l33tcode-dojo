class Solution {
    
    
public:
    int fib(int n) {
        // DYNAMIC PROGRAMMINGGGGG
        vector<int> v = {0, 1};
        
        for (int i = 2; i <= n; i++) {
            if (i <= 1) { v.push_back(1); } else
            v.push_back(v[i-1] + v[i-2]);
        }
        
        return v[n];
    }
};