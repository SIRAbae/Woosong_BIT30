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
    public partial class SelectDrink : Form//재품 구매

    {
        Form1 form1;
        Machine mach = Machine.Instance;
        public SelectDrink(Form1 f)
        {
            form1 = f;
            InitializeComponent();

            for (int i = 0; i < mach.drinklist.Count; i++)
            {
                comboBox1.Items.Add(mach.drinklist[i].Name.ToString());
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                mach.SelectDrink(comboBox1.Text);
                form1.updateData();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
