using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1008학생_성적관리
{

    //과목 테이블
    class Subject
    {
        public int SUBID { get; private set; }
        public string SUBNAME { get; private set; }
        public string STARTDAY { get; private set; }
        public string ENDDAY { get; private set; }

        public Subject(string subname, string startday, string endday)
        {
            SUBNAME = subname;
            STARTDAY = startday;
            ENDDAY = endday;
        }
        
    }
}
