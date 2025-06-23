class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int , int> cnt ;
        for(auto x :nums) ++cnt[x];
        for(auto [k ,v] : cnt)
        if(v==1)
        return k;

        return 0;
    }
};