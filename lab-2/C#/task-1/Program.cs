using Task1;

class Program
{
    // "Глобальний" (статичний) об'єкт — ініціалізується до виконання Main (при ініціалізації типу)
    static Car? GlobalCar = new(1999, "Toyota", 180);

    static void Main()
    {
        Console.WriteLine("Start Main");
        RunTests();
        Console.WriteLine("End Main");
    }

    static void RunTests()
    {
        // Локальний об'єкт в основному блоці
        Car? local1 = new(2005, "Honda");

        // Локальний об'єкт у вкладеному блоці (стане недоступним після виходу зі скопу)
        {
            Car local2 = new(2010, "Ford");
            Console.WriteLine("Exiting inner scope (local2 will become eligible for GC)");
        }

        // Робимо local1 недоступним
        local1 = null;

        // Демонстративно викликаємо GC щоб побачити виклики фіналайзерів (не гарантовано в реальному коді)
        Console.WriteLine("Forcing GC...");
        GC.Collect();
        GC.WaitForPendingFinalizers();

        Console.WriteLine("Now clearing global reference and forcing GC again...");
        GlobalCar = null;
        GC.Collect();
        GC.WaitForPendingFinalizers();
    }
}
