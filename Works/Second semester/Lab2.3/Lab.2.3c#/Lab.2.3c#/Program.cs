using System;
using System.Collections.Generic;
using System.Linq;

namespace TextProcessingLab
{
    // Interface for digit operations
    public interface IDigitOperations
    {
        double CalculateDigitPercentage();
        int CountDigits();
    }

    // Class representing a text line
    public class TextLine : IDigitOperations
    {
        private readonly string _text;

        public TextLine(string text)
        {
            _text = text ?? throw new ArgumentNullException(nameof(text));
        }

        public string Content => _text;
        public int Length => _text.Length;

        public double CalculateDigitPercentage()
        {
            if (_text.Length == 0) return 0;
            int digitCount = _text.Count(char.IsDigit);
            return (double)digitCount / _text.Length * 100;
        }

        public int CountDigits()
        {
            return _text.Count(char.IsDigit);
        }

        public override string ToString() => _text;
    }

    // Class representing a text document
    public class TextDocument
    {
        private readonly List<TextLine> _lines = new List<TextLine>();

        public void AddLine(TextLine line)
        {
            if (line == null)
                throw new ArgumentNullException(nameof(line));

            _lines.Add(line);
        }

        public bool RemoveLine(int index)
        {
            if (index < 0 || index >= _lines.Count)
                return false;

            _lines.RemoveAt(index);
            return true;
        }

        public void ClearDocument()
        {
            _lines.Clear();
        }

        public TextLine FindLongestLine()
        {
            return _lines.OrderByDescending(line => line.Length).FirstOrDefault();
        }

        public double CalculateTotalDigitPercentage()
        {
            if (_lines.Count == 0) return 0;
            int totalChars = _lines.Sum(line => line.Length);
            int totalDigits = _lines.Sum(line => line.CountDigits());
            return (double)totalDigits / totalChars * 100;
        }

        public int CalculateTotalCharacters()
        {
            return _lines.Sum(line => line.Length);
        }

        public void DisplayAllLines()
        {
            Console.WriteLine("=== Document Contents ===");
            for (int i = 0; i < _lines.Count; i++)
            {
                Console.WriteLine($"[Line {i + 1}] {_lines[i]}");
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            TextDocument document = new TextDocument();

            // Adding sample lines
            document.AddLine(new TextLine("RCHP"));
            document.AddLine(new TextLine("Nirvana"));
            document.AddLine(new TextLine("Metallica"));
            document.AddLine(new TextLine("Nickelback"));
            document.AddLine(new TextLine("2025 year"));

            // Display all lines
            document.DisplayAllLines();
            Console.WriteLine();

            // Analyze document
            TextLine longestLine = document.FindLongestLine();
            if (longestLine != null)
            {
                Console.WriteLine($"Longest line ({longestLine.Length} chars): {longestLine.Content}");
            }

            Console.WriteLine($"Digit percentage: {document.CalculateTotalDigitPercentage():F2}%");
            Console.WriteLine($"Total characters: {document.CalculateTotalCharacters()}");

            // Modify document
            document.RemoveLine(1);
            Console.WriteLine("\nAfter removing line 2:");
            document.DisplayAllLines();

            // Clear document
            document.ClearDocument();
            Console.WriteLine("\nAfter clearing document:");
            Console.WriteLine($"Total lines: {document.CalculateTotalCharacters()}");
        }
    }
}