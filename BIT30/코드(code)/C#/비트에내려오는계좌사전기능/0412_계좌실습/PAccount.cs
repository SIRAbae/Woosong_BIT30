using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0412_계좌실습
{
    abstract class PAccount
    {
        #region 멤버 필드 및 프로퍼티

        readonly int id;
        public int Id { get { return id; } }

        public int Balance { get; protected set; }        //잔액

        //readonly string name;   //이름

        public string Name
        { get; protected set; }


        readonly DateTime dtime;

        public DateTime Dtime     //개설일시   
        {
            get
            {
                return dtime;
            }
        }
        #endregion

        #region 생성자
        public PAccount(int _id, string _name, int _balance)
        {
            id = _id;
            Name = _name;
            Balance = _balance;
            dtime = DateTime.Now;

        }
        #endregion
        public virtual void AddMoney(int _balance)
        {
            if (_balance < 0)        // 마이너스 금액에 대한 예외 발생
                throw new Exception("마이너스 금액 입금 불가");

            Balance += _balance;
        }

        internal virtual void SubMoney(int _balance)
        {
            if (_balance < 0)
                throw new Exception("마이너스 금액 출금 불가");
            if (Balance < _balance)
                throw new Exception("잔액부족으로 인한 출금 불가");

            Balance -= _balance;
        }
    }
}
