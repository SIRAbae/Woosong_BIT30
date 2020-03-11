using System;
using System.Collections.Generic;
using System.Text;

namespace _0925계좌과업
{
    [Serializable]
    class Member // Account : 일반계좌
    {
        public int Id { get; private set; }
        public string Name { get; private set; }
        public int Balance;
        public int balance
        {
            get { return Balance; }
            set
            {
                if (value >= 0)
                    Balance = value;
            }
        }
        //  public float Sel { get; private set; }

        public Member(int id, string name, int balance)
        {
            Id = id;
            Name = name;
            Balance = balance;
            
           // Sel = MemberSel();
        }

        public void Print()
        {
            Console.WriteLine("******** 계좌 개설 ********");
            Console.WriteLine("계좌  ID : " + Id);
            Console.WriteLine("이    름 : " + Name);
            Console.WriteLine("입 금 액 : " + Balance);
        }

        public override string ToString()
        {
            string temp =
                string.Format("[{0}] {1}, {2}원",
                                Id, Name, Balance);
            return temp;
        }
        public void addmoney(int money)
        {
            Balance += money;
        }

    }




}
