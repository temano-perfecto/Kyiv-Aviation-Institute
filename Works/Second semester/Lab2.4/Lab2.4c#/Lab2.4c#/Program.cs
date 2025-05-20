using MathLibrary;
using System;

namespace MathLibrary
{
    public class ExpressionCalculator
    {
        private double a;
        private double c;
        private double d;

        public ExpressionCalculator(double a, double c, double d)
        {
            this.a = a;
            this.c = c;
            this.d = d;
        }

        public double A
        {
            get { return a; }
            set { a = value; }
        }

        public double C
        {
            get { return c; }
            set { c = value; }
        }

        public double D
        {
            get { return d; }
            set { d = value; }
        }

        public double Calculate()
        {
            if (d == 0)
            {
                throw new ArgumentException("Division by zero in sqrt(42/d) - d cannot be zero");
            }

            if (42.0 / d < 0)
            {
                throw new ArgumentException("Square root of negative number in sqrt(42/d)");
            }

            double denominator = c + a - 1;
            if (denominator == 0)
            {
                throw new ArgumentException("Division by zero in denominator (c + a - 1)");
            }

            double numerator = 2 * c - d * Math.Sqrt(42.0 / d);
            return numerator / denominator;
        }
    }

    public class AdvancedCalculator
    {
        public static double CalculateWithLogarithm(double a, double b, double c, double d)
        {
            if (b <= 0)
            {
                throw new ArgumentException("Logarithm argument must be positive");
            }

            if (b == 1)
            {
                throw new ArgumentException("Logarithm base cannot be 1");
            }

            double logValue = Math.Log(a) / Math.Log(b);
            ExpressionCalculator calc = new ExpressionCalculator(a, c, d);
            return logValue * calc.Calculate();
        }
    }
}

class Program
{
    static void Main()
    {
        ExpressionCalculator[] calculators = {
            new ExpressionCalculator(1, 2, 3),
            new ExpressionCalculator(0, 1, 0),  
            new ExpressionCalculator(2, 3, -1), 
            new ExpressionCalculator(0, 1, 1)   
        };

        for (int i = 0; i < calculators.Length; i++)
        {
            Console.Write($"Calculating for object {i + 1} (a={calculators[i].A}, " +
                          $"c={calculators[i].C}, d={calculators[i].D}): ");

            try
            {
                double result = calculators[i].Calculate();
                Console.WriteLine($"Result = {result}");
            }
            catch (ArgumentException e)
            {
                Console.WriteLine($"Error: {e.Message}");
            }
            catch (Exception)
            {
                Console.WriteLine("Unknown error occurred");
            }
        }

        
        try
        {
            double advancedResult = AdvancedCalculator.CalculateWithLogarithm(10, 2, 3, 4);
            Console.WriteLine($"Advanced calculation result: {advancedResult}");
        }
        catch (ArgumentException e)
        {
            Console.WriteLine($"Advanced calculation error: {e.Message}");
        }
    }
}