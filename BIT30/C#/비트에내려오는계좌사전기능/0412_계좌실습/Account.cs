using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0412_계좌실습
{
    class Account:PAccount
    {
       
        public Account(int _id, string _name, int _balance):base(_id,_name,_balance)
        {

        }

        public override void AddMoney(int _balance)
        {
            if (_balance < 0)        // 마이너스 금액에 대한 예외 발생
                throw new Exception("마이너스 금액 입금 불가");

            Balance += _balance;
        }

        internal override void SubMoney(int _balance)
        {
            if (_balance < 0)
                throw new Exception("마이너스 금액 출금 불가");
            if (Balance < _balance)
                throw new Exception("잔액부족으로 인한 출금 불가");

            Balance -= _balance;
        }
    }
}
