using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0924관리
{
    class acciolist
    {
        private int id;
        public int Imoney { get; set; }
        public int Omoney { get; set; }
        private int balance;
        private string date;

        #region 프로퍼티
        public int Id
        {
            get { return id; }
            set
            {
                if (id < 0)
                    throw new Exception("잘못된 아이디");
                else
                    id = value;
            }
        }
        public string Date
        {
            get;
            private set;
        }
        public int Balance
        {
            get { return balance; }
            set
            {
                if (value < 0)
                    throw new Exception("잘못된 잔액");
                else
                    balance = value;
            }
        }
        #endregion

        public acciolist(int i, int im, int om, int b)
        {
            Id = i;
            Imoney = im;
            Omoney = om;
            Balance = b;
            Date = DateTime.Now.ToString("yyyy-MM-dd");
        }

        public override string ToString()
        {
            string temp = string.Format("[ 계좌ID ] : {0}  [ 입금액 ] : {1}  [ 출금액 ] : {2}  [ 잔액 ] : {3}  [ 일시 ] : {4}"
                , Id, Imoney, Omoney, Balance, Date);
            return temp;
        }
    }
}
