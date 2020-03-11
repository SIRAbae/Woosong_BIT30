using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1008학생_성적관리
{
    class Student
    {
        public int SID { get; private set; }
        public string SPW { get; private set; }
        public string SNAME { get; private set; }
        public int SGRADE { get; private set; }
        public int SNUM { get;  set; }
        public string SDRPT { get;  set; }
        public string PHONE { get;  set; }
        // public byte[] SIMG { get;  set; }

        public Student(int sid, string spw, string sname, int sgrade, string sdept, string phone/*, byte[] simg*/)
        {
            SID = sid;
            SPW = spw;
            SNAME = sname;
            SGRADE = sgrade;

            SDRPT = sdept;
            PHONE = phone;
            // SIMG = simg;
        }



    }
}
