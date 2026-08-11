class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }

        int ans;

        for(auto &p:m)
        {
            if(p.second > n/2){
                ans = p.first;
                break;
            }
        }
        
        return ans;
    }
};