class Solution {
public:
   int longestConsecutive(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if(nums.size() < 2) return nums.size();
    unordered_set<int> st(nums.begin(), nums.end());
    int maxSeq = 0;
    for(auto it : st){
        if(st.find(it-1) != st.end()) continue;
        int seq = 0;
        while(st.find(it++) != st.end()){
            seq++;
            
        } 
        maxSeq = max(maxSeq, seq);
    }
    return maxSeq;
}
};