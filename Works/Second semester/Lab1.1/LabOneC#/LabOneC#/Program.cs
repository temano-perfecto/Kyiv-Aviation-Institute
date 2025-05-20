namespace LabOne
{
    internal class Program
    {

        class Segment
        {
            public double StartX;
            public double StartY;
            public double EndX;
            public double EndY;

            public double CalculateLength()
            {
                return Math.Sqrt(Math.Pow(EndX - StartX, 2) + Math.Pow(EndY - StartY, 2));
            }

            public double CalculateAngleWithXAxis()
            {
                double deltaX = EndX - StartX;
                double deltaY = EndY - StartY;
                return Math.Atan2(deltaY, deltaX) * (180 / Math.PI);
            }
        }

        static void Main(string[] args)
        {
            Segment Seg = new Segment();
            Console.WriteLine("Enter Section's Coordinates in particular order: Ax, Ay, Bx, By: ");
            Seg.StartX = Convert.ToDouble(Console.ReadLine());
            Seg.StartY = Convert.ToDouble(Console.ReadLine());
            Seg.EndX = Convert.ToDouble(Console.ReadLine());
            Seg.EndY = Convert.ToDouble(Console.ReadLine());
            double SegLength = Seg.CalculateLength();
            double AngleToAbsciss = Seg.CalculateAngleWithXAxis();

            Console.WriteLine($"Segment's Length: {SegLength} | Segment's Angle relatively to absciss: {AngleToAbsciss}");
        }
    }
}