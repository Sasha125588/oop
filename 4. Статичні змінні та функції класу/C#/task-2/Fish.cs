using System;

namespace Task2
{
  public class Fish
  {
    public Point Position { get; set; }

    public int Health { get; private set; }
    public static char[,] Ocean { get; private set; } = new char[0, 0];
    public static int CountOfLiveFish { get; private set; } = 0;

    public Fish()
    {
      Position = new Point();
      Health = 100;
      ++CountOfLiveFish;
    }

    static public void InitializeMap(string path = "ocean.txt")
    {
      string[] lines = File.ReadAllLines(path);

      if (lines.Length == 0)
        throw new Exception("Файл карти порожній!");

      int rows = lines.Length;
      int cols = lines[0].Length;

      char[,] ocean = new char[rows, cols];

      for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
          ocean[row, col] = lines[row][col];
        }
      }

      Ocean = ocean;
    }

    static public void InitializeMapWithSeaweed(string path = "ocean.txt", int seaweedCount = 20)
    {
      InitializeMap(path);

      Random rand = new();

      while (seaweedCount > 0) {
        int row = rand.Next(1, Ocean.GetLength(0) - 1);
        int col = rand.Next(1, Ocean.GetLength(1) - 1);

        if (Ocean[row, col] == ' ') {
          Ocean[row, col] = '*';
          seaweedCount--;
        }
      }
    }

    public static void WriteMap(char[,] map)
    {
      for (int row = 0; row < map.GetLength(0); row++) {
        for (int col = 0; col < map.GetLength(1); col++) {
          Console.Write(map[row, col]);
        }
        Console.WriteLine();
      }
    }

    public static void SpawnSeaweed()
    {
      Random rand = new();
      int row = rand.Next(1, Ocean.GetLength(0) - 1);
      int col = rand.Next(1, Ocean.GetLength(1) - 1);

      if (Ocean[row, col] == ' ') {
        Ocean[row, col] = '*';
      }
    }

    public bool HandleInput(char[,] map, ConsoleKeyInfo inputKey, ref int row, ref int col)
    {
      int[] direction = GetDirection(inputKey);

      if (direction[0] == 0 && direction[1] == 0)
        return false;

      int nextRow = row + direction[1];
      int nextCol = col + direction[0];

      if (map[nextRow, nextCol] == '#') return false;

      if (map[nextRow, nextCol] == '*') {
        Feed(10);
        Console.WriteLine($"Риба з'їла водорость! Ситість: {Health}");
        map[nextRow, nextCol] = ' ';
      }

      col = nextCol;
      row = nextRow;

      DecreaseHunger();

      return true;
    }

    static int[] GetDirection(ConsoleKeyInfo inputKey)
    {
      int[] direction = [0, 0];

      switch (inputKey.Key) {
        case ConsoleKey.UpArrow or ConsoleKey.W:
          direction[1] = -1;
          break;
        case ConsoleKey.DownArrow or ConsoleKey.S: // "|" Так не можна :(
          direction[1] = 1;
          break;
        case ConsoleKey.RightArrow or ConsoleKey.D:
          direction[0] = 1;
          break;
        case ConsoleKey.LeftArrow or ConsoleKey.A:
          direction[0] = -1;
          break;
      }

      return direction;
    }

    public void DisplayFish()
    {
      Console.WriteLine($"🐟 Риба {Position.Name}:");
      Console.WriteLine($"   Позиція: ({Position.X:F1}, {Position.Y:F1})");
      Console.WriteLine($"   Ситий: {Health}%");

      string hungerBar = GetHungerBar();
      Console.WriteLine($"   [{hungerBar}]");

      string status = GetFishStatus();
      Console.WriteLine($"   Статус: {status}");
    }

    private string GetHungerBar()
    {
      const int barLength = 20;
      int filledLength = (int)((double)Health / 100 * barLength);

      string bar = "";
      for (int i = 0; i < barLength; i++) {
        bar += i < filledLength ? "█" : "░";
      }

      return bar;
    }

    private string GetFishStatus()
    {
      if (Health >= 80)
        return "Ситий і задоволений 😊";
      else if (Health >= 60)
        return "Нормально харчується 🙂";
      else if (Health >= 40)
        return "Трохи голодний 😐";
      else if (Health >= 20)
        return "Голодний 😟";
      else
        return "Дуже голодний! 😰";
    }

    public void ChangeHealth(int amount)
    {
      Health = Math.Max(0, Math.Min(100, Health + amount));

      if (Health == 0) CountOfLiveFish--;
    }

    public void Feed(int foodValue = 20)
    {
      ChangeHealth(foodValue);
      Console.WriteLine($"🍎 Риба {Position.Name} поїла! +{foodValue} до ситості");
    }

    public void DecreaseHunger(int amount = 5) => ChangeHealth(-amount);
  }
}
