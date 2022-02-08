class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string sDone;
        string tDone;
        
        for (char c : s) {
            if (c == '#') {
                if (!sDone.empty()) { sDone.pop_back(); }
            } else {
                sDone.push_back(c);
            }
        }
        for (char c : t) {
            if (c == '#') {
                if (!tDone.empty()) { tDone.pop_back(); }
            } else {
                tDone.push_back(c);
            }
        }
        return sDone == tDone;
    }
};