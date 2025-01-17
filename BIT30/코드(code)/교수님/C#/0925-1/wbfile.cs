﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0924관리프로그램
{
    class wbfile
    {
        #region 바이트 배열 기반 파일 IO
        public static void filesave(member[] arr, int size)
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

        public static member[] fileload()
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
                //객체 분리
                member mem = new member(
                    temp1[0],
                    temp1[1],
                    (enumdept)2,//int.Parse(temp1[3]), 
                    int.Parse(temp1[2]));
                memlist[j++] = mem;
            }
            return memlist;
        }
       
        #endregion 
    }
}
