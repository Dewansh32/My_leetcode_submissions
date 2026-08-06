class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        
        // We stop when mid crosses high, meaning the unknown area is fully explored.
        while (mid <= high) {
            if (nums[mid] == 0) {
                // Chuck 0s to the left boundary
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } 
            else if (nums[mid] == 1) {
                // 1s belong in the middle, just step over them
                mid++;
            } 
            else { // nums[mid] == 2
                // Chuck 2s to the right boundary
                swap(nums[mid], nums[high]);
                high--;
                
                // Notice we do NOT do mid++ here. 
                // The number we just swapped from 'high' is still unknown, 
                // so we must evaluate it on the next loop iteration.
            }
        }
    }
};