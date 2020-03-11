using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1008학생_성적관리
{
    public partial class Form1 : Form
    {
        private WdDB db = new WdDB();
        public Form1()
        {
            InitializeComponent();
            ScoreCombobox();
        }

        public void ScoreCombobox()
        {
            string[] scordata = { "단일과목으로 검색", "전체과목으로 검색", "등수로 검색" };

            comboBox2.Items.AddRange(scordata);

            comboBox2.SelectedIndex = 0;
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: 이 코드는 데이터를 'wb30DataSet2.Subject' 테이블에 로드합니다. 필요 시 이 코드를 이동하거나 제거할 수 있습니다.
            this.subjectTableAdapter1.Fill(this.wb30DataSet2.Subject);
            // TODO: 이 코드는 데이터를 'wb30DataSet1.Subject' 테이블에 로드합니다. 필요 시 이 코드를 이동하거나 제거할 수 있습니다.
            this.subjectTableAdapter.Fill(this.wb30DataSet1.Subject);
            // TODO: 이 코드는 데이터를 'wb30DataSet.Score' 테이블에 로드합니다. 필요 시 이 코드를 이동하거나 제거할 수 있습니다.
            this.scoreTableAdapter.Fill(this.wb30DataSet.Score);

            // DataTable 생성(쿼리에 의해 생성된 DataTable도 동일)

        }



        private void button1_Click_1(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {

            int snum = int.Parse(textBox8.Text);

            string combodata = comboBox3.Text;


            if (comboBox2.SelectedIndex == 0)
            {
                Student stu = db.SelectProduct1(snum, combodata);

                NewSetting(true);
            }

            else if (comboBox2.SelectedIndex == 1)
            {
                Student stu = db.SelectProduct2(snum);
                NewSetting(true);
            }

            else
            {
                Student stu = db.SelectProduct3(snum);
                NewSetting(true);
            }
        }
        public void NewSetting( bool true1)
        { 

            if (true1 != false)
            {
                //textBox10.Text = student.SNAME;
                //textBox11.Text = student.SDRPT;
                //textBox12.Text = student.SGRADE.ToString();
                //textBox13.Text = student.PHONE;
            }
            else
            {
                MessageBox.Show("없는 ID입니다.");
                textBox1.Text = string.Empty;
                textBox2.Text = string.Empty;
                textBox3.Text = string.Empty;
                textBox4.Text = string.Empty;
            }
        }

        private void tabPage2_Click(object sender, EventArgs e)
        {

        }
    }
}
