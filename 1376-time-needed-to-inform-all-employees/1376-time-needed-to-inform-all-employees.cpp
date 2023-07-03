class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            adj[manager[i]].push_back(i);
        }
        vector<int> inform(n,0);
        inform[headID]=0;
        queue<int> q;
        q.push(headID);
        int ans=0;
        while(!q.empty()){
            int mgr=q.front();
            q.pop();
            for(int emp:adj[mgr]){
                q.push(emp);
                inform[emp]=inform[mgr]+informTime[mgr];
                ans=max(ans,inform[emp]);
            }
        }
        return ans;
    }
};