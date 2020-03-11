using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MenuAnimation
{
    class ACCDATA
    {
        public int ACC_NUM { get; private set; }
        public string ACC_NAME { get; private set; }
        public string ACC_IMAGE{ get; private set; }
        public string ACC_ID{ get; private set; }
        public string ACC_PW{ get; private set; }
        public string ACC_PROFILE{ get; private set; }
        public string ACC_DATE{ get; private set; }


        public ACCDATA(int acc_num, string acc_name, string acc_image, string acc_id, string acc_pw, string acc_profile ,string acc_date)
        {
            ACC_NUM = acc_num;

            ACC_NAME = acc_name;

            ACC_IMAGE = acc_image;

            ACC_ID = acc_id;

            ACC_PW = acc_pw;

            ACC_PROFILE = acc_profile;

            ACC_DATE = acc_date;

        }
    }
}
