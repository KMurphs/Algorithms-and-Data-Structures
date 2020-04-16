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
        public void TestMethod1(List<int> input, int n, List<int> exp)
        {
            var expList = ListToListNode(exp);
            var inList = ListToListNode(input);

            var res = Solution.ExecuteWith(inList, n);
            //string res = IntegerToRoman.Convert(2000);
            //Console.WriteLine($"{res} - {exp}");
            //Console.WriteLine(String.Join(", ", arr));

            var runnerRes = res;
            var runnerExp = expList;
            while(runnerRes.next != null && runnerExp.next != null)
            {
                Assert.AreEqual(runnerRes.val, runnerExp.val);
                runnerRes = runnerRes.next;
                runnerExp = runnerExp.next;
            }

            //Assert.AreEqual(res, exp);
            //Assert.Fail();
        }
        static IEnumerable<object[]> TestMethod1_DataSource()
        {
            return new[] {
                new object[] { new List<int>() { 1, 2, 3, 4, 5 }, 2, new List<int>() { 1, 2, 3, 5 }},
            };
        }
        public ListNode ListToListNode(List<int> x)
        {
            ListNode head = new ListNode(x[0]);

            ListNode runner = head;
            for(int i = 1; i < x.Count; i++)
            {
                runner.next = new ListNode(x[i]);
                runner = runner.next;
            }
            runner.next = null;

            return head;
        }
    }
}
