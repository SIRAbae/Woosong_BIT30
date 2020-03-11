using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1005집에서_과제
{
    public partial class Inputmoney : Form
    {
        Form1 form1;

        public Inputmoney(Form1 f)
        {
            form1 = f;
            InitializeComponent();
        }
        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                form1.inputmoney(int.Parse(textBox1.Text));
                //Machine에 있는 InputMoney매서드를 호출해 textBox1의 
                //  Text를 넣어 준다.
                form1.UpdateData();
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        
    }
}
