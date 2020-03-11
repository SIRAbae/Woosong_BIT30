using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;

namespace _1104저녁실습2
{
    class Program
    {
        static void Main(string[] args)
        {
            BasicHost();
        }

        static void BasicHost()
        {
            //다음 코드가 정상적으로 작동하기 위해서는 app.config파일의
            //<services> 요소를 comment로 막아 두어야 한다.
            ServiceHost host = new ServiceHost(typeof(Example));


            host.Open();
            Console.WriteLine("Press Any key to stop the service");
            Console.ReadKey(true);
            host.Close();
        }
    }
}
