class Solution {
public:
    bool isMatch(string s, string p) {
        return recurse(s, p, 0, 0);
    }
    
private:
    bool recurse(string &s, string &p, int sIndex, int pIndex) {
        // cout << "Trying to match s=" << sIndex << " with p=" << pIndex << " ";

        // out of bounds, assume vacuous truth for matching
        if (sIndex >= s.size() && pIndex >= p.size()) {
            // cout << "True: End of both strings" << endl;
            return true;
        }
        
        if (pIndex >= p.size()) {
            // out of characters in pattern matches, return false
            return false;
        }
        
        if (sIndex >= s.size()) {
            // keep trying to match if we can...
            if (p[pIndex] == '*' || (pIndex + 1 < p.size() && p[pIndex + 1] == '*')) {
                return recurse(s, p, sIndex, pIndex + 1);
            }
            return false;
        }
        
        // expansion character
        if (p[pIndex] == '*') {
            char preceding = p[pIndex - 1];
            
            // wildcard case or matches character
            if (preceding == '.' || preceding == s[sIndex]) {
                // cout << "Matching with *" << endl;
                return recurse(s, p, sIndex + 1, pIndex) // use wildcard
                    || recurse(s, p, sIndex, pIndex + 1) // don't use wildcard;
                    || recurse(s, p, sIndex + 1, pIndex + 1); // use wildcard and move on
            } else {
                //cout << "skipping *" << endl;
                // doesn't match character, keep on going with next character
                // in pattern to try to match
                return recurse(s, p, sIndex, pIndex + 1);
            }
        } else {
            // normal character
            
            if (p[pIndex] == '.' || s[sIndex] == p[pIndex]) {
                // matches!
                if (pIndex + 1 < p.size() && p[pIndex + 1] == '*') {
                    //cout << "Trying either normal char or wildcard" << endl;
                    // next character is a wildcard so we can try skipping it
                    return recurse(s, p, sIndex + 1, pIndex + 1) || recurse(s, p, sIndex, pIndex + 2);
                }
                
                //cout << "regular character" << endl;
                return recurse(s, p, sIndex + 1, pIndex + 1);
            } else if (pIndex + 1 < p.size() && p[pIndex + 1] == '*') {
                
                //cout << "trying skipping *" << endl;
                // next character is a wildcard so we can try skipping it
                return recurse(s, p, sIndex, pIndex + 2);
            } else {
                //cout << "no match";
                return false;
            }
            
        }
    }
};