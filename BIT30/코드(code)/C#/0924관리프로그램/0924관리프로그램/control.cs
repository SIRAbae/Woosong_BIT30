using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0924관리프로그램
{
    class control
    {
        //저장소=======================
        wbarray array = new wbarray();
        //=============================

        public void printall()
        {
            Console.WriteLine("저장개수 : {0}개", array.Size);
            for(int i=0; i<array.Size; i++)
            {
                member mem = array[i];// array.getdata(i);
                Console.WriteLine(mem); 
            }
        }

        public void insert()
        {
            try
            {
                string name = wblib.inputstring("이름");
                string phone = wblib.inputstring("전화번호");
                int grad = wblib.inputnumber("학년");
                enumdept dept = (enumdept)wblib.inputnumber("학과 [1]컴 [2]IT [3]게임 [4]기타");

                array.insert(new member(name, phone, dept, grad));
                Console.WriteLine("저장 완료");
            }
            catch(Exception ex)
            {
                Console.WriteLine("입력 오류");
                Console.WriteLine(">> " + ex.Message);
            }
        }

        private int nametoidx(string name)
        {
            for(int i=0; i<array.Size; i++)
            {
                member mem = array[i];
                if (mem.Name.Equals(name) == true)
                    return i;
            }
            throw new Exception("없음");      //return -1;
        }

        public void select()
        {
            try
            {
                string name = wblib.inputstring("검색 이름");

                member mem = array[nametoidx(name)];
                Console.WriteLine(mem);
            }
            catch(Exception ex)
            {
                Console.WriteLine("검색 에러");
                Console.WriteLine(">> " + ex.Message);
            }
        }

        public void update()
        {
            try
            {
                string name = wblib.inputstring("수정 이름");

                member mem = array[nametoidx(name)];

                mem.Phone = wblib.inputstring("전화번호");
                mem.Grad = wblib.inputnumber("학년");
                mem.Dept = (enumdept)wblib.inputnumber("학과 [1]컴 [2]IT [3]게임 [4]기타");

                Console.WriteLine("수정 완료");
            }
            catch (Exception ex)
            {
                Console.WriteLine("수정 에러");
                Console.WriteLine(">> " + ex.Message);
            }
        }

        public void delete()
        {
            try
            {
                string name = wblib.inputstring("삭제 이름");

                int idx = nametoidx(name);
                array.erase(idx);
                Console.WriteLine("삭제 완료");
            }
            catch (Exception ex)
            {
                Console.WriteLine("삭제 에러");
                Console.WriteLine(">> " + ex.Message);
            }
        }
    }
}
