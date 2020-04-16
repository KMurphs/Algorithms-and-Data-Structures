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
        public void TestMethod1( int n, List<string> exp)
        {
            exp.Sort();

            var res = Solution.ExecuteWith(n);
            //string res = IntegerToRoman.Convert(2000);
            //Console.WriteLine($"{res} - {exp}");
            //Console.WriteLine(String.Join(", ", arr));

            ((List<string>)res).Sort();

            for(int i = 0; i < exp.Count; i++)
            {
                Assert.AreEqual(res[i], exp[i]);
            }

            //Assert.AreEqual(res, exp);
            //Assert.Fail();
        }
        static IEnumerable<object[]> TestMethod1_DataSource()
        {
            return new[] {
                new object[] { 3, new List<string>() { "((()))", "(()())", "(())()", "()(())", "()()()" } },
            };
        }

    }
}
