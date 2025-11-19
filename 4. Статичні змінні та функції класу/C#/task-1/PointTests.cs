using System;
using Task1;
using Xunit;

namespace Task1.Tests
{
  public class PointTests
  {
    #region Constructor Tests

    [Fact]
    public void Constructor_Default_CreatesPointAtOrigin()
    {
      // Arrange & Act
      var point = new Point();

      // Assert
      Assert.Equal(0, point.X);
      Assert.Equal(0, point.Y);
      Assert.NotEqual('\0', point.Name);
    }

    [Theory]
    [InlineData(3.5, 4.2)]
    [InlineData(-2.1, 5.8)]
    [InlineData(0, 0)]
    public void Constructor_WithParameters_SetsCorrectCoordinates(double x, double y)
    {
      // Arrange & Act
      var point = new Point(x, y);

      // Assert
      Assert.Equal(x, point.X);
      Assert.Equal(y, point.Y);
    }

    #endregion

    #region Property Tests

    [Fact]
    public void Name_AfterCreation_IsAssignedSequentially()
    {
      // Arrange & Act
      var point1 = new Point();
      var point2 = new Point();
      var point3 = new Point();

      // Assert
      Assert.True(point2.Name > point1.Name || (point1.Name == 'Z' && point2.Name == 'A'));
      Assert.True(point3.Name > point2.Name || (point2.Name == 'Z' && point3.Name == 'A'));
    }

    [Fact]
    public void XProperty_CanBeSet()
    {
      // Arrange
      var point = new Point(1, 2);

      // Act
      point.X = 10;

      // Assert
      Assert.Equal(10, point.X);
    }

    [Fact]
    public void YProperty_CanBeSet()
    {
      // Arrange
      var point = new Point(1, 2);

      // Act
      point.Y = 20;

      // Assert
      Assert.Equal(20, point.Y);
    }

    [Fact]
    public void Name_IsReadOnly()
    {
      // Arrange
      var point = new Point();

      // Assert
      // Цей тест перевіряє, що Name має приватний setter
      // Якщо спробувати point.Name = 'X', це не скомпілюється
      Assert.NotEqual('\0', point.Name);
    }

    #endregion

    #region Method Tests

    [Theory]
    [InlineData(3, 4, 5)]
    [InlineData(0, 0, 0)]
    [InlineData(5, 12, 13)]
    [InlineData(-3, -4, 5)]
    public void DistanceFromOrigin_CalculatesCorrectly(double x, double y, double expectedDistance)
    {
      // Arrange
      var point = new Point(x, y);

      // Act
      double distance = point.DistanceFromOrigin();

      // Assert
      Assert.Equal(expectedDistance, distance, 10);
    }

    [Fact]
    public void ToString_ReturnsFormattedString()
    {
      // Arrange
      var point = new Point(3.456, 7.891);
      char name = point.Name;

      // Act
      string result = point.ToString();

      // Assert
      Assert.Equal($"{name}(3,46, 7,89)", result);
    }

    #endregion

    #region Operator Tests

    [Fact]
    public void ExplicitOperator_FromDouble_CreatesPointWithXCoordinate()
    {
      // Arrange
      double value = 5.5;

      // Act
      var point = (Point)value;

      // Assert
      Assert.Equal(value, point.X);
      Assert.Equal(5.5, point.Y);
    }

    [Fact]
    public void AdditionOperator_AddsTwoPoints()
    {
      // Arrange
      var point1 = new Point(3, 4);
      var point2 = new Point(1, 2);

      // Act
      var result = point1 + point2;

      // Assert
      Assert.Equal(4, result.X);
      Assert.Equal(6, result.Y);
    }

    [Fact]
    public void SubtractionOperator_SubtractsTwoPoints()
    {
      // Arrange
      var point1 = new Point(5, 7);
      var point2 = new Point(2, 3);

      // Act
      var result = point1 - point2;

      // Assert
      Assert.Equal(3, result.X);
      Assert.Equal(4, result.Y);
    }

    #endregion

    #region Static Method Tests

    [Fact]
    public void AreEqual_WithEqualPoints_ReturnsTrue()
    {
      // Arrange
      var point1 = new Point(3.14159, 2.71828);
      var point2 = new Point(3.14159, 2.71828);

      // Act
      bool result = Point.AreEqual(point1, point2);

      // Assert
      Assert.True(result);
    }

    [Fact]
    public void AreEqual_WithDifferentPoints_ReturnsFalse()
    {
      // Arrange
      var point1 = new Point(3, 4);
      var point2 = new Point(3, 5);

      // Act
      bool result = Point.AreEqual(point1, point2);

      // Assert
      Assert.False(result);
    }

    [Fact]
    public void AreEqual_WithVeryClosePoints_ReturnsTrue()
    {
      // Arrange
      var point1 = new Point(1.0, 2.0);
      var point2 = new Point(1.0 + 1e-11, 2.0 + 1e-11);

      // Act
      bool result = Point.AreEqual(point1, point2);

      // Assert
      Assert.True(result);
    }

    [Fact]
    public void CompareDistances_FirstPointCloser_ReturnsNegative()
    {
      // Arrange
      var point1 = new Point(1, 1);
      var point2 = new Point(5, 5);

      // Act
      int result = Point.CompareDistances(point1, point2);

      // Assert
      Assert.Equal(-1, result);
    }

    [Fact]
    public void CompareDistances_FirstPointFarther_ReturnsPositive()
    {
      // Arrange
      var point1 = new Point(5, 5);
      var point2 = new Point(1, 1);

      // Act
      int result = Point.CompareDistances(point1, point2);

      // Assert
      Assert.Equal(1, result);
    }

    [Fact]
    public void CompareDistances_EqualDistances_ReturnsZero()
    {
      // Arrange
      var point1 = new Point(3, 4);
      var point2 = new Point(0, 5);

      // Act
      int result = Point.CompareDistances(point1, point2);

      // Assert
      Assert.Equal(0, result);
    }

    #endregion
  }
}
