using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace _0924연습
{
    class Program
    {
        static void filesave(member[] arr, int size)
        {
            //1.배열을 문자열로 변경
            string str = string.Empty;
            for (int i = 0; i < size; i++)
            {
                member mem = arr[i];
                str += mem.Name + "#";
                str += mem.Phone + "#";
                str += mem.Grad + "#";
                str += mem.Dept + "@";
            }
            Console.WriteLine(str);
            //2. string -> byte[]
            byte[] wBytes = Encoding.UTF8.GetBytes(str);

            //3. file save
            Stream outStream =
                new FileStream("a.txt", FileMode.Create);
            int count = wBytes.Length;
            byte[] wcount = Encoding.UTF8.GetBytes(count.ToString());
            outStream.Write(wcount, 0, wcount.Length);
            outStream.Write(wBytes, 0, wBytes.Length);
            outStream.Close();
        }

        static member[] fileload()
        {
            Stream inStream =
                new FileStream("a.txt", FileMode.Open);

            //갯수
            byte[] sizebytes = new byte[2];
            sizebytes[0] = (byte)inStream.ReadByte();
            sizebytes[1] = (byte)inStream.ReadByte();
            string str = Encoding.Default.GetString(sizebytes);
            Console.WriteLine(str);

            //본 데이터 
            byte[] rbytes = new byte[int.Parse(str)];
            int i = 0;
            while (inStream.Position < inStream.Length)
                rbytes[i++] = (byte)inStream.ReadByte();

            string str1 = Encoding.UTF8.GetString(rbytes);
            Console.WriteLine(str1);
            inStream.Close();

            //배열 담기
            string[] temp = str1.Split('@');
            member[] memlist = new member[temp.Length - 1];
            int j = 0;
            for (int i1 = 0; i1 < temp.Length - 1; i1++)
            {
                string[] temp1 = temp[i1].Split('#');
                //객체분리
                if (temp1[3].Equals("COM") == true)
                {
                    dept = 1;
                }
                else if (temp1[3].Equals("IT") == true)
                {
                    dept = 2;
                }
                else if (temp1[3].Equals("GAME") == true)
                {
                    dept = 3;
                }
                else if (temp1[3].Equals("ETC") == true)
                {
                    dept = 4;
                }
                member mem = new member(temp1[0], temp1[1], (enumdept)dept//int.Parse(temp1[3])
                    , int.Parse(temp1[2]));
                memlist[j++] = mem;
            }
            return memlist;
        }

        static void Main(string[] args)
        {
            //member[] memlist = new member[3];
            //memlist[0] = new member("홍길동", "111", enumdept.COM, 1);
            //memlist[1] = new member("이길동", "222", enumdept.IT, 2);
            //memlist[2] = new member("고길동", "333", enumdept.GAME, 3);

            //filesave(memlist, 3);

            member[] memlist1;
            memlist1 = fileload();

            //결과 출력
            Console.WriteLine("결과출력");
            for (int i = 0; i < memlist1.Length; i++)
            {
                Console.WriteLine(memlist1[i]);
            }

            //           app ap = new app();
            //           ap.init();
            //           ap.run();
            //           ap.exit();
        }
    }
}