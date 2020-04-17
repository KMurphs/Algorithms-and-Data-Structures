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

        public static ListNode ExecuteWith(ListNode l1, ListNode l2)
        {
            ListNode res = new ListNode(0);
            ListNode i = l1;
            ListNode j = l2;
            ListNode k = res;
            int carry = 0;

            while (i != null || j != null)
            {
                // Ensure that we always have a valid integer to play with
                int ival = i == null ? 0 : i.val;
                int jval = j == null ? 0 : j.val;


                // Add from l1 l2 and value in current node of res - put in current node of res
                // The handle carry in current node of res
                k.val = ival + jval + k.val;
                carry = 0;
                if (k.val > 9)
                {
                    carry = (int)(k.val / 10);
                    k.val = k.val % 10;
                }

                // Prepare runner variables for next cycle
                i = i == null ? i : i.next; // if null, pass null to next cycle
                j = j == null ? j : j.next;


                // if addition will continue to the next cycle, prepare next node of res
                // and put in the current carry
                if (i != null || j != null || carry != 0)
                {
                    k.next = new ListNode(carry);
                    k = k.next;
                }
            }

            return res;
        }
    }




}
