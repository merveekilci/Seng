using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace INTERFACE
{
    public interface IEnumerator
    {
        bool MoveNext(); 
        object Current { get; }
        void Reset();
    }


    public interface IsimpleInterface
    {
        double X { set; get; }
        double Y { set; get; }

        void printData();
    }

    public class derivedClass : IsimpleInterface
    {
        private double mX;
        private double mY;

        public double X { set => mX = value; get => mX; }
        public double Y { set => mY = value; get => mY; }

        public void printData()
        {
            double result = Math.Sqrt(mX * mX + mY * mY);
            Console.WriteLine("Result : " + result);
        }

        public double calculateData() { return 0; }
    }
}
