using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace casting2
{
    public class Person
    {
        public string name;
        public DateTime birth;
        
        public void writeToConsole()
        {
            Console.WriteLine(name + " was born on " + birth.ToString());   
        }

        public virtual void printInformation()
        {
            
        }
    }

    public class Employee:Person
    {
        public DateTime hired;
        public string ID;

        // create a new 'writeToConsole' method with the 'new keyword'
        public new void writeToConsole()
        {
            Console.WriteLine(name + " was born on " + birth.ToString() +
                " and hired on " + hired.ToString());
        }

        // override the base class's 'printInformation' method
        public override void printInformation()
        {
            Console.WriteLine(name + "'s code is " + ID);
        }
    }

    public class Manager:Employee
    {
        public new void writeToConsole()
        {
            Console.WriteLine(name + " is a MANAGER");
            Console.WriteLine(name + " was born on " + birth.ToString() +
                " and hired on " + hired.ToString());
        }

        public override void printInformation()
        {
            Console.WriteLine(name + "'s code is " + ID);
        }
    }
}
