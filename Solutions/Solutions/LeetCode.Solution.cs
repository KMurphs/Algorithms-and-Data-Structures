using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

// https://docs.microsoft.com/en-us/visualstudio/test/getting-started-with-unit-testing?view=vs-2019
// https://leetcode.com/problems/string-to-integer-atoi/

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

        public static int ExecuteWith(string str)
        {
            // Discard a null string
            if (str.Length == 0)
            {
                return 0;
            }


            // Initialize variables
            int i = 0;
            int curr = 0;
            int num = 0, tmp = 0, tmp2 = 0;
            int maxPreMultiplicationBy10 = Int32.MaxValue / 10;
            bool isNeg = false;



            // Handle white spaces
            if (i == str.Length) { return 0; }
            while ((int)str[i] == 32) { i++; if (i == str.Length) { return 0; } }
            if (i == str.Length) { return 0; }



            // Handle plus, minus, or anything that's not a number
            curr = (int)str[i];
            if (curr == 43) { i++; }
            else if (curr == 45) { i++; isNeg = true; }
            else if (curr < 48) { return 0; }
            else if (curr > 57) { return 0; }



            // Handle any sequences of 0s
            if (i == str.Length) { return 0; }
            while ((int)str[i] == 48) { i++; if (i == str.Length) { return 0; } }
            if (i == str.Length) { return 0; }



            // if we don't have a digit next, return 0
            curr = (int)str[i];
            if (curr < 48) { return 0; }
            else if (curr > 57) { return 0; }



            // if we do have a digit, start computing (multiply num by 10, then add curr digit)
            while (curr >= 48 && curr <= 57)
            {
                // multiply by 10
                tmp = (num << 3) + (num << 1);

                // add current digit
                tmp2 = tmp + (curr - 48);

                // check that there was no overflow
                if (num > maxPreMultiplicationBy10 || tmp >> 31 != tmp2 >> 31) // Overflow on operatio over signed numbers
                {
                    // there is an overflow on x+y=z iif (msb of x != msb of z) or (msb of x != msb of z)
                    // https://stackoverflow.com/questions/10078778/bitwise-overflow-checking-in-c
                    // there is an overflow on x*y=z if x > max/10 or y > max/10
                    // https://stackoverflow.com/questions/1815367/catch-and-compute-overflow-during-multiplication-of-two-large-integers

                    // if there was an overflow, go to max integer
                    num = Int32.MaxValue;
                    return isNeg ? ++num : num;
                }
                else
                {
                    num = tmp2;
                }




                // Prepare next cycle
                i++;
                // if we have reached the end of the string, that's it
                if (i == str.Length) { break; }
                // Extract next digit, and prep curr for the next iteration
                curr = (int)str[i];
            }


            return isNeg ? 0 - num : num;
        }
    }




}
