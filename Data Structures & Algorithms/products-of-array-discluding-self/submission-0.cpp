class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
// Optimized Approach, Prefix in ans + running Suffix Product, TC=O(N), SC=O(1)

        int n=nums.size();

        vector<int> ans(n);
        ans[0]=1;
        // filling prefix
        for(int i=1;i<n;i++)
        ans[i]=ans[i-1]*nums[i-1];

        int suffix=1;
        for(int i=n-1;i>=0;i--) {
            ans[i]=ans[i]*suffix;
            suffix=suffix*nums[i];
            }

        return ans;

/*
// Better than Brute Force, using Prefix & Suffix Product, TC=O(N), SC=O(N)

        int n=nums.size();

        vector<int> prefix(n);
        prefix[0]=1;
        for(int i=1;i<n;i++)
        prefix[i]=nums[i-1]*prefix[i-1];

        vector<int> suffix(n);
        suffix[n-1]=1;
        for(int i=n-2;i>=0;i--)
        suffix[i]=nums[i+1]*suffix[i+1];

        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            ans[i]=prefix[i]*suffix[i];
        }

        return ans;
*/

/*
// Brute Force Approach, TC=O(N^2), Auxiliary Space=O(1)

        int n=nums.size();
        vector<int> output(n);

        for(int i=0;i<n;i++) {
            int product=1;
            for(int j=0;j<n;j++) {
                if(i==j)
                continue;

                product*=nums[j];
            }

            output[i]=product;
        
            // we can also write like this

            // int product1=1, product2=1;

            // for(int j=i+1;j<n;j++) {
            //     product1=product1*nums[j];
            // }
            
            // for(int k=i-1;k>=0;k--) {
            //     product2=product2*nums[k];
            // }

            // int finalP=product1*product2;
            // output[i]=finalP;
        }

        return output;
*/
    }
};
