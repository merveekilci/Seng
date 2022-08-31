using System;

namespace polymorphic
{
    class Program
    {
        static void Main(string[] args)
        {
            C objectC = new C();
            objectC.printValue(new A());        // upcasting
            objectC.printValue(new B());        // upcasting

            //A objectA = new A();
            //BaseClass base1 = new A();          // upcasting


        }
    }
}
