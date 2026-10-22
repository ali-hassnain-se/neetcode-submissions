class Solution {
public:
    int search(vector<int>& nums, int target) {
        // TC=O(logn), SC=O(1)
        
        int n=nums.size();

        int st=0, end=n-1, mid=-1;
        while(st<=end) {
            mid=st+(end-st)/2;

            if(nums[mid]==target)
            return mid;

            else if(nums[mid]<target)
            st=mid+1;

            else
            end=mid-1;
        }

        return -1;
    }
};
