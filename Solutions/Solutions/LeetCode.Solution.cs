using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

// https://docs.microsoft.com/en-us/visualstudio/test/getting-started-with-unit-testing?view=vs-2019
// https://leetcode.com/problems/longest-palindromic-substring/

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

        public static string ExecuteWith(string s)
        {
            if (s.Length < 2)
            {
                return s;
            }


            string maxPal = s.Substring(0, 1);
            int ptrLeft, ptrRight, ptrLength;


            // Iterate through each char in the input string
            // There are 2 kinds of palyndromic substring: Those with even lengths, and htose with odd lengths
            for (int runningIndex = 0; runningIndex < s.Length; runningIndex++)
            {


                // Looking for palyndromes with odd length
                ptrLeft = runningIndex;
                ptrRight = runningIndex;
                // Expanding current solution as far as possible
                while (ptrLeft >= 0 && ptrRight <= s.Length - 1 && s[ptrLeft] == s[ptrRight])
                {
                    ptrLeft--;
                    ptrRight++;
                }
                ptrLeft++;
                ptrRight--;
                ptrLength = ptrRight - ptrLeft + 1;
                // Comparing with max solution
                if (s[ptrLeft] == s[ptrRight] && ptrLength > maxPal.Length)
                {
                    maxPal = s.Substring(ptrLeft, ptrLength);
                }







                // Doing the exact same thing, but setup for palyndroms with even length
                ptrLeft = runningIndex;
                ptrRight = runningIndex + 1;
                if (ptrRight > s.Length - 1)
                {
                    // Boundary consideration
                    continue;
                }
                if (s[ptrLeft] != s[ptrRight])
                {
                    // Ensure we have a palyndrom
                    continue;
                }
                // Expanding current solution as far as possible
                while (ptrLeft >= 0 && ptrRight <= s.Length - 1 && s[ptrLeft] == s[ptrRight])
                {
                    ptrLeft--;
                    ptrRight++;
                }
                ptrLeft++;
                ptrRight--;
                ptrLength = ptrRight - ptrLeft + 1;
                // Comparing with max solution
                if (s[ptrLeft] == s[ptrRight] && ptrLength > maxPal.Length)
                {
                    maxPal = s.Substring(ptrLeft, ptrLength);
                }




            }

            return maxPal;
        }
    }




}
