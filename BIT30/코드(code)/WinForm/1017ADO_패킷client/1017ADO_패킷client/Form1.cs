using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1017ADO_패킷client
{
    public partial class Form1 : Form
    {
       public bool bl { get; private set; }
        Form2 IM = new Form2();
        NewMember newf = new NewMember();

        WbClient client = new WbClient();

        Ui ui = new Ui();
        //private readonly object titlebar;

        public Form1()
        {
            InitializeComponent();
            client.ParentInfo(this);
            bl = false;
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
            Ui.LogPrint(listBox2, str);
        }
        #endregion

        private void 프로그램종료ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void 서버연결ToolStripMenuItem_Click(object sender, EventArgs e)
        {

            if (IM.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    //IM.IP;
                    if (client.ClientRun(IM.IP, IM.Port) == true)
                    {
                        Ui.FillDrawing(panel1, Color.Blue);
                        Ui.LabelState(label1, true);

                        String temp = String.Format("[서버실행]{0}:{1} 성공",
                            client.ClientIp, client.ClientPort);
                        Ui.LogPrint(listBox1, temp);

                    }
                    else
                    {
                        String temp = String.Format("[연결실패] {0} : {1} 실패",
                            client.ClientIp, client.ClientPort);
                        Ui.LogPrint(listBox1, temp);
                    }


                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
        }

        private void 서버연결해제ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Ui.FillDrawing(panel1, Color.Red);
            Ui.LabelState(label1, false);

            String temp = String.Format("[서버종료]{0}:{1} 성공",
                        client.ClientIp, client.ClientPort);
            Ui.LogPrint(listBox1, temp);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string name = textBox1.Text;
            string msg = textBox2.Text;
            string temp = string.Format("[{0}] : {1}", name, msg);
            string msg1 = Packet.Intance.GetMessage(msg);

            client.Send(msg);

        }

        public void RecvPrint(string data)
        {
           
                Ui.LogPrint(listBox2, data);
       
        }

        private void 회원가입ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (newf.ShowDialog() == DialogResult.OK)
            {
                string msg = Packet.Intance.GetNewMember(newf.ID, newf.PW, newf.NAME, newf.AGE);
                client.Send(msg);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            newf.ID = textBox1.Text;
            string msg = Packet.Intance.GetLogout(newf.ID);
            client.Send(msg);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            newf.ID = textBox1.Text;
            string msg = Packet.Intance.GetDelMember(newf.ID);
            client.Send(msg);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            newf.ID = textBox1.Text;
            newf.PW = textBox3.Text;
            string msg = Packet.Intance.GetLogin(newf.ID, newf.PW);
            client.Send(msg);
            
        }

        #region 수신패킷 분석
        public void PaserByteData(byte[] data)
        {
            string msg = Encoding.Default.GetString(data);
            string[] token = msg.Split('@');
            switch (token[0].Trim())
            {
                case "NEWMEMBERACK": NewMember(token[1]); break;
                case "DELMEMBERACK": DelMember(token[1]); break;
                case "LOGINACK": Login(token[1]); break;
                case "LOGOUTACK": Logout(token[1]); break;
                case "MESSAGEACK": Messageack(token[1]); break;
            }
        }
        #endregion

        #region 수신 패킷 처리
        void NewMember(string msg)
        {
            

            string[] sp = msg.Split('#');

       
            if (bool.Parse(sp[0]) == true)
            {
                MessageBox.Show("어서오...왜왔어요??");
                Ui.LogPrint(listBox2, msg);
            }
            else
                MessageBox.Show("실패했지롱!!!!!~~~!!~@~!#!!#!~");
        }

        void DelMember(string msg)
        {

            string[] sp = msg.Split('#');
            //string id = sp[0];

            if (bool.Parse(sp[0]) == true)
            {
                MessageBox.Show("이제 안오는 거야.?..그래..??..잘가......");
                Ui.LogPrint(listBox2, msg);
            }
            else
                MessageBox.Show("실패했지롱!!!!!~~~!!~@~!#!!#!~");
        }

        void Login(string msg)
        {
           
            string[] sp = msg.Split('#');
            //string id = sp[0];

            if (bool.Parse(sp[0]) == true)
            {
                if (textBox1.Text.Equals(sp[1]) && bl == false)
                {
                    MessageBox.Show("와 진짜왔네... 이거 들어올시간이 있어??");
                    string str = string.Format("{0} 님이 입장", sp[1]);
                    this.Text = string.Format("{0} 님이 로그인 하셨습니다.", sp[2]);

                    Ui.LogPrint(listBox2, msg);
                    bl = true;

                }
                else if (bl == true)
                {
                    MessageBox.Show("실패했지롱!!!!!~~~!!~@~!#!!#!~");
                }
            }
            else
            {
                MessageBox.Show("실패했지롱!!!!!~~~!!~@~!#!!#!~"); 
            }
        }

        void Logout(string msg)
        {
            
            string[] sp = msg.Split('#');
            //string id = sp[0];
            string str = string.Format("{0} 나감", sp[1]);
            if (bool.Parse(sp[0]) == true)
            {
                MessageBox.Show(" 가.??..가는구나...지금가야되.??..잘가...");
                bl = false;

            }
            else
            {
                MessageBox.Show("실패했지롱!!!!!~~~!!~@~!#!!#!~");
                
            }

        }
        void Messageack(string msg)
        {
            string[] sp = msg.Split('#');

            if (sp[0].Equals("True") && bl == true)
            {
                string str = string.Format("[{0}] {1} ", sp[1], sp[2]);
            }


        }
        #endregion
    }
}
