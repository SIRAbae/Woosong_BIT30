using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

namespace ConsoleApp1
{
    class FirstForm : Form
    {
        public FirstForm(string strText)
        {
            #region 맴버필드 초기화
            //속성 초기화  : 생성자에서 담당
            this.Text = strText;
            this.Top = 10;
            this.Left = 10;
            this.Width = 250;
            this.Height = 200;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Show();// 이거 꼭 해줘야함 안하면 화면에 안보입

            //위에 있는 this는 모두 부모(from의 값이다.)
            #endregion

            this.Load += new System.EventHandler(this.Form_Load);
            this.FormClosed += new FormClosedEventHandler(this.Form_Closed);
            this.FormClosing += new FormClosingEventHandler(this.Form_Closing);
            this.MouseClick += new System.Windows.Forms.MouseEventHandler(this.From_MouseClick);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.From_KeyDown);


            this.Show();
        }
        private void From_KeyDown(object sender, System.Windows.Forms.KeyEventArgs e)
        {
            Console.WriteLine("KeyDown 이벤트 발생!!!");
        }
        private void From_MouseClick(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            
            Console.WriteLine("MouseMove 이벤트 발생!!!");
        }
            // 초기화 작업 표시 
            private void Form_Load(object sender, System.EventArgs e)
        {
            Console.WriteLine("윈도우가 Load 됩니다.");
        }

        // 종료 작업 표시 
        private void Form_Closed(object sender, FormClosedEventArgs e)
        {
            Console.WriteLine("윈도우가 Closed 됩니다.");
        }

        private void Form_Closing(object sender, FormClosingEventArgs e)
        {


            DialogResult r = MessageBox.Show("종료???", "알림", MessageBoxButtons.YesNo, MessageBoxIcon.Information); ;

            if (r == DialogResult.No)
            e.Cancel = true;

            Console.WriteLine("윈도우가 Closing 됩니다.");

            //this.Text = string.Format("{0},{1}", e.X, e.Y); 타이틀바
         
            //e.Cancel = false;
        }

        private void InitializeComponent()
        {
            this.SuspendLayout();
            // 
            // FirstForm
            // 
            this.ClientSize = new System.Drawing.Size(282, 253);
            this.Name = "FirstForm";
            this.Load += new System.EventHandler(this.FirstForm_Load);
            this.ResumeLayout(false);

        }

        private void FirstForm_Load(object sender, EventArgs e)
        {

        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            NewMethod4();
        }

        private static void NewMethod4()
        {
            FirstForm newFrom = new FirstForm("첫번째 폼");
            Application.Run(new FirstForm("상속받아 구현된 윈도우"));
        }

        private static void NewMethod3()
        {
            /*
            string[] strText = { "빨", "주", "노", "초", "파", "남", "보" };


            Form[] wnd = new Form[7];
            for (int i = 0; i < 7; i++)
            {
                wnd[i] = new Form();
                wnd[i].Text = strText[i];
                wnd[i].SetBounds((i + 1) * 10, (i + 1) * 10, 100, 100);
                wnd[i].MaximizeBox = false;
                wnd[i].Show();
                Console.WriteLine("{0} 번째 윈도우 출력 성공!!!", i);

            }
            Application.Run(wnd[0]);
            */
            // 창이 여러개일 경우에도 Run메서드에 등록하는 Form 개체 인스턴스는
            //  한번만 설정하면 됨

            // 첫번째 윈도우를 등록... : 등록된 윈도우만 메시지루프가 구동됨
            // 이를 주석처리하면 Show되었다가 사라짐
            // 등록된 놈을 제거하면 모두 제거됨
        }

        private static void NewMethod2()
        {
            NewMethod1();




            //DialogResult r = MessageBox.Show("TEXT", "알림", MessageBoxButtons.YesNo, MessageBoxIcon.Information);

            //if (r == DialogResult.Yes)
            //    Console.WriteLine("확인");

            //else (r == DialogResult.No)
            //Console.WriteLine("실패");
        }

        private static void NewMethod1()
        {
            NewMethod();




            //Application.Run(new Form);
        }

        private static void NewMethod()
        {
            Form obj = new Form();
            obj.Text = "Form클래스를 이용한 윈폼";       // 제목표시줄에 글자 출력
            obj.SetBounds(10, 10, 300, 150);            // 윈폼 크기 지정
            obj.MaximizeBox = false;            // 윈도우 버튼 속성 지정
            obj.StartPosition = FormStartPosition.CenterScreen; // 초기 출력위치 
                                                                // 윈폼 크기 지정시 초기 출력위치가 변경됨


            Application.Run(obj);
        }
    }
}
