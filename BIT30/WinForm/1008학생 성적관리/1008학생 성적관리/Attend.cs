using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1008학생_성적관리
{
    class Attend
    {
        public int AID { get; private set; }
        public int SNUM { get; private set; }
        public string ADATE { get; private set; }
        public string ATIME { get; private set; }
        public string ACHECK { get; private set; }

        public Attend(int snum, string adate, string atime, string achck)
        {
            SNUM = snum;
            ADATE = adate;
            ATIME = atime;
            ACHECK = achck;
        }
    }
}
