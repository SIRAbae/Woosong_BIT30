using System;
using System.Windows.Forms;

namespace _1005집에서_과제
{
    public partial class Form1 : Form
    {
        Machine mch = new Machine();

        public Form1()
        {
            InitializeComponent();
            mch.InitDrinkSetting();
            ListBoxSetting();
        }

        private void ListBoxSetting()
        {
            listView1.Items.Clear(); // 리스트 박스(뷰)1 청소
            for (int i = 0; i < 5; i++) // DrinkList의 개수 만큼 반복 실행
            {
                String[] arr = new String[3];
                arr[0] = mch.drinklist[i].Name; //[i] 번째 이름 출력
                arr[1] = mch.drinklist[i].Price.ToString(); //[i] 번째 가격 출력
                arr[2] = mch.drinklist[i].Stock.ToString(); //[i] 번째 재고량 출력
                ListViewItem lvt = new ListViewItem(arr);
                listView1.Items.Add(lvt);
            }
        }
        public void UpdateData()
        {
            label6.Text = mch.Money.ToString();
            label4.Text = mch.AllSale.ToString();
            label5.Text = mch.AllPrice.ToString();
            ListBoxSetting();// 리스트박스 셋팅을 왜 부르는거??
        }

        private void button1_Click(object sender, EventArgs e)
        {
            mch.GetMoney();
            UpdateData();
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {
            int indexnum = listView1.FocusedItem.Index; //리스트박스(뷰)에 포커스
            string txt = listView1.Items[indexnum].SubItems[0].Text;
            //리스트박스(뷰)아이템에 인덱스 번호와 포커스 생성
            for (int i = 0; i < mch.drinklist.Count; i++)
            {    //Machine에 저장되어 있는 상품 갯수 만큼 반복 실행
                
                if (Text.Equals(mch.drinklist[i].Name))
                    // Machine의 인덱스 값에 맞추어 각각 인자값을 넣어 준다.
                {
                    textBox1.Text = mch.drinklist[i].Name;
                    textBox2.Text = mch.drinklist[i].Price.ToString();
                    textBox3.Text = mch.drinklist[i].Stock.ToString();
                    textBox4.Text = mch.drinklist[i].Sale.ToString();
                    textBox5.Text = (mch.drinklist[i].Sale * mch.drinklist[i].Price).ToString();
                }
            }
        }

        private void 프로그렘종료ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void 금액투입ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Inputmoney input = new Inputmoney(this);
            input.Show();
        }

        private void 제품선택ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Drinkselect slect = new Drinkselect(this);
            slect.Show();
        }
        public void inputmoney(int money)
        {
            try
            {
                mch.InputMoney(money);
                //SetData();
            }
            catch(Exception ex)
            {
                Console.WriteLine("오류 :" + ex.Message);
            }
        }
    }
}
