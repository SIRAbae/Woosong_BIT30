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
    public partial class Drinkselect : Form
    {
        Form1 form1;
        Machine mch = Machine.Instance;
        public Drinkselect(Form1 f)
        {
            form1 = f;
            InitializeComponent(); 

            for (int i = 0; i < mch.drinklist.Count; i++)
            {//콤보박스 셋팅 이걸해서 콤보박스 사용
                //drinklist 의 상품갯수 만큼 반복실해햐며 
                //상품을 콤보박스에 넣어줌
                comboBox1.Items.Add(mch.drinklist[i].Name.ToString());
            }
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                mch.SelectDrink(comboBox1.Text);
                form1.UpdateData();
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
