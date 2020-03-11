using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1018_client_시험
{
    public partial class Form1 : Form
    {

        WbClient client = new WbClient();
        Ui ui = new Ui();
        public string IP { get; private set; }
        public int Port { get; private set; }
        public Form1()
        {
            InitializeComponent();
            client.ParentInfo(this);
        }
        #region  소켓에서 보낸 정보
        public void LogMessage(string str)
        {
            str += "(" + DateTime.Now.ToString() + ")";
            Ui.LogPrint(listBox1, str);
        }

        public void ShortMessage(string str)
        {
            str += "(" + DateTime.Now.ToString() + ")";
            Ui.LogPrint(listBox1, str);
        }
        #endregion
        public void RecvPrint(string data)
        {
            Ui.LogPrint(listBox1, data);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            IP = textBox1.Text;
            Port = int.Parse(textBox2.Text);

            //IM.IP;
            if (client.ClientRun(IP, Port) == true)
                {
                    String temp = String.Format("게임을 시작합니다. 숫자를 입력하세요");
                    Ui.LogPrint(listBox1, temp);
                }
            else
            {
                String temp = String.Format("서버 연결이 실패했습니다. 다시 시도해 주세요");
                Ui.LogPrint(listBox1, temp);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            String temp = String.Format("게입을 종료합니다.");
            Ui.LogPrint(listBox1, temp);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string name = textBox3.Text;
            int num = int.Parse(textBox4.Text);
            string temp = string.Format("[{0}] : {1}", name, num);
            string msg = Packet.Intance.GetSendNumber(name, num);

            client.Send(msg);
        }

        #region 수신패킷 분석
        public void PaserByteData(byte[] data)
        {
            string msg = Encoding.Default.GetString(data);
            string[] token = msg.Split('@');
            switch (token[0].Trim())
            {
                case "SENDNUMBERACK": NewNumber(token[1]); break;
                case "SENDNUMBERSUCCESSACK": SendNumber(token[1]); break;

            }
        }
        #endregion

        #region 수신 패킷 처리
        void NewNumber(string msg)
        {


            string[] sp = msg.Split('#');


            if (textBox3.Text.Equals(sp[1]))
            {
                try
                {
                    MessageBox.Show("어서오...왜왔어요??");
                    Ui.LogPrint(listBox1, msg);
                }
                catch(Exception ex)
                { MessageBox.Show(ex.Message); }
            }
            else
                MessageBox.Show("실패했지롱!!!!!~~~!!~@~!#!!#!~");
        }

        void SendNumber(string msg)
        {


            string[] sp = msg.Split('#');


            if (textBox3.Text.Equals(sp[1]))
            {
                MessageBox.Show("어서오...왜왔어요??");
                Ui.LogPrint(listBox1, msg);
            }
            else
                MessageBox.Show("실패했지롱!!!!!~~~!!~@~!#!!#!~");
        }
        #endregion
    }
}
