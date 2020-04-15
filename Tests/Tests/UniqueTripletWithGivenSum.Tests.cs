using NUnit.Framework;
using System;
using System.IO;
using System.Collections.Generic;
using Solutions;


namespace Tests
{
    public class UniqueTripletWithGivenSumTests
    {
        // private const string Expected = "Hello World!";
        private UniqueTripletWithGivenSum solution;

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
        public void TestMethod1(int[] num, List<List<int>> exp)
        {
            IList<IList<int>> res = UniqueTripletWithGivenSum.FindUniqueTripletWithGivenSum(ref num);
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
                new object[] { new int[] { 2,1,3 }, new List<List<int>>() },
                new object[] { new int[] { -1, 0, 1, 2, -1, -4 }, new List<List<int>>() { new List<int>() { -1, 0, 1 }, new List<int>() { -1, -1, 2 } } },
            };
        }
    }


    class ListOfListComparer : IComparer<IList<int>>
    {
        public int Compare(IList<int> x, IList<int> y)
        {

            if (x == null || y == null)
            {
                return 0;
            }

            // "CompareTo()" method 
            return String.Join("", x).CompareTo(String.Join("", y));

        }
    }
}