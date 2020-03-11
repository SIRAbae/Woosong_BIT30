using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0412_계좌실습
{
    class AccountAddr //CONTROL
    {
        AccountManager mm = AccountManager.Singleton;

        public void AddAccount()
        {
            try
            {
                Console.WriteLine("생성 할 계좌 종류를 선택하세요. <1 : 일반 계좌  2 : 이자 계좌  3 : 기부 계좌>");
                int idx = int.Parse(Console.ReadLine());
                
                int id = IDMachine.GetNumber();
                Console.WriteLine("추가 할 이름을 입력하세요.");
                
                string name = Console.ReadLine();
                Console.WriteLine("입금액을 입력하세요.");
                int balance = int.Parse(Console.ReadLine());

                if (mm.AddAccount(id, name, balance, idx) == false)
                {
                    Console.WriteLine("{0} 정보는 이미 존재합니다.", name);
                    return;
                }
                Pause();
            }
          catch(Exception)
            {
                throw new Exception("계좌를 생성하지 못했습니다.");
            }
        }

        public void DeleteAccount()
        {
            try
            {
                Console.WriteLine("삭제할 계좌번호를 입력하세요.");
                int id = int.Parse(Console.ReadLine());

                PAccount acc = AccIdToAcc(id);
                mm.accounts.Remove(acc.Id);
                Pause();
            }
            catch (Exception)
            {
                throw new Exception("계좌를 삭제하지 못했습니다.");
            }
        }

        internal void SelectName()
        {
            try
            {
                Console.WriteLine("검색할 이름을 입력하세요.");
                string name = Console.ReadLine();

                //Account acc = AccNameToAcc(name);
                if (mm.Selectnameprint(name) == false)
                {
                    Console.WriteLine("{0} 정보가 존재하지 않습니다", name);
                    Pause();
                    return;
                }
                Pause();
            }
            catch (Exception)
            {
                throw new Exception("계좌를 삭제하지 못했습니다.");
            }

        }

        private PAccount AccNameToAcc(string name)
        {
            foreach (KeyValuePair<int, PAccount> item in mm.accounts)
            {
                if (item.Value.Name == name)
                {
                    return item.Value;
                }
            }
            throw new Exception("해당하는 계좌번호가 없습니다.");
        }

        internal void TransferAccount()
        {
            try
            {
                Console.WriteLine("계좌번호를 입력하세요.");
                int id = int.Parse(Console.ReadLine());
                Console.WriteLine("이체할 계좌번호를 입력하세요.");
                int id2 = int.Parse(Console.ReadLine());
                Console.WriteLine("이체할 금액을 입력하세요.");
                int balance = int.Parse(Console.ReadLine());

                if (mm.Transfer(id,id2,balance) == false)
                {
                    Console.WriteLine("{0} 정보가 존재하지 않습니다", id);
                    Pause();
                    return;
                }
                Pause();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                Pause();
            }
        }

        internal void SelectAccount()
        {
            try
            {
                Console.WriteLine("검색할 계좌번호를 입력하세요.");
                int id = int.Parse(Console.ReadLine());

                if (mm.Selectprint(id) == false)
                {
                    Console.WriteLine("{0} 정보가 존재하지 않습니다", id);
                    Pause();
                    return;
                }
                Pause();
            }
            catch (Exception)
            {
                throw new Exception("계좌를 삭제하지 못했습니다.");
            }

        }

        public void Withdraw()
        {
            try
            {
                Console.WriteLine("출금 할 계좌번호를 입력하세요.");
                int id = int.Parse(Console.ReadLine());
                Console.WriteLine("출금할 금액을 입력하세요");
                int balance = int.Parse(Console.ReadLine());

                //Account acc = AccIdToAcc(id);
                if (mm.Withdraw(id, balance) == false)
                {
                    Console.WriteLine("{0} 정보는 존재하지 않습니다.", id);
                    Pause();
                    return;
                }
                Pause();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                Pause();
            }
        }



        public void Deposit()
        {
            try
            {
                Console.WriteLine("송금 할 계좌번호를 입력하세요.");
                int id = int.Parse(Console.ReadLine());
                Console.WriteLine("입금할 금액을 입력하세요");
                int balance = int.Parse(Console.ReadLine());

                //Account acc = AccIdToAcc(id);
                if (mm.Deposit(id,balance) == false)
                {
                    Console.WriteLine("{0} 정보는 존재하지 않습니다.", id);
                    Pause();
                    return;
                }
                Pause();
            }
            catch (Exception)
            {
                throw new Exception("계좌를 송금하지 못했습니다.");
            }
        }

        private PAccount AccIdToAcc(int id)
        {
            foreach(KeyValuePair<int, PAccount> item in mm.accounts)
            {
                if(item.Key==id)
                {
                    return item.Value;
                }
            }
            throw new Exception("해당하는 계좌번호가 없습니다.");
        }

        public void Pause()
        {
            Console.WriteLine("\n\n아무키나 누르세요......");
            Console.ReadKey();      //입력받으면 종료
        }
    }
}
