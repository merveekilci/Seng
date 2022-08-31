class A
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
    }
}


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

 