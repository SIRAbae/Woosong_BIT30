﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using MenuAnimation;

namespace MenuAnimation
{
    /// <summary>
    /// photoBtn.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class photoBtn : UserControl
    {


        public photoBtn(string url)
        {
            InitializeComponent();

            Image img = new Image();
            img.Source = new BitmapImage(new Uri(url, UriKind.Relative));
            ImageBrush IB = new ImageBrush(img.Source);
            mypicture.Background = IB;
        }

        //버튼_클릭
        private void Mypicture_Click(object sender, RoutedEventArgs e)
        {
            PostUI PU = new PostUI();
            PU.ShowDialog();
        }
    }
}
