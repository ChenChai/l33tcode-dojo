class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // target string hashset
        vector<int> target(26, 0);
        vector<int> current(26, 0);
        
        // construct target
        for (const char& c : s1) {
            target[c - 'a']++;
        }
        
        int windowStart = 0;
        
        // search string for permutation substring
        for (int i = 0; i < s2.size(); i++) {

            char c = s2[i];
            current[c - 'a']++;
            
            // if char not a part of permutation, clear out
            // until it is
            while (windowStart <= i && current[c - 'a'] > target[c - 'a']) {
                current[s2[windowStart] - 'a']--;
                windowStart++;
            }
            
            if (i - windowStart + 1 == s1.size() && target == current) { return true; }
        }
        
        return false;
    }
    
private:
    void clear(vector<int>& v) {
        for (int& num : v) {
            num = 0;
        }
    }
};