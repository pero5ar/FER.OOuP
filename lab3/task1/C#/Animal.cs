using System;

namespace MyFactory
{
    public abstract class Animal
    {
        public string Name { get; set; }
        public abstract string Greeting {get; set; }
        public abstract string Menu { get; set; }

        public Animal(string name)
        {
            Name = name;
        }
        public void AnimalPrintGreeting()
        {
            Console.WriteLine($"{Name} pozdravlja: {Greeting}");
        }

        public void AnimalPrintMenu()
        {
            Console.WriteLine($"{Name} voli {Menu}.");
        }
    }
}