using NUnit.Framework;
using System;
using System.IO;
using System.Collections.Generic;
using Solutions;


namespace Tests
{
    public class ContainerWithMostWaterTests
    {
        private const string Expected = "Hello World!";
        private ContainerWithMostWater solution;

        [SetUp]
        public void Setup()
        {
            solution = new ContainerWithMostWater();
            //using (var sw = new StringWriter())
            //{
            //    Console.SetOut(sw);
            //    Solutions.ContainerWithMostWater.Main();
            
            ///    var result = sw.ToString().Trim();
            //    Assert.AreEqual(Expected, result);
            //}
        }

        [Test]
        [TestCaseSource(nameof(TestMethod1_DataSource))]
        public void TestMethod1(int[] arr, int exp)
        {
            int res = solution.MaxArea(arr);
            //Console.WriteLine($"{res} - {exp}");
            //Console.WriteLine(String.Join(", ", arr));
            Assert.AreEqual(res, exp);
            //Assert.Fail();
        }
        static IEnumerable<object[]> TestMethod1_DataSource()
        {
            return new[] {
                new object[] { new int[] { 1, 8, 6, 2, 5, 4, 8, 3, 7 }, 49},
            };
        }
    }
}