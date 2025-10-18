using Task3;

class Program
{
    static void Main()
    {
        TestFraction();
    }

    static void TestFraction()
    {
        Console.WriteLine("=== Тестування класу Fraction ===\n");

        // Тестування конструкторів
        Console.WriteLine("1. Тестування конструкторів:");
        var f1 = new Fraction();
        Console.WriteLine($"За замовчуванням: {f1}");

        var f2 = new Fraction(15);
        Console.WriteLine($"З одним параметром (15): {f2}");

        var f3 = new Fraction(10, -2);
        Console.WriteLine($"З двома параметрами (10/-2): {f3}");

        // Тестування скорочення
        Console.WriteLine("\n2. Тестування скорочення:");
        var f4 = new Fraction(15, 25);
        Console.WriteLine($"До скорочення: {f4}");
        f4.Reduce();
        Console.WriteLine($"Після скорочення: {f4}");

        // Тестування арифметичних операцій
        Console.WriteLine("\n3. Тестування арифметичних операцій:");
        var a = new Fraction(1, 2);
        var b = new Fraction(1, 3);
        Console.WriteLine($"a = {a}");
        Console.WriteLine($"b = {b}");

        var sum = new Fraction(1, 2).Add(b);
        Console.WriteLine($"a + b = {sum}");

        var diff = new Fraction(1, 2).Subtract(b);
        Console.WriteLine($"a - b = {diff}");

        var prod = new Fraction(1, 2).Multiply(b);
        Console.WriteLine($"a * b = {prod}");

        var quot = new Fraction(1, 2).Divide(b);
        Console.WriteLine($"a / b = {quot}");

        // Тестування операцій з цілими числами
        Console.WriteLine("\n4. Тестування операцій з цілими числами:");
        var c = new Fraction(1, 2);
        Console.WriteLine($"c = {c}");
        c.Add(3);
        Console.WriteLine($"c + 3 = {c}");
        c.Multiply(2);
        Console.WriteLine($"Результат * 2 = {c}");

        // Тестування порівняння
        Console.WriteLine("\n5. Тестування порівняння:");
        var d1 = new Fraction(1, 2);
        var d2 = new Fraction(2, 4);
        var d3 = new Fraction(3, 4);

        Console.WriteLine($"Порівняння {d1} та {d2}");
        Console.WriteLine($"Результат: {(d1.Equals(d2) ? "Рівні" : "Не рівні")}");

        Console.WriteLine($"Порівняння {d1} та {d3}");
        Console.WriteLine($"Результат: {(d1.Equals(d3) ? "Рівні" : "Не рівні")}");
    }
}
