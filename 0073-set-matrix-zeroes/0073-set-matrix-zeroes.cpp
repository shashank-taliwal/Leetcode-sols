class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        
        int firstRowFlag=0, firstColFlag=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    if(i==0){
                        firstRowFlag=1;
                    }
                    else{
                        matrix[i][0]=0;
                    }
                    if(j==0){
                        firstColFlag=1;
                    }
                    else{
                        matrix[0][j]=0;
                    }
                }
            }
        }
        cout<<firstRowFlag<<" "<<firstColFlag<<endl;
        for(int i=rows-1;i>=0;i--){
            for(int j=cols-1;j>=0;j--){
                if(i==0 and firstRowFlag==1){
                            matrix[i][j]=0;
                        }
                        if(j==0 and firstColFlag==1){
                            matrix[i][j]=0;
                        }
                    if(matrix[i][0]==0 or matrix[0][j]==0){
                        matrix[i][j]=0;
                    }

                    }
            }
        
    }
};