using System;

public class Base
{
    public string line;
    public int i = 0;

    public Base() { }

    public Base(string line)
    {
        LineLength(line);
    }

    public int LineLength(string UIline)
    {
        i = UIline.Length;
        return i;
    }
}

public class Inherited : Base
{
    public Inherited()
    {
        line = "5423412sdfasfasfasgrvsrvrgr53g5rg4grdgdfg3";
    }

    public void SortingBy()
    {
        char[] chars = line.ToCharArray();
        Array.Sort(chars);
        line = new string(chars);
    }
}

class Program
{
    static void Main(string[] args)
    {
        Inherited inh = new Inherited();

        inh.LineLength(inh.line);
        inh.SortingBy();

        Console.WriteLine(inh.line);
        Console.WriteLine(inh.i);
    }
}