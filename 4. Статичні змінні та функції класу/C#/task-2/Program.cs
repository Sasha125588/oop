using Task2;

namespace MyApp
{
  internal class Program
  {
    static void Main(string[] args)
    {
      const int GAME_SPEED_MS = 400;

      Console.CursorVisible = false;

      int moves = 0;

      Fish.InitializeMapWithSeaweed("ocean.txt");

      Fish fish = new();

      int fishRow = 1;
      int fishCol = 1;

      ConsoleKeyInfo? lastKey = null;

      while (true) {
        Console.Clear();

        Fish.WriteMap(Fish.Ocean);

        if (Console.KeyAvailable) {
          lastKey = Console.ReadKey(true);

          if (lastKey.Value.Key == ConsoleKey.Escape) {
            Console.WriteLine("\n\n👋 Ви вийшли з гри.");
            break;
          }
        }

        if (lastKey.HasValue) {
          bool moved = fish.HandleInput(Fish.Ocean, lastKey.Value, ref fishRow, ref fishCol);
          if (moved) {
            moves++;
          }
        }

        Console.WriteLine($"\nХід #{moves}");

        if (moves > 0 && moves % 3 == 0)
          Fish.SpawnSeaweed();


        Console.WriteLine($"Позиція: Col={fishCol}, Row={fishRow}");
        Console.WriteLine($"Здоров'я: {fish.Health}%");

        Console.SetCursorPosition(fishCol, fishRow);
        Console.ForegroundColor = ConsoleColor.Cyan;
        Console.Write("F");
        Console.ResetColor();

        Console.SetCursorPosition(0, Fish.Ocean.GetLength(0) + 1);

        Thread.Sleep(GAME_SPEED_MS);

        if (fish.Health <= 0) {
          ShowGameOver(moves);
          break;
        }
      }

      Console.CursorVisible = true;
    }

    static void ShowGameOver(int moves)
    {
      Console.ForegroundColor = ConsoleColor.Red;
      Console.WriteLine();
      Console.WriteLine("╔════════════════════════════════╗");
      Console.WriteLine("║   ВАША РИБКА ПОМЕРЛА! 💀       ║");
      Console.WriteLine("║      від голоду :(             ║");
      Console.WriteLine($"║  Ви протрималися {moves,3} ходів!    ║");
      Console.WriteLine("╚════════════════════════════════╝");
      Console.ResetColor();
      Console.WriteLine();
    }
  }
}