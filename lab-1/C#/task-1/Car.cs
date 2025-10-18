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
        public string Brand { get; set; }

        private int _maxSpeed;
        public int MaxSpeed
        {
            get => _maxSpeed;
            set
            {
                _maxSpeed = Math.Max(0, value);
                if (_maxSpeed < _speed)
                {
                    _speed = _maxSpeed;
                }
            }
        } = 200;

        private int _speed;
        public int Speed
        {
            get => _speed;
            set
            {
                if (value > _maxSpeed)
                {
                    throw new ArgumentException("Швидкість не може бути більше максимальної.");
                }
                _speed = Math.Max(0, value);
            }
        }

        public void Accelerate(int value = 5)
        {
            this.Speed = Math.Min(this.MaxSpeed, this.Speed + value);
        }

        public void Brake(int value = 5)
        {
            this.Speed = Math.Max(0, this.Speed - value);
        }
    }
}
