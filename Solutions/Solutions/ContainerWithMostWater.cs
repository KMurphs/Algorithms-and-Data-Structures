using System;
// https://docs.microsoft.com/en-us/visualstudio/test/getting-started-with-unit-testing?view=vs-2019
namespace Solutions
{
    public class ContainerWithMostWater
    {
        public static void Main()
        {
            Console.WriteLine("Hello World!");
        }
        public int MaxArea(int[] height)
        {
            int maxArea = 0;
            int maxAreaLeft = 0;
            int maxAreaRight = 0;

            int localArea = 0;
            int delta = -1;

            int r = 0;
            int l = 0;


            // Walk through the array
            for(int i = 0; i < height.Length; i++)
            {



                // Look for the furthest higher height on the right 
                r = height.Length - 1;
                l = i;
                while (height[r] < height[l] && --r > l) { }


                localArea = (height[r] > height[l] ? height[l] : height[r]) * (r - l);
                if (r > l && localArea > maxArea) {
                    maxAreaLeft = l;
                    maxAreaRight = r;
                    maxArea = localArea;
                }




                // Look for the furthest higher height on the right 
                r = i;
                l = 0;
                while (height[l] < height[r] && r > ++l) { }


                localArea = (height[r] > height[l] ? height[l] : height[r]) * (r - l);
                if (r > l && localArea > maxArea)
                {
                    maxAreaLeft = l;
                    maxAreaRight = r;
                    maxArea = localArea;
                }



            }
            return maxArea;
        }
    }
}
