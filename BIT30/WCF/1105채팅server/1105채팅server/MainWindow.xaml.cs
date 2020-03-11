using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.ServiceModel;
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

namespace _1105채팅server
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            //Address             
            Uri uri = new Uri(ConfigurationManager.AppSettings["addr"]);             
            //Contract-> Setting            
            //Binding -> App.Config             
            ServiceHost host = new ServiceHost(typeof(Chating.ChatService), uri); 

            //오픈             
            host.Open();            
            Console.WriteLine("채팅 서비스를 시작합니다. {0}", uri.ToString());            
            Console.WriteLine("http://61.81.99.75:9000/GetService");             
            Console.WriteLine("멈추시려면 엔터를 눌러주세요..");             
            Console.ReadLine();             
            //서비스             
            host.Abort();             
            host.Close();           
        }
    }
}
