class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int lastIndex[2] = { -1, -1 }, validIndex = -1;
        long result = 0;
    
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK or nums[i] > maxK) {
                lastIndex[0] = lastIndex[1] = validIndex = -1;
                continue;
            }
            if (validIndex == -1 and minK <= nums[i] and nums[i] <= maxK)
                validIndex = i;
            if (nums[i] == minK)
                lastIndex[0] = i;
            if (nums[i] == maxK)
                lastIndex[1] = i;
             result += max(0, min(lastIndex[0], lastIndex[1]) - validIndex + 1);
    }
    
    return result;
    }
};
