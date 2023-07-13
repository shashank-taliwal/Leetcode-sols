class Solution {
    int findRow(vector<vector<int>>& matrix, int target){
        int n=matrix.size();
        int low=0,high=n-1;
        int mid;
        int ans=-1;
        while(low<=high){
            mid=(low+high)/2;
            if(matrix[mid][0]<=target){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    int findElement(vector<int> row, int target){
        for(int i=0;i<row.size();i++){
            cout<<row[i]<<" ";
        }
        cout<<endl;
        int low=0,high=row.size()-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(row[mid]==target){
                return mid;
            }
            else if(row[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int idx=findRow(matrix,target);
        cout<<idx<<endl;
        if(idx==-1)return false;
        int ans=findElement(matrix[idx],target);
        if(ans==-1)return false;
        return true;
    }
};