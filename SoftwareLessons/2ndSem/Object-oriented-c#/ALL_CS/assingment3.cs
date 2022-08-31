using System;

namespace Assignment_3
{

    class Point3D
    {
        // Point3D fields
        private int mX;
        private int mY;
        private int mZ;

        // Point3D access modifiers
        public int x { set => mX = value; get => mX; }
        public int y { set => mY = value; get => mY; }
        public int z { set => mZ = value; get => mZ; }

        // Define a constructor that assigns x, y and z values
        public Point3D(int x, int y, int z) { mX = x; mY = y; mZ = z; }

        //Define a constructor with no parameters and sets all x, y and z to random values
        public Point3D()
        {
            Random random = new Random();
            x = random.Next(11);            // sets a values between [1-10]
            y = random.Next(11);
            z = random.Next(11);
        }

        //Define a printCoordinates() method that pirint the coordinates of the 3D point
        public void printCoordinates()
        {
            Console.WriteLine("Coordinates of point : (" + mX + "," + mY + "," + mZ + ")");
        }

        //Define a calculateSphericalCoordinates() method that calculates
        //spherical coordinates(p(ρ, φ, θ)) of this 3D point according to the formula below:
        public void calculateSphericalCoordinates(out double ro, out double phi, out double theta)
        {
            double x2 = Math.Pow(mX, 2);
            double y2 = Math.Pow(mY, 2);
            double z2 = Math.Pow(mZ, 2);

            double r = Math.Sqrt(x2 + y2);
            ro = Math.Sqrt( x2+y2+z2);

            phi = Math.Asin(r / ro);
            phi= phi * 180 / Math.PI;

            theta = Math.Asin(y/r);
            theta = theta * 180 / Math.PI;
        }

        //Define a printSphericalCoordinates() method that prints the pre-calculated spherical coordinates of this 3D point.
        public void printSphericalCoordinates()
        {
            Console.WriteLine("Spherical Coordinates of point : ");
            calculateSphericalCoordinates(out double ro, out double phi, out double theta);

            Console.WriteLine("ro : " + ro.ToString("#.##"));
            Console.WriteLine("phi : " + phi.ToString("#.##"));
            Console.WriteLine("theta : " + theta.ToString("#.##"));
        }

        //Define a calculateDistance() method that calculates the distance between this point with a given point
        private double calculateDistance(Point3D point2)
        {
            double x2 = Math.Pow((mX - point2.x), 2);
            double y2 = Math.Pow((mY - point2.y), 2);
            double z2 = Math.Pow((mZ - point2.z), 2);
           
            return Math.Sqrt(x2 + y2 + z2);
        }

        //Define a printDistance() method that prints the pre-calculated distance
        //between this point with a given point
        public void printDistance(Point3D point2)
        {
            double distance = calculateDistance(point2);
            Console.WriteLine("Distance between points : " + distance.ToString("#.##"));
        }
    }

    class Sphere
    {
        const double PI = 3.14;

        // Sphere fields
        private Point3D mCenter;
        private int mRadius;

        // Sphere access modifiers
        public Point3D center { set => mCenter = value; get => mCenter; }
        int radius { set => mRadius = radius; get => mRadius; }

        //Define a constructor 
        public Sphere(Point3D center, int radius)
        {
            mCenter = new Point3D();

            mCenter = center;
            mRadius = radius;
        }

        //Define a constructor setting inital center and radius with random values
        public Sphere()
        {
            // to prevent from the following error
            // System.NullReferenceException: 'Object reference not set to an instance of an object.'
            mCenter = new Point3D();

            Random random = new Random();
            mRadius = random.Next(10);

            center.x = random.Next(11);
            center.y = random.Next(11);
            center.z = random.Next(11);
        }

        //Define a calcVolume() method that calculates the volume of this sphere


        public void printInformation()
        {
            Console.WriteLine("Center Point Coordinates : (" + mCenter.x + "," + mCenter.y + "," + mCenter.z + ")");
            Console.WriteLine("Radius                   : " + mRadius);
        }

        private double calculateVolume()
        {
            return (4 / 3) * Math.PI * Math.Pow(mRadius, 3);
        }

        //Define a printVolume() method that prints the pre-calculated volume of this sphere
        public void PrintVolume()
        {
            double volume = calculateVolume();
            Console.WriteLine("Volume of Sphere : " + volume.ToString("#.##"));
        }

        //Define a isPointInSphere() method that calculated
        //whether an input point is in this sphere or not, and returns the result

        private bool isPointInSphere(Point3D point)
        {
            double x2 = Math.Pow( (mCenter.x - point.x),2);
            double y2 = Math.Pow( (mCenter.y - point.y), 2);
            double z2 = Math.Pow( (mCenter.z - point.z), 2);
            
            double result = Math.Sqrt( x2 + y2 + z2);

            if (result < (mRadius * mRadius))
                return true;
            else
                return false;
        }

        //Define a printIsPointInSphere() method that prints the pre-calculated result of
        //whether a given point is in sphere or not
        public void printIsPointInSphere(Point3D point)
        {
            if (isPointInSphere(point))
                Console.WriteLine("The point is in sphere");
            else
                Console.WriteLine("The point is not in sphere");
        }

        //Define a isColliding() method that calculates whether the sphere collides with a given sphere
        private bool isColliding(Sphere sphere)
        {
            double x2 = (mCenter.x - sphere.center.x) * (mCenter.x - sphere.center.x);
            double y2 = (mCenter.y - sphere.center.y) * (mCenter.y - sphere.center.y);
            double z2 = (mCenter.z - sphere.center.z) * (mCenter.z - sphere.center.z);

            double distance = Math.Sqrt(x2 + y2 + z2);

            return distance < (mRadius + sphere.radius);
        }


        //Define a pringIsColling() method that prints the pre-calculated result of
        //whether the sphere collides with a given sphere.
        public void printIsColliding(Sphere sphere)
        {
            if (isColliding(sphere))
                Console.WriteLine("Spheres are colliding...");
            else
                Console.WriteLine("Spheres are not colliding...");
        }


    }

    class Program
    {
        static void Main(string[] args)
        {
            Point3D point1 = new Point3D();
            Point3D point2 = new Point3D(1, 1, 1);

            Console.Write(nameof(point1) + "=> ");
            point1.printCoordinates();

            Console.Write(nameof(point2) + "=> ");
            point2.printCoordinates();

            point2.printDistance(point1);

            Point3D point3 = new Point3D(0, 0, 0);

            Sphere sphere1 = new Sphere(point3, 2);

            Console.WriteLine(nameof(sphere1) + "=> ");
            sphere1.printInformation();
            sphere1.PrintVolume();

            Sphere sphere2 = new Sphere();

            Console.WriteLine(nameof(sphere2) + "=> ");
            sphere2.printInformation();
            sphere2.PrintVolume();

            sphere1.printIsPointInSphere(point2);

            sphere1.printIsColliding(sphere2);

            Sphere sphere3 = new Sphere(point2, 1);
            sphere1.printIsColliding(sphere3);


            Point3D point4 = new Point3D(2,2,0);
            point4.printSphericalCoordinates();

        }
    }
}
