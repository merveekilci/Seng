
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CLASSES
{
    class Complex
    {
        private float mReal;
        private float mImaginary;

        public float real
        {
            set
            {
                mReal = value;
            }
            get
            {
                return mReal;
            }
        }

        public float imaginary
        {
            set
            {
                mImaginary = value;
            }
            get
            {
                return mImaginary;
            }
        }

        public Complex()
        {
        }

        public Complex(float real, float imaginary)
        {
            mReal = real;
            mImaginary = imaginary;
        }

        private float calculateMagnitude()
        {
            float m = (float)(mReal * mReal + mImaginary * mImaginary);
            return (float)(Math.Sqrt(m));
        }

        public void calculateLength(Complex complex2)
        {
            float result = (float)(Math.Pow((this.mReal - complex2.mReal), 2) + Math.Pow((this.mImaginary - complex2.mImaginary), 2));
            result = (float)(Math.Sqrt(result));

            string n1 = mReal + "+" + mImaginary + "i";
            string n2 = complex2.mReal + "+" + complex2.mImaginary + "i";

            Console.WriteLine("Length between " + n1 + " and " + n2 + " is " + result);
        }

        public void printComplexNumber()
        {
            Console.WriteLine(mReal + "+" + mImaginary + "i");
        }

        public void printMagnitude()
        {
            string number = mReal + "+" + mImaginary + "i";
            Console.WriteLine("Magnitude of " + number + " is " + calculateMagnitude());
        }


    }
}
