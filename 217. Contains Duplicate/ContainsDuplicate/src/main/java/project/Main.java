package project;

import java.util.Arrays;

class Solution {

    // First approach, without sorting
    public boolean containsDuplicateFirstApproach(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }

    public boolean containsDuplicateSecondApproach(int[] nums) {
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums = new int[] {1,2,3,1};

        sol.containsDuplicateSecondApproach(nums);

    }
}