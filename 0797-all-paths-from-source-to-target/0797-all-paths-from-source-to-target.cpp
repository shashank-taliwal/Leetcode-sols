class Solution {
        void dfsUtil(int src, int dest, vector<vector<int>>& allPaths, vector<int> path, vector<int> visited, vector<vector<int>>& graph){
                visited[src]=1;
                path.push_back(src);
                if(src==dest){
                        allPaths.push_back(path);
                        return;
                }
                for(int i=0;i<graph[src].size();i++){
                        if(!visited[graph[src][i]]){
                                dfsUtil(graph[src][i],dest,allPaths,path,visited,graph);
                        }
                }
                return;
        }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> allPaths;
        vector<int> path;
            int n=graph.size();
            int src=0;
            int dest=n-1;
            
            vector<int> visited(n,0);
            dfsUtil(src,dest,allPaths,path,visited, graph);
            return allPaths;
    }
};