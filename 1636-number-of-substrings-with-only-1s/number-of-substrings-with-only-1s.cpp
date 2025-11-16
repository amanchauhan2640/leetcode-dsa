class Solution {
public:
    int numSub(string s) {
         const long long mod = 1e9 + 7;
        long long ans = 0, cnt = 0;

        for (char c : s) {
            if (c == '1') {
                cnt++;
            } else {
                ans = (ans + cnt * (cnt + 1) / 2) % mod;
                cnt = 0;
            }
        }
        ans = (ans + cnt * (cnt + 1) / 2) % mod;

        return ans;
    }
};