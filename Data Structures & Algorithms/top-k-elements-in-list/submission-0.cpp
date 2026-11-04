class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
// Most Optimized Approach, using Bucket Sort, TC=O(N), SC=O(N)

        int n=nums.size();

        unordered_map<int, int> mp;
        for(int i=0;i<n;i++)
        mp[nums[i]]++;

        vector<vector<int>> bucket(n+1);
        // index i=freq
        // value arr[i]=elements
        // bucket[i] = elements having i frequency
        for(auto &it : mp) {
            int element=it.first;
            int freq=it.second;

            bucket[freq].push_back(element);
        }

        // pick elements form right to left from bucket to find max freq elements
        vector<int> ans;
        for(int i=n;i>=0;i--) {
            if(bucket[i].size()==0)
            continue;

            while(bucket[i].size()>0 && k>0) {
                ans.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }

        return ans;

/*
// Optimized Approach, using Min Heap, TC=O(Nlog(k)), SC=O(N)
// k=heap size (push and pop)

        typedef pair<int, int> P;

        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++)
        mp[nums[i]]++;

        // define min heap
        priority_queue<P, vector<P>, greater<P>> pq;  // min-heap

        // push elements in heap
        // maintain size of k only
        for(auto &it : mp) {   // O(n)
            int value=it.first;
            int freq=it.second;

            pq.push({freq, value});  // log(k)

            if(pq.size()>k)
            pq.pop();
        }

        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
*/

/*
// Better Than Brute Force, Sort + runs, TC=O(N log N), SC=O(N)

        int n=nums.size();
        sort(nums.begin(), nums.end());

        vector<pair<int, int>> freq;  // (count, number)
        int count=1;
        for(int i=1;i<n;i++) {
            if(nums[i]==nums[i-1])
                count++;

            else {
                freq.push_back({count, nums[i-1]});
                count=1;
            }
        }

        freq.push_back({count, nums[n-1]});

        sort(freq.rbegin(), freq.rend());

        vector<int> ans;
        for(int i=0;i<k;i++)
        ans.push_back(freq[i].second);

        return ans;
*/

/*
// Better than Brute Force, Hashing + sort, TC=O(N log N), SC=O(N)

        int n=nums.size();

        unordered_map<int, int> freq;
        for(int i=0;i<n;i++)
        freq[nums[i]]++;

        vector<pair<int, int>> v;
        for(auto &it : freq)
        v.push_back({it.second, it.first});  // (count, number)

        sort(v.rbegin(), v.rend());

        vector<int> ans;
        for(int i=0;i<k;i++)
        ans.push_back(v[i].second);

        return ans;
*/

/* 
// Brute Force Approach, TC=O(N^2), SC=O(N)

        int n=nums.size();

        vector<pair<int, int>> freq;    // (count, number)
        vector<bool> visited(n, false);

        for(int i=0;i<n;i++) {
            if(visited[i]) continue;

            int count=1;
            for(int j=i+1;j<n;j++) {
                if(nums[i]==nums[j]) {
                    count++;
                    visited[j]=true;
                }
            }

            freq.push_back({count, nums[i]});
        }

        sort(freq.rbegin(), freq.rend());

        vector<int> ans;
        for(int i=0;i<k;i++)
        ans.push_back(freq[i].second);

        return ans;
*/
    }
};
