using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1017ADO_패킷client
{
    class Packet
    {

        //싱글톤
        public static Packet Intance { get; private set; }


        static Packet()
        {
            Intance = new Packet();
        }
        private Packet()
        {

        }

        #region 클라이언트--> 서버전송

        public string GetNewMember(string id, string pw, string name, int age)
        {
            string msg = null;
            msg += "NEWMEMBER@";         // 회원 가입 요청 메시지
            msg += id + "#";                  // 아이디
            msg += pw + "#";                 // 암호
            msg += name + "#";                // 이름
            msg += age;               // 나이

            return msg;
        }

        public string GetDelMember(string id)
        {
            string msg = null;
            msg += "DELMEMBER@";         // 회원 가입 요청 메시지
            msg += id;                  // 아이디

            return msg;
        }

        public string GetLogin(string id, string pw)
        {
            string msg = null;
            msg += "LOGIN@";         // 회원 가입 요청 메시지
            msg += id + "#";                  // 아이디
            msg += pw;                 // 암호

            return msg;
        }

        public string GetLogout(string id)
        {
            string msg = null;
            msg += "LOGOUT@";         // 회원 가입 요청 메시지
            msg += id;                  // 아이디


            return msg;
        }

        public string GetMessage(string data)
        {
            string msg = null;
            msg += "MESSAGE@";         // 회원 가입 요청 메시지
            msg += data;
            return msg;
        }
        #endregion

        #region 서버--> 클라이언트 응답

        public string GetNewMemberAck(string id, string name, bool b)
        {
            string msg = null;
            msg += "NEWMEMBERACK@";         // 회원 가입 요청 메시지
            msg += b + "#";
            msg += id + "#";                  // 아이디                      
            msg += name;                // 이름
             
            return msg;
        }

        public string GetDelMemberAck(string id, bool b)
        {
            string msg = null;
            msg += "DELMEMBERACK@";         // 회원 가입 요청 메시지
            msg += b + "#";
            msg += id;               // 아이디                      

            return msg;
        }


        public string GetLoginAck(string id, string name, bool b)
        {
            string msg = null;
            msg += "LOGINACK@";         // 회원 가입 요청 메시지
            msg += b + "#";
            msg += id + "#";                  // 아이디                      
            msg += name;                // 이름

            return msg;
        }

        public string GetLogoutAck(string id, bool b)
        {
            string msg = null;
            msg += "LOGOUTACK@";         // 회원 가입 요청 메시지
            msg += b + "#";
            msg += id;                  // 아이디                      
            return msg;
        }

        public string GetMessageAck(string data)
        {
            string msg = null;
            msg += "MESSAGEACK@";         // 회원 가입 요청 메시지
            msg += data;
            return msg;
        }

        #endregion

        //#region 수신패킷 분석
        //public void PaserByteData(byte[] data)
        //{
        //    string msg = Encoding.Default.GetString(data);
        //    string[] token = msg.Split('@');
        //    switch (token[0].Trim())
        //    {
        //        case "NEWMEMBER": NewMember(token[1]); break;


        //    }
        //}
        //#endregion

        //#region 수신 패킷 처리
        //void NewMember(string msg)
        //{
        //    string[] sp = msg.Split('#');

        //    Member mem = new Member(sp[0], sp[1], sp[2], int.Parse(sp[3]));

        //    MemberControl.Intance.Insert(mem);
        //}
        //#endregion
    }


}