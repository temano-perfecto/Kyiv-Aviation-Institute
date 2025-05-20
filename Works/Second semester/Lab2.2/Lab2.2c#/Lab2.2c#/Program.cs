using System;

namespace ShapesApplication
{
    
    public abstract class Shape
    {
        public abstract double CalculateArea();
        public abstract double CalculatePerimeter();
    }

   
    public class Ellipse : Shape
    {
        public double SemiMajorAxis { get; }
        public double SemiMinorAxis { get; }

        public Ellipse(double majorAxis, double minorAxis)
        {
            if (majorAxis <= 0 || minorAxis <= 0)
                throw new ArgumentException("Axis values must be positive");

            SemiMajorAxis = majorAxis;
            SemiMinorAxis = minorAxis;
        }

        public override double CalculateArea()
        {
            return Math.PI * SemiMajorAxis * SemiMinorAxis;
        }

        public override double CalculatePerimeter()
        {
       
            double h = Math.Pow(SemiMajorAxis - SemiMinorAxis, 2) /
                      Math.Pow(SemiMajorAxis + SemiMinorAxis, 2);
            return Math.PI * (SemiMajorAxis + SemiMinorAxis) *
                  (1 + (3 * h) / (10 + Math.Sqrt(4 - 3 * h)));
        }
    }

    
    public class Circle : Shape
    {
        public double Radius { get; }

        public Circle(double radius)
        {
            if (radius <= 0)
                throw new ArgumentException("Radius must be positive");

            Radius = radius;
        }

        public override double CalculateArea()
        {
            return Math.PI * Radius * Radius;
        }

        public override double CalculatePerimeter()
        {
            return 2 * Math.PI * Radius;
        }
    }

    class Program
    {
      
        static void PrintShapeInfo(Shape shape)
        {
            Console.WriteLine($"Shape Type: {shape.GetType().Name}");
            Console.WriteLine($"Area: {shape.CalculateArea():F2}");
            Console.WriteLine($"Perimeter: {shape.CalculatePerimeter():F2}\n");
        }

        static void Main()
        {
            try
            {
                
                Shape circle = new Circle(5.0);
                Shape ellipse = new Ellipse(5.0, 3.0);

                
                Console.WriteLine("Shape Information:");
                PrintShapeInfo(circle);
                PrintShapeInfo(ellipse);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
        }
    }
}