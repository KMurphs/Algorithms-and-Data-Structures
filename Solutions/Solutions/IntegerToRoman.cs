using System;
using System.Collections.Generic;

// https://docs.microsoft.com/en-us/visualstudio/test/getting-started-with-unit-testing?view=vs-2019
// https://leetcode.com/problems/container-with-most-water/solution/

namespace Solutions
{
    public class IntegerToRoman
    {

        static int[] levels = new int[] { 0, 1, 5, 10, 50, 100, 500, 1000 };
        static string[] romans = new string[] { "", "I", "V", "X", "L", "C", "D", "M" };



        public static void Main()
        {
            Console.WriteLine("Hello World!");
        }
        public static string IntToRoman(int num)
        {
            if (num == 0) { return ""; }


            // Search for the closest level below num, and the substractor if needed
            int level = levels.Length - 1;
            int substractor = levels.Length - 3;
            bool toggler = false;


            while (num < levels[level] - levels[substractor])
            {
                level--;

                if (toggler)
                {
                    substractor -= 2;
                    if (substractor < 0) { substractor = 0; }
                }
                toggler = !toggler;
            }



            if (num < levels[level])
            {
                num = num - (levels[level] - levels[substractor]);
                return romans[substractor] + romans[level] + IntToRoman(num);
            }
            else
            {
                num = num - levels[level];
                return romans[level] + IntToRoman(num);
            }



            // return "";
        }
    }
}
