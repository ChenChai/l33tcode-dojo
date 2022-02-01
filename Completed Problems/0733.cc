class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        floodFillRecurse(image, sr, sc, image[sr][sc]);
        for (int i = 0; i < image.size(); i++) {
            for (int j = 0; j < image[0].size(); j++) {
                if (image[i][j] == -1) {
                    image[i][j] = newColor;
                }
            }
        }
        
        return image;
    }
    
private:
    void floodFillRecurse(vector<vector<int> > &image, int sr, int sc, int prevColor) {
        // check if out of bounds
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size()) {
            return;
        }
        
        // check if current pixel is flood fillable
        if (image[sr][sc] != prevColor) { 
            return;
        }
        
        image[sr][sc] = -1;
        
        // Fill adjacent squares
        floodFillRecurse(image, sr + 1, sc, prevColor);
        floodFillRecurse(image, sr - 1, sc, prevColor);
        floodFillRecurse(image, sr, sc + 1, prevColor);
        floodFillRecurse(image, sr, sc - 1, prevColor);   
    }
};