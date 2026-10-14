class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
// Optimized Approach using TWO POINTER, TC=O(N^2), SC=O(1)

        int n=nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for(int i=0;i<n-2;i++) {
            if(i>0 && nums[i]==nums[i-1])
            continue;

            int st=i+1, end=n-1;
            while(st<end) {
                int sum=nums[i]+nums[st]+nums[end];
                if(sum==0) {
                    ans.push_back({nums[i], nums[st], nums[end]});
                    st++;
                    end--;
/*
After finding a valid triplet, move both pointers inward. The sorted array keeps equal values next to each other, so if the new nums[st] equals the previous one (nums[st-1]), using it again would produce the same triplet. Keep moving st right until we land on a different value. This removes duplicates without a set.
*/
                while(st<end && nums[st]==nums[st-1])
                st++;

/* 
Same idea for the right pointer: if the new nums[end] equals the previous one (nums[end+1]), skip it by moving end left until the value changes.
*/
                while(st<end && nums[end]==nums[end+1])
                end--;
                }

                else if(sum<0)
                st++;

                else
                end--;
            }
        }

        return ans;
/*
Brute Force Approach, TC= O(n^3 log k), SC=O(k)  (k=number of unique triplets)

        sort(nums.begin(), nums.end());

        set<vector<int>> unique;
        int n=nums.size(), i, j, k;

        for(i=0;i<n-2;i++) {
            for(j=i+1;j<n-1;j++) {
                for(k=j+1;k<n;k++) {
                    if(nums[i]+nums[j]+nums[k]==0)
                    unique.insert({nums[i], nums[j], nums[k]});
                }
            }
        }

        vector<vector<int>> ans(unique.begin(), unique.end());

        return ans;
*/
    }
};
