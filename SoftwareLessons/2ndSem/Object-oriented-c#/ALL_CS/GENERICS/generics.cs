using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace generics
{
    // example class with generics
    public class genericsCollection<T>
    {
        private T[] mArray = new T[5];
        public T this[int index] { set => mArray[index] = value; get => mArray[index]; }
       
        public genericsCollection(){ mArray = new T[3]; }
        public genericsCollection(int length){ mArray = new T[length]; }

        private T[] reverseOrder()
        {
            int len = mArray.Length;

            T[] returnArray = new T[len];

            for (int i = 0; i < len; i++) returnArray[i] = mArray[len-i];

            return returnArray;
        }
    }

    // example class without generics
    public class nonGenericCollection
    {
        private int[] mArray = new int[5];
        public int this[int index] { set => mArray[index] = value; get => mArray[index]; }
            
        public nonGenericCollection(){mArray = new int[3];}
        public nonGenericCollection(int length){mArray = new int[length];}
        
        private int[] reverseOrder()
        {
            int len = mArray.Length;

            int[] returnArray = new int[len];

            for (int i = 0; i < len; i++)   returnArray[i] = mArray[len - i];

            return returnArray;
        }
    }
    
    // We use < > to specify Parameter type
    // The IComparable is implemented by types whose values can be ordered or sorted.
    // The interface requires the CompareTo method to be implemented
    // Generic Constraints
    // where T:IComparable
    public class genericsClass<T> where T:IComparable
    {
        private T mData = default(T);  // default - default value of generic type                                      // private data members
        public T data { set => mData = value; get => mData; } // using properties

        // generic indexer
        private T[] mList;
        public T this[int index] 
        {
            get {
                if (index < 0 && index >= mList.Length)
                    throw new IndexOutOfRangeException("Index out of range...");

                return mList[index];
            }
            set {
                if (index < 0 || index >= mList.Length)
                    throw new IndexOutOfRangeException("Index out of range");

                mList[index] = value;
            }
        }

        public genericsClass()
        {
            mList = new T[5];
        }

        public genericsClass(int length)
        {
            mList = new T[length];
        }

        static public void Swap(ref T a, ref T b)
        {
            T temp = a; 
            a = b; 
            b = temp;
        }

        public void printData() 
        {
            Console.Write(this.GetType().Name + " object is " + mData.GetType());
            Console.WriteLine(" and its value is " + "\"" + mData + "\"");
        }

        public void printList()
        {
            Console.Write(this.GetType().Name + " list is " + mData.GetType());
            Console.WriteLine(" and its value is as follows");
            
            foreach (T element in mList)
                Console.WriteLine(element);
        }
    }
    
}
