class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
// Most Optimized Approach, Using Two Pointer Approach
// TC=O(N), SC=O(1)

        int st=0, end=nums.size()-1;
        while(st<end) {
            int sum=nums[st]+nums[end];

            if(sum==target)
            return {st+1, end+1};

            else if(sum<target)
            st++;

            else
            end--;
        }

        return {};

/* 
Optimized Approach, Using unordered_map, TC=O(N), SC=O(N)

    unordered_map<int, int> mp; // value->index

    for(int i=0;i<nums.size();i++) {
        int need=target-nums[i];

        if(mp.find(need) != mp.end())
        return {mp[need]+1, i+1};

        else
        mp[nums[i]]=i;
    }
    return {};
*/

/*
Brute Force Approach, TC=O(N^2), SC=O(1)

        for(int i=0;i<nums.size()-1;i++) {
            int need=target-nums[i];
            for(int j=i+1;j<nums.size();j++) {
                if(need==nums[j])
                return {i+1, j+1};
                
                // Second way to find target:

                // if(nums[i]+nums[j]==target) {
                //     return {i+1, j+1};
                // }
                
            }
        }

        return {};
*/
    }
};
