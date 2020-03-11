using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927
{
    delegate void DelResult(int n1, char op, int n2, int n3);
    
    class Cal
    {
        public DelResult delresult = null;
        public event CalEvent log = null;

        public int Num1 { get; set; }
        public int Num2 { get; set; }

        public int Num3 { get; set; }

        public void Set(int num1, int num2)
        {
            Num1 = num1;
            Num2 = num2;

            LogMessage("set");
        }

        public void Add()
        {
            Num3 = Num1 + Num2;
            delresult(Num1, '+', Num2, Num3);

            LogMessage("add");
        }

        public void Sub()
        {
            Num3 = Num1 - Num2;
            delresult(Num1, '-', Num2, Num3);

            LogMessage("sub");
        }

        //event 발생(게시)함수 
        private void LogMessage(string msg)
        {
            if (log != null)
            {
                log(this, new CalEventArgs(msg, Num1, Num2, Num3));
            }
        }
    }
}
