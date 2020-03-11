using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1008학생_성적관리
{
    class Score
    {

        public int SCORINDEX { get;  set; }
        public int SNUM { get;  set; }
        public int SUBID { get; private set; }
        public int HOME_SCOR { get; private set; }
        public int WRITING_SCOR { get; private set; }
        public int PRACTICAL_SCOR { get; private set; }
        public string DATE { get; private set; }

        public Score(int snum, int subid, int home_score, int writing_scor, int practical_scor, string date )
        {
            SNUM = snum;
            SUBID = subid;
            HOME_SCOR = home_score;
            WRITING_SCOR = writing_scor;
            PRACTICAL_SCOR = practical_scor;
            DATE = date;
        }



    }
}
