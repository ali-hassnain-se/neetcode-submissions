class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
// Optimized Approach, TC=O(N), SC=O(N), Using unordered_map

    unordered_map<int,int> mp;   // value -> index

    for(int i=0;i<nums.size();i++) {
        int need = target - nums[i];

        // pehle check: kya need diary mein hai?
        if(mp.find(need) != mp.end()) {
            return {mp[need], i};
        }

        // nahi mila, to current number diary mein likh do
        mp[nums[i]] = i;
    }

    return {};

/*
Brute Force Approach, TC=O(N^2), SC=O(1)

        for(int i=0;i<nums.size()-1;i++) {
            for(int j=i+1;j<nums.size();j++) {
                if(nums[i]+nums[j]==target)
                return {i, j};
            }
        }

        return {};
*/

/* 
Better Than Brute Force Approach, Using Two Pointer Approach, TC=O(NlogN), SC=O(N)

    // pairs: {value, original index}
    vector<pair<int,int>> arr;

    for(int i=0;i<nums.size();i++) {
        arr.push_back({nums[i], i});
    }

    sort(arr.begin(), arr.end());

    int st=0, end=arr.size()-1;

    while(st<end) {
        int sum=arr[st].first+arr[end].first;

        if(sum==target)
        return {arr[st].second, arr[end].second};

        else if(sum<target) 
            st++;

        else
        end--;
    }

    return {};
*/
    }
};
