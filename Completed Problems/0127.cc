class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Add beginWord since it might not be in wordList
        bool found = false;
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == beginWord) {
                found = true;
            }
        }
        if (!found) {
            wordList.push_back(beginWord);
        }
        
        // Construct adjacency list graph representation
        // Each word is a vertex in the graph
        // Nodes that are different by one letter are connected by an edge.
        unordered_map<string, vector<string> > graph;
        
        // Insert each word in the graph and check for words different by one letter
        for (int i = 0; i < wordList.size(); i++) {
            
            graph[wordList[i]] = {};
            for (int j = 0; j < i; j++) {
                
                if (differByOne(wordList[i], wordList[j])) {
                    // Add to both nodes' adjacency lists since
                    // edges will be bidirectional
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        
        // Now that our graph is constructed, we can perform a simple breadth-first
        // search to locate the shortest path from start to end node
        // this works since each edge is one transformation on the ladder.
        
        // BFS queue with starting node inserted
        queue<string> q;
        q.push(beginWord);
        unordered_map<string, int> distance;
        distance[beginWord] = 1;
        
        while (!q.empty()) {
            string current = q.front();
            int currentDistance = distance[current];
            // Find adjacent nodes
            for (string adjacent : graph[current]) {
                
                // Already searched
                if (distance.find(adjacent) != distance.end()) {
                    continue;
                } 
                
                // We found it! It's adjacent to the
                // current node and not explored yet so
                // we can just say adjacent + 1
                if (adjacent == endWord) {
                    return currentDistance + 1;
                }
                
                
                // Add to queue
                distance[adjacent] = currentDistance + 1;
                q.push(adjacent);
            }
            
            q.pop();
        }
        
        return 0;
    }
    
private:
    // May be able to optimize this by precomputing some representative value (sum?) 
    // for each string and using that to help
    bool differByOne(string s1, string s2) {
        int different = 0;
        
        for (int i = 0; i < s1.size(); i++) {
            different += s1[i] != s2[i];
        }
        
        return different == 1;
    }
};