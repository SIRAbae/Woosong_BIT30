using System;
using System.Collections.Generic;
using System.Text;

namespace _0925계좌과업
{
    [Serializable]
    class FAcc : Member
    {

        public FAcc(int id, string name,  int balance) : base(id, name, balance)
        {
            Balance = balance + (int)(balance * 0.01);
        }

        public new void addmoney(int money)
        {
            Balance += money + (int)(money * 0.01);

        }
    }
}
