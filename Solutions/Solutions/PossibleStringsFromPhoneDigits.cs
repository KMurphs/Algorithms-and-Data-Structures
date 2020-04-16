using System;
using System.Collections.Generic;
using System.Text;
//using System.Linq;

// https://docs.microsoft.com/en-us/visualstudio/test/getting-started-with-unit-testing?view=vs-2019
// https://leetcode.com/problems/container-with-most-water/solution/

namespace Solutions
{
    public class PossibleStringsFromPhoneDigits
    {

        static int[] levels = new int[] { 0, 1, 5, 10, 50, 100, 500, 1000 };
        static string[] romans = new string[] { "", "I", "V", "X", "L", "C", "D", "M" };



        public static void Main()
        {
            Console.WriteLine("Hello World!");
        }
        public static IList<string> FindPossibleStringsFromPhoneDigits(string digits)
        {
            
            IList<string> res = new List<string>();

            Dictionary<char, char[]> mappings = new Dictionary<char, char[]>()
            {
                { '2', new char[] { 'a', 'b', 'c' } },
                { '3', new char[] { 'd', 'e', 'f' } },
                { '4', new char[] { 'g', 'h', 'i' } },
                { '5', new char[] { 'j', 'k', 'l' } },
                { '6', new char[] { 'm', 'n', 'o' } },
                { '7', new char[] { 'p', 'q', 'r', 's' } },
                { '8', new char[] { 't', 'u', 'v' } },
                { '9', new char[] { 'w', 'x', 'y', 'z' } },
            };



            if (digits.Length == 0) { return res; }


            // Compute the size of the return object res
            // Build up the first return element where generatorIndexes are all 0
            int[] generatorsIndexes = new int[digits.Length];
            char[] letters = new char[digits.Length];
            int resSize = 1;
            for (int i = 0; i < digits.Length; i++)
            {
                generatorsIndexes[i] = 0;
                letters[i] = mappings[digits[i]][generatorsIndexes[i]];
                resSize *= mappings[digits[i]].Length;
            }
            res.Add(new String(letters));




            // Counting the number of expected element in the return obj (minus 1)
            for (int i = 1; i < resSize; i++)
            {

                // Update the least significant char counter
                generatorsIndexes[digits.Length - 1]++;
                // Chain the next counters updates and compute the next return obj element
                for (int k = digits.Length - 1; k >= 0; k--)
                {
                    if (generatorsIndexes[k] >= mappings[digits[k]].Length)
                    {
                        generatorsIndexes[k] = 0;
                        if (k > 0) generatorsIndexes[k - 1]++;
                    }
                    // compute the next return obj element
                    letters[k] = mappings[digits[k]][generatorsIndexes[k]];

                }
                // Add the next return obj element
                res.Add(new String(letters));

            }

            return res;
        }


    }




    public static class DecimalToBaseX
    {
        public static string ToBaseX(this int num, int baseX)
        {
            const Int32 BitSizeOfInt = 32;
            const string DigitEncodings = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // base 36

            if (baseX < 2 || baseX > BitSizeOfInt) { throw new ArgumentException($"The base must be greater than 2 and less than { DigitEncodings.Length }"); };
            if (num == 0) { return "0"; }


            int index = BitSizeOfInt - 1;
            Int32 updatedNum = Math.Abs(num);
            char[] convertedNum = new char[BitSizeOfInt];

            while (updatedNum != 0)
            {
                int remainder = (int)updatedNum % baseX;
                convertedNum[index] = DigitEncodings[remainder];
                index--;
                updatedNum = updatedNum / baseX;
            }

            string res = new String(convertedNum, index + 1, BitSizeOfInt - index - 1);
            return num < 0 ? "-" + res : res;
        }
    }

}
