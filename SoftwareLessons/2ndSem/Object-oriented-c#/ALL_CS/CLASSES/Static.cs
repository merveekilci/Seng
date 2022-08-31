using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CLASSES
{
    class staticClass
    {
        private int mAge = 0;

        static public int count;

        static public int getCount()
        {
            return count;
        }

        public staticClass()
        {
            count++;
        }
        public int age
        {
            set
            {
                if (age > 0) mAge = age;
            }
            get
            {
                return mAge;
            }
        }
    }
}
