using System.Numerics;

namespace Task2
{
    public class Array<T>
        where T : INumber<T>, IComparable<T>
    {
        private T[] _arr;
        public int Size { get; private set; }
        public int Capacity { get; private set; }

        public Array()
        {
            Size = 10;
            Capacity = Size;
            _arr = new T[Capacity];
        }

        public Array(int size)
        {
            Size = size;
            Capacity = size;
            _arr = new T[Capacity];
        }

        public Array(int size, T value)
        {
            Size = size;
            Capacity = size;
            _arr = new T[Capacity];
            for (int i = 0; i < size; i++)
            {
                _arr[i] = value;
            }
        }

        public Array(Array<T> other)
        {
            Size = other.Size;
            Capacity = other.Capacity;
            _arr = new T[Capacity];

            for (int i = 0; i < Size; i++)
            {
                _arr[i] = other._arr[i];
            }
        }

        public void Add(T value)
        {
            if (Size >= Capacity)
            {
                Alloc(GetNewCapacity());
            }
            _arr[Size] = value;
            Size++;
        }

        public void RemoveByIndex(int index)
        {
            EnsureNotEmpty();
            EnsureValidIndex(index);

            for (int i = index; i < Size - 1; i++)
            {
                _arr[i] = _arr[i + 1];
            }
            Size--;

            if (Size < Capacity / 2 && Capacity > 10)
            {
                Alloc(Capacity / 2);
            }
        }

        public bool RemoveByValue(T value)
        {
            for (int i = 0; i < Size; i++)
            {
                if (_arr[i].Equals(value))
                {
                    RemoveByIndex(i);
                    return true;
                }
            }
            return false;
        }

        public void Sort(bool isAscending)
        {
            if (isAscending)
            {
                System.Array.Sort(_arr);
            }
            else
            {
                System.Array.Sort(_arr);
                System.Array.Reverse(_arr);
            }
        }

        public T Min()
        {
            EnsureNotEmpty();

            return _arr.Take(Size).Min();
        }

        public T Max()
        {
            EnsureNotEmpty();

            return _arr.Take(Size).Max();
        }

        public int IndexOf(T value)
        {
            for (int i = 0; i < Size; i++)
            {
                if (_arr[i].Equals(value))
                {
                    return i;
                }
            }
            return -1;
        }

        public void Fill(T value)
        {
            for (int i = 0; i < Size; i++)
            {
                _arr[i] = value;
            }
        }

        public void FillRandom()
        {
            var rand = new Random();

            for (int i = 0; i < Size; i++)
            {
                double randValue = rand.NextDouble() * 100;
                _arr[i] = T.CreateChecked(randValue);
            }
        }

        public void Print()
        {
            Console.WriteLine("┌─────────────────────────────────────┐");
            Console.WriteLine($"│              Array [{Size}]              │");
            Console.WriteLine("├─────────────────────────────────────┤");

            if (Size == 0)
            {
                Console.WriteLine("│              (empty)                │");
            }
            else
            {
                for (int i = 0; i < Size; i++)
                {
                    string value = _arr[i].ToString();
                    int spaces = 8 - value.Length;
                    Console.WriteLine($"│ [{i}] = {_arr[i]}{new string(' ', spaces)}│");
                }
            }

            Console.WriteLine("└─────────────────────────────────────┘");
        }

        public void PrintInfo()
        {
            Console.WriteLine("┌─────────────────────────────────────┐");
            Console.WriteLine("│            Array Info               │");
            Console.WriteLine("├─────────────────────────────────────┤");
            Console.WriteLine($"│ Size: {Size}                           │");
            Console.WriteLine($"│ Capacity: {Capacity}                       │");
            Console.WriteLine("└─────────────────────────────────────┘");
        }

        private void Alloc(int newCapacity)
        {
            T[] newArr = new T[newCapacity];

            for (int i = 0; i < Size; i++)
            {
                newArr[i] = _arr[i];
            }

            _arr = newArr;
            Capacity = newCapacity;
        }

        public T this[int index]
        {
            get
            {
                EnsureNotEmpty();
                EnsureValidIndex(index);
                return _arr[index];
            }
            set
            {
                EnsureNotEmpty();
                EnsureValidIndex(index);
                _arr[index] = value;
            }
        }

        private int GetNewCapacity()
        {
            if (Capacity == 0)
                return 1;

            if (Capacity < 256)
                return Capacity * 2;

            return (int)(Capacity * 1.25 + 3.0 * 256.0 / 4.0);
        }

        private void EnsureNotEmpty()
        {
            if (Size == 0)
                throw new InvalidOperationException("Array is empty");
        }

        private void EnsureValidIndex(int index)
        {
            if (index < 0 || index >= Size)
                throw new IndexOutOfRangeException("Index out of bounds");
        }
    }
}
