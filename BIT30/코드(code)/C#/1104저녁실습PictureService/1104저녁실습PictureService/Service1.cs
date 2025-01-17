﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Services;

namespace _1104저녁실습PictureService
{
    class PictureService : IPictureService
    {
        // 해당 이미지 파일을 서비스해주는 메서드
        [WebMethod]	// 웹메소드 속성을 가진다는 것을 명시
        public byte[] GetPicture(string strFileName)
        {
            byte[] bytePic = { 0 }; // 바이트 배열을 하나 만든다.
            try
            {
                // 해당 이미지 파일을 스트림 형식으로 오픈한다.
                FileStream picFileStream = new
             FileStream(@"D:\WCF\제비\" + strFileName, FileMode.Open,
             FileAccess.Read, FileShare.Read);

                // 이미지 파일 스트림을 읽을 객체를 하나 만든다.
                BinaryReader picReader = new BinaryReader(picFileStream);
                // 이미지 파일을 바이트 배열에 넣는다.
                bytePic = picReader.ReadBytes(Convert.ToInt32(picFileStream.Length));
                // 파일스트림을 닫는다.
                picFileStream.Close();
                // 이미지 파일이 들어있는 바이트 배열을 리턴한다.
                return bytePic;
            }
            catch
            {
                // 초기값을 그냥 리턴한다.
                return bytePic;
            }

        }

        // 이미지 파일 목록을 리턴해주는 메서드
        [WebMethod]
        public string[] GetPictureList()
        {
            // 이미지 파일이 들어있는 디렉토리에서 파일 이름들을 문자열 배열에 넣는다.
            string[] strPicList = Directory.GetFiles(@"D:\WCF\제비\");

            // 파일 경로를 뺀 파일 이름만 다시 추출한다.
            for (int i = 0; i < strPicList.Length; i++)
            {
                FileInfo fi = new FileInfo(strPicList[i]);
                strPicList[i] = fi.Name;
            }
            // 이 이미지 파일 이름들을 리턴한다.
            return strPicList;

        }

        // 클라이언트들이 업로드하는 이미지 파일들을 저장하는 메서드
        [WebMethod]
        public bool UploadPicture(string strFileName, byte[] bytePic)
        {
            try
            {
                // 주어진 이미지 파일의 이름으로 파일을 하나 만든다.
                FileStream writeFileStream = new FileStream(
              @"D:\WCF\제비\" + strFileName, FileMode.Create,
              FileAccess.Write);

                // 이 파일에 바이너리를 넣기 위해 BinaryWriter 객체 생성
                BinaryWriter picWriter = new BinaryWriter(writeFileStream);
                // 바이트 배열로 받은 이미지를 파일에 쓴다.
                picWriter.Write(bytePic);
                // 파일스트림을 닫는다.
                writeFileStream.Close();
                // 업로드 성공
                return true;
            }
            catch (Exception e)
            {
                // 업로드 실패
                return false;
            }

        }
    }
}
