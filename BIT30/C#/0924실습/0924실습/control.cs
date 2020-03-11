using System;
using System.Collections.Generic;
using System.Text;

namespace _0924실습
{
    class control
    {
        //저장소=================================
        wbarray array = new wbarray();
        //=====================================

        public void printall()
        {
            Console.WriteLine("저장개수 : {0}개", array.Size);
            for (int i = 0; i < array.Size; i++)
            {
                member mem = array.getdata(i);// array.getdata(i);
                Console.WriteLine(mem);
            }
        }
        public void insert()
        {
            try
            {
                int id = wblib.inputnember("계좌 ID");
                String name = wblib.Inputstring("이름");
                int balance = wblib.inputnember("입 금 액");


                array.insert(new member(id, name, balance));
                Console.WriteLine("저장완료");
            }
            catch (Exception ex)
            {
                Console.WriteLine("입력 오류");
                Console.WriteLine(">>" + ex.Message);
            }
        }

        private int nametoidx(int id)
        {
            for (int i = 0; i < array.Size; i++)
            {
                member mem = array[i];
                if (mem.Id.Equals(id) == true)

                    return i;
            }
            throw new Exception("없음");      //return -1;
        }

        public void update()
        {
            try
            {
                int id = wblib.inputnember("회원 ID ");

                member mem = array[nametoidx(id)];
                int num = wblib.inputnember("입금할 금액");

                if(num>0)
                {
                    mem.Balance = mem.Balance + num;
                }

                else
                    throw new Exception("입금액 에러");

                Console.WriteLine("입금완료");


            }
            catch (Exception ex)
            {
                Console.WriteLine("유효하지 않은 ID 입니다.");
                Console.WriteLine(">>" + ex.Message);
            }

        }

        public void update1()
        {
            try
            {
                int id = wblib.inputnember("회원 ID ");

                member mem = array[nametoidx(id)];

                int num = wblib.inputnember("출금할 금액");

                if (num <= mem.Balance)
                {
                    mem.Balance = mem.Balance - num;
                }

                else
                    throw new Exception("출금액 에러");

                Console.WriteLine("출금완료");


            }
            catch (Exception ex)
            {
                Console.WriteLine("유효하지 않은 ID 입니다.");
                Console.WriteLine(">>" + ex.Message);
            }
        }
        
        public void select()
        {
            try
            {
                int id = wblib.inputnember("검색할 회원 ID");
                // int idx = nametoidx(name);
                member mem = array[nametoidx(id)];

                Console.WriteLine(mem);

            }
            catch (Exception ex)
            {
                Console.WriteLine("검색 오류");
                Console.WriteLine(">>" + ex.Message);

            }
        }
    }
}

