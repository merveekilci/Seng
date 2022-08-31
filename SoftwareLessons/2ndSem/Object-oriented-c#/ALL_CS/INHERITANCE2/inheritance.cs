using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace inheritance2
{
    /*public class baseClass
    {
        public int mNumber;
        public virtual void printNumber()
        {
            Console.WriteLine("Base Class Number : " + mNumber);
        }
    }

    public class derivedClass:baseClass
    {
        public new int mNumber;
        public override void printNumber()
        {
            Console.WriteLine("Base Class Number : " + base.mNumber);
            Console.WriteLine("Derived Class Number : " + mNumber);
        }
    }*/

    /*public class secondderivedClass : derivedClass
    {
        public new int mNumber;
        public new void printNumber()
        {
            Console.WriteLine("Base Class Number : " + base.mNumber);
            Console.WriteLine("Derived Class Number : " + mNumber);
        }
    }*/

    public class baseClass
    {
        public int mBaseNumber;
        public void printBaseNumber()
        {
            Console.WriteLine("Base Class Number : " + mBaseNumber);
        }
    }
    public class derivedClass : baseClass
    {
        public int mDerivedNumber;
        public void printDerivedNumber()
        {
            Console.WriteLine("Derived Class Number : " + mDerivedNumber);
        }
    }

    public class secondderivedClass : baseClass
    {
        public int mDerivedNumber;
        public void printDerivedNumber()
        {
            Console.WriteLine("Derived Class Number : " + mDerivedNumber);
        }
    }


    public abstract class abstractClass
    {
        // Note empty implementation
        public abstract decimal mValue { get; }
    }
}
