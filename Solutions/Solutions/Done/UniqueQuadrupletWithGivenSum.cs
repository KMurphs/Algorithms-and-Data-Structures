using System;
using System.Collections.Generic;
using System.Text;
//using System.Linq;

// https://docs.microsoft.com/en-us/visualstudio/test/getting-started-with-unit-testing?view=vs-2019
// https://leetcode.com/problems/container-with-most-water/solution/

namespace Solutions
{
    public class UniqueQuadrupletWithGivenSum
    {

        static int[] levels = new int[] { 0, 1, 5, 10, 50, 100, 500, 1000 };
        static string[] romans = new string[] { "", "I", "V", "X", "L", "C", "D", "M" };



        public static void Main()
        {
            Console.WriteLine("Hello World!");
        }
        public static IList<IList<int>> FindUniqueQuadrupletWithGivenSum(int[] nums, int target)
        {

            IList<IList<int>> res = new List<IList<int>>();
            if (nums.Length < 4) { return res; }


            Array.Sort(nums);
            for (int i = 0; i < nums.Length - 3; i++)
            {


                // Optimization: if 4 of the smallest of the quadruplet are still bigger than target, no solution
                if (nums[i] * 4 > target) { break; }
                // Optimization: if the first/smallest 4 elements adds up above target, no solution
                if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) { break; }
                // Optimization: if the smallest and 3 of the biggest elements adds up below target, no solution
                if (nums[i] + nums[nums.Length - 1] * 3 < target) { continue; }





                for (int j = i + 1; j < nums.Length - 2; j++)
                {



                    // Optimization: if the smalledst and 3 of the next smallest of the quadruplet are still bigger than target, no solution
                    if (nums[i] + nums[j] * 3 > target) { break; }
                    // Optimization: if the first and the next 3 smallest elements adds up above target, no solution
                    if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) { break; }
                    // Optimization: if the 2 smallest of the quadruplet and 2 of the biggest elements adds up below target, no solution
                    if (nums[i] + nums[j] + nums[nums.Length - 1] * 2 < target) { continue; }



                    int l, r;
                    int sum;

                    l = j + 1;
                    r = nums.Length - 1;
                    while (l < r)
                    {
                        sum = nums[i] + nums[j] + nums[l] + nums[r];
                        if (sum > target) { r--; }
                        else if (sum < target) { l++; }
                        else
                        {
                            res.Add(new List<int>() { nums[i], nums[j], nums[l], nums[r] });
                            l++;
                            while (l < nums.Length && nums[l] == nums[l - 1]) { l++; }
                        }
                    }
                    while (j < nums.Length - 2 && nums[j + 1] == nums[j]) { j++; }
                }
                while (i < nums.Length - 1 && nums[i + 1] == nums[i]) { i++; }
            }



            return res;
        }


    }


}
