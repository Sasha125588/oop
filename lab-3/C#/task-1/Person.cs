namespace Task1
{
    public class Person
    {
        public string Name { get; set; }
        public string Address { get; set; }

        private int _age;
        public int Age
        {
            get => _age;
            set
            {
                if (value < 0)
                    throw new ArgumentException("Age cannot be less than 0");
                _age = value;
            }
        }
        public string PhoneNumber { get; set; }

        public Person()
        {
            Name = string.Empty;
            Address = string.Empty;
            Age = 0;
            PhoneNumber = string.Empty;
        }

        public Person(string personName)
        {
            Name = personName;
            Address = string.Empty;
            Age = 0;
            PhoneNumber = string.Empty;
        }

        public Person(Person other)
        {
            Name = other.Name;
            Address = other.Address;
            Age = other.Age;
            PhoneNumber = other.PhoneNumber;
        }

        ~Person()
        {
            Console.WriteLine($"Person {Name} destructor");
        }
    }
}
