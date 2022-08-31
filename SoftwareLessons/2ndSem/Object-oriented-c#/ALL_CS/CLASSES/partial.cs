using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CLASSES
{
    partial class simpleClass
    {
        private int mAge;

        /*public int age                   
        {
            get => mAge; 
            set { if (value > 0) mAge = value; else mAge = 0; }
        }*/

        public int age                   // property 
        {
            get { return mAge; }
            set { if (value > 0) mAge = value; else mAge = 0; }
        }

        // constructor with no parameter - default constructor
        public simpleClass()
        {
            mAge = 0;
        }

        public simpleClass(int _age)    // constructor with one parameter
        {
            mAge = _age;
        }

        ~simpleClass()
        {
            Console.WriteLine("Destructor is called...");
        }
    }
}
