class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
      unordered_map<int, int> mp;
      for(int x: nums){
        mp[x]++ ;
      }
      vector<int> ans;
        for (auto &p : mp) {
            if (p.second == 2) {
                ans.push_back(p.first);
            }
        }

        sort(ans.begin(), ans.end()); // Problem expects them sorted
        return ans;

        
    }
};