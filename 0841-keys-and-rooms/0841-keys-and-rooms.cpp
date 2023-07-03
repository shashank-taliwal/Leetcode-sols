class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       int n=rooms.size();
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int room=q.front();
            q.pop();
            visited[room]=true;
            for(int key:rooms[room]){
                if(!visited[key])q.push(key);
            }
        }
        // cout<<"_________________________________________"<<endl;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};