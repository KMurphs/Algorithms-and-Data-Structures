using System;
using System.Collections.Generic;
using System.Text;
//using System.Linq;

// https://docs.microsoft.com/en-us/visualstudio/test/getting-started-with-unit-testing?view=vs-2019
// https://leetcode.com/problems/container-with-most-water/solution/

namespace Solutions
{
    public class TripletWithSumClosestToConstant
    {

        static int[] levels = new int[] { 0, 1, 5, 10, 50, 100, 500, 1000 };
        static string[] romans = new string[] { "", "I", "V", "X", "L", "C", "D", "M" };



        public static void Main()
        {
            Console.WriteLine("Hello World!");
        }
        public static int FindTripletWithSumClosestToConstant(int[] nums, int target)
        {
            if (nums.Length < 3) { return 0; }
            int sum = nums[0] + nums[1] + nums[2], workingSum;


            Array.Sort(nums);
            for (int i = 0; i < nums.Length - 2; i++)
            {
                int l, r;

                l = i + 1;
                r = nums.Length - 1;
                while (l < r)
                {

                    workingSum = nums[l] + nums[r] + nums[i];
                    if (Math.Abs(workingSum - target) < Math.Abs(sum - target)) { sum = workingSum; }


                    if (workingSum > target) { r--; }
                    else if (workingSum < target) { l++; }
                    else
                    {
                        sum = target;
                        return sum;
                    }
                }
                while (i < nums.Length - 1 && nums[i + 1] == nums[i]) { i++; }
            }



            return sum;
        }


    }
}
