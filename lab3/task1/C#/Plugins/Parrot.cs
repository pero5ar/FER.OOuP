namespace MyFactory.Plugins
{
    public class Parrot : Animal
    {
        public override string Greeting { get ; set; } = "Sto mu gromova!";
        public override string Menu { get; set; } = "brazilske orahe";

        public Parrot(string name) : base(name) {}
    }
}