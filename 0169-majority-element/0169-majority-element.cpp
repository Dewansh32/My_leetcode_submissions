class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        int el;

        for(int i=0;i<n;i++)
        {
            if(cnt == 0)
            {
                el = nums[i];
                cnt = 1;
            }
            else if(nums[i] == el) cnt++;
            else cnt--;
        }

        int check_cnt=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i] == el) check_cnt++;
        }

        if(check_cnt > n/2) return el;
        return -1;
    }
};