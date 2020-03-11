using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace _0926수업시간
{
    class Sample3
    {
        Hashtable list = new Hashtable();

        #region 검색 관련 코드 ============================
       
        #endregion 

        //저장 : Add, Insert
        public void insert(Account data)
        {
            //list.Add(data.Id, data);
            list[data.Id] = data;
            Console.WriteLine("검색성공");

        }

        public void printall()
        {
            foreach (DictionaryEntry d in list)
            { 
                Console.WriteLine("KEY : "+ d.Key);
                Account acc = (Account)d.Value;
                acc.Print();
            }
        }

        public void select(int key)
        {
            try
            {
                Account acc = (Account)list[key];
                acc.Print();


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

                Account acc = (Account)list[key];
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
                Account acc = (Account)list[key];
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
