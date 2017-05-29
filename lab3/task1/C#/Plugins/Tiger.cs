namespace MyFactory.Plugins
{
    public class Tiger : Animal
    {
        public override string Greeting { get ; set; } = "Mijau!";
        public override string Menu { get; set; } = "mlako mlijeko";

        public Tiger(string name) : base(name) {}
    }
}