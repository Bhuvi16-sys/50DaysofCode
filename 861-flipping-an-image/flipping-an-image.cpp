class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int row = image.size();
        int col = image[0].size();
        
        for (int i = 0; i < row; i++) {
            int left = 0;
            int right = col - 1;
            
            while (left <= right) {
                if (image[i][left] == image[i][right]) {
                    // Invert both since they are identical
                    int temp = image[i][left] ^ 1;
                    image[i][left] = temp;
                    image[i][right] = temp;
                }
                left++;
                right--;
            }
        }
        
        return image;
    }
};