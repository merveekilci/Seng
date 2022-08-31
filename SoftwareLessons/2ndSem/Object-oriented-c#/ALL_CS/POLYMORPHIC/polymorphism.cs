using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace polymorphic
{

    public abstract class BaseClass
    {
        public abstract void printName();
    }

    public class A:BaseClass
    {
        private string name = "A";

        public override void printName()
        {
            Console.WriteLine("The value of name is " + name);    
        }
    }

    public class B:BaseClass
    {
        private string name = "B";

        public override void printName()
        {
            Console.WriteLine("The value of name is " + name);
            Console.WriteLine("We did this to show the difference " +
                              "between polymorphic and non-polymorphic approaches");
        }
    }

    public class C{
        public void printValue(BaseClass baseObject)
        {
            baseObject.printName();
        }
    }


}
