using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace casting
{
    public class BaseClass
    {
        public int mBaseClassMember;
        public void printBaseClassMember()
        {
            Console.WriteLine("The Base Class Number is " + mBaseClassMember);
            Console.WriteLine("-------------------------------------------");
        }
    }

    public class DerivedClass:BaseClass
    {
        public int mDerivedClassMember;
        public void printDerivedClassMember()
        {
            Console.WriteLine("The Derived Class Number is " + mDerivedClassMember);
            Console.WriteLine("The Base Class Number is " + mBaseClassMember);
            Console.WriteLine("-------------------------------------------");
        }
    }
}
