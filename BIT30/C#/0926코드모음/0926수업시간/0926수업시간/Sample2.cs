using System;
using System.Collections.Generic;
using System.Text;

namespace _0926수업시간
{
    class Sample2
    {
        List<Account> list = new List<Account>();

        #region 검색 관련 코드 ============================
        private int Key { get; set; }
        private Predicate<Account> predicate;
        private bool FindAccount(Account s)
        {
            return s.Id == Key;
        }
        public Sample2()
        {
            predicate = FindAccount;
        }
        #endregion

        #region 정렬부분Sort
        public void sortname()
        {
            list.Sort();
        }

        public void sortbalance()
        {
            list.Sort(new BalanceCompaer());
        }

        #endregion


        //저장 : Add, Insert
        public void insert(Account data)
        {
            list.Add(data);
            Console.WriteLine("저장 성공");
        }

        public void printall()
        {
            for (int i = 0; i < list.Count; i++)
            {
                list[i].Print();
                Console.WriteLine("----------------------");
            }
        }

        public void select(int key)
        {
            try
            {
                Key = key;
                Account finddata = list.Find(predicate);
                finddata.Print();
            }
            catch (Exception)
            {
                Console.WriteLine("없다.");
            }
        }

        public void update(int key, int input, int output)
        {
            try
            {
                Key = key;
                Account acc = list.Find(predicate);
                acc.AddMoney(input);
                acc.MinMoney(output);
                Console.WriteLine("입금완료");
            }
            catch (Exception)
            {
                Console.WriteLine("없다.");
            }
        }

        public void delete(int key)
        {
            try
            {
                Key = key;
                Account acc = list.Find(predicate);
                list.Remove(acc);
                Console.WriteLine("성공");
            }
            catch (Exception)
            {
                Console.WriteLine("실패");
            }
        }
    }
}