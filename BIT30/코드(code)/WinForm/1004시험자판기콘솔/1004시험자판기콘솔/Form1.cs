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
    public partial class Form1 : Form
    {
        Machine mach = Machine.Instance;
        public Form1()
        {
            InitializeComponent();
            mach.InitDrinkSetting();
            ListBoxSetting();
        }
        private void ListBoxSetting()
        {
            listView1.Items.Clear();
            for (int i = 0; i < 5; i++)
            {
                String[] arr = new String[3];
                arr[0] = mach.drinklist[i].Name;
                arr[1] = mach.drinklist[i].Price.ToString();
                arr[2] = mach.drinklist[i].Count.ToString();
                ListViewItem lvt = new ListViewItem(arr);
                listView1.Items.Add(lvt);
            }
        }

        public void updateData()
        {
            label6.Text = mach.Money.ToString();
            label4.Text = mach.AllSal.ToString();
            label3.Text = mach.AllPrice.ToString();
            ListBoxSetting();
        }
        private void 프로그램종료ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void 금액투입ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            InputMoney IM = new InputMoney(this);
            IM.Show();
        }

        private void 제품선택ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SelectDrink IM = new SelectDrink(this);
            IM.Show();
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e) //
        {
            int indexnum = listView1.FocusedItem.Index;
            string txt = listView1.Items[indexnum].SubItems[0].Text;

            for (int i = 0; i < mach.drinklist.Count; i++)
            {
                if (txt.Equals(mach.drinklist[i].Name))
                {
                    textBox1.Text = mach.drinklist[i].Name;
                    textBox2.Text = mach.drinklist[i].Price.ToString();
                    textBox3.Text = mach.drinklist[i].Count.ToString();
                    textBox4.Text = mach.drinklist[i].Sal.ToString();
                    textBox5.Text = (mach.drinklist[i].Price * mach.drinklist[i].Sal).ToString();
                }
            }
        }
    }
}
