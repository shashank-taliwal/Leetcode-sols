class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int N=cost.size()+1;
        vector<int> ans(N);
        ans[0]=cost[0];
        ans[1]=cost[1];
        for(int i=2;i<N-1;i++){
            ans[i]=cost[i]+min(ans[i-1],ans[i-2]);
        }
        return min(ans[N-2],ans[N-3]);
    }
};