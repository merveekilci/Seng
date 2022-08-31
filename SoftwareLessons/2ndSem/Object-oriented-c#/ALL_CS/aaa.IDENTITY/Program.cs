using System;

namespace _identity
{
    class Program
    {
        static void Main(string[] args)
        {
            Identity tc1 = new Identity(12345678950);
            tc1.printCheckedNumber();
        }
    }
}
