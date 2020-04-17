using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

// https://docs.microsoft.com/en-us/visualstudio/test/getting-started-with-unit-testing?view=vs-2019
// https://leetcode.com/problems/zigzag-conversion/

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

        public static string ExecuteWith(string s, int numRows)
        {
            int n = s.Length;
            char[] s_zigzag = new char[n];


            /// Solution is built around the goal of doing one pass
            /// and therefore completely determining the coordinate of
            /// the final poisition of the curretn char in the final string
            /// as a function of the coordinate x and y in the zigzag

            int mod = Math.Max(numRows + numRows - 2, 1); // Length of a zizag cycle
            int cycles = (int)Math.Floor((double)n / mod); // number of zigzag cycles in current string 



            int pos;
            int index = 0;
            int[] y_arr;


            // y coordinate - rows
            for (int y = 0; y < numRows; y++)
            {
                // in each cycle, we have 2 points per row
                y_arr = new int[] { y, mod - y };
                // Except for coordinate 0 and last row - only 1 point
                if (y == 0 || y == numRows - 1)
                {
                    y_arr = new int[] { y };
                }


                // x coordinate - cols
                for (int x = 0; x <= cycles; x++)
                {

                    foreach (int tmp_y in y_arr)
                    {
                        // Extracting curr char as function of coordinates
                        pos = x * mod + tmp_y;
                        if (pos < n)
                        {
                            // Storing current char in its final position
                            // Setup index for next char
                            s_zigzag[index++] = s[pos];
                        }
                    }
                }
            }



            return new string(s_zigzag);
        }
    }




}
