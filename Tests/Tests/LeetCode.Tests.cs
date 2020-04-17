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
        public void TestMethod1(string input, int numRows, string exp)
        {

            var res = Solution.ExecuteWith(input, numRows);


            Assert.AreEqual(res, exp);
            //Assert.Fail();
        }
        static IEnumerable<object[]> TestMethod1_DataSource()
        {
            return new[] {
                new object[] { "PAYPALISHIRING", 3, "PAHNAPLSIIGYIR" },
                new object[] { "PAYPALISHIRING", 4, "PINALSIGYAHRPI" },
            };
        }



    }
}
