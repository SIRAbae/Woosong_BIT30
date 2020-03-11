using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0412_계좌실습
{
    class AccountViewer
    {
        AccountManager mm = AccountManager.Singleton;

        public AccountViewer()
        {
            //이벤트 처리기 등록
            //계좌생성
            mm.AccountEventHandler +=  new AccountEvent(mm_AddAccountEventHandler);
            //입금
            mm.DepositEventHandler += new AccountEvent(mm_DepositEventHandler);
            //출금
            mm.WithdrawEventHandler += new AccountEvent(mm_WithdrawEventHandler);
            //선택출력 - 계좌번호로 검색
            mm.SelectEventHandler += new AccountEvent(mm_SelectEventHandler);
            //계좌이체
            mm.TransferEventHandler += new AccountEvent(mm_TransferEventHandler);
            //선택출력 - 이름으로 검색
            mm.SelectNameEventHandler += new AccountEvent(mm_SelectNameEventHandler);
        }

        private void mm_SelectNameEventHandler(object obj, AccountEventArgs e)
        {
            Console.WriteLine("선택하신 계좌입니다.");
            Console.WriteLine("계좌번호 :{0} 이름 : {1}, 잔액 : {2}, 개설일 : {3}", e.Id, e.Name, e.Balance, e.Dtime);

        }

        private void mm_TransferEventHandler(object obj, AccountEventArgs e)
        {
            Console.WriteLine("계좌이체가 완료되었습니다.");
            Console.WriteLine("계좌번호 :{0} 이름 : {1}, 잔액 : {2}, 개설일 : {3}", e.Id, e.Name, e.Balance, e.Dtime);
        }

        private void mm_SelectEventHandler(object obj, AccountEventArgs e)
        {
            Console.WriteLine("선택하신 계좌입니다.");
            Console.WriteLine("계좌번호 :{0} 이름 : {1}, 잔액 : {2}, 개설일 : {3}", e.Id, e.Name, e.Balance, e.Dtime);
        }

        private void mm_WithdrawEventHandler(object obj, AccountEventArgs e)
        {
            Console.WriteLine("출금되었습니다.");
            Console.WriteLine("계좌번호 :{0} 이름 : {1}, 잔액 : {2}, 개설일 : {3}", e.Id, e.Name, e.Balance, e.Dtime);
        }

        private void mm_DepositEventHandler(object obj, AccountEventArgs e)
        {
            Console.WriteLine("입금되었습니다.");
            Console.WriteLine("계좌번호 :{0} 이름 : {1}, 잔액 : {2}, 개설일 : {3}", e.Id, e.Name, e.Balance, e.Dtime);
        }

        public void mm_AddAccountEventHandler(object obj, AccountEventArgs e)
        {
            Console.WriteLine("회원이 추가되었습니다.");
            Console.WriteLine("계좌번호 :{0} 이름 : {1}, 잔액 : {2}, 개설일 : {3}", e.Id, e.Name, e.Balance, e.Dtime);
        }

        public void PrintAll()
        {
            foreach (KeyValuePair<int, PAccount> item in mm.accounts)
            {
                Console.WriteLine("계좌번호 :{0} 이름 : {1}, 잔액 : {2}, 개설일 : {3}", item.Key, item.Value.Name, item.Value.Balance, item.Value.Dtime);
                Console.WriteLine("----------------------------------------------------------------");
            }
        }


    }
    
}
