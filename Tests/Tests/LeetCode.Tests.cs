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
        public void TestMethod1(int[] res, int[] exp)
        {

            Solution.ExecuteWith(ref res);

            for(int i = 0; i < exp.Length; i++)
            {
                Assert.AreEqual(res[i], exp[i]);
            }


            
            //Assert.Fail();
        }
        static IEnumerable<object[]> TestMethod1_DataSource()
        {
            return new[] {
                new object[] { new int[] { 1, 2, 3 }, new int[] { 1, 3, 2 } },
                new object[] { new int[] { 1, 3, 2 }, new int[] { 2, 1, 3 } },
            };
        }



    }
}
