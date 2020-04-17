using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

// https://docs.microsoft.com/en-us/visualstudio/test/getting-started-with-unit-testing?view=vs-2019
// https://leetcode.com/problems/container-with-most-water/solution/

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

        public static int ExecuteWith(int dividend, int divisor)
        {
            int log10 = 0, max_log10 = 9;
            int max_divided_by_10 = 214748364;
            int q = 0;




            // Removing the sign complexitiies
            bool isNeg = (dividend < 0) ^ (divisor < 0);
            int num = dividend < 0 ? 0 - dividend : dividend;
            int den = divisor < 0 ? 0 - divisor : divisor;



            // Optimization and more complexities removing
            if (divisor == dividend) { return 1; }
            else if (dividend == Int32.MinValue && divisor == Int32.MaxValue) { return -1; }
            else if (dividend == Int32.MaxValue && divisor == Int32.MinValue) { return 0; }
            else if (divisor == Int32.MinValue || divisor == Int32.MaxValue) { return 0; }
            else if (dividend == Int32.MinValue)
            {
                num = Int32.MaxValue;
                if (divisor == 1)
                {
                    return Int32.MinValue;
                }
                else if (divisor == -1)
                {
                    return Int32.MaxValue;
                }
            }





            int[] dens = Enumerable.Repeat<int>(0, max_log10).ToArray();
            int[] facts = Enumerable.Repeat<int>(0, max_log10).ToArray();
            dens[0] = den; // Save the (positive) divisor to the dens array
            facts[0] = 1; 
            log10 = 1;

            // (den << 3 + den << 1) is the same as 10*den
            // We are looking for how any times must divisor be multiplied by 10 before outgrowing num 
            while ((den << 3) + (den << 1) < num) {         // Foreseeing Multiplication of divisor by 10
                if (den > max_divided_by_10) { break; };    // There is a divisor that will cause overflow
                den = (den << 3) + (den << 1);              // Saving multiplication of divisor by 10    
                dens[log10] = den;                     
                
                // Everytime you remove den * 10^x from dividend, the quotient increment by 10^x
                facts[log10] = (facts[log10 - 1] << 3) + (facts[log10 - 1] << 1);  // quotient of current den / divisor, ie a power of 10
                
                log10++; 
                if (log10 == max_log10) { break; }          // We shouldn't go over the max power of 10 for any int32 
            }








            // Doing the division
            for (int i = max_log10 - 1; i >= 0; i--)
            {
                den = dens[i];
                if (den == 0) { continue; }
                // Remove greatest power of 10 * divisor, update quotient to match that
                while (num >= den) { num = num - den; q = q + facts[i]; } 
            }

            // Edge case when dividend is minimum int32 value (negative)
            if (dividend == Int32.MinValue && divisor > 0 && ++num >= den)
            {
                q++;
            }

            // Return quotient with sign
            return isNeg ? 0 - q : q;
        }
    }




}
