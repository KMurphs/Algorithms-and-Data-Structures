using System;
using System.Collections.Generic;
using System.Text;
//using System.Linq;

// https://docs.microsoft.com/en-us/visualstudio/test/getting-started-with-unit-testing?view=vs-2019
// https://leetcode.com/problems/container-with-most-water/solution/

namespace Solutions
{
    public class UniqueTripletWithGivenSum
    {

        static int[] levels = new int[] { 0, 1, 5, 10, 50, 100, 500, 1000 };
        static string[] romans = new string[] { "", "I", "V", "X", "L", "C", "D", "M" };



        public static void Main()
        {
            Console.WriteLine("Hello World!");
        }
        public static IList<IList<int>> FindUniqueTripletWithGivenSum(ref int[] nums)
        {
            IList<IList<int>> res = new List<IList<int>>();

            int sum = 0;
            int target;
            int l, r;

            Array.Sort(nums);
            for(int i = 0; i < nums.Length - 2; i++)
            {
                target = sum - nums[i];
                l = i + 1;
                r = nums.Length - 1;
                while (l < r)
                {
                    if(nums[l] + nums[r] > target) { r--; }
                    else if(nums[l] + nums[r] < target) { l++; }
                    else
                    {
                        res.Add(new List<int>() { nums[i], nums[l], nums[r] });
                        l++;
                        while (nums[l] == nums[l - 1]) { l++; }
                    }
                }
                i++;
                while (nums[i] == nums[i - 1]) { i++; }
            }



            return res;
        }


    }
    public static class MyExtensions
    {
        public static void HeapSort(this int[] Numbers)
        {
            int n = Numbers.Length;
            for (int i = n / 2 - 1; i >= 0; i--)
            {
                Heapify(ref Numbers, n, i);
            }
            for (int i = n - 1; i >= 0; i--)
            {
                swap(ref Numbers, 0, i);
                Heapify(ref Numbers, i, 0);
            }
        }
        public static void swap(ref int[] Numbers, int p1, int p2)
        {
            int tmp = Numbers[p1];
            Numbers[p1] = Numbers[p2];
            Numbers[p2] = tmp;
        }
        public static void Heapify(ref int[] Numbers, int heapsize, int nodeIndex)
        {
            int ch1Index = 2 * nodeIndex + 1;
            int ch2Index = 2 * nodeIndex + 2;
            int maxIndex = nodeIndex;

            if (ch1Index < heapsize && Numbers[ch1Index] > Numbers[maxIndex])
            {
                maxIndex = ch1Index;
            }
            if (ch2Index < heapsize && Numbers[ch2Index] > Numbers[maxIndex])
            {
                maxIndex = ch2Index;
            }
            if (maxIndex != nodeIndex)
            {
                swap(ref Numbers, maxIndex, nodeIndex);
                Heapify(ref Numbers, heapsize, maxIndex);
            }
        }
    }
}
