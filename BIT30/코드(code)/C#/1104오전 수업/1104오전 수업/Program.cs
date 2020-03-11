using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.ServiceModel.Description;
using System.Text;
using System.Threading.Tasks;

namespace _1104오전_수업
{

    // HelloWorld 서비스에 대한 WCF 호스트를 구현
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
            ServiceHost host = new ServiceHost(typeof(HelloWorldWCFService),
                new Uri("http://192.168.0.34:8888/wcf/example/helloworldservice"));

            host.AddServiceEndpoint(
                typeof(IHelloWorld),            //sevice contract
                new BasicHttpBinding(),         //sevice binding
                "");                            //relative address

            //ServiceMetadataBehavior 설정
            // WSDL 문서제공 코드 ================================================
            ServiceMetadataBehavior behavior =
                host.Description.Behaviors.Find<ServiceMetadataBehavior>();
            if(behavior == null)
            {
                behavior = new ServiceMetadataBehavior();
                host.Description.Behaviors.Add(behavior);
            }
            behavior.HttpGetEnabled = true;
            //===================================================================

            host.Open();
            Console.WriteLine("Press Any key to stop the service");
            Console.ReadKey(true);
            host.Close();
        }
    }
}
