using NUnit.Framework;
using System;
using System.IO;

namespace Tests
{
    public class ContainerWithMostWaterTests
    {
        private const string Expected = "Hello World!";

        [SetUp]
        public void Setup()
        {
        }

        [Test]
        public void TestMethod1()
        {
            using (var sw = new StringWriter())
            {
                Console.SetOut(sw);
                Solutions.ContainerWithMostWater.Main();

                var result = sw.ToString().Trim();
                Assert.AreEqual(Expected, result);
            }
        }
    }
}