using System;
using System.Collections.Generic;
using System.Text;

namespace _0925계좌과업
{
    [Serializable]
    class CAcc : Member
    {
        public int cAcc { get; private set; }

        public CAcc(string name, int id, int balance) : base(id, name, balance)
        {
            Balance = balance - (int)(balance * 0.01);
            cAcc = (int)(balance * 0.01);

        }

        public new void addmoney(int money)
        {
            Balance += money - (int)(money * 0.01);
            cAcc += (int)(money * 0.01);
        }
        public new void Print()
        {
            Console.WriteLine("이름 : " + Name);
            Console.WriteLine("계좌번호 : " + Id);
            Console.WriteLine("잔액 : " + Balance);
            Console.WriteLine("기부금 : " + cAcc);

        }

        public override string ToString()
        {
            string temp = string.Format("[{0}] 계좌 : {1} 잔액 : {2} 기부금:{3}", Name, Id, Balance, cAcc);
            return temp;
        }
    }
}
