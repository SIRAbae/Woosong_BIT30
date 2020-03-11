using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0924관리
{
    class member
    {
        public string M_name { get; private set; }
        private int m_id;
        private int m_balance;

        #region 프로퍼티
        public int M_balance
        {
            get { return m_balance; }
            set
            {
                if (value <= 0)
                    throw new Exception("잘못된 잔액");
                else
                    m_balance = value;
            }
        }
        public int M_id
        {
            get { return m_id; }
            set
            {
                if (value <= 0 && value >=10000)
                    throw new Exception("잘못된 아이디( 0 ~ 9999 )");
                else
                    m_id = value;
            }
        }
        #endregion

        #region 생성자
        public member(int i, int b, string n)
        {
            M_name = n;
            M_id = i;
            M_balance = b;
        }

        #endregion

        #region 메서드
        public void Print()
        {
            Console.WriteLine("계좌  ID : " + M_name);
            Console.WriteLine("이    름 : " + M_id);
            Console.WriteLine("잔    액 : " + M_balance);
        }

        public override string ToString()
        {
            string temp = string.Format("[ 계좌ID ] : {0}  [ 예금주명 ] : {1}  [ 잔액 ] : {2} ", M_id, M_name, M_balance);
            return temp;
        }
        #endregion
    }
}