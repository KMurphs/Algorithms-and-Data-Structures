using NUnit.Framework;
using System;
using System.IO;
using System.Collections.Generic;
using Solutions;


namespace Tests
{
    public class PossibleStringsFromPhoneDigitsTests
    {
        // private const string Expected = "Hello World!";
        private UniqueQuadrupletWithGivenSum solution;

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
        public void TestMethod1(string digits, List<string> exp)
        {
            IList<string> res = PossibleStringsFromPhoneDigits.FindPossibleStringsFromPhoneDigits(digits);
            //string res = IntegerToRoman.Convert(2000);
            //Console.WriteLine($"{res} - {exp}");
            //Console.WriteLine(String.Join(", ", res));
            //Console.WriteLine(String.Join(", ", exp));

            // Arrange list elements in the list of lists
            exp.Sort();
            ((List<string>)res).Sort();


            Assert.AreEqual(res.Count, exp.Count);
            if(res.Count == exp.Count)
            {
                for (int i = 0; i < exp.Count; i++)
                {
                    Assert.AreEqual(res[i], exp[i]);
                }
            }

            
            //Assert.Fail();
        }
        static IEnumerable<object[]> TestMethod1_DataSource()
        {
            return new[] {
                new object[] { "23", new List<string>() { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" } },
            };
        }
    }

}
