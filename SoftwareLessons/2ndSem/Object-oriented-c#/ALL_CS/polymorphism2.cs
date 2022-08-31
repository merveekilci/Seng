using System;

namespace polymorphism
{

    /*class A
    {
        private string adi = "A";
        public void EkranaYaz()
        {
            Console.WriteLine(this.adi);
        }
    }

    class B
    {
        private string adi = "B";
        public void EkranaYaz()
        {
            Console.WriteLine(this.adi);
        }
    }

    class GenelSinif
    {
        public void YazdirA()
        {
            A yeniA = new A(); 
            yeniA.EkranaYaz();
        }

        public void YazdirB()
        {
            B yeniB = new B(); 
            yeniB.EkranaYaz();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            GenelSinif g = new GenelSinif();
            g.YazdirA(); g.YazdirB();
        }
    }*/


    /*abstract class BaseSinif
    {
        public abstract void EkranaYaz();
    }

    class A : BaseSinif
    {
        private string adi = "A"; 
        public override void EkranaYaz()
        {
            Console.WriteLine(this.adi);
        }
    }

    class B : BaseSinif
    {
        private string adi = "B";
        public override void EkranaYaz()
        {
            Console.WriteLine(this.adi);
        }
    }

    class GenelSinif
    {
        public void EkranaYaz(BaseSinif b)                  // a parameter from base class type
        {
            b.EkranaYaz();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            GenelSinif gs = new GenelSinif();
        
            gs.EkranaYaz(new A()); 
            gs.EkranaYaz(new B());
        }
    }*/

    // this will also be interface
    abstract class PERSON
    {
        protected string mName; 
        protected string mSurname;
        
        public PERSON (string name, string surname)
        {
            this.mName = name; 
            this.mSurname = surname;
        }

        public virtual string Etiket()
        {
            return this.mName + " " + this.mSurname;
        }
    }
    class Student : PERSON
    {
        private string mStudentNumber; 
        public string studentNumber { set=> mStudentNumber = value; }

        // base anahtar kelimesini açıkla
        public Student(string studentNumber, string name, string surname) : base(name, surname)
        {
            //base.mName= name;
            //base.mSurname= surname;
            this.mStudentNumber= studentNumber;
        }

        public override string Etiket()
        {
            return this.mStudentNumber + "  " + this.mName+ " " + this.mSurname;
        }
    }

    class Lecturer : PERSON
    {
        public Lecturer(string name, string surname) : base(name, surname){}
    }

    class Program
    {
        static void Main(string[] args)
        {
            Lecturer lecturer1 = new Lecturer("Gülüzar", "ÇİT");
            Lecturer lecturer2 = new Lecturer("Deniz", "BALTA");
            Lecturer lecturer3 = new Lecturer("Mustafa", "AKPINAR");

            Student student1 = new Student("1", "Mertcan", "YILMAZ");
            Student student2 = new Student("2", "Cenk Eren", "CENGİZ");
            Student student3 = new Student("3", "Muhammed Emirhan", "MURAT");
            Student student4 = new Student("4", "Salih", "DOĞANER");
            Student student5 = new Student("5", "Halil İbrahim", "ÜSTÜN");

            PERSON[] people = { lecturer1, lecturer2, lecturer3, student1, student2, student3, student4, student5};
            
            foreach (PERSON p in people) 
                EkranaYazdir(p);
        }
    
        static void EkranaYazdir(PERSON p)
        {
            Console.WriteLine(p.Etiket());
        }
}
}
