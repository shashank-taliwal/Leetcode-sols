class Solution {
    bool topologicalSortExisting(map<int,vector<int>>& adj, vector<int>& inDegree, int n){
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int neighs: adj[node]){
                inDegree[neighs]--;
                if(inDegree[neighs]==0){
                    q.push(neighs);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(inDegree[i]!=0){
                return false;
            }
        }
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //This problem is equivalent of finding if a cycle exists in a graph 
        //Approach Used:- Topological Sorting
        
        map<int,vector<int>> adj;
        vector<int> inDegree(numCourses,0);
        
        for(vector<int> prerequisite: prerequisites){
            int obtd=prerequisite[0];
            int reqd=prerequisite[1];
            
            adj[reqd].push_back(obtd);
            inDegree[obtd]++;
        }
        return topologicalSortExisting(adj,inDegree,numCourses);
    }
};