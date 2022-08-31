using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace inheritance
{
    public class BaseClass
    {
        public int baseNumber;
        protected int test;

        public BaseClass()
        {
            this.baseNumber = 0;
        }

        public BaseClass(int baseNumber)
        {
            this.baseNumber = baseNumber;
        }

        public void printBaseClassNumber()
        {
            Console.WriteLine("Value of Base Class Number is " + baseNumber);
        }
    }

    public class DerivedClass : BaseClass
    {
        public int derivedNumber;

        public DerivedClass(int derivedNumber)
        {
            this.derivedNumber = derivedNumber;
        }

        public DerivedClass()
        {
            this.derivedNumber = 0;
        }

        //overridden function
        new public void printBaseClassNumber()
        {
            Console.WriteLine("Runs Derived Class Function");
            Console.WriteLine("Value of Base Class Number is " + baseNumber);
        }

        public void printDerivedClassNumber()
        {
            Console.WriteLine("Value of Base Class Number is " + derivedNumber);
        }

        public void increaseBaseClassNumber()
        {
            baseNumber++;
            test = 30;
        }
    }
}
