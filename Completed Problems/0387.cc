class Solution {
public:
    int firstUniqChar(string s) {
        
        // First index of each character; -1 if hasn't been seen yet, -2 if repeating
        vector<int> firstIndex(26, -1);
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (firstIndex[c - 'a'] == -1) {
                firstIndex[c - 'a'] = i;
            } else {
                firstIndex[c - 'a'] = -2;
            }
        }
        
        int first = s.size();
        
        for (int i = 0; i < 26; i++) {
            if (firstIndex[i] == -1 || firstIndex[i] == -2) {
                continue;
            }
            
            first = min(first, firstIndex[i]);
        }
        
        // char not found!
        if (first == s.size()) { first = -1; }
        
        return first;
    }
};