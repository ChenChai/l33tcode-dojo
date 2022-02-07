class Solution {
public:
    bool isValid(string s) {
        stack<char> parenStack;
        
        for (int i = 0; i < s.size(); i++) {
            
            char c = s[i];
            
            switch (c) {
                case '(':
                case '[':
                case '{':
                    
                    parenStack.push(c);
                    break;
                case ')':
                    if (!parenStack.empty() && parenStack.top() == '(') {
                        parenStack.pop();
                    } else {
                        return false; 
                    }
                    break;
                case ']':
                    if (!parenStack.empty() && parenStack.top() == '[') {
                        parenStack.pop();
                    } else {
                        return false; 
                    }
                    break;
               case '}':
                    if (!parenStack.empty() && parenStack.top() == '{') {
                        parenStack.pop();
                    } else {
                        return false; 
                    }
                    break;
            }
            
            
        }
        
        return parenStack.empty();
    }
};