using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;

namespace _1104저녁실습2
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
