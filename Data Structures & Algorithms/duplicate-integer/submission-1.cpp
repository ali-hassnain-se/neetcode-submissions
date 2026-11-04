class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

// Optimized Approach, Using Hash Map, TC=O(N), SC=O(N)

    unordered_map<int, int> freq;
    for(int i=0;i<nums.size();i++)
    freq[nums[i]]++;

    for(auto &it : freq) {
        if(it.second>1)
        return true;
    }

    return false;

// Optimized Approach, Best for unsorted array, SC=O(N), TC=O(N)

    // unordered_set<int> s;

    // for(int i=0;i<nums.size();i++) {

    //     /*
    //     we can also write like this:

    //     auto result=s.insert(nums[i]);

    //     if(result.second==false)
    //     return true;
    //     */

    //     if(s.insert(nums[i]).second==false)
    //     return true;
    // }

    // return false;

/*
// Optimized approach for sorted array, TC=O(N), SC=O(1)
    
        int ans=-1;
        for(int i=0;i<nums.size()-1;i++) {
            ans=nums[i];
            if(nums[i]==nums[i+1]) 
            return true;
        }

        return false;
*/

/* 
// Brute Force Approach, TC=O(N^2), SC=O(1)

          int n=nums.size();

          for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                if(nums[i]==nums[j])
                return true;
            }
          }

          return false;
*/
    }
};