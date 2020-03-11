using System;
using System.Collections.Generic;
using System.Text;

namespace _0926저녁실습
{
    class Account
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

        public Account(int id, string name, int balance)
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

        #region 복붙한곳
        public override string ToString()
        {
            string temp = string.Format("[{0}] 계좌 : {1} 잔액 : {2}", Name, Id, Balance);
            return temp;
        }


        public int CompareTo(object obj)
        {
            Account acc = obj as Account;
            if (acc == null)
                throw new Exception("잘못된 객체 전달");

            return Name.CompareTo(acc.Name);
        }
        #endregion

        public void addmoney(int account)
        {
            Balance += account;
        }


        public void minmoney(int account)
        {
            Balance -= account;
        }
        
        
    }
    //내림 차순
    class BalanceComparaer : IComparer<Account>
    {
        public int Compare(Account x, Account y)
        {
            return y.Balance - x.Balance;
        }
    }


    //오름 차순
    class IDComparaer : IComparer<Account>
    {
        public int Compare(Account x, Account y)
        {
            return x.Id - y.Id;
        }
    }



}
