class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
/* First Method, Time Complexity=O(N), Space Complexity=O(1)
    
        int ans=-1;
        for(int i=0;i<nums.size()-1;i++) {
            ans=nums[i];
            if(nums[i]==nums[i+1]) 
            return true;
        }

        return false;
    */

// Second Method, Best for unsorted array, Space Complexity=O(N)
// Time Complexity=O(N)

    unordered_set<int> s;

    for(int i=0;i<nums.size();i++) {

        /*
        we can also write like this:

        auto result=s.insert(nums[i]);

        if(result.second==false)
        return true;
        */

        if(s.insert(nums[i]).second==false)
        return true;
    }

    return false;
    }
};