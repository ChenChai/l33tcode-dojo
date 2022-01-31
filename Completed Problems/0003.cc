class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> charsInWindow;
        
        int maxSize = 0;
        int windowStart = 0;
        
        for (int i = 0; i < s.size(); i++) {
            
            char c = s[i];
            
            // duplicate letter, move window up until duplicate gone
            while (charsInWindow.find(c) != charsInWindow.end()) {
                charsInWindow.erase(s[windowStart]);
                windowStart++;
            }

            charsInWindow.insert(c);
            
            maxSize = max(maxSize, i - windowStart + 1);
        }
        
        return maxSize;
    }
};