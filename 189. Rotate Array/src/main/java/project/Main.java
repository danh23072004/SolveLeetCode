package project;

public class Main {

    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 10, 12, 5, 5, 6, 7};

        Solution sol = new Solution();

        sol.rotate(nums, 3);

        for (int i = 0; i < nums.length; i++) {
            System.out.println(nums[i]);
        }

    }
}