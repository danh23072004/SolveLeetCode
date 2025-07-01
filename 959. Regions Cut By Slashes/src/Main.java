public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        String[] test1 = {" /","/ "};
        String[] test2 = {" /","  "};
        String[] test3 = {"/\\","\\/"};
//        int res = sol.regionsBySlashes(test1);

        int count = sol.regionsBySlashes(test1);
        System.out.println(count);
    }
}