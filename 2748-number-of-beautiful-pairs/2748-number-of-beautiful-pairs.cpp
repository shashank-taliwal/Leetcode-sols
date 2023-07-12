class Solution {
    int gcd(int x, int y){
        if(y==0){
            return x;
        }
        return gcd(y,x%y);
    }
    bool isCoprime(int x, int y){
        return gcd(max(x,y),min(x,y))==1;
    }
    int getLastDigit(int n){
        return n%10;
    }
    int getFirstDigit(int n){
        int exp=log10(n);
        return n/pow(10,exp);
    }
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(isCoprime(getFirstDigit(nums[i]), getLastDigit(nums[j]))){
                  ans++;  
                }
            }
        }
        return ans;
    }
};