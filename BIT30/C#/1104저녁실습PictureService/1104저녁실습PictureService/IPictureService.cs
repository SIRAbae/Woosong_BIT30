using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;

namespace _1104저녁실습PictureService
{
    [ServiceContract]
    interface IPictureService
    {
        [OperationContract]
        byte[] GetPicture(string strFileName);

        [OperationContract]
        string[] GetPictureList();

        [OperationContract]
        bool UploadPicture(string strFileName, byte[] bytePic);
    }
}
