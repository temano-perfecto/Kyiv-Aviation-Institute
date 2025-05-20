using System;

namespace IndexerAndProperty
{
    public class TwoDArray
    {
        private int[,] array;

       
        public TwoDArray(int rows, int cols)
        {
            array = new int[rows, cols];
        }

       
        public int this[int row, int col]
        {
            get => array[row, col];
            set => array[row, col] = value;
        }

        
        public double this[int row]
        {
            get
            {
                double sumOfSquares = 0.0;
                int cols = array.GetLength(1);

                for (int col = 0; col < cols; col++)
                {
                    sumOfSquares += Math.Pow(array[row, col], 2);
                }

                return Math.Sqrt(sumOfSquares / cols);
            }
        }

      
        public int SumOfAllElements
        {
            get
            {
                int sum = 0;
                foreach (int element in array)
                {
                    sum += element;
                }
                return sum;
            }
        }

      
        public void FillRandom(int minValue, int maxValue)
        {
            Random rnd = new Random();
            for (int row = 0; row < array.GetLength(0); row++)
            {
                for (int col = 0; col < array.GetLength(1); col++)
                {
                    array[row, col] = rnd.Next(minValue, maxValue);
                }
            }
        }

       
        public void PrintArray()
        {
            for (int row = 0; row < array.GetLength(0); row++)
            {
                for (int col = 0; col < array.GetLength(1); col++)
                {
                    Console.Write($"{array[row, col],5}");
                }
                Console.WriteLine();
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
           
            TwoDArray myArray = new TwoDArray(3, 4);

           
            myArray.FillRandom(1, 10);

            
            Console.WriteLine("2D Array:");
            myArray.PrintArray();

           
            Console.WriteLine("\nRow Root Mean Square values:");
            for (int row = 0; row < 3; row++)
            {
                Console.WriteLine($"Row {row}: {myArray[row]:F2}");
            }

           
            Console.WriteLine($"\nSum of all array elements: {myArray.SumOfAllElements}");
        }
    }
}