using System;
using System.Collections;           // for array list
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CLASSES
{
    // 1- 999 number
    class Number
    {
        private int mValue;

        public int value { set; get; } = 0;

        /*public int value
        {
            set
            {
                if ((value > 1) & (value < 999))
                    mValue = value;
                else
                    mValue = 1;
            }
        }*/

        public Number()
        { }

        public Number(int value)
        {
            if ((value > 1) & (value < 999))
                mValue = value;
            else
                mValue = 1;
        }
        private ArrayList dividers;


        // calculate whether the value is prime or not
        private bool isPrime()
        {
            bool prime = true;

            for (int i = 2; i < mValue; i++)
                // if the number is divided between 2 and itself, 
                // it is not a prime number 
                if ((mValue % i) == 0)
                {
                    prime = false;
                    break;
                }
            return prime;
        }

        public void printIsPrime()
        {
            if (isPrime())
                Console.WriteLine(mValue + " is a prime number");
            else
                Console.WriteLine(mValue + " is not a prime number");

        }

        public string convertToWords()
        {
            // String is the same (System.String)
            // int is System.Int32
            string[] units = { "Zero", "One", "Two", "Three",
                                            "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
                                            "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                                            "Seventeen", "Eighteen", "Nineteen" };
            string[] ones = { "Zero","One", "Two", "Three",
                              "Four", "Five", "Six", 
                              "Seven", "Eight", "Nine" };
            
            string[] twos = { "Ten","Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", 
                              "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
            
            
            string[] tens = { "", "", "Twenty", "Thirty", "Forty",
            "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

            int i = mValue;

            if (i < 10)
                return ones[i];
            else if (i < 20)
                return twos[i%10];
            else if (i < 100)
                //return tens[i / 10] + ((i % 10 > 0) ? " " + convertToWords(i % 10) : "");
                return tens[i / 10] + ((i % 10 > 0) ? " " + ones[i % 10] : "");
            else //(i < 1000)
            {
                string st = units[i / 100] + " Hundred";

                if ((i % 100) > 0)
                {
                    i = i % 100;
                    st = st + " and " + tens[i/10] + ((i % 10 > 0) ? " " + ones[i % 10] : "");
                }
                return st;


                //return units[i / 100] + " Hundred"
                //        + ((i % 100 > 0) ? " And " + convertToWords(i % 100) : "");
            }
        }

        public void calcDividers()
        {
            dividers = new ArrayList();

            for (int i = 2; i <= mValue; i++)
                if ((mValue % i) == 0)
                    dividers.Add(i);
        }

        public void printDividers()
        {
            calcDividers();

            foreach (int i in dividers)
                Console.Write(i + " ");
        }
    }
}
