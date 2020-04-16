using NUnit.Framework;
using System;
using System.IO;
using System.Collections.Generic;
using Solutions;


namespace Tests
{
    public class UniqueQuadrupletWithGivenSumTests
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
        public void TestMethod1(int[] num, int target, List<List<int>> exp)
        {
            IList<IList<int>> res = UniqueQuadrupletWithGivenSum.FindUniqueQuadrupletWithGivenSum(num, target);
            //string res = IntegerToRoman.Convert(2000);
            //Console.WriteLine($"{res} - {exp}");
            //Console.WriteLine(String.Join(", ", res));
            //Console.WriteLine(String.Join(", ", exp));
            
            // Arrange list elements in the list of lists
            for (int i = 0; i < res.Count; i++)
            {
                ((List<int>)res[i]).Sort();
            }
            for (int i = 0; i < exp.Count; i++)
            {
                ((List<int>)exp[i]).Sort();
            }

            // Arrange the list of list according to the first elements of the list element
            ListOfListComparer ll = new ListOfListComparer();
            ((List<IList<int>>)res).Sort(ll);
            exp.Sort(ll);
            Assert.AreEqual(res.Count, exp.Count);
            if(res.Count == exp.Count)
            {
                for (int i = 0; i < exp.Count; i++)
                {
                    Assert.AreEqual(String.Join("", res[i]), String.Join("", exp[i]));
                }
            }

            
            //Assert.Fail();
        }
        static IEnumerable<object[]> TestMethod1_DataSource()
        {
            return new[] {
                new object[] { new int[] { 2,1,3 }, 0, new List<List<int>>() },
                new object[] { new int[] { 1, 0, -1, 0, -2, 2 }, 0, new List<List<int>>() { new List<int>() { -1, 0, 0, 1 }, new List<int>() { -2, -1, 1, 2 }, new List<int>() { -2, 0, 0, 2 } } },
                new object[] { new int[] { 1, -2, -5, -4, -3, 3, 3, 5 }, -11, new List<List<int>>() { new List<int>() { -5, -4, -3, 1 } } },
            };
        }
    }

}
