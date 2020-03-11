using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;

namespace _1105오후수업
{
    [ServiceContract]
    interface IExample
    {
        [OperationContract]
        List<Cal> GetExample(int n1);

        [OperationContract]
        bool InputExample(int n1, int n2, char c1, float f1);

        [OperationContract]
        string printExample(int n1, int n2, char c1);

    }
}
