class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        // breadth First Search
        
        queue<pair<int, int> > q;
        vector<vector<int> > ans(mat.size(), vector<int>(mat[0].size(), INT_MAX));

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    q.push(pair<int, int>{i, j});
                    ans[i][j] = 0;
                }
            }
        }
        
        do {
            // Searches next node in queue
            search(q, mat, ans);
        } while (!q.empty());
        
        return ans;
    }
    
private:
    bool isValidCoord(int i, int j, vector<vector<int>>& mat) {
        return i >= 0 && j >= 0 && i < mat.size() && j < mat[0].size();
    }
    
    void search(queue<pair<int, int> > & q, vector<vector<int> > &mat,vector<vector<int> >& ans) {
        // Grab node
        int i = get<0>(q.front());
        int j = get<1>(q.front());
        q.pop();
        //cout << "processing " <<  i << " " << j << " " << endl; 
 
        if (!isValidCoord(i, j, mat)) { return; }    
        
        
        int minValSurrounding = INT_MAX;
        if (isValidCoord(i + 1, j, mat)) {
            minValSurrounding = min(minValSurrounding, ans[i + 1][j]);
            if (ans[i + 1][j] == INT_MAX) { q.push(pair<int, int>(i + 1, j)); }
        }        
        
        if (isValidCoord(i - 1, j, mat)) {
            minValSurrounding = min(minValSurrounding, ans[i - 1][j]);
            if (ans[i - 1][j] == INT_MAX) { q.push(pair<int, int>(i - 1, j)); }
        }
        
        if (isValidCoord(i, j + 1, mat)) {
            minValSurrounding = min(minValSurrounding, ans[i][j + 1]);
            if (ans[i][j + 1] == INT_MAX) { q.push(pair<int, int>(i, j + 1)); }
        }
         
        if (isValidCoord(i, j - 1, mat)) {
            minValSurrounding = min(minValSurrounding, ans[i][j - 1]);
            if (ans[i][j - 1] == INT_MAX) { q.push(pair<int, int>(i, j - 1)); }
        }
        
        // node has already been processed
        if (ans[i][j] != INT_MAX) { return; }

        // get next lowest value from nodes around
        ans[i][j] = minValSurrounding + 1;
        cout << "got " <<  minValSurrounding + 1  << endl; 

    }
    
};