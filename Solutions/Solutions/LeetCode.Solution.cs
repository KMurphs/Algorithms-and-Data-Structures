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

        public static IList<string> ExecuteWith(int n)
        {
            List<string> l = new List<string>();
            GenerateWithRecursion(ref l, "", n, 0);
            return l;
        }

        public static void GenerateWithRecursion(ref List<string> list, string str, int remaining, int opened)
        {
            if (remaining == 0 && opened == 0) { list.Add(str); }
            else
            {
                if (remaining > 0) { GenerateWithRecursion(ref list, str + "(", remaining - 1, opened + 1); }
                if (opened > 0) { GenerateWithRecursion(ref list, str + ")", remaining, opened - 1); }
            }
        }
    }




}
