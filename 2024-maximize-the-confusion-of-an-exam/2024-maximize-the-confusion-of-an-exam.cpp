class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        //Approach :- Using sliding window
        //Initialise left=0,right=0, and while  arr[left.....right] is valid
        // increment right, and once arr[left....right] becomes invalid, slide the window to arr[left+1.....right+1]
        //In short, Find the longest window which is possible
        
        int n=answerKey.size();
        int left=0,right=0;
        int cnt0=0,cnt1=0;
        int ans=0;
        for(right=0;right<n;right++){
            // cout<<left<<" "<<right<<endl;
            if(answerKey[right]=='F'){
                cnt0++;
            }
            else{
                cnt1++;
            }
            // cout<<cnt0<<" "<<cnt1<<endl;
            // cout<<"---------------------------------"<<endl;
            while(min(cnt1,cnt0)>k){
                if(answerKey[left]=='F'){
                    cnt0--;
                }
                else{
                    cnt1--;
                }
                left++;
            }
            ans=max(ans,right-left+1);
        }
         ans=max(ans,right-left);
        return ans;
    }
};