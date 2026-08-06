class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(3,0);

        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }

        int index = 0; 
        for(int color = 0; color < 3; color++) {
            while(freq[color] > 0) {
                nums[index] = color;
                index++;
                freq[color]--;
            }
        }
    }
};