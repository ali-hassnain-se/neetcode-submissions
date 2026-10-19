class Solution {
public:
    int trap(vector<int>& height) {
// Optimized Approach, using TWO POINTER, TC=O(N), SC=O(1)

        int water=0, leftMax=0, rightMax=0, n=height.size(), maxheight=height[0], index=-1;
        
        // finding maximum height in building and it's index
        for(int i=1;i<n;i++) {
            if(maxheight<height[i]) {
                maxheight=height[i];
                index=i;
            }
        }

        // left part
        for(int i=0;i<index;i++) {
            if(leftMax>height[i])
                water+=leftMax-height[i];
            
            else
                leftMax=height[i];
        }

        // right part
        for(int i=n-1;i>index;i--) {
            if(rightMax>height[i])
                water+=rightMax-height[i];
            
            else
                rightMax=height[i];
        }    

        return water;

/* 
Better than Brute Force, TC=O(N), SC=O(N)

        int n=height.size();

        // to store left max
        vector<int> leftMax(n);
        leftMax[0]=0;
        for(int i=1;i<n;i++)
        leftMax[i]=max(leftMax[i-1], height[i-1]);

        // to store right max
        vector<int> rightMax(n);
        rightMax[n-1]=0;
        for(int i=n-2;i>=0;i--)
        rightMax[i]=max(rightMax[i+1], height[i+1]);
        
        // to calculate trapped water
        int water=0, miniheight;
        for(int i=0;i<n;i++) {
            miniheight=min(leftMax[i], rightMax[i]);

            if(miniheight-height[i]>0)
            water+=miniheight-height[i];
        }

        return water;
*/

/*
Brute Force Approach, TC=O(N^2), SC=O(1)

        int n=height.size(), water=0, leftMax, rightMax, trapWater;

        for(int i=0;i<n;i++) {
            leftMax=0, rightMax=0;
            // left max
            for(int j=0;j<i;j++)
            leftMax=max(leftMax, height[j]);
            // right max
            for(int j=i;j<n;j++)
            rightMax=max(rightMax, height[j]);

            trapWater=min(leftMax, rightMax)-height[i];
            if(trapWater>0)
            water+=trapWater;
        }

        return water;
*/
    }
};
