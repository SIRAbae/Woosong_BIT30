using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1017ADO_패킷client
{
    class Member
    {
        public string ID { get; set; }
        public string PW { get; set; }
        public string NAME { get; private set; }
        public int AGE { get; set; }

        public Member(string id, string pw, string name, int age)
        {
            ID = id;
            PW = pw;
            NAME = name;
            AGE = age;
        }
    }
    class MemberControl
    {
        private List<Member> memlist = new List<Member>();
        #region 싱글톤
        public static MemberControl Intance { get; private set; }


        static MemberControl()
        {
            Intance = new MemberControl();
        }
        private MemberControl()
        {

        }
        #endregion
        public bool Insert(Member mem)
        {
            try
            {
                memlist.Add(mem);
                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }

        

    }
}
