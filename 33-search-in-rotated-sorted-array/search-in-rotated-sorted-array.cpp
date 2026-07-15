class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while(s <= e) {
            int m = s + (e - s) / 2;

            if(nums[m] == target) {
                return m;
            }

            // Left half is sorted
            if(nums[s] <= nums[m]) {
                if(target >= nums[s] && target < nums[m]) {
                    e = m - 1;  // target in left half
                } else {
                    s = m + 1;  // target in right half
                }
            }
            // Right half is sorted
            else {
                if(target > nums[m] && target <= nums[e]) {
                    s = m + 1;  // target in right half
                } else {
                    e = m - 1;  // target in left half
                }
            }
        }

        return -1;
    }
};