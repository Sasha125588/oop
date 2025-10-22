using System;
using Task2;
using Xunit;

namespace Task2.Tests
{
    public class ArrayTests
    {
        #region Constructor Tests

        [Fact]
        public void Constructor_Default_CreatesArrayWithSize10()
        {
            // Arrange & Act
            var arr = new Array<int>();

            // Assert
            Assert.Equal(10, arr.Size);
            Assert.Equal(10, arr.Capacity);
        }

        [Fact]
        public void Constructor_WithSize_CreatesArrayWithSpecifiedSize()
        {
            // Arrange & Act
            var arr = new Array<int>(5);

            // Assert
            Assert.Equal(5, arr.Size);
            Assert.Equal(5, arr.Capacity);
        }

        [Fact]
        public void Constructor_WithSizeAndValue_FillsArrayWithValue()
        {
            // Arrange & Act
            var arr = new Array<int>(3, 42);

            // Assert
            Assert.Equal(3, arr.Size);
            Assert.Equal(42, arr[0]);
            Assert.Equal(42, arr[1]);
            Assert.Equal(42, arr[2]);
        }

        [Fact]
        public void Constructor_Copy_CreatesDeepCopy()
        {
            // Arrange
            var original = new Array<int>(3, 10);

            // Act
            var copy = new Array<int>(original);
            copy[0] = 99;

            // Assert
            Assert.Equal(3, copy.Size);
            Assert.Equal(99, copy[0]);
            Assert.Equal(10, original[0]); // Original unchanged
        }

        #endregion

        #region Add Tests

        [Fact]
        public void Add_SingleElement_IncreasesSize()
        {
            // Arrange
            var arr = new Array<int>(0);

            // Act
            arr.Add(42);

            // Assert
            Assert.Equal(1, arr.Size);
            Assert.Equal(42, arr[0]);
        }

        [Fact]
        public void Add_MultipleElements_IncreasesCapacityWhenNeeded()
        {
            // Arrange
            var arr = new Array<int>(2);
            int initialCapacity = arr.Capacity;

            // Act
            arr.Add(1);
            arr.Add(2);
            arr.Add(3);

            // Assert
            Assert.Equal(5, arr.Size);
            Assert.True(arr.Capacity > initialCapacity);
        }

        [Fact]
        public void Add_ManyElements_DoublesCapacityCorrectly()
        {
            // Arrange
            var arr = new Array<int>(0);

            // Act
            for (int i = 0; i < 100; i++)
            {
                arr.Add(i);
            }

            // Assert
            Assert.Equal(100, arr.Size);
            Assert.True(arr.Capacity >= 100);
        }

        #endregion

        #region RemoveByIndex Tests

        [Fact]
        public void RemoveByIndex_ValidIndex_RemovesElement()
        {
            // Arrange
            var arr = new Array<int>(3, 0);
            arr[0] = 1;
            arr[1] = 2;
            arr[2] = 3;

            // Act
            arr.RemoveByIndex(1);

            // Assert
            Assert.Equal(2, arr.Size);
            Assert.Equal(1, arr[0]);
            Assert.Equal(3, arr[1]);
        }

        [Fact]
        public void RemoveByIndex_EmptyArray_ThrowsException()
        {
            // Arrange
            var arr = new Array<int>(0);

            // Act & Assert
            Assert.Throws<InvalidOperationException>(() => arr.RemoveByIndex(0));
        }

        [Fact]
        public void RemoveByIndex_NegativeIndex_ThrowsException()
        {
            // Arrange
            var arr = new Array<int>(3, 1);

            // Act & Assert
            Assert.Throws<IndexOutOfRangeException>(() => arr.RemoveByIndex(-1));
        }

        [Fact]
        public void RemoveByIndex_OutOfBounds_ThrowsException()
        {
            // Arrange
            var arr = new Array<int>(3, 1);

            // Act & Assert
            Assert.Throws<IndexOutOfRangeException>(() => arr.RemoveByIndex(5));
        }

        [Fact]
        public void RemoveByIndex_ReducesCapacityWhenNeeded()
        {
            // Arrange
            var arr = new Array<int>(20);
            for (int i = 0; i < 20; i++)
            {
                arr[i] = i;
            }
            int initialCapacity = arr.Capacity;

            // Act - remove enough elements to trigger capacity reduction
            for (int i = 0; i < 11; i++)
            {
                arr.RemoveByIndex(0);
            }

            // Assert
            Assert.True(arr.Capacity < initialCapacity);
        }

        #endregion

        #region RemoveByValue Tests

        [Fact]
        public void RemoveByValue_ExistingValue_RemovesAndReturnsTrue()
        {
            // Arrange
            var arr = new Array<int>(3, 0);
            arr[0] = 1;
            arr[1] = 2;
            arr[2] = 3;

            // Act
            bool result = arr.RemoveByValue(2);

            // Assert
            Assert.True(result);
            Assert.Equal(2, arr.Size);
            Assert.Equal(1, arr[0]);
            Assert.Equal(3, arr[1]);
        }

        [Fact]
        public void RemoveByValue_NonExistingValue_ReturnsFalse()
        {
            // Arrange
            var arr = new Array<int>(3, 1);

            // Act
            bool result = arr.RemoveByValue(99);

            // Assert
            Assert.False(result);
            Assert.Equal(3, arr.Size);
        }

        [Fact]
        public void RemoveByValue_DuplicateValues_RemovesFirstOccurrence()
        {
            // Arrange
            var arr = new Array<int>(4, 0);
            arr[0] = 1;
            arr[1] = 2;
            arr[2] = 2;
            arr[3] = 3;

            // Act
            arr.RemoveByValue(2);

            // Assert
            Assert.Equal(3, arr.Size);
            Assert.Equal(1, arr[0]);
            Assert.Equal(2, arr[1]); // Second occurrence remains
            Assert.Equal(3, arr[2]);
        }

        #endregion

        #region Sort Tests

        [Fact]
        public void Sort_Ascending_SortsCorrectly()
        {
            // Arrange
            var arr = new Array<int>(5, 0);
            arr[0] = 5;
            arr[1] = 2;
            arr[2] = 8;
            arr[3] = 1;
            arr[4] = 9;

            // Act
            arr.Sort(true);

            // Assert
            Assert.Equal(1, arr[0]);
            Assert.Equal(2, arr[1]);
            Assert.Equal(5, arr[2]);
            Assert.Equal(8, arr[3]);
            Assert.Equal(9, arr[4]);
        }

        [Fact]
        public void Sort_Descending_SortsCorrectly()
        {
            // Arrange
            var arr = new Array<int>(5, 0);
            arr[0] = 5;
            arr[1] = 2;
            arr[2] = 8;
            arr[3] = 1;
            arr[4] = 9;

            // Act
            arr.Sort(false);

            // Assert
            Assert.Equal(9, arr[0]);
            Assert.Equal(8, arr[1]);
            Assert.Equal(5, arr[2]);
            Assert.Equal(2, arr[3]);
            Assert.Equal(1, arr[4]);
        }

        [Fact]
        public void Sort_EmptyArray_DoesNotThrow()
        {
            // Arrange
            var arr = new Array<int>(0);

            // Act & Assert
            arr.Sort(true); // Should not throw
            Assert.Equal(0, arr.Size);
        }

        #endregion

        #region Min/Max Tests

        [Fact]
        public void Min_ReturnsSmallestElement()
        {
            // Arrange
            var arr = new Array<int>(5, 0);
            arr[0] = 5;
            arr[1] = 2;
            arr[2] = 8;
            arr[3] = 1;
            arr[4] = 9;

            // Act
            int min = arr.Min();

            // Assert
            Assert.Equal(1, min);
        }

        [Fact]
        public void Max_ReturnsLargestElement()
        {
            // Arrange
            var arr = new Array<int>(5, 0);
            arr[0] = 5;
            arr[1] = 2;
            arr[2] = 8;
            arr[3] = 1;
            arr[4] = 9;

            // Act
            int max = arr.Max();

            // Assert
            Assert.Equal(9, max);
        }

        [Fact]
        public void Min_EmptyArray_ThrowsException()
        {
            // Arrange
            var arr = new Array<int>(0);

            // Act & Assert
            Assert.Throws<InvalidOperationException>(() => arr.Min());
        }

        [Fact]
        public void Max_EmptyArray_ThrowsException()
        {
            // Arrange
            var arr = new Array<int>(0);

            // Act & Assert
            Assert.Throws<InvalidOperationException>(() => arr.Max());
        }

        #endregion

        #region IndexOf Tests

        [Fact]
        public void IndexOf_ExistingValue_ReturnsCorrectIndex()
        {
            // Arrange
            var arr = new Array<int>(3, 0);
            arr[0] = 10;
            arr[1] = 20;
            arr[2] = 30;

            // Act
            int index = arr.IndexOf(20);

            // Assert
            Assert.Equal(1, index);
        }

        [Fact]
        public void IndexOf_NonExistingValue_ReturnsMinusOne()
        {
            // Arrange
            var arr = new Array<int>(3, 1);

            // Act
            int index = arr.IndexOf(99);

            // Assert
            Assert.Equal(-1, index);
        }

        [Fact]
        public void IndexOf_DuplicateValues_ReturnsFirstIndex()
        {
            // Arrange
            var arr = new Array<int>(4, 0);
            arr[0] = 1;
            arr[1] = 2;
            arr[2] = 2;
            arr[3] = 3;

            // Act
            int index = arr.IndexOf(2);

            // Assert
            Assert.Equal(1, index);
        }

        #endregion

        #region Fill Tests

        [Fact]
        public void Fill_FillsAllElementsWithValue()
        {
            // Arrange
            var arr = new Array<int>(5, 0);

            // Act
            arr.Fill(42);

            // Assert
            for (int i = 0; i < arr.Size; i++)
            {
                Assert.Equal(42, arr[i]);
            }
        }

        #endregion

        #region FillRandom Tests

        [Fact]
        public void FillRandom_FillsWithDifferentValues()
        {
            // Arrange
            var arr = new Array<int>(100);

            // Act
            arr.FillRandom();

            // Assert
            bool hasDifferentValues = false;
            for (int i = 1; i < arr.Size; i++)
            {
                if (arr[i] != arr[0])
                {
                    hasDifferentValues = true;
                    break;
                }
            }
            Assert.True(hasDifferentValues);
        }

        [Fact]
        public void FillRandom_ValuesInExpectedRange()
        {
            // Arrange
            var arr = new Array<double>(50);

            // Act
            arr.FillRandom();

            // Assert
            for (int i = 0; i < arr.Size; i++)
            {
                Assert.InRange(arr[i], 0, 100);
            }
        }

        #endregion

        #region Indexer Tests

        [Fact]
        public void Indexer_Get_ReturnsCorrectValue()
        {
            // Arrange
            var arr = new Array<int>(3, 0);
            arr[0] = 10;
            arr[1] = 20;
            arr[2] = 30;

            // Act & Assert
            Assert.Equal(10, arr[0]);
            Assert.Equal(20, arr[1]);
            Assert.Equal(30, arr[2]);
        }

        [Fact]
        public void Indexer_Set_SetsCorrectValue()
        {
            // Arrange
            var arr = new Array<int>(3, 0);

            // Act
            arr[0] = 100;
            arr[1] = 200;
            arr[2] = 300;

            // Assert
            Assert.Equal(100, arr[0]);
            Assert.Equal(200, arr[1]);
            Assert.Equal(300, arr[2]);
        }

        [Fact]
        public void Indexer_EmptyArray_ThrowsException()
        {
            // Arrange
            var arr = new Array<int>(0);

            // Act & Assert
            Assert.Throws<InvalidOperationException>(() => arr[0]);
        }

        [Fact]
        public void Indexer_NegativeIndex_ThrowsException()
        {
            // Arrange
            var arr = new Array<int>(3, 1);

            // Act & Assert
            Assert.Throws<IndexOutOfRangeException>(() => arr[-1]);
        }

        [Fact]
        public void Indexer_OutOfBounds_ThrowsException()
        {
            // Arrange
            var arr = new Array<int>(3, 1);

            // Act & Assert
            Assert.Throws<IndexOutOfRangeException>(() => arr[5]);
        }

        #endregion

        #region Integration Tests

        [Fact]
        public void Integration_AddSortAndFind_WorksTogether()
        {
            // Arrange
            var arr = new Array<int>(0);

            // Act
            arr.Add(5);
            arr.Add(2);
            arr.Add(8);
            arr.Add(1);
            arr.Sort(true);

            // Assert
            Assert.Equal(1, arr.Min());
            Assert.Equal(8, arr.Max());
            Assert.Equal(0, arr.IndexOf(1));
            Assert.Equal(3, arr.IndexOf(8));
        }

        [Fact]
        public void Integration_RemoveAndCapacity_WorksTogether()
        {
            // Arrange
            var arr = new Array<int>(20);
            for (int i = 0; i < 20; i++)
            {
                arr[i] = i;
            }

            // Act
            for (int i = 0; i < 15; i++)
            {
                arr.RemoveByIndex(0);
            }

            // Assert
            Assert.Equal(5, arr.Size);
            Assert.True(arr.Capacity < 20);
        }

        [Fact]
        public void Integration_CopyModifyOriginal_DoesNotAffectCopy()
        {
            // Arrange
            var original = new Array<int>(3, 0);
            original[0] = 1;
            original[1] = 2;
            original[2] = 3;

            // Act
            var copy = new Array<int>(original);
            original.Add(4);
            original[0] = 99;

            // Assert
            Assert.Equal(4, original.Size);
            Assert.Equal(3, copy.Size);
            Assert.Equal(99, original[0]);
            Assert.Equal(1, copy[0]);
        }

        #endregion

        #region Edge Cases

        [Fact]
        public void EdgeCase_SingleElement_AllOperationsWork()
        {
            // Arrange
            var arr = new Array<int>(1, 42);

            // Assert
            Assert.Equal(42, arr.Min());
            Assert.Equal(42, arr.Max());
            Assert.Equal(0, arr.IndexOf(42));

            // Act
            arr.Sort(true);
            Assert.Equal(42, arr[0]);
        }

        [Fact]
        public void EdgeCase_LargeArray_HandlesCorrectly()
        {
            // Arrange
            var arr = new Array<int>(0);

            // Act
            for (int i = 0; i < 10000; i++)
            {
                arr.Add(i);
            }

            // Assert
            Assert.Equal(10000, arr.Size);
            Assert.Equal(0, arr.Min());
            Assert.Equal(9999, arr.Max());
        }

        #endregion
    }
}
