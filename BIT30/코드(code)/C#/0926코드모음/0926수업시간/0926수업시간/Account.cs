using System;
using System.Collections.Generic;
using System.Text;

namespace _0926수업시간
{
    class Account : IComparable
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public int Balance { get; set; }
        public DateTime Date { get; set; }

        public void AddMoney(int money)
        {
            Balance += money;
        }

        public int CompareTo(object obj)
        {
            Account acc = obj as Account;
            if (acc == null)
            {
                throw new Exception("잘못된 객체 전달");

            }
            return Name.CompareTo(acc.Name);
            
        }

        public void MinMoney(int money)
        {
            Balance -= money;
        }

        public void Print()
        {
            Console.WriteLine("[계좌번호] " + Id);
            Console.WriteLine("[이름] " + Name);
            Console.WriteLine("[잔액] " + Balance);
            Console.WriteLine("[개설일] " + Date.Year + "/" + Date.Month + "/" + Date.Date);
        }

    }

    class BalanceCompaer : IComparer<Account>
    {
        public int Compare(Account x, Account y)
        {
            return x.Balance - y.Balance;
        }
    }
}
