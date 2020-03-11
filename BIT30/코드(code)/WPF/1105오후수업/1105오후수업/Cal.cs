using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Description;
using System.Text;
using System.Threading.Tasks;

namespace _1105오후수업
{
    [DataContract]
    public class Cal
    {
        [DataMember]
        public int Num1;
        [DataMember]
        public int Num2;
        [DataMember]
        public char Oper;
    }
}
