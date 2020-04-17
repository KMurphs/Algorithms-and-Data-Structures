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
        public void TestMethod1(int dividend, int divisor, int exp)
        {

            var res = Solution.ExecuteWith(dividend, divisor);

            Assert.AreEqual(res, exp);


            //Assert.AreEqual(res, exp);
            //Assert.Fail();
        }
        static IEnumerable<object[]> TestMethod1_DataSource()
        {
            return new[] {
                new object[] { 10, 3, 3 },
                new object[] { 7, -3, -2 },
                new object[] { 102, 5, 20 },
            };
        }

    }
}
