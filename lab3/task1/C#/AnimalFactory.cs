using System;

namespace MyFactory
{
    public static class AnimalFactory
    {
        public static Animal NewInstance(string animalKind, string name)
        {
            var type = Type.GetType("MyFactory.Plugins." + animalKind);
            return Activator.CreateInstance(type, name) as Animal;
        }
    }
}