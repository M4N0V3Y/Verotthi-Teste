using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

namespace Problem2
{
    class Program
    {
        // Complete the circularArrayRotation function below.
        //a:            an array of integers to rotate
        //k:            an integer, the rotation count
        //queries:      an array of integers, the indices to report
        static int[] circularArrayRotation(int[] a, int k, int[] queries)
        {
            int[] shiftA = new int[a.Count()];
            int[] resultQuery = new int[queries.Count()];

            for (int index = 0; index < a.Length; index++)
            {
                shiftA[(index + a.Length + k % a.Length) % a.Length] = a[index];
            }

            a = shiftA;

            for (int index = 0; index < queries.Length; index++)
            {
                resultQuery[index] = a[queries[index]];
            }

            return resultQuery;

        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter("OUTPUT2.TXT", true);

            string[] nkq = Console.ReadLine().Split(' ');

            int n = Convert.ToInt32(nkq[0]);

            int k = Convert.ToInt32(nkq[1]);

            int q = Convert.ToInt32(nkq[2]);

            int[] a = Array.ConvertAll(Console.ReadLine().Split(' '), aTemp => Convert.ToInt32(aTemp))
            ;

            int[] queries = new int[q];

            for (int i = 0; i < q; i++)
            {
                int queriesItem = Convert.ToInt32(Console.ReadLine());
                queries[i] = queriesItem;
            }

            int[] result = circularArrayRotation(a, k, queries);

            textWriter.WriteLine(string.Join("\n", result));

            textWriter.Flush();
            textWriter.Close();
        }

    }
}
