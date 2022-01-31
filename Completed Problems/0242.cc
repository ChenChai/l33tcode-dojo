class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) { return false; }
        
        // Store how many times we've seen each letter 
        // in string s minus the times we've seen it in string t
        //
        // if they're all zero at the end then well the letters are the same!
        vector<int> letters(26, 0);
        
        
        for (int i = 0; i < s.size(); i++) {
            letters[s[i] - 'a']++;
            letters[t[i] - 'a']--;
        }
        
        for (int i = 0; i < letters.size(); i++) {
            if (letters[i] != 0) { return false; }
        }
        
        return true;
    }
};