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
                for (int j = i + 1; j < nums.Length - 2; j++)
                {
                    int l, r;

                    l = j + 1;
                    r = nums.Length - 1;
                    while (l < r)
                    {
                        if (nums[i] + nums[j] + nums[l] + nums[r] > target) { r--; }
                        else if (nums[i] + nums[j] + nums[l] + nums[r] < target) { l++; }
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
