using NUnit.Framework;
using System;
using System.IO;
using System.Collections.Generic;
using Solutions;


namespace Tests
{
    public class IntegerToRomanTests
    {
        private const string Expected = "Hello World!";
        private IntegerToRoman solution;

        [SetUp]
        public void Setup()
        {
            Console.WriteLine("Starting...");
            //solution = new IntegerToRoman();
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
        public void TestMethod1(int num, string exp)
        {
            string res = IntegerToRoman.IntToRoman(num);
            //string res = IntegerToRoman.Convert(2000);
            //Console.WriteLine($"{res} - {exp}");
            //Console.WriteLine(String.Join(", ", arr));
            Assert.AreEqual(res, exp);
            //Assert.Fail();
        }
        static IEnumerable<object[]> TestMethod1_DataSource()
        {
            return new[] {
                new object[] { 2000, "MM"},
                new object[] { 2001, "MMI"},
                new object[] { 1999, "MCMXCIX"},
                new object[] { 1994, "MCMXCIV"},
                new object[] { 1888, "MDCCCLXXXVIII"},
                new object[] { 1, "I"},
                new object[] { 2, "II"},
                new object[] { 3, "III"},
                new object[] { 4, "IV"},
                new object[] { 5, "V"},
                new object[] { 6, "VI"},
                new object[] { 7, "VII"},
                new object[] { 8, "VIII"},
                new object[] { 9, "IX"},
                new object[] { 10, "X"},
            };
        }
    }
}