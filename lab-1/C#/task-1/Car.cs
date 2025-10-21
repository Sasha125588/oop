namespace Task1
{
    public class Car
    {
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

        private double _maxSpeed = 200;
        public double MaxSpeed
        {
            get => _maxSpeed;
            set
            {
                _maxSpeed = Math.Max(0.0, value);
                if (_speed > _maxSpeed)
                    _speed = _maxSpeed;
            }
        }

        private double _speed;
        public double Speed
        {
            get => _speed;
            set
            {
                if (value > _maxSpeed)
                {
                    throw new ArgumentException("Швидкість не може бути більше максимальної.");
                }
                _speed = Math.Max(0.0, value);
            }
        }

        public void Accelerate(int delta = 5) => Speed = Math.Min(MaxSpeed, Speed + delta);

        public void Brake(int delta = 5) => Speed = Math.Max(0, Speed - delta);
    }
}
