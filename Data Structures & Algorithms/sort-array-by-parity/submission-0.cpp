class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
// Optimized Approach, Using Two Pointer Approach, TC=O(N), SC=O(1)

        int st=0, end=nums.size()-1;

        while(st<end) {
            if(nums[st]%2!=0 && nums[end]%2==0) { 
                swap(nums[st], nums[end]);
                st++;
                end--;
            }

            else if(nums[st]%2==0 && nums[end]%2==0)
            st++;

            else if(nums[st]%2!=0 && nums[end]%2!=0)
            end--;

            else {
                st++;
                end--;
            }
        }

        return nums;

/* 
Brute Force Approach, TC=O(N), SC=O(N)

    vector<int> ans;

    for(int i=0;i<nums.size();i++) {
        if(nums[i]%2==0)
        ans.push_back(nums[i]);
    }

    for(int i=0;i<nums.size();i++) {
        if(nums[i]%2!=0)
        ans.push_back(nums[i]);
    }

    return ans;
*/
    }
};