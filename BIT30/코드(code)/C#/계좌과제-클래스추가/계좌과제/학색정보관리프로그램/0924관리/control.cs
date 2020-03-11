using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0924관리
{
    class control
    {
        //저장소============================
        wbArr arr = new wbArr();
        wbioArr ioarr = new wbioArr();
        //=====================================
        public void printall()
        {
            Console.WriteLine("저장된 계좌 개수 : {0}개", arr.Size);
            for (int i = 0; i < arr.Size; i++)
            {
                member mem = arr[i];
                Console.WriteLine(mem);
            }
        }
        public void makeaccount()
        {
            try
            {
                int id = wblib.inputnumber("계좌ID");
                string name = wblib.inputstring("이름");
                int balance = wblib.inputnumber("입금액");
                arr.makeacc(new member(id, balance, name));

                ioarr.makeacc(new acciolist(id, balance, 0, balance));
            }
            catch (Exception ex)
            {
                Console.WriteLine("계좌생성 에러");
                Console.WriteLine(" >> " + ex.Message);
            }
        }
        private int nametoidx(string name)
        {
            for (int i = 0; i < arr.Size; i++)
            {
                member mem = arr[i];
                if (mem.M_name.Equals(name) == true)
                {
                    return i;
                }
            }
            throw new Exception("검색 실패");       //return -1;
        }
        private int idtoidx(int id)
        {
            for (int i = 0; i < arr.Size; i++)
            {
                member mem = arr[i];
                if (mem.M_id.Equals(id) == true)
                {
                    return i;
                }
            }
            throw new Exception("검색 실패");       //return -1;
        }
        private int acctoimoney(int id)
        {
            int result = 0;
            for(int i = 0; i<ioarr.Size; i++)
            {
                acciolist acc = ioarr[i];
                if (acc.Id.Equals(id) == true)
                {
                    result += acc.Imoney;
                }
            }
            return result;
            //throw new Exception("입금액 에러");
        }
        private int acctoomoney(int id)
        {
            int result = 0;
            for (int i = 0; i < ioarr.Size; i++)
            {
                acciolist acc = ioarr[i];
                if (acc.Id.Equals(id) == true)
                {
                    result += acc.Omoney;
                }
            }
            return result;
            //throw new Exception("입금액 에러");
        }
        private int acctobalance(int id)
        {
            int result = 0;
            for (int i = 0; i < ioarr.Size; i++)
            {
                acciolist acc = ioarr[i];
                if (acc.Id.Equals(id) == true)
                {
                    result += acc.Balance;
                }
            }
            return result;
            //throw new Exception("입금액 에러");
        }
        public void Inquire()
        {
            try
            {
                int id = wblib.inputnumber("검색할 계좌ID");
                member mem = arr[idtoidx(id)];
                
                Console.WriteLine(mem);
                for(int i = 0; i<ioarr.Size; i++)
                {
                    acciolist acc = ioarr[i];
                    if (acc.Id.Equals(id) == true)
                    {
                        Console.WriteLine(acc);
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("검색 에러");
                Console.WriteLine(" >> " + ex.Message);
            }
        }
        public void Deposit()
        {
            try
            {
                int id = wblib.inputnumber("입금할 계좌ID");
                member mem = arr[idtoidx(id)];

                int money = wblib.inputnumber("입금할 금액 : ");
                mem.M_balance = mem.M_balance + money;

                int balance = acctobalance(mem.M_id) + money;
                ioarr.makeacc(new acciolist(mem.M_id, money, 0, balance));

                Console.WriteLine("입금 완료");
                Console.WriteLine(mem);
            }
            catch (Exception ex)
            {
                Console.WriteLine("입금 에러");
                Console.WriteLine(" 유효하지 않은 ID 입니다. " + ex.Message);
            }
        }
        public void Withdraw()
        {
            try
            {
                int id = wblib.inputnumber("출금할 계좌ID");
                member mem = arr[idtoidx(id)];


                int money = wblib.inputnumber("출금할 금액 : ");
                mem.M_balance = mem.M_balance - money;

                int balance = acctobalance(mem.M_id) - money;
                ioarr.makeacc(new acciolist(mem.M_id, 0, money, balance));
                Console.WriteLine("출금 완료");
                Console.WriteLine(mem);
            }
            catch (Exception ex)
            {
                Console.WriteLine("출금 에러");
                Console.WriteLine(" 유효하지 않은 ID 입니다. " + ex.Message);
            }
        }
    }
}
