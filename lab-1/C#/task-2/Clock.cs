namespace Task1
{
    public class Clock
    {
        public int Hours { get; private set; } = 15;
        public int Minutes { get; private set; } = 59;

        public bool AlarmEnabled { get; set; }
        public int AlarmHours { get; private set; }
        public int AlarmMinutes { get; private set; }

        public void SetTime(int hours, int minutes)
        {
            CheckTimeFormat(hours, minutes);

            Hours = hours;
            Minutes = minutes;
        }

        public void SetAlarm(int hours, int minutes)
        {
            CheckTimeFormat(hours, minutes);

            AlarmHours = hours;
            AlarmMinutes = minutes;
            AlarmEnabled = true;
        }

        public string Get24HourFormat()
        {
            return $"{Hours:D2}:{Minutes:D2}";
        }

        public string Get12HourFormat()
        {
            int displayHours = Hours % 12;
            if (displayHours == 0)
                displayHours = 12;
            string period = Hours < 12 ? "AM" : "PM";
            return $"{displayHours:D2}:{Minutes:D2} {period}";
        }

        public void AddMinute()
        {
            Minutes++;
            if (Minutes == 60)
            {
                Minutes = 0;
                Hours = (Hours + 1) % 24;
            }

            if (AlarmEnabled && Hours == AlarmHours && Minutes == AlarmMinutes)
            {
                Console.WriteLine("ALARM!");
            }
        }

        private static void CheckTimeFormat(int hours, int minutes)
        {
            if (hours < 0 || hours > 23)
                throw new ArgumentOutOfRangeException(
                    nameof(hours),
                    "Hours must be between 0 and 23"
                );
            if (minutes < 0 || minutes > 59)
                throw new ArgumentOutOfRangeException(
                    nameof(minutes),
                    "Minutes must be between 0 and 59"
                );
        }
    }
}
