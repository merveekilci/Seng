using System;
using System.Windows.Forms;

namespace Week11
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void webBrowser1_DocumentCompleted(object sender, WebBrowserDocumentCompletedEventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label2_Click_1(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void label2_Click_2(object sender, EventArgs e)
        {

        }

        private void btnCalculate_Click(object sender, EventArgs e)
        {
            Student student1 = new Student();
            student1.Name = txtName.Text;
            student1.Number = txtNumber.Text;
            student1.Midterm = Convert.ToInt32(txtMidterm.Text);
            student1.Final = Convert.ToInt32(txtFinal.Text);
            do
            {
                student1.Gender = "Female";
                break;
            } while (rbtnFemale.Checked);
            do
            {
                student1.Gender = "Male";
                break;
            } while (rbtnMale.Checked);
            lblMessage.Visible = true;
            lblMessage.Text = student1.Name + " " + student1.Number + " " + student1.Gender + " has " + student1.printResult();
        }

        private void Clear_Click(object sender, EventArgs e)
        {
            txtFinal.Clear();
            txtMidterm.Clear();
            txtName.Clear();
            txtNumber.Clear();
            rbtnFemale.Checked = false;
            rbtnMale.Checked = false;
            lblMessage.Visible = false;
            lblMessage.Text = "";
        }
    }
}
