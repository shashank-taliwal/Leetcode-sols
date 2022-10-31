class Solution {
        int sod(long long n){
                long long ans=0;
                while(n){
                        ans+=n%10;
                        n/=10;
                }
                return ans;
        }
public:
    long long makeIntegerBeautiful(long long n, int target) {
            if(sod(n)<=target)return 0;
            long long m=n;
        vector<long long> prsod;
        prsod.push_back(0);
            vector<int> digits(13,0);
            int j=0;
            while(n){
                    digits[j]=(n%10);
                    n/=10;
                    j++;
            }
            reverse(digits.begin(),digits.end());
            long long sum=0;
            for(int i=0;i<digits.size();i++){
                    sum+=digits[i];
                    prsod.push_back(sum);
            }
            for(int i=prsod.size()-1;i>=0;i--){
                    int sum=prsod[i-1]+digits[i-1]+1;
                    if(sum<=target){
                            digits[i-1]+=1;
                            break;
                    }
                    else{
                            digits[i-1]=0;
                    }
                    
            }
            long long num=0;
            for(int i=0;i<13;i++){
                    num=(num*10)+digits[i];
            }
            return num-m;
    }
};