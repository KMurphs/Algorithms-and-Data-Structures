using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

// https://docs.microsoft.com/en-us/visualstudio/test/getting-started-with-unit-testing?view=vs-2019
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

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

        public static int ExecuteWith(string s)
        {
            int ASCIISIZE = 128;
            int[] asciiarray = Enumerable.Repeat(-1, ASCIISIZE).ToArray<int>(); //maps a char to the index of the last time we met it
            int maxLength = 0, strLength = s.Length, nextIndex, start, prevIndex, currChar;


            // Iterate through string chars
            // Start is the start of a substring - updated everytime we encounter a char that we already met
            for (nextIndex = 0, start = 0; nextIndex < strLength; nextIndex++)
            {
                currChar = (int)s[nextIndex];
                prevIndex = asciiarray[currChar];

                // We found a repeating char
                // Compute substring length up until this point
                // Compare its length to maxLength
                if (prevIndex >= 0 && start < prevIndex + 1)
                {
                    maxLength = maxLength >= nextIndex - start ? maxLength : nextIndex - start;
                    start = prevIndex + 1;
                }

                // Mark the current char as already been met
                asciiarray[currChar] = nextIndex;
            }


            return maxLength >= nextIndex - start ? maxLength : nextIndex - start;
        }
    }




}
