class Solution {
public:
    int countPrimes(int n) {
        //straightforward sieve of eratosthenes
            vector<int> primes(n,0);
            int ans=0;
            for(int i=2;i<n;i++){
                    if(primes[i]==0){
                            ans++;
                            for(int j=i+i;j<n;j+=i){
                                    primes[j]=1;
                            }
                    }
            }
            return ans;
    }
};