using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace week8
{
    class A {
        private string name = "A";
        public void printA()
        {
            Console.WriteLine("value of name is " + this.name);
        }
    }

    class B {
        private string name = "B";
        public void printB()
        {
            Console.WriteLine("value of name is " + this.name);
        }
    }

    class C {
        public void printA()
        {
            A newA = new A();
            newA.printA();

        }

        public void printB()
        {
            B newB = new B();
            newB.printB();
        }


    }
}
