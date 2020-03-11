using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0412_계좌실습
{
    class AccountEventArgs : EventArgs
    {
        #region 멤버 필드 및 프로퍼티


        public int Id { get; private set; }         // 계좌번호
        public int Balance { get; private set; }    // 잔액
        public string Name { get; private set; }
        public DateTime Dtime { get; private set; }
        public PAccount Account { get; private set; }
        #endregion


        #region 생성자
        public AccountEventArgs(PAccount acc)
        {
            Id = acc.Id;
            Balance = acc.Balance;
            Name = acc.Name;
            Dtime = acc.Dtime;
            this.Account = acc;
            
        }

        #endregion
    }
}
