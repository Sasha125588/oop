using Task2;

class Program
{
    static void Main()
    {
        var date = new Date();

        try
        {
            date.SetDate(23, 1, 2013);
            Console.WriteLine(date.ToShortDateString()); // 23/01/2013
            Console.WriteLine(date.ToLongDateString()); // 23 січня, 2013
            Console.WriteLine(date.ToShortMonthDateString()); // 23 січ 2013

            // Перевірка високосного року
            date.SetDate(29, 2, 2020); // OK - 2020 високосний
            Console.WriteLine(date);

            // Має викинути помилку
            date.SetDate(29, 2, 2019); // Помилка - 2019 не високосний
        }
        catch (ArgumentOutOfRangeException ex)
        {
            Console.WriteLine($"Помилка: {ex.Message}");
        }
    }
}
