struct comp{
    bool operator()(pair<string,int> P1, pair<string,int> P2)
        const noexcept
    {
        if(P1.second>P2.second){
            return true;
        }
        else if(P1.second==P2.second){
            return P1.first<P2.first;
        }
        return false;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m1;
        for(auto word:words){
            m1[word]++;
        }
        
        priority_queue<pair<string,int>, vector<pair<string,int>>, comp> pq;
        
        for(auto it: m1){
            pq.push(it);
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<string> ans;
        while(!pq.empty()){
            pair<string,int> P=pq.top();
            ans.push_back(P.first);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};