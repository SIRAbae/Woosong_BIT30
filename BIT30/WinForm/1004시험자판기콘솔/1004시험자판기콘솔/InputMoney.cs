using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1004시험자판기콘솔
{
    public partial class InputMoney : Form
    {
        Form1 form1;
        Machine mach = Machine.Instance;

        public InputMoney(Form1 f)
        {
            form1 = f;
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                mach.InsertMoney(int.Parse(textBox1.Text));
                form1.updateData();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
