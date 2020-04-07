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
            int maxArea = 0, maxAreaLeft = 0, maxAreaRight = 0;
            int localArea;

            int r = height.Length - 1;
            int l = 0;


            // Walk through the array
            while (l < r)
            {
                if(l < r)
                {
                    l++;
                }
                else
                {
                    r--;
                }


                localArea = (height[r] > height[l] ? height[l] : height[r]) * (r - l);
                if (localArea > maxArea)
                {
                    maxAreaLeft = l;
                    maxAreaRight = r;
                    maxArea = localArea;
                }
            }

            Console.WriteLine($"Found MaxArea {maxArea} between indexes '{maxAreaLeft}' and '{maxAreaRight}'");
            return maxArea;
        }
    }
}
