using NUnit.Framework;
using System;
using System.IO;
using System.Collections.Generic;
using LeetCode;


namespace LeetCodeTests
{
    public class Tests
    {
        private Solution solution;
        [SetUp]
        public void Setup()
        {
            Console.WriteLine("Starting...");
            solution = new Solution();
        }




        [Test]
        [TestCaseSource(nameof(TestMethod1_DataSource))]
        public void TestMethod1(List<int> input, List<int> exp)
        {

            var res = Solution.ExecuteWith(ListToListNode(input));


            ListNode resRunner = res, expRunner = ListToListNode(exp);
            while(resRunner != null && expRunner != null)
            {
                Assert.AreEqual(resRunner.val, expRunner.val);
                resRunner = resRunner.next;
                expRunner = expRunner.next;
            }


            //Assert.AreEqual(res, exp);
            //Assert.Fail();
        }
        static IEnumerable<object[]> TestMethod1_DataSource()
        {
            return new[] {
                new object[] { new List<int>() { 1, 2, 3, 4 }, new List<int>() { 2, 1, 4, 3 } },
            };
        }

        public static ListNode ListToListNode(List<int> input)
        {
            ListNode head, runner;

            head = new ListNode(input[0]);
            runner = head;
            for(int i = 1; i < input.Count; i++)
            {
                runner.next = new ListNode(input[i]);
                runner = runner.next;
            }

            return head;
        }

    }
}
