// just implement a trie lololol

struct TrieNode {
    // Does a word exist stopping at this Trie?
    bool containsWord = false;
    
    unordered_map<char, TrieNode*> children;
};


class WordDictionary {

    TrieNode* root = new TrieNode();
    
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode* current = root;
        
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];

            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();          
            }
            
            current = current->children[c];
        }
        
        current->containsWord = true;
    }
    
    bool search(string word) {
        return searchHelper(word, root, 0);
    }
    
private: 
    bool searchHelper(string& word, TrieNode* node, int index) {
        
        if (index == word.size()) { return node->containsWord; }
    
        // word not empty
        
        char c = word[index];
        
        if (c == '.') {
            
            // key = character
            // child = trieNode* that we're pointing to
            for (const auto& [key, child] : node->children) {
                if (searchHelper(word, child, index + 1)) {
                    return true;
                }
            }
        }
        
        if (node->children.find(c) != node->children.end()) {
            
            // We've found the character!
            return searchHelper(word, node->children[c], index + 1);
        } else {
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */