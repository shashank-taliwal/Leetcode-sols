class Solution {
public:
    int climbStairs(int n) {
        if(n==1 or n==2){
                return n;
        }
            int first=1,second=2;
            for(int i=3;i<=n;i++){
                    int sum=first+second;
                    first=second;
                    second=sum;
            }
            return second;
    }
};