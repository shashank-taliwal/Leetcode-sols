class Solution {
public:
    int fib(int n) {
         vector<int> fib_num(n+1);
        fib_num[0]=0;
        if(n==0){
            return 0;
        }
        fib_num[1]=1;
        for(int i=2;i<=n;i++){
            fib_num[i]=fib_num[i-1]+fib_num[i-2];
        }
        return fib_num[n];
    }
};