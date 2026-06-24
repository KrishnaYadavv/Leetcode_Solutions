class Solution {
public:
    int bS(vector<int>& nums, int i, int j, int target) {
        int c;
        if(i>=j){
            if(nums[i]==target){
                return i;
            }
            return -1;
        }
        if (nums[i] == target) {
            return i;
        }
        if (nums[j] == target) {
            return j;
        }
        c = (i + j) / 2;
        if (nums[c] == target) {
            return c;
        }
        if (nums[c] > nums[i]) {
            if (target > nums[c] || target < nums[i]) {
                return bS(nums, c, j, target);
            } else {
                return bS(nums, i, c, target);
            }
        } else {
            if (target < nums[c] || target > nums[i]) {
                return bS(nums, i, c, target);
            } else {
                return bS(nums, c, j, target);
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int i = 0, j;
        j = nums.size() - 1;
        return bS(nums, i, j, target);
    }
};