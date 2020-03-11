using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_실습
{
    class Money
    {
        private int inputmoney;

        public int Inputmoney
        {
            get { return inputmoney; }
            set {
                if (value < 0)
                    throw new Exception("잔액이 부족합니다.");
                else
                    inputmoney = value;
            }
        }

        public Money(int in_m)
        {
            Inputmoney = in_m;
        }

        public override string ToString()
        {
            string temp = string.Format("투입금액 {0}원",inputmoney);

            return temp;
        }

    }
}
