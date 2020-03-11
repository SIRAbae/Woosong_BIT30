using System;
using System.Collections.Generic;
using System.Text;

namespace _0925계좌과업
{
    class Control
    {
        //저장소=================================
        wbarray array = new wbarray();
        App app = new App();
        //=====================================

        public void printall()
        {
            Console.WriteLine("저장개수 : {0}개", array.Size);
            for (int i = 0; i < array.Size; i++)
            {
                Member mem = array.getdata(i);// array.getdata(i);
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
                string give = wblib.Inputstring("1.기부계좌 2.신용계좌 3.일반계좌");

                switch (give)
                {
                    case "1": array.insert(new CAcc(name, id, balance)); break;
                    case "2": array.insert(new FAcc(id, name, balance)); break;
                    case "3": array.insert(new Member(id,  name, balance)); break;
                    default: Console.WriteLine("저장 실패"); break;
                }

                array.insert(new Member(id, name, balance));
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
                Member mem = array[i];
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
                int Balance = wblib.inputnember("입금할 금액");

                Member mem = (Member)array[nametoidx(id)];
                if (mem is CAcc)
                {
                    CAcc cac = (CAcc)mem;
                    cac.addmoney(Balance);
                }

                else if (mem is FAcc)
                {
                    FAcc fac = (FAcc)mem;
                    fac.addmoney(Balance);
                }

                else
                { mem.addmoney(Balance); }


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
                int money = wblib.inputnember("출금액");
                Member mem = array[nametoidx(id)];

                if (money < 0 || mem.Balance < money)
                {
                    Console.WriteLine("잘못된 금액");
                    return;
                }

               

                mem.Balance -= money;
            

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
                Member mem = array[nametoidx(id)];

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

