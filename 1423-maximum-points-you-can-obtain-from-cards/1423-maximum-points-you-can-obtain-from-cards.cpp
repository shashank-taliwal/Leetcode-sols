class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        //The major goal is to find the window of size n-k with minimum sum
        int len=n-k;
        int start=0,tail=len-1;
        int min_sum=0;
            for(int i=start;i<=tail;i++){
                    min_sum+=cardPoints[i];
            }
            int sum=min_sum;
            while(tail<n-1){
                    tail++;
                    start++;
                    sum+=cardPoints[tail]-cardPoints[start-1];
                    min_sum=min(min_sum,sum);
            }
            int total_sum=0;
            for(int num:cardPoints)total_sum+=num;
            return total_sum-min_sum;
    }
};