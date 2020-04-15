using NUnit.Framework;
using System;
using System.IO;
using System.Collections.Generic;
using Solutions;


namespace Tests
{
    public class TripletWithSumClosestToConstantTests
    {
        // private const string Expected = "Hello World!";
        private TripletWithSumClosestToConstant solution;

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
        public void TestMethod1(int[] nums, int target, int exp)
        {
            int res = TripletWithSumClosestToConstant.FindTripletWithSumClosestToConstant(nums, target);
            //string res = IntegerToRoman.Convert(2000);
            //Console.WriteLine($"{res} - {exp}");
            //Console.WriteLine(String.Join(", ", res));
            //Console.WriteLine(String.Join(", ", exp));
            

            Assert.AreEqual(res, exp);


            
            //Assert.Fail();
        }
        static IEnumerable<object[]> TestMethod1_DataSource()
        {
            return new[] {
                //new object[] { new int[] { 2,1,3 }, new List<List<int>>() },
                new object[] { new int[] { -1, 2, 1, -4 }, 1, 2 },
                new object[] { new int[] { 1, 2, 5, 10, 11 }, 12, 13 },
            };
        }
    }

}

