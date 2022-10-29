class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=floodFillUtil(image, sr, sc, color);
        return ans;
    }
private:
    vector<vector<int>> floodFillUtil(vector<vector<int>>& image, int sr, int sc, int color){
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        queue<pair<int,int>> q;
        int r=image.size();
        int c=image[0].size();
       int visited[r][c];
        memset(visited,0,sizeof(visited));
        q.push({sr,sc});
        int initialColor=image[sr][sc];
        while(!q.empty()){
            int x1=q.front().first;
            int y1=q.front().second;
            visited[x1][y1]=1;
            q.pop();
             image[x1][y1]=color;
            for(int i=0;i<4;i++){
                int x=x1+dx[i];
                int y=y1+dy[i];
                if(isValid(x,y,image) and image[x][y]==initialColor and visited[x][y]==0){
                    q.push({x,y});
                }
            }
        }
        return image;
    }
    bool isValid(int x, int y,vector<vector<int>>& image){
        int rows=image.size();
        int cols=image[0].size();
        if(x<0 or x>=rows){
            return false;
        }
        if(y<0 or y>=cols){
            return false;
        }
        return true;
    }
};