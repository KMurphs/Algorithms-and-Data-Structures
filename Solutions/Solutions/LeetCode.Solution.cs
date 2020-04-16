using System;
using System.Collections.Generic;
using System.Text;

// https://docs.microsoft.com/en-us/visualstudio/test/getting-started-with-unit-testing?view=vs-2019
// https://leetcode.com/problems/container-with-most-water/solution/

namespace LeetCode
{
    public class Solution
    {
        public static string ExecuteWith(int num)
        {
            int[] values = new int[] { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
            string[] words = new string[] { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
            System.Text.StringBuilder st = new StringBuilder();
            int count = 0;

            for (int i = values.Length - 1; i >= 0 && num > 0; i--)
            {
                count = num / values[i];
                if (count == 0) { continue; }

                while (count > 0)
                {
                    st.Append(words[i]);
                    count--;
                }
                num = num % values[i];
            }

            return st.ToString();
        }
    }
}
