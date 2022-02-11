class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int> charsSeen(26, 0);
        vector<int> charsWanted(26, 0);
        
        // Fill up charsWanted
        for (char s : s1) {
            charsWanted[s - 'a']++;
        }
        
        int windowStart = 0;
        for (int i = 0; i < s2.size(); i++) {
                        
            char c = s2[i];
            charsSeen[c - 'a']++;

            // Next character makes permutation impossible
            // shift window up until permutation possible
            while (charsSeen[c - 'a'] > charsWanted[c - 'a']) {
                
                charsSeen[s2[windowStart] - 'a']--;
                windowStart++;
            }
            
            
            if (charsSeen == charsWanted) {
                return true;
            }
        }
        
        
        return false;
    }
};