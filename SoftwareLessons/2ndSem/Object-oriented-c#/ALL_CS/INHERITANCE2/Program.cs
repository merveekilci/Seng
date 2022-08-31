using System;

namespace inheritance2
{
    class Program
    {
        static void Main(string[] args)
        {
            /*baseClass base1 = new baseClass { mBaseNumber = 0 };
            base1.printBaseNumber();

            derivedClass derived1 = new derivedClass { mDerivedNumber = 0 };
            derived1.printDerivedNumber();*/

            //baseClass base1 = new baseClass { mNumber= 0 };
            //base1.printNumber();

            //derivedClass derived1 = new derivedClass { mNumber = 0 };
            //derived1.printNumber();

            /*derivedClass derivedObj = new derivedClass();
            baseClass baseObj = derivedObj;

            derivedObj.mBaseNumber = 20;        // OK!
            derivedObj.mDerivedNumber = 40;     // OK!

            baseObj.mBaseNumber = 20;           // OK!
            baseObj.mDerivedNumber = 40;        // compile-time error*/


            /*derivedClass cast = new derivedClass(); 
            baseClass baseObj = cast;                           // Upcast
            derivedClass derivedObj = (derivedClass)baseObj;    // Downcast

            Console.WriteLine (derivedObj.mDerivedNumber);      // OK!
            Console.WriteLine ( derivedObj== baseObj);          // TRUE!
            Console.WriteLine (derivedObj == cast);             // TRUE!*/

            //secondderivedClass cast = new secondderivedClass();
            //baseClass baseObj = cast;                               // Upcast always succeeds
            //derivedClass derivedObj = (derivedClass)baseObj;        // Downcast fails: baseObj is not a derivedClass object

            baseClass baseObj = new baseClass();
            derivedClass derivedObj = baseObj as derivedClass;  // derivedObj is null;
                                                                // no exception thrown

            if (derivedObj != null) Console.WriteLine(derivedObj.mDerivedNumber);

            if (baseObj is derivedClass)
                Console.Write(((derivedClass)baseObj).mDerivedNumber);

        }
    }
}
