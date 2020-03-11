using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0926_Collection
{
    class Account
    {
        public int Id { get;  set; }
        public string Name { get;  set;  }
        public int Balance { get;  set; }
        public DateTime Date { get;  set; }

        public void AddMoney(int money)
        {
            Balance += money;
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
            Console.WriteLine("[개설일] " + Date.Year + "/"+Date.Month + "/" + Date.Date);
        }

    }
}
