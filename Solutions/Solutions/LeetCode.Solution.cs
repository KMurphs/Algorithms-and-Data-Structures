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

        public static ListNode ExecuteWith(ListNode head, int n)
        {
            ListNode ptrReckon, ptrDelete;

            // First node is at 1, we are stopping at node n
            int index = 1;
            ptrReckon = head;
            while (index < n)
            {
                if (ptrReckon.next != null)
                {
                    index++;
                    ptrReckon = ptrReckon.next;
                }
            }


            // let's move to node n + 1 so that deleter can sit one behind the node to be deleted
            if (ptrReckon.next != null)
            {
                ptrReckon = ptrReckon.next;
                ptrDelete = head;
            }
            else
            {
                // We can't move to node n + 1
                // Current list only has n nodes
                // The first one must be removed
                return head.next;
            }


            // Traversing the list n+1 nodes apart
            while (ptrReckon.next != null)
            {
                ptrReckon = ptrReckon.next;
                ptrDelete = ptrDelete.next;
            }


            // Deleting
            ptrDelete.next = ptrDelete.next.next;


            return head;
        }
    }




}
