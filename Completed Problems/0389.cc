class Solution {
public:
    char findTheDifference(string s, string t) {
        
        vector<int> count(26, 0);
        
        for (const char& c : s) {
            count[c - 'a']++;
        }
        
        
        for (const char& c : t) {
            count[c - 'a']--;
        }
        
        for (int i = 0; i < count.size();i++) {
            if (count[i] != 0) {
                return i + 'a';
            }
        }
        
        return -1;
    }
};