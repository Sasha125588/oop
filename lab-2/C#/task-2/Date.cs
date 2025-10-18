namespace Task2
{
    public class Date
    {
        private static readonly string[] MonthNames =
        [
            "січня",
            "лютого",
            "березня",
            "квітня",
            "травня",
            "червня",
            "липня",
            "серпня",
            "вересня",
            "жовтня",
            "листопада",
            "грудня",
        ];

        private int _day = 1;
        public int Day
        {
            get => _day;
            private set
            {
                int maxDays = GetDaysInMonth(_month, Year);
                if (value <= 0 || value > maxDays)
                    throw new ArgumentOutOfRangeException(
                        nameof(Day),
                        $"День має бути від 1 до {maxDays} для місяця {_month}"
                    );
                _day = value;
            }
        }

        private int _month = 1;
        public int Month
        {
            get => _month;
            private set
            {
                if (value < 1 || value > 12)
                    throw new ArgumentOutOfRangeException(
                        nameof(Month),
                        "Місяць має бути від 1 до 12"
                    );
                _month = value;
            }
        }

        public int Year { get; private set; }

        public void SetDate(int day, int month, int year)
        {
            Year = year;
            Month = month;
            Day = day;
        }

        private static bool IsLeapYear(int year) =>
            (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

        private static int GetDaysInMonth(int month, int year)
        {
            return month switch
            {
                2 => IsLeapYear(year) ? 29 : 28,
                4 or 6 or 9 or 11 => 30,
                _ => 31,
            };
        }

        public string ToShortDateString() => $"{Day:D2}/{Month:D2}/{Year}";

        public string ToLongDateString() => $"{Day} {MonthNames[Month - 1]}, {Year}";

        public string ToShortMonthDateString() => $"{Day} {MonthNames[Month - 1][..3]} {Year}";

        public override string ToString() => ToShortDateString();
    }
}
