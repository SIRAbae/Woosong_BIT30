using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace _0926저녁실습
{
    class Control
    {
        //저장소=================================
        List<Account> acc = new List<Account>();
        //=====================================

        static Control con;
        public static Control instance
        {
            get
            {
                return con;
            }
        }

        static Control()
        {
            con = new Control();
        }

        private Control()
        {
        }
        public void SortAccount(string idx)
        {
            switch (idx)
            {
                case "1": acc.Sort(new IDComparaer()); break;
                case "2": acc.Sort(); break;
                case "3": acc.Sort(new BalanceComparaer()); break;
                default: break;
            }
        }



        public bool DelAccount(int id)
        {
            for (int i = 0; i < acc.Count; i++)
            {
                Account mem = acc[i];

                if (mem.Id == id)
                {
                    acc.Remove(mem);
                    return true;
                }
            }
            return false;
        }

        public void outputAccount(int id, int Balance)
        {

            for (int i = 0; i < acc.Count; i++)
            {
                Account mem = acc[i];

                if (mem.Id == id)
                {
                    mem.minmoney(Balance);
                    return;
                }
            }
            throw new Exception("없쥬");
        }

        public void InputAccount(int id, int Balance)
        {

            for (int i = 0; i < acc.Count; i++)
            {
                Account mem = acc[i];

                if (mem.Id == id)
                {
                    mem.addmoney(Balance);
                    return;
                }
            }
            throw new Exception("없쥬");
        }

        public Account SelectAccount(int id)
        {
            for (int i = 0; i < acc.Count; i++)
            {
                Account mem = acc[i];
                if (mem.Id == id)
                    return mem;
            }
            throw new Exception("없쥬");

        }

        public void SelectAllAccount(out List<Account> mem)//out 함수
        {
            mem = acc;
        }
        public bool AddAccount(Account mem)
        {
            try
            {
                acc.Add(mem);
                return true;
            }
            catch (Exception)
            {
                return false;
            }

        }

    }

}

