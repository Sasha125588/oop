using System;
using Task1;
using Xunit;

namespace Task1.Tests
{
    public class PersonTests
    {
        [Fact]
        public void DefaultConstructor_ShouldInitializeWithDefaultValues()
        {
            // Act
            var person = new Person();

            // Assert
            Assert.Equal(string.Empty, person.Name);
            Assert.Equal(string.Empty, person.Address);
            Assert.Equal(0, person.Age);
            Assert.Equal(string.Empty, person.PhoneNumber);
        }

        [Fact]
        public void Constructor_WithName_ShouldSetNameAndDefaultOthers()
        {
            // Arrange
            string name = "Alice";

            // Act
            var person = new Person(name);

            // Assert
            Assert.Equal("Alice", person.Name);
            Assert.Equal(string.Empty, person.Address);
            Assert.Equal(0, person.Age);
            Assert.Equal(string.Empty, person.PhoneNumber);
        }

        [Fact]
        public void CopyConstructor_ShouldCopyAllFields()
        {
            // Arrange
            var original = new Person
            {
                Name = "Bob",
                Address = "123 Street",
                Age = 25,
                PhoneNumber = "555-1234",
            };

            // Act
            var copy = new Person(original);

            // Assert
            Assert.Equal(original.Name, copy.Name);
            Assert.Equal(original.Address, copy.Address);
            Assert.Equal(original.Age, copy.Age);
            Assert.Equal(original.PhoneNumber, copy.PhoneNumber);

            // Изменяем оригинал — копия не должна измениться
            original.Name = "Changed";
            Assert.NotEqual(original.Name, copy.Name);
        }

        [Fact]
        public void Age_SetNegativeValue_ShouldThrowArgumentException()
        {
            // Arrange
            var person = new Person();

            // Act & Assert
            var ex = Assert.Throws<ArgumentException>(() => person.Age = -5);
            Assert.Equal("Age cannot be less than 0", ex.Message);
        }

        [Fact]
        public void Age_SetValidValue_ShouldUpdateAge()
        {
            // Arrange
            var person = new Person();

            // Act
            person.Age = 30;

            // Assert
            Assert.Equal(30, person.Age);
        }

        [Fact]
        public void Properties_ShouldBeGetAndSetProperly()
        {
            // Arrange
            var person = new Person();

            // Act
            person.Name = "Charlie";
            person.Address = "Kyiv, Ukraine";
            person.Age = 40;
            person.PhoneNumber = "+380501234567";

            // Assert
            Assert.Equal("Charlie", person.Name);
            Assert.Equal("Kyiv, Ukraine", person.Address);
            Assert.Equal(40, person.Age);
            Assert.Equal("+380501234567", person.PhoneNumber);
        }
    }
}
