class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        for(int i=0;i<rows;i++){
            int j=0;
            int k=i;
            while(k<rows-1 && j<cols-1){
                if(matrix[k][j]!=matrix[k+1][j+1]){
                    return false;
                }
                k++;j++;
            }
        }
        
         for(int i=0;i<cols;i++){
            int j=0;
            int k=i;
            while(k<cols-1 && j<rows-1){
                if(matrix[j][k]!=matrix[j+1][k+1]){
                    return false;
                }
                k++;j++;
            }
        }
        return true;
    }
};