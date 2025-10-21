namespace Task3
{
    public class Fraction
    {
        public int Numerator { get; set; }

        private int _denominator = 1;
        public int Denominator
        {
            get => _denominator;
            set
            {
                if (value == 0)
                {
                    throw new ArgumentException("Знаменник не може бути нулем");
                }
                if (value < 0)
                {
                    Numerator = -Numerator;
                    _denominator = -value;
                }
                else
                {
                    _denominator = value;
                }
            }
        }

        public Fraction()
            : this(0) { }

        public Fraction(int numerator)
            : this(numerator, 1) { }

        public Fraction(int numerator, int denominator)
        {
            Numerator = numerator;
            Denominator = denominator;
        }

        private static int GCD(int a, int b)
        {
            a = Math.Abs(a);
            b = Math.Abs(b);
            while (b != 0)
            {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }

        public Fraction Reduce()
        {
            int gcd = GCD(Numerator, _denominator);
            Numerator /= gcd;
            _denominator /= gcd;
            return this;
        }

        public Fraction Add(Fraction other)
        {
            Numerator = Numerator * other._denominator + other.Numerator * _denominator;
            _denominator *= other._denominator;
            return Reduce();
        }

        public Fraction Add(int number) => Add(new Fraction(number));

        public Fraction Subtract(Fraction other)
        {
            Numerator = Numerator * other._denominator - other.Numerator * _denominator;
            _denominator *= other._denominator;
            return Reduce();
        }

        public Fraction Multiply(Fraction other)
        {
            Numerator *= other.Numerator;
            _denominator *= other._denominator;
            return Reduce();
        }

        public Fraction Multiply(int number) => Multiply(new Fraction(number));

        public Fraction Divide(Fraction other)
        {
            if (other.Numerator == 0) throw new DivideByZeroException();

            Numerator *= other._denominator;
            _denominator *= other.Numerator;
            
            return Reduce();
        }

        public bool Equals(Fraction other)
        {
            Fraction f1 = new Fraction(Numerator, _denominator).Reduce();
            Fraction f2 = new Fraction(other.Numerator, other._denominator).Reduce();
            return f1.Numerator == f2.Numerator && f1._denominator == f2._denominator;
        }

        public override string ToString() => $"{Numerator}/{_denominator}";
    }
}
