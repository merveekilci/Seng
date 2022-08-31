using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace week10
{
    class Operation
    {
        private int mNumber1;
        private int mNumber2;
        private char mOperation;

        public int number1 { set => mNumber1 = value; get => mNumber1; }
        public int number2 { set => mNumber2 = value; get => mNumber2; }
        public char operation { set => mOperation = value; get => mOperation; }

        public Operation()
        { }

        public Operation(int _number1, int _number2, char _operation)
        {
            mNumber1 = _number1;
            mNumber2 = _number2;
            mOperation = _operation;
        }


        private dynamic calculate()
        {
            dynamic result = 0;

            if (mOperation == '+') result = mNumber1 + mNumber2;
            else if (mOperation == '-') result = mNumber1 - mNumber2;
            else if (mOperation == '*') result = mNumber1 * mNumber2;
            else if (mOperation == '/')
            {
                try
                {
                    result =(float)(mNumber1) / mNumber2;
                }
                catch (DivideByZeroException ex)
                {
                    //result = ex.Message;
                    result = "A number can not be divided by zero!...";
                }
            }
            else result = null;
            
            return result;
        }

        public void printResult()
        {
            dynamic result = calculate();
            if (result!= null)
            {
                Console.WriteLine(mNumber1 + " " + mOperation + " " + mNumber2 + " = " + result);
            }

        }
    }
}
