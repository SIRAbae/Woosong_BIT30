﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;

namespace _0924cs관리프로그램
{
    class wbfile
    {
        #region 직렬화 기반 파일 IO
        public static void filesersave(object[] arr, int size)
        {
            Stream ws = new FileStream("mlist.txt", FileMode.Create);
            BinaryFormatter serializer = new BinaryFormatter();

            int max = arr.Length;
            serializer.Serialize(ws, max);
            serializer.Serialize(ws, size);

            for (int i = 0; i < size; i++)
            {
                account mem = (account)arr[i];
                serializer.Serialize(ws, mem);
            }

            ws.Close();
        }

        public static account[] fileserload(out int max)
        {
            Stream rs = new FileStream("mlist.txt", FileMode.Open);
            BinaryFormatter deserializer = new BinaryFormatter();

            max = (int)deserializer.Deserialize(rs);
            int size = (int)deserializer.Deserialize(rs);
            Console.WriteLine("불러온 최대저장개수 : {0}개", max);
            Console.WriteLine("불러온 개수 : {0}개", size);

            account[] memlist = new account[size];
            for (int i = 0; i < size; i++)
            {
                memlist[i] = (account)deserializer.Deserialize(rs);
            }
            rs.Close();
            return memlist;
        }
        #endregion
    }
}
