namespace Task1
{
  class Point
  {
    public double X { get; set; }
    public double Y { get; set; }
    public char Name { get; private set; }

    public static int ObjectCount { get; private set; } = 0;
    private static char lastPointName = '@';

    public Point()
    {
      X = 0;
      Y = 0;
      AssignName();
      ObjectCount++;
    }

    public Point(double x, double y)
    {
      X = x;
      Y = y;
      AssignName();
      ObjectCount++;
    }

    public static explicit operator Point(double value)
    {
      return new Point(value, value);
    }

    ~Point()
    {
      ObjectCount--;
    }

    private void AssignName()
    {
      lastPointName++;
      if (lastPointName > 'Z')
        lastPointName = 'A';
      Name = lastPointName;
    }

    public double DistanceFromOrigin()
    {
      return Math.Sqrt(X * X + Y * Y);
    }

    public void Display()
    {
      Console.WriteLine($"Точка {Name}: ({X:F2}, {Y:F2})");
    }

    public static Point operator +(Point p1, Point p2)
    {
      return new Point(p1.X + p2.X, p1.Y + p2.Y);
    }

    public static Point operator -(Point p1, Point p2)
    {
      return new Point(p1.X - p2.X, p1.Y - p2.Y);
    }

    public static bool AreEqual(Point p1, Point p2)
    {
      const double epsilon = 1e-10;
      return Math.Abs(p1.X - p2.X) < epsilon && Math.Abs(p1.Y - p2.Y) < epsilon;
    }

    public static int CompareDistances(Point p1, Point p2)
    {
      double dist1 = p1.DistanceFromOrigin();
      double dist2 = p2.DistanceFromOrigin();
      const double epsilon = 1e-10;

      if (Math.Abs(dist1 - dist2) < epsilon)
        return 0;
      else if (dist1 > dist2)
        return 1;
      else
        return -1;
    }

    public override string ToString()
    {
      return $"{Name}({X:F2}, {Y:F2})";
    }
  }
}
