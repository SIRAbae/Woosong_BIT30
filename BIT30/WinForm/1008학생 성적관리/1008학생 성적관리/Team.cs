using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1008학생_성적관리
{
    class Team
    {
        public int TID { get; private set; }
        public string TSTARTDATE { get; private set; }
        public string TENDDATE { get; private set; }
        public string TNAME { get; private set; }


        public Team(string tstartdate, string tenddate, string tname)
        {
            TSTARTDATE = tstartdate;
            TENDDATE = tenddate;
            TNAME = tname;
        }
    }
}
