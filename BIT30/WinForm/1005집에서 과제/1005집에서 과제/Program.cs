using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1005집에서_과제
{
    static class Program
    {
        /// <summary>
        /// 해당 애플리케이션의 주 진입점입니다.
        /// </summary>
        //[STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }

        #region 콘솔(Winform사용 안함)
        //static void Main(string[] args)
        //{
        //    App ap = new App();
        //    ap.init();
        //    ap.run();
        //    ap.exit();
        //}
        #endregion


    }
}
