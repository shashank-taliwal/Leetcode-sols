class Solution {
    long long pi(int hi, int lo){
        long long p=1;
        for(int i=lo;i<=hi;i++){
            p*=i;
        }
        return p;
    }
    long long calculateValue(int row, int col){
        int nr=row-1;
        int dr1=col-1;
        int dr2=nr-dr1;
        int dr=max(dr1,dr2);
        long long Nr=pi(nr,dr+1);
        long long Dr=pi(min(dr1,dr2),1);
        return (long long)Nr/Dr;
    }
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int> > ans;
        for(int i=1;i<=numRows;i++){
            vector<int> currentRow;
            for(int j=1;j<i+1;j++){
                if(j==0 or j==i){
                    currentRow.push_back(1);
                }
                else{
                    long long value=calculateValue(i,j);
                    currentRow.push_back(value);
                }
            }
            ans.push_back(currentRow);
        }
        return ans;
    }
};