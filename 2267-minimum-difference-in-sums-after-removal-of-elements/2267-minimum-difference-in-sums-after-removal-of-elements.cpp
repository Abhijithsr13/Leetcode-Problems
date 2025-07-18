#define ll long long
class Solution {
public:
    ll minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int k = n / 3;
        
        priority_queue<int> maxHeap;
        vector<ll> prefix(n, 0);
        ll sum = 0;
        for(int i = 0; i < k; ++i){
            maxHeap.push(nums[i]);
            sum += nums[i];
        }
        prefix[k-1] = sum;
        for(int i = k; i < 2 * k; ++i){
            if(maxHeap.top() > nums[i]){
                prefix[i] = prefix[i-1] - maxHeap.top() + nums[i];

                maxHeap.pop();
                maxHeap.push(nums[i]);
            }
            else {
                prefix[i] = prefix[i-1]; 
            }
        }
        priority_queue<int, vector<int>, greater<>> minHeap;
        vector<ll> suffix(n, 0);
        sum = 0;

        for(int i = n - 1; i >= n - k; --i){
            minHeap.push(nums[i]);
            sum += nums[i];
        }
        suffix[n - k] = sum;

        for(int i = n - k - 1; i >= k; --i){
            if(minHeap.top() < nums[i]){
                suffix[i] = suffix[i+1] - minHeap.top() + nums[i];

                minHeap.push(nums[i]);
                minHeap.pop();
            } 
            else {
                suffix[i] = suffix[i+1]; 
            }
        }
        ll ans = LLONG_MAX;
        for(int i = k - 1; i < 2 * k; ++i){
            ans = min(ans, prefix[i] - suffix[i + 1]);
        }

        return ans;
    }
};