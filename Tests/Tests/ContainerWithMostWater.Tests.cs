using NUnit.Framework;
using System;
using System.IO;
using System.Collections.Generic;



namespace Tests
{
    public class ContainerWithMostWaterTests
    {
        private const string Expected = "Hello World!";

        [SetUp]
        public void Setup()
        {
            //using (var sw = new StringWriter())
            //{
            //    Console.SetOut(sw);
            //    Solutions.ContainerWithMostWater.Main();
            //
            //    var result = sw.ToString().Trim();
            //    Assert.AreEqual(Expected, result);
            //}
        }

        [Test]
        [TestCaseSource(nameof(TestMethod1_DataSource))]
        public void TestMethod1(int[] arr)
        {
            
            Console.WriteLine(String.Join(", ", arr));
            Assert.AreEqual(1, 1);
        }
        static IEnumerable<object[]> TestMethod1_DataSource()
        {
            return new[] {
                new object[] { new int[] { 1, 8, 6, 2, 5, 4, 8, 3, 7 } },
            };
        }
    }
}