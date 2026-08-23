class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> index;

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];

            if (mp.count(complement))
            {
                index.push_back(mp[complement]);
                index.push_back(i);
                break;
            }

            mp[nums[i]] = i;
        }

        return index;
    }
};