using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

// https://docs.microsoft.com/en-us/visualstudio/test/getting-started-with-unit-testing?view=vs-2019
// https://leetcode.com/problems/next-permutation/

namespace LeetCode
{

    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int x) { val = x; }
    }
    public class Solution
    {

        public static void ExecuteWith(ref int[] nums)
        {

            // Looking for the first element that is smaller than its predecessor
            int i = nums.Length - 2;
            while (i >= 0 && nums[i] >= nums[i + 1]) i--;


            if (i >= 0)
            {
                // Look for the first older sibling starting from the end
                int j = nums.Length - 1;
                while (nums[j] <= nums[i]) { j--; }

                // The next lexicograpical elmt will have this sibling at i
                Swap(ref nums, i, j);
            }

            // Ensures that what was at position i is now at position i + 1
            // and generally everything between i and end is rranged in descending order from i
            Reverse(ref nums, i + 1, nums.Length - 1);
        }


        static void Swap(ref int[] nums, int i1, int i2)
        {
            int tmp = nums[i1];
            nums[i1] = nums[i2];
            nums[i2] = tmp;
        }

        static void Reverse(ref int[] nums, int i, int j)
        {
            while (i < j) { Swap(ref nums, i++, j--); }
        }
    }




}
