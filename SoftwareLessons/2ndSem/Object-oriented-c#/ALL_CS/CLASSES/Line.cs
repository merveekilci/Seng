using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CLASSES
{
    public class Point
    {
        public int x { set; get; }
        public int y { set; get; }
        //public int color { set; }

        public Point()
        {

        }

        public Point(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }

    public class Line
    {
        public Point begin;
        public Point end;
        public int color;

        public Line()
        {
        }

        public Line(Point begin, Point end)
        {
            this.begin = begin;
            this.end = end;
        }

        private int calculate(out double xDiff, out double yDiff)
        {
            int deltaX = Math.Abs(begin.x - end.x);
            int deltaY = Math.Abs(begin.y - end.y);

            int numberOfPixels = 0;

            if (deltaX > deltaY)
                numberOfPixels = deltaX;
            else
                numberOfPixels = deltaY;

            xDiff = (double)deltaX / (double)numberOfPixels;
            yDiff = (double)deltaY / (double)numberOfPixels;

            return numberOfPixels;
        }

        public void writeCoordinates()
        {
            double coordX = begin.x;
            double coordY = begin.y;

            double xDiff_ = 0;
            double yDiff_ = 0;

            int count = calculate(out xDiff_, out yDiff_);

            // diğer for 'a da bak
            for (int i = 0; i < count; i++)
            {
                coordX = coordX + xDiff_;
                coordY = coordY + yDiff_;

                Console.Write("(" + Math.Round(coordX) + "," + Math.Round(coordY) + ")");
                Console.WriteLine();
            }
        }

        public void drawCoordinates(char ch)
        {
            double coordX = begin.x;
            double coordY = begin.y;

            double xDiff_ = 0;
            double yDiff_ = 0;

            int count = calculate(out xDiff_, out yDiff_);

            // diğer for 'a da bak
            for (int i = 0; i < count; i++)
            {
                coordX = coordX + xDiff_;
                coordY = coordY + yDiff_;

                Console.CursorTop = (int)(Math.Round(coordX));
                Console.CursorLeft = (int)(Math.Round(coordY));

                Console.Write(ch);


                //Console.Write("(" + Math.Round(coordX) + "," + Math.Round(coordY) + ")");
                //Console.WriteLine();
            }
        }

        private double calcLength()
        {
            double diffX = Math.Abs(begin.x - end.x);
            double diffY = Math.Abs(begin.y - end.y);
            double l = Math.Sqrt((diffX * diffX) + (diffY * diffY));
            return l;
        }

        public void writeLength()
        {
            Console.WriteLine("Length of line : " + calcLength());
        }

    }

    /*class Rectangle
    {
        public Point topLeft { set; get; }
        public int width { set; get; }
        public int height { set; get; }
        //public int color;

        public Rectangle()
        {
        }

        public Rectangle(Point _topLeft, int _width, int _height)
        {
            topLeft = _topLeft;
            width = _width;
            height = _height;
        }

        public void draw() {
            Console.CursorTop = topLeft.x;
            Console.CursorLeft = topLeft.y;
            Console.ForegroundColor = ConsoleColor.Red;


            string s = "";
            
            for (int i = 0; i < width; i++)
                s += "*";
            

            Console.Write(s);

            Console.WriteLine();

            

            string temp = "";
            for (int i = 0; i < height; i++) {
                Console.CursorLeft = topLeft.y;
                temp = "*";
                for (int j = 1; j < width-1; j++)
                    temp += " ";
                temp += "*";
                Console.Write(temp);
                Console.WriteLine();
            }

            Console.CursorLeft = topLeft.y;
            s = "";
            for (int i = 0; i < width; i++)
                s += "*";
            Console.Write(s);

            Console.WriteLine();






        }
    } */

}
