using System;

namespace Abstract
{
    public abstract class TwoDimPoint
    {
        protected int mX;
        protected int mY;

        public int X { set; get; }
        public int Y { set; get; }

        public void test()
        {
            Console.WriteLine("This is a test method...");
        }

        public abstract void printCoordinates();
    }

    public class Point : TwoDimPoint
    {
        public Point()
        {
            mX = 0;
            mY = 0;
        }

        public Point(int _X, int _Y)
        {
            mX = _X;
            mY = _Y;
        }

        public int X { set { mX = value; } get { return mX; } }
        public int Y { set { mY = value; } get { return mY; } }

        public override void printCoordinates()
        {
            Console.WriteLine("The point is (" + mX + "," + mY + ")");
        }
    }
	
	class Program
    {
        static void Main(string[] args)
        {
            //Console.WriteLine("Hello World!");
            Point p = new Point(3,4);
            p.test();
            p.printCoordinates();

        }
    }
}
