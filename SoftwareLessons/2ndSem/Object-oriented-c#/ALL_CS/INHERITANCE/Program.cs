using System;

namespace inheritance
{
    class Program
    {
        static void Main(string[] args)
        {
            BaseClass base1 = new BaseClass();
            base1.baseNumber = 20;
            base1.printBaseClassNumber();

            DerivedClass derived1 = new DerivedClass();
            derived1.baseNumber = 30;
            derived1.printBaseClassNumber();
            derived1.increaseBaseClassNumber();

            base1.printBaseClassNumber();
            derived1.printBaseClassNumber();

        }
    }
}
