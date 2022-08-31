using System;

namespace casting
{
    class Program
    {
        static void Main(string[] args)
        {
            BaseClass       baseObject1 = new BaseClass();
            DerivedClass    derivedObject1 = new DerivedClass();

            baseObject1.mBaseClassMember = 10;
            
            derivedObject1.mDerivedClassMember = 20;
            derivedObject1.mBaseClassMember = 30;

            baseObject1.printBaseClassMember();
            derivedObject1.printDerivedClassMember();

            
            BaseClass baseObject2 = derivedObject1;     // upcasting
            
            baseObject2.printBaseClassMember();

            baseObject2.mBaseClassMember = 40;

            derivedObject1.printDerivedClassMember();

            //derivedObject1 = (DerivedClass)baseObject1;          // downcast



        }
    }
}
