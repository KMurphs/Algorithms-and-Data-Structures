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
            bool hasProcessedNums = false;
            int curr;


            // Looking for the first element that is smaller than its predecessor
            for (int i = nums.Length - 2; i >= 0; i--)
            {
                if (nums[i] < nums[i + 1])
                {
                    hasProcessedNums = true;
                    curr = nums[i];

                    // Sort in ascending everythning form end of array until this point in ascending order
                    HeapSort(ref nums, i, nums.Length - 1); 

                    // Look for the new position of the element we were busy with
                    // or more exactly look for its direct older sibling
                    int j = nums.Length;
                    while (nums[j - 1] != curr) { j--; }

                    // Push this sibling to were the element we were busy with originally sat
                    for (int k = j; k > i; k--)
                    {
                        Swap(ref nums, k, k - 1);
                    }

                    // done
                    break;
                }
            }


            // If this element was never met, the whole array is in descending order
            // Next permutation is ascending order
            if (hasProcessedNums == false)
            {
                HeapSort(ref nums, 0, nums.Length - 1); // in ascending
            }
        }






        static void HeapSort(ref int[] nums, int l, int r)
        {
            for (int i = (r + l - 1) / 2; i >= l; i--)
            {
                Heapify(ref nums, l, r, i);
            }
            for (int i = r; i > l; i--)
            {
                Swap(ref nums, l, i);
                Heapify(ref nums, l, i-1, l);
            }
        }
        static void Heapify(ref int[] nums, int l, int r, int parent)
        {
            // The tree is contained within l and r
            // adjusting child index computation to restrict tree within these boundaries
            int child1 = 2 * (parent - l) + 1;
            int child2 = 2 * (parent - l) + 2;
            int maxFamily = parent;

            // Offseting children due to the boundaries of our tree 
            if (l + child1 <= r && nums[l + child1] > nums[maxFamily]) { maxFamily = l + child1; }
            if (l + child2 <= r && nums[l + child2] > nums[maxFamily]) { maxFamily = l + child2; }
            if (maxFamily != parent)
            {
                Swap(ref nums, maxFamily, parent);
                Heapify(ref nums, l, r, maxFamily);
            }
        }
        static void Swap(ref int[] nums, int i1, int i2)
        {
            int tmp = nums[i1];
            nums[i1] = nums[i2];
            nums[i2] = tmp;
        }
    }




}
