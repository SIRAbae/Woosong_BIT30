using _1104수업클라이언트.ServiceReference1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.ServiceModel.Description;
using System.Text;
using System.Threading.Tasks;

namespace _1104수업클라이언트
{
    class Program
    {
        static void Main(string[] args)
        {
            Example r = new Example();
            Cal[] arr = r.GetExample(10);
            for (int i = 0; i < 10; i++)
            {
                string str = r.printExample(arr[i].Num1, arr[i].Num2, arr[i].Oper);
                Console.Write(str);
                float result = float.Parse(Console.ReadLine());
                if (r.InputExample(arr[i].Num1, arr[i].Num2, arr[i].Oper, result))
                    Console.WriteLine("정답");
                else
                    Console.WriteLine("오답");
            }
        }

        private static List<Cal> GetArr(Example r)
        {
            return r.GetExample(10);
        }

    }

        //static void invokeUsingHTTP()
        //{
        //    Uri uri = new Uri("http://192.168.0.34:8888/wcf/example/helloworldservice");
        //    ServiceEndpoint ep = new ServiceEndpoint(
        //        ContractDescription.GetContract(typeof(IHelloWorld)),
        //        new BasicHttpBinding(),
        //        new EndpointAddress(uri));

        //}
    }
}
