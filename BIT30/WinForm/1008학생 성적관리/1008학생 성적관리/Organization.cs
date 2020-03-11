using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1008학생_성적관리
{
    class Organization
    {
        public int OID { get; private set; }
        public int TID { get; private set; }
        public int SNUM { get; private set; }
       
        public Organization(int oid, int tid, int snum)
        {
            OID = oid;
            TID = tid;
            SNUM = snum;
        }
    }
}
