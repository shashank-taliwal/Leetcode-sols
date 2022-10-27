class Solution {
        int log2f(int num){
                if(num==0){
                        return -1;
                }
                return log2(num);
        }
        bool isPowerOf2ExistsBetween(int left, int right){
                int pow1=log2f(left);
                int pow2=log2f(right);
                return pow1!=pow2;
        }
public:
    int rangeBitwiseAnd(int left, int right) {
        if(isPowerOf2ExistsBetween(left,right)){
                return 0;
        }
            else{
                    long long ans=left;
                    long long i=(long long)left+1;
                    for(i;i<=right;i++){
                            ans=ans & i;
                    }
                    return ans;
            }
    }
};