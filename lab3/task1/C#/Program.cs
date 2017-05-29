using System;

namespace MyFactory
{
    class Program
    {
        static void Main(string[] args)
        {
            var parrot = AnimalFactory.NewInstance("Parrot", "Modrobradi");
            var tiger = AnimalFactory.NewInstance("Tiger", "Straško");

            parrot?.AnimalPrintGreeting();
            tiger?.AnimalPrintGreeting();

            parrot?.AnimalPrintMenu();
            tiger?.AnimalPrintMenu();
        }
    }
}
