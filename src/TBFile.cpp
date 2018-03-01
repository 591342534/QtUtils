#include <stdafx.h>

#include <QtCore/qfile.h>

#include "TBDir.h"
#include "TBFile.h"

CTBFile::CTBFile()
{

}

//static
bool CTBFile::Copy(QString strDestName, QString strSrcName)
{
    strDestName.trimmed();
    strDestName.replace("\\", "/");
    if(strDestName.endsWith("/"))
    {
        strDestName.chop(1);
    }

    strSrcName.trimmed();
    strSrcName.replace("\\", "/");

    //Դ�ļ��������򷵻�
    if(!QFile::exists(strSrcName))
    {
        return false;
    }

    QString strPath = "";
    strPath = strDestName.left(strDestName.lastIndexOf("/"));
    //ȷ��Ŀ¼�Ѵ�����ԭ�е�Ŀ���ļ���ɾ��
    CTBDir::Mkpath(strPath);
    QFile::remove(strDestName);

    return QFile::copy(strSrcName, strDestName);
}

//static
bool CTBFile::Copy(QString strDestPath, QString strDestFile, QString strSrcName)
{
    strDestPath.trimmed();
    strDestPath.replace("\\", "/");
    if(strDestPath.endsWith("/"))
    {
        strDestPath.chop(1);
    }

    strSrcName.trimmed();
    strSrcName.replace("\\", "/");

    //Դ�ļ��������򷵻�
    if(!QFile::exists(strSrcName))
    {
        return false;
    }

    //ȷ��Ŀ¼�Ѵ�����ԭ�е�Ŀ���ļ���ɾ��
    CTBDir::Mkpath(strDestPath);
    QString strDestName = strDestPath + "/" + strDestFile;
    QFile::remove(strDestName);

    return QFile::copy(strSrcName, strDestName);
}
