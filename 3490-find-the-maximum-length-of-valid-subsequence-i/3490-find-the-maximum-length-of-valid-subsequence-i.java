class Solution {
    public int maximumLength(int[] nums) {
         int evenCount = 0, oddCount = 0;

        for (int num : nums) {
            if (num % 2 == 0) evenCount++;
            else oddCount++;
        }

        int sameParityMax = Math.max(evenCount, oddCount);

        int even_ends = 0, odd_ends = 0;

        for (int num : nums) {
            if (num % 2 == 0) {
                even_ends = odd_ends + 1;
            } else {
                odd_ends = even_ends + 1;
            }
        }

        int alternatingMax = Math.max(even_ends, odd_ends);

        return Math.max(sameParityMax, alternatingMax);
    }
}