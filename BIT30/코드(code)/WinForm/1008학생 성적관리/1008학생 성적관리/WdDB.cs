using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1008학생_성적관리
{
    class WdDB
    {

        List<Student> stulist = new List<Student>();
        SqlConnection conn;


        public string Constr1 { get; private set; }
        public string Constr2 { get; private set; }

        public WdDB()
        {
            conn = new SqlConnection();
            Constr1 = @"Server=DESKTOP-L0CJR7G\SQLEXPRESS;database= wb30;uid=ysb2;pwd=1234;";
            Constr2 = @"Server=user-pc;database=wb30;uid=ccm;pwd=1234;;";
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

        private bool ExSqlCommand(string comstr)
        {
            SqlCommand scom = new SqlCommand();
            scom.Connection = conn;
            scom.CommandText = comstr;
            scom.CommandType = System.Data.CommandType.Text;
            //page112
            if (scom.ExecuteNonQuery() > 0)         //1)DDL, I, U, D
            {
                scom.Dispose();
                return true;
            }
            scom.Dispose();
            return false;
        }

        public Student SelectProduct1(int snum, string combodata)
        {
            string comtext =
                string.Format("select (slect * from Student;) from Student, Subject, Score where snum = {0} and SUBNAME={1}; ", snum, combodata);
            SqlCommand command = new SqlCommand(comtext, conn);
            SqlDataReader reader = command.ExecuteReader();//2)s 전용
            if (reader.Read() == false)
                return null;

            Student stu = new Student(
                int.Parse(reader[0].ToString()),
                reader[1].ToString(),
                reader[2].ToString(),
                int.Parse(reader[3].ToString()),
                reader[4].ToString(),
                reader[5].ToString()               
                );
             
            //reader[1].ToString(),
            //int.Parse(reader[2].ToString()),
            //reader[3].ToString());
            stu.SNUM = int.Parse(reader[5].ToString());
            // s.SIMG = (Byte[])reader[6];
            stulist.Add(stu);
            reader.Close();
            command.Dispose();

            return stu;
        }

        public Student SelectProduct2(int snum)
        {
            string comtext =
                string.Format("select * from Student where snum = {0};", snum);
            SqlCommand command = new SqlCommand(comtext, conn);
            SqlDataReader reader = command.ExecuteReader();//2)s 전용
            if (reader.Read() == false)
                return null;

            Student stu = new Student(
                int.Parse(reader[0].ToString()),
                reader[1].ToString(),
                reader[2].ToString(),
                int.Parse(reader[3].ToString()),
                reader[4].ToString(),
                reader[5].ToString()
                );

            //reader[1].ToString(),
            //int.Parse(reader[2].ToString()),
            //reader[3].ToString());
            stu.SNUM = int.Parse(reader[5].ToString());
            // s.SIMG = (Byte[])reader[6];
            stulist.Add(stu);
            reader.Close();
            command.Dispose();

            return stu;
        }

        public Student SelectProduct3(int snum)
        {
            string comtext =
                string.Format("SELECT sid as 학번, 평균점수, 순위 as 내등수 " +
                "FROM (SELECT DENSE_RANK() OVER(ORDER BY 전체평균.평균점수 desc) as 순위, sid, 전체평균.평균점수 FROM (SELECT sid, AVG(home_Score + writing_Score + practical_score) as 평균점수 FROM score GROUP BY snum) as 전체평균) as 전체등수 WHERE snum = {0}; ", snum);
            SqlCommand command = new SqlCommand(comtext, conn);
            SqlDataReader reader = command.ExecuteReader();//2)s 전용
            if (reader.Read() == false)
                return null;

            Student stu = new Student(
                int.Parse(reader[0].ToString()),
                reader[1].ToString(),
                reader[2].ToString(),
                int.Parse(reader[3].ToString()),
                reader[4].ToString(),
                reader[5].ToString()
                );

            //reader[1].ToString(),
            //int.Parse(reader[2].ToString()),
            //reader[3].ToString());
            stu.SNUM = int.Parse(reader[5].ToString());
            // s.SIMG = (Byte[])reader[6];
            stulist.Add(stu);
            reader.Close();
            command.Dispose();

            return stu;
        }
    }
}
