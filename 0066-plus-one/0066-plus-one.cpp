class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(begin(digits),end(digits));
        int carry=0;
        if(digits[0]==9){
                digits[0]=0;
                carry=1;
                for(int i=1;i<digits.size() && carry>0;i++){
                        digits[i]+=1;
                        carry=digits[i]/10;
                        digits[i]%=10;
                }
                if(carry){
                        digits.push_back(1);
                }
        }
        else{
                digits[0]+=1;
        }
        reverse(begin(digits),end(digits));
        return digits;
    }
};