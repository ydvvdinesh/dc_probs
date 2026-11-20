//we will do dry run of it - optimal 
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        int count = 0;
        int sum = 0;

        unordered_map<int, int> mpp;

        // Empty prefix sum has remainder 0
        mpp[0] = 1;

        for(int i = 0; i < n; i++){
            sum += nums[i];

            int rem = ((sum % k) + k) % k;

            // Check how many times this remainder appeared
            if(mpp.find(rem) != mpp.end()){
                count += mpp[rem];
            }

            // Store the frequency of remainder
            mpp[rem]++;
        }

        return count;
    }
};
