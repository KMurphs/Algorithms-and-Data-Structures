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
        public void TestMethod1(string input, int exp)
        {

            var res = Solution.ExecuteWith(input);


            Assert.AreEqual(res, exp);
            //Assert.Fail();
        }
        static IEnumerable<object[]> TestMethod1_DataSource()
        {
            return new[] {
                new object[] { "42", 42 },
                new object[] { "-9128347233", -2147483648 },
                new object[] { "words and 987", 0 },
                new object[] { "    -42", -42 },
                new object[] { "4193 with words", 4193 },
            };
        }



    }
}
