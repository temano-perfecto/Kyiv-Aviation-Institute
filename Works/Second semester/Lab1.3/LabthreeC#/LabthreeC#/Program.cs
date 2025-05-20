using System;

class StringNumber
{
    private string value;

    public StringNumber()
    {
        value = "0";
    }

    public StringNumber(string initialValue)
    {
        value = initialValue;
    }

    public StringNumber(StringNumber other)
    {
        value = other.value;
    }

    public string GetValue()
    {
        return value;
    }

    public static StringNumber operator +(StringNumber a, StringNumber b)
    {
        int num1 = int.Parse(a.value);
        int num2 = int.Parse(b.value);
        return new StringNumber((num1 + num2).ToString());
    }

    public static StringNumber operator -(StringNumber a, StringNumber b)
    {
        int num1 = int.Parse(a.value);
        int num2 = int.Parse(b.value);
        return new StringNumber((num1 - num2).ToString());
    }

    public override string ToString()
    {
        return value;
    }
}

class Program
{
    static void Main(string[] args)
    {
        StringNumber C1 = new StringNumber();
        StringNumber C2 = new StringNumber("123");
        StringNumber C3 = new StringNumber(C2);

        Console.WriteLine("C1: " + C1);
        Console.WriteLine("C2: " + C2);
        Console.WriteLine("C3: " + C3);

        C2 = new StringNumber(C2.GetValue() + "5");
        Console.WriteLine("C2 after adding '5': " + C2);

        C1 = C2 + C3;
        Console.WriteLine("result of addition C2 and C3: " + C1);

        C1 = C2 - C3;
        Console.WriteLine("resoult of subtraction C2 and C3: " + C1);
    }
}