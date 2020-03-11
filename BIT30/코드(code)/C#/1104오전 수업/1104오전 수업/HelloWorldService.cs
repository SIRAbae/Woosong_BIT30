using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;

namespace _1104오전_수업
{
    [ServiceContract]
    public interface IHelloWorld
    {
        [OperationContract]
        string SayHello();

        [OperationContract]
        int Add(int n1, int n2);

        int Sub(int n1, int n2);
    }

    public class HelloWorldWCFService : IHelloWorld
    {
        public int Add(int n1, int n2)
        {
            return n1 + n2;
        }

        public string SayHello()
        {
            return "Hello WCF World!";
        }

        public int Sub(int n1, int n2)
        {
            return n1 - n2;
        }
    }
}
