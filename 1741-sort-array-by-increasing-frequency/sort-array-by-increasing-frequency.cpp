class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size() ;i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> minh;
        for(auto i = mp.begin(); i!= mp.end();i++){
            minh.push({i->second , -i->first});
        }
        vector<int> ans ;
         while(minh.size()>0){
           int val = -minh.top().second;
           int frq = minh.top().first;
            minh.pop();

            while(frq--) ans.push_back(val);
        }

        return ans;
    }
};