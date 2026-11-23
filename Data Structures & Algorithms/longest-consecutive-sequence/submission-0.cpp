class Solution {
public:

// Brute -> function to find element
    // bool linearSearch(vector<int>& arr, int x) {
    //     for(int i=0;i<arr.size();i++) {
    //         if(arr[i]==x)
    //         return true;
    //     }

    //     return false;
    // }

    int longestConsecutive(vector<int>& nums) {
// Optimized Approach, using unordered_set, TC=O(N), SC=O(N)

        unordered_set<int> s(nums.begin(), nums.end());

        int longest=0;
        for(int x : s) {
            if(s.count(x-1)==0) {          // x is start of sequence
                int cur=x, cnt=1;
                while(s.count(cur+1)) {    // follow chain
                    cur++;
                    cnt++;
                }
            longest=max(longest, cnt);
            }
        }

    return longest;

/*
// Better Approach, Sorting + runs, TC=O(N log N), SC=O(1)

        if(nums.empty())
        return 0;

        sort(nums.begin(), nums.end());

        int best=1, cnt=1;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]==nums[i-1]) {
            continue;                  // duplicate, ignore
                }
            else if(nums[i]==nums[i-1]+1) {
                cnt++;
            }
            else {
                cnt=1;   // sequence break; start new
            }

            best=max(cnt, best);
        }

        return best;
*/

/*
// Brute Force Approach, TC=O(N^3), SC=O(1)

        if(nums.empty())
        return 0;

        int longest=1;
        for(int i=0;i<nums.size();i++) {
            int x=nums[i], cnt=1;
            while(linearSearch(nums, x+1)) {
                cnt++;
                x++;
            }

            longest=max(longest, cnt);
        }

        return longest;
*/
    }
};
