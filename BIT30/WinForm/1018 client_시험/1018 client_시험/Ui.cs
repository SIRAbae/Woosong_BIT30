using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1018_client_시험
{
    class Ui
    {
        public static void LogPrint(ListBox c, string msg)
        {
            //msg = [연결].....성공
            msg += DateTime.Now.ToString();
            c.Items.Add(msg);
        }
    }
}
