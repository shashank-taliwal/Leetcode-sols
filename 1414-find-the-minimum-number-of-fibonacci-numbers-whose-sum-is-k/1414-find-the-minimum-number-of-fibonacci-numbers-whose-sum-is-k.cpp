class Solution {
        void generateFibs(vector<long long>& fibs){
                fibs.push_back(1);
                fibs.push_back(1);
                for(int i=2;i<=50;i++){
                        long long x=(long long)fibs[i-1]+(long long)fibs[i-2];
                        fibs.push_back(x);
                }
                reverse(fibs.begin(),fibs.end());
        }
        long long getVal(vector<long long>& fibs,long long k){
                long long ans=0;
                for(int i=0;i<fibs.size();i++){
                        if(k>=fibs[i]){
                              ans+=k/fibs[i];
                                k=k%fibs[i];
                        }
                }
                return ans;
        }
public:
    int findMinFibonacciNumbers(int k) {
        vector<long long> fibs;
        generateFibs(fibs);
        long long ans=getVal(fibs,(long long)k);
        return ans;
    }
};