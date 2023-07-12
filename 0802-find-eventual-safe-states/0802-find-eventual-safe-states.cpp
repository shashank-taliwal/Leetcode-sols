class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      // Approach: Using topological sort (kahn's algorithm to find the cycle in a graph)
        // The question boils down to finding the nodes that do not lead to cycle of the graph
        
        int n=graph.size();
        map<int,vector<int>> adj;
        vector<int> outDegree(n,0);
        for(int i=0;i<n;i++){
            outDegree[i]+=graph[i].size();
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(outDegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(int neighs:adj[node]){
                outDegree[neighs]--;
                if(outDegree[neighs]==0){
                    q.push(neighs);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};