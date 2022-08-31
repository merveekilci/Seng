using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace INTERFACE
{
    public  abstract class abstractClass
    {
        private double mX;
        private double mY;

        public double X { set => mX = value; get => mX; }
        public double Y { set => mY = value; get => mY; }

        // it has not body, because it is abstract
        public abstract void printData(); 
    }

    public class derivedfromAbstractClass:abstractClass
    {
        public override void printData()
        {
            Console.WriteLine("X: " + X);
            Console.WriteLine("X: " + Y);
        }
    }
}
