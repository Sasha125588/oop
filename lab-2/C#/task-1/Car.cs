namespace Task1
{
    public class Car
    {
        private static int _counter;
        private readonly int _id;

        private int _yearModel;
        public int YearModel
        {
            get => _yearModel;
            set
            {
                if (value < 1885)
                {
                    throw new ArgumentOutOfRangeException(
                        nameof(YearModel),
                        "Перша машина зʼявилася в 1885 році."
                    );
                }
                _yearModel = value;
            }
        }

        public string Brand { get; set; } = "Unknown";

        private int _maxSpeed = 200;
        public int MaxSpeed
        {
            get => _maxSpeed;
            private set
            {
                ArgumentOutOfRangeException.ThrowIfNegative(value);
                _maxSpeed = value;
                if (_speed > _maxSpeed)
                    _speed = _maxSpeed;
            }
        }

        private int _speed;
        public int Speed
        {
            get => _speed;
            private set
            {
                ArgumentOutOfRangeException.ThrowIfNegative(value);

                if (value > _maxSpeed)
                    throw new ArgumentException("Швидкість не може бути більше максимальної.");

                _speed = value;
            }
        }

        public Car()
            : this(DateTime.Now.Year, "Unknown", 200) { }

        public Car(int yearModel, string brand, int maxSpeed)
        {
            _id = ++_counter;
            YearModel = yearModel;
            Brand = brand;
            MaxSpeed = maxSpeed;
            Speed = 0;
            Console.WriteLine(
                $"[Ctor#{_id}] Car created: {Brand} {YearModel}, MaxSpeed={MaxSpeed}"
            );
        }

        public Car(int yearModel, string brand)
            : this(yearModel, brand, 200) { }

        public void Accelerate(int delta = 5) => Speed = Math.Min(MaxSpeed, Speed + delta);

        public void Brake(int delta = 5) => Speed = Math.Max(0, Speed - delta);

        ~Car()
        {
            Console.WriteLine($"[Dtor#{_id}] Car finalized: {Brand} {YearModel}");
        }

        public override string ToString() => $"{Brand} {YearModel} (speed {Speed}/{MaxSpeed})";
    }
}
