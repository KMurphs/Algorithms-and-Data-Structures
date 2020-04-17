using System;
using System.Collections.Generic;
using System.Text;

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

        public static ListNode ExecuteWith(ListNode head)
        {
            ListNode newHead;

            if (head == null) { return head; }



            // If we have more than 1 node in list, set return object's head to second
            // If we don't, return list intact
            if (head.next != null)
            {
                newHead = head.next;
            }
            else return head;




            // Use a tmp data strcuture to ease the work
            // Initialize runner, temp structure and index
            List<ListNode> tmp = new List<ListNode>();
            ListNode runner = head;
            int i = -1;
            while (runner != null)
            {

                // Indexing nodes and matching the index counter
                i++;
                tmp.Add(runner);

                // Saving the next point. Other wose the swapping may loose the connection
                runner = runner.next;

                // Do the swapping every odd index
                if (i % 2 == 1)
                {
                    // Currently there are 2 nodes between the current node and the last one
                    if (i - 3 >= 0) tmp[i - 3].next = tmp[i];
                    // The backward connection
                    tmp[i].next = tmp[i - 1];
                    // This is a temporary connection. Final one should point to runner.next
                    tmp[i - 1].next = runner;
                }

            }


            return newHead;
        }
    }




}
