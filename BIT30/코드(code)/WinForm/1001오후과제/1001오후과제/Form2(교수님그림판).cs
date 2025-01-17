﻿using System;
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
    public partial class Form2_교수님그림판_ : Form
    {
        private Shape curShape;

        public Form2_교수님그림판_()
        {
            InitializeComponent();

            curShape = new Shape(new Point(10, 10), 50, Color.Red);

        }

        private void Form2_MouseClick(object sender, MouseEventArgs e)
        {
            //10,10 ~ 210,60
            Rectangle r = new Rectangle(10, 10, 200, 50);
            if ((r.Top < e.Y && r.Bottom > e.Y) &&
                (r.Left < e.X && r.Right > e.X))
            {
                if (10 < e.X && 60 > e.X)
                {
                    curShape.BrushColor = Color.Red;
                    DrawColorPicture(Color.Red);
                }
                else if (60 < e.X && 110 > e.X)
                {
                    curShape.BrushColor = Color.Green;
                    DrawColorPicture(Color.Green);
                }
                else if (160 < e.X && 210 > e.X)
                {
                    //색상 다이얼로그 출력page 9
                    ColorDialog colorDlg = new ColorDialog();
                    colorDlg.AllowFullOpen = false;
                    colorDlg.ShowHelp = true;
                    colorDlg.Color = curShape.BrushColor;
                    //--------------------------------------------
                    if (colorDlg.ShowDialog() == DialogResult.OK)
                    {
                        Graphics gr1 = this.CreateGraphics();
                        gr1.FillRectangle(new SolidBrush(colorDlg.Color), 160, 10, 50, 50);
                        curShape.BrushColor = colorDlg.Color;
                        DrawColorPicture(colorDlg.Color);
                        gr1.Dispose();
                    }
                }
                return;
            }

            if (Control.ModifierKeys.Equals(Keys.Control))
            {
                this.Invalidate();
                return;
            }
            curShape.point = new Point(e.X, e.Y);

            using (Graphics gr = this.CreateGraphics())
            {
                gr.FillRectangle(new SolidBrush(curShape.BrushColor),
                    new Rectangle(curShape.point.X, curShape.point.Y, 50, 50));
            }// 자동으로 gr.Dispose()호출
        }

        private void Form2_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.R:
                    curShape.BrushColor = Color.Red;
                    DrawColorPicture(Color.Red); break;
                case Keys.G:
                    curShape.BrushColor = Color.Green;
                    DrawColorPicture(Color.Green); break;
                case Keys.B:
                    curShape.BrushColor = Color.Blue;
                    DrawColorPicture(Color.Blue); break;
            }
        }

        private void Form2_Paint(object sender, PaintEventArgs e)
        {
            PrintColor(e.Graphics);
        }

        //팔래트 출력 기능
        private void PrintColor(Graphics gr)
        {
            //10,10 ~ 210,60
            gr.FillRectangle(new SolidBrush(Color.Red), 10, 10, 50, 50);
            gr.FillRectangle(new SolidBrush(Color.Green), 60, 10, 50, 50);
            gr.FillRectangle(new SolidBrush(Color.Blue), 110, 10, 50, 50);
            gr.FillRectangle(new SolidBrush(Color.White), 160, 10, 50, 50);
        }

        //픽처박스 컨트롤에 색상 칠하기
        private void DrawColorPicture(Color color)
        {
            Graphics gr = pictureBox1.CreateGraphics();
            gr.FillRectangle(new SolidBrush(color),
                pictureBox1.ClientRectangle);
            gr.Dispose();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            listBox1.Items.Add("RED");
            listBox1.Items.Add("GREEN");
            listBox1.Items.Add("BLUE");
        }

        private void listBox1_KeyDown(object sender, KeyEventArgs e)
        {
            this.Form2_KeyDown(sender, e);
        }

        private void listBox1_MeasureItem(object sender, MeasureItemEventArgs e)
        {

        }

        private void listBox1_DrawItem(object sender, DrawItemEventArgs e)
        {
            Graphics g = e.Graphics;
            Brush brush = Brushes.Black;

            switch (e.Index)
            {
                case 0: brush = Brushes.Red; break;
                case 1: brush = Brushes.Green; break;
                case 2: brush = Brushes.Blue; break;
            }
            g.DrawString(listBox1.Items[e.Index].ToString(),
                e.Font, brush, e.Bounds, StringFormat.GenericDefault);
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex == 0)
                DrawColorPicture(Color.Red);
            else if (listBox1.SelectedIndex == 1)
                DrawColorPicture(Color.Green);
            else if (listBox1.SelectedIndex == 2)
                DrawColorPicture(Color.Blue);
        }
    }
}
