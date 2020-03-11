using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1018_client_시험
{
    class Packet
    {
        public static Packet Intance { get; private set; }


        static Packet()
        {
            Intance = new Packet();
        }
        private Packet()
        {

        }

        public string GetSendNumber(string id, int num)
        {
            string msg = null;
            msg += "SENDNUMBER@";         // 회원 가입 요청 메시지
            msg += id + "#";                  // 아이디
            msg += num;               // 나이

            return msg;
        }

        public string GetSendNumberSuccess(string id, int num)
        {
            string msg = null;
            msg += "SENDNUMBERSUCCESS@";         // 회원 가입 요청 메시지
            msg += id + "#";                  // 아이디
            msg += num;               // 나이

            return msg;
        }

    }
}
