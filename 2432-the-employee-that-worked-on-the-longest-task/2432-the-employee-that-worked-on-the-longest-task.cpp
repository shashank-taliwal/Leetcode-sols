class Solution {
public:
       int hardestWorker(int n, vector<vector<int>>& logs) {
        int m=logs.size();
        vector<int> current_max;
        current_max.push_back(logs[0][1]);
        for(int i=1;i<m;i++){
            current_max.push_back(logs[i][1]-logs[i-1][1]);
        }
        int maxi=*max_element(current_max.begin(),current_max.end());
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            if(current_max[i]==maxi){
                ans=min(ans,logs[i][0]);
            }
        }
        return ans;
    }
};