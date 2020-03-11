using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace _1025수업연습
{
    class MyWindow : Window
    {

        //기본적으로 wpf에서 자식은 1개 존재한다.
        public MyWindow()
        {
            Button btn = new Button();
            btn.Click += Btn_Click;
            btn.Width = 100;
            btn.Height = 25; //버튼의 크기를 지정 안하면 출력되는 창과 같아 진다. (부모의 크기를 가져옴)
            btn.Content = " 클릭 ";

            AddChild(btn);

            Title = "WPF Window";
        }

        private void Btn_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("버튼 클릭");
        }
    }
    class Program : Application
    {
        [STAThread]
        static void Main(string[] args)
        {
            Program pro = new Program();
            pro.Startup += Pro_Startup;
            pro.Run();
        }

        private static void Pro_Startup(object sender, StartupEventArgs e) //start up Uri
        {
        MyWindow window = new MyWindow();
            window.Show();

        }
    }
}
