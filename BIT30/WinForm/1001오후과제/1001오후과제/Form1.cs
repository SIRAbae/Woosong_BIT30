using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1001오후과제
{
    public partial class Form1 : Form
    {
        Graphics g;
        Pen p;
        SolidBrush b = new SolidBrush(Color.Violet);
        List<Point> pList = new List<Point>();
        public Form1()
        {
            InitializeComponent();

            this.Text = "0930 ## 비트 30기 ## 오후 실습 ## 윤상배";

            panel1.BackColor = Color.White;
            g = panel1.CreateGraphics();
            // p = new Pen(Color.Black);
            b = new SolidBrush(Color.Violet);
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);
            Draw();
        }
        private void panel1_Move(object sender, EventArgs e)
        {
            Draw();
        }

        #region 빵꾸뚤린 사각형
        //public void Draw()
        //{
        //    foreach (var pnt in pList)
        //        g.DrawRectangle(p, pnt.X, pnt.Y, 50, 50); //좌표와 크기 도형 종류
        //}

        //private void panel1_MouseDown(object sender, MouseEventArgs e)
        //{

        //    if (e.Button == MouseButtons.Left && (ModifierKeys & Keys.Control) == Keys.Control)
        //    {
        //        try
        //        {
        //            g.DrawLine(p, pList.ElementAt(pList.Count - 2), pList.ElementAt(pList.Count - 1));
        //            pList.RemoveAt(pList.Count - 2);
        //            pList.RemoveAt(pList.Count - 1);

        //        }
        //        catch { }
        //        Refresh();
        //    }
        //    else
        //    {
        //        int x = e.X;
        //        int y = e.Y;
        //        g.DrawRectangle(p, x, y, 50, 50);
        //        pList.Add(new Point(x, y));
        //    }
        //}



        //private void Form1_KeyDown(object sender, KeyEventArgs e)
        //{
        //    if (e.KeyCode == Keys.R)
        //    {
        //        p = new Pen(Color.Red);
        //    }
        //    else if (e.KeyCode == Keys.G)
        //    {
        //        p = new Pen(Color.Green);
        //    }
        //    else if (e.KeyCode == Keys.B)
        //    {
        //        p = new Pen(Color.Blue);
        //    }

        //    else
        //    {
        //        Console.WriteLine("오류");
        //    }
        //}
        #endregion

        #region  채워진 사각형

        
        public void Draw()
        {
            foreach (var pnt in pList)
                g.FillRectangle(b, pnt.X, pnt.Y, 50, 50); //좌표와 크기 도형 종류
        }

        private void panel1_MouseDown(object sender, MouseEventArgs e)
        {

            if (e.Button == MouseButtons.Left && (ModifierKeys & Keys.Control) == Keys.Control)
            {
                try
                {
                    g.DrawLine(p, pList.ElementAt(pList.Count - 2), pList.ElementAt(pList.Count - 1));
                    pList.RemoveAt(pList.Count - 2);
                    pList.RemoveAt(pList.Count - 1);

                }
                catch { }
                Refresh();
            }
            else
            {
                int x = e.X;
                int y = e.Y;
               // g.DrawRectangle(b, x, y, 50, 50); //빵꾸난거
                g.FillRectangle(b, x, y, 50, 50); //채운거
                pList.Add(new Point(x, y));
            }
        }



        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.R)
            {
                 b = new SolidBrush(Color.Red);
            }
            else if (e.KeyCode == Keys.G)
            {
                 b = new SolidBrush(Color.Green);
            }
            else if (e.KeyCode == Keys.B)
            {
                 b = new SolidBrush(Color.Blue);
            }

            else
            {
                Console.WriteLine("오류");
            }
        }
        #endregion


        // 픽저박스 컨트롤에 색상 칠하기
       /*
        private void DrawColorpicture(Color color)
        {
            Graphics gr = Pi
        }
        */
    }
}
