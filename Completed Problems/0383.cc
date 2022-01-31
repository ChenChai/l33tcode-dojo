class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // how many times each letter appears in each of note and magazine
        vector<int> ransomCount(26, 0);
        vector<int> magazineCount(26, 0);
        
        // count!
        for (const char &c : ransomNote) {
            ransomCount[c - 'a']++;
        }
        
        for (const char &c : magazine) {
            magazineCount[c - 'a']++;
        }
        
        // Compare!
        for (int i = 0; i < 26; i++) {
            // ransom note has too of this letter for magazine to provide
            if (ransomCount[i] > magazineCount[i]) { 
                return false;
            }
        }
        
        return true;
    }
};