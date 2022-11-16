class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        // dp[i][j] indicates the s(i......j) is a palindrome
        // Conditions to consider:-
        //     1) if i equals j, dp[i][j]=1
        //     2) if |i-j| equals 1 and s(i) equals s(j), dp[i][j]=1
        //     3) if s(i) equals s(j) and s(i+1................j-1) is palindrome, dp[i][j]=1
        
        // Base case:- if (i>j) execution stops
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int left=-1,right=-1;
        int max_length=0;
        string ans;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(i<=j){
                    if(i==j){
                        dp[i][j]=1;
                    }
                    else if(abs(i-j)==1 and s[i]==s[j]){
                        dp[i][j]=1;
                    }
                    else if(s[i]==s[j]){
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
                if(dp[i][j]==1 and j-i+1>max_length){
                    max_length=j-i+1;
                    left=i;
                    right=j;
                }
            }
        }
        for(int i=left;i<=right;i++){
            ans+=s[i];
        }
        return ans;
    }
};