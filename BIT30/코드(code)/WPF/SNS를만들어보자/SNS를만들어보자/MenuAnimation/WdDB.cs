using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace MenuAnimation
{
    class WdDB
    {
        List<ACCDATA> accdata = new List<ACCDATA>();
        SqlConnection conn;


        public string Constr1 { get; private set; }
       // public string Constr2 { get; private set; }

        public WdDB()
        {
            conn = new SqlConnection();
            Constr1 = @"Server=DESKTOP-L0CJR7G\SQLEXPRESS;database= DESKTOP-L0CJR7G\SQLEXPRESS;uid=ysb2;pwd=1234;";
           // Constr2 = @"Server=user-pc;database=wb30;uid=ccm;pwd=1234;;";
            conn.ConnectionString = Constr1;



        }




        #region 연결 관련


        public bool Connect()
        {
            try
            {
                conn.Open();    //  데이터베이스 연결
                //Console.WriteLine("데이터베이스 연결 성공...");
                MessageBox.Show("연결 썽꽁00");
                return true;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return false;
            }



        }
        public void DisConnect()
        {
            conn.Close();
            MessageBox.Show("데이터베이스 연결 해제");
        }
        #endregion

    }
}
