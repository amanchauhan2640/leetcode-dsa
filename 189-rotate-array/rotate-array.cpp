


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int x = nums.size();
        k=k%x;
        reverse(nums, 0, x-1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, x-1);

        
    }
    private:
void reverse(vector<int> &nums,int l ,int r){
    while(l<r)
    swap(nums[l++],nums[r--]);
}




};
