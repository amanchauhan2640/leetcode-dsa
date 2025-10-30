class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        if (target.empty()) {
            return 0;
        }

        int operations = target[0]; // The first element requires `target[0]` operations.

        // Iterate from the second element of the array
        for (int i = 1; i < target.size(); ++i) {
            // If the current element is greater than the previous, we need additional increments
            if (target[i] > target[i - 1]) {
                operations += target[i] - target[i - 1];
            }
        }
        return operations;
        
    }
};