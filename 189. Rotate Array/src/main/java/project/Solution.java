package project;

class Solution {

    public void rotate(int[] nums, int k) {

        if (nums.length > 1) {
            k = k % nums.length;

            int [] new_arr = new int[nums.length];

            for (int i = 0; i < nums.length; i++) {
                if (i < k)
                {
                    new_arr[i] = nums[nums.length - k + i];
                }
                else {
                    new_arr[i] = nums[i - k];
                }
            }
    
    
            for (int i = 0; i < nums.length; i++) {
                nums[i] = new_arr[i];
            }
        }

    }
}
