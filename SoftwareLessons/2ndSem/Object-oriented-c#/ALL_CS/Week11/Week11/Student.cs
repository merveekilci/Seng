namespace Week11
{
    public class Student
    {
        private string mName;
        private string mNumber;
        private string mGender;
        private int mMidterm;
        private int mFinal;

        public string Name { get => mName; set => mName = value; }
        public string Number { get => mNumber; set => mNumber = value; }
        public string Gender { get => mGender; set => mGender = value; }
        public int Midterm { get => mMidterm; set => mMidterm = value; }
        public int Final { get => mFinal; set => mFinal = value; }

        public Student()
        { }

        private bool Calculate()
        {
            bool result = false;

            if ((float)(mMidterm + mFinal) * 0.5f >= 50)
                result = true;

            return result;
        }

        public string printResult()
        {
            string result = "Failed with " + ((float)(mMidterm + mFinal) * 0.5f);

            if (Calculate())
                result = "Passed with " + ((float)(mMidterm + mFinal) * 0.5f);

            return result;
        }



    }
}
