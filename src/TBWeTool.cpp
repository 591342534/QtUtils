#include <stdafx.h>
#include "TBWeTool.h"

#include <QtCore/qdatetime.h>
#include <QtCore/qcoreapplication.h>

#include "TBDir.h"
#include "TBMachine.h"
#include "version.h"

CTBWeTool::CTBWeTool()
{

}

//static
int CTBWeTool::sm_iAppType = APP_TYPE_WETOOL;            //��������
//���ó�������
//static
void CTBWeTool::SetAppType(int iAppType)
{
    sm_iAppType = iAppType;
}

//static
QString CTBWeTool::GetMainAppName(int iAppType /*= APP_TYPE_WETOOL*/)
{
	//����������Ϊwetao,��ʾ����Ϊbyn
	switch (iAppType)
	{
	case APP_TYPE_WETOOL:
		return "WeTool";
		break;
	case APP_TYPE_WECOP:
		return "WeCop";
		break;
	case APP_TYPE_BYN:
		return "Byn";
		break;
	case APP_TYPE_BYN_TOOL:
		return "BynTool";
		break;
	case APP_TYPE_BYN_COLLECT:
		return "BynCollect";
	default:
        //return qApp->applicationName();
        return "";
		break;
	}
}

//static
QString CTBWeTool::GetCachePath()
{
    QString strValue = "";

    //��ʽ��C:/Users/��ǰ�û�����/AppData/Roaming/WeTool
    strValue = QString("%1/%2")
            .arg(CTBMachine::GetAppDataPath())
            .arg(GetMainAppName(sm_iAppType));

    return strValue;
}

//static
QString CTBWeTool::GetCacheImagePath()
{
    QString strValue = "";

    //��ʽ��C:/Users/��ǰ�û�����/AppData/Roaming/WeTool/images
    strValue = QString("%1/%2/images")
            .arg(CTBMachine::GetAppDataPath())
            .arg(GetMainAppName(sm_iAppType));

    return strValue;
}

//static
QString CTBWeTool::GetSysCfgFile()
{
    //C:\Users\��ǰϵͳ��¼�û�\AppData\Roaming\WeTool\system\cfg\sys_cfg.db
    QString strPath = GetCachePath() + "/system/cfg";
    CTBDir::Mkpath(strPath);

    QString strValue = strPath + "/sys_cfg.db";

    return strValue;
}

//��ȡϵͳ����ini�ļ�
//static
QString CTBWeTool::GetSysCfgIniFile()
{
	//C:\Users\��ǰϵͳ��¼�û�\AppData\Roaming\WeTool\system\cfg\sys_cfg.ini
	QString strPath = GetCachePath() + "/system/cfg";
	CTBDir::Mkpath(strPath);

	QString strValue = strPath + "/sys_cfg.ini";

	return strValue;
}

QString CTBWeTool::GetHeadImgPath()
{
	static QString strPath;
	if (strPath.isEmpty())
	{
		strPath = GetCachePath() + "/headimgs";
		CTBDir::Mkpath(strPath);
	}
	return strPath;
}

//��ȡ΢�����ݿ��·��(����ȫ·��)
//static
QString CTBWeTool::GetWetaoDBPath()
{
    static QString strPath = "";
    if (strPath.isEmpty())
    {
        strPath = GetCachePath() + "/system/cfg";
        CTBDir::Mkpath(strPath);
    }
    return strPath;
}

//��ȡ΢�����ݿ���ļ�(����ȫ·�����ļ�����׺)
//static
QString CTBWeTool::GetWetaoDBFile()
{
    static QString strFile = "";
    if (strFile.isEmpty())
    {
        strFile = GetWetaoDBPath() + "/byn.db";
    }
    return strFile;
}

//��ȡ��Ӧ�񹤾ߵ�·��(����ȫ·��)
QString CTBWeTool::GetBynToolDBPath()
{
	static QString strPath = "";
	if (strPath.isEmpty())
	{
		strPath = GetCachePath() + "/system/cfg";
		CTBDir::Mkpath(strPath);
	}
	return strPath;
}

//��ȡ��Ӧ�񹤾����ݿ���ļ�(����ȫ·�����ļ�����׺)
QString CTBWeTool::GetBynToolDBFile()
{
	static QString strFile = "";
	if (strFile.isEmpty())
	{
		strFile = GetBynToolDBPath() + "/BynTool.db";
	}
	return strFile;
}

//��ȡdump�ļ�(����ȫ·��)
QString CTBWeTool::GetDumpFile()
{
	QString strPath = GetSysLogPath();
	CTBDir::Mkpath(strPath);

	QString strName = QString("dump%1_%2_%3.dmp")
        .arg(GetMainAppName(sm_iAppType))
		.arg(VERSTRING)
		.arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss"));

	QString strFile = QString("%1/%2").arg(strPath).arg(strName);

	return strFile;
}

//��ȡѹ����־�ļ�(����ȫ·��)
 QString CTBWeTool::GetZipLogFile(const QString& strUserName)
{
	 QString strZipFile = QString("%1/%2_%3_%4.zip")
		 .arg(CTBWeTool::GetSysLogPath())
         .arg(CTBWeTool::GetMainAppName(sm_iAppType) + VERSTRING)
		 .arg(strUserName)
		 .arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss"));

	 return strZipFile;
}

QString CTBWeTool::GetWeCopDBFile(const QString& wecop_user_name)
{
	QString strPath = QString("%1/%2/wecop_user_data/%3/")
		.arg(CTBMachine::GetAppDataPath())
        .arg(GetMainAppName(sm_iAppType))
		.arg(wecop_user_name);
	CTBDir::Mkpath(strPath);
	QString strValue = strPath + "/wecop.db";
	return strValue;
}

//������db�ļ�
//static
QString CTBWeTool::GetBillDBFile(const QString& strBynId, const QString& strWxid)
{
	static QString strFile = "";
	if (strFile.isEmpty())
	{
		strFile = GetWetaoDBPath() + QString("/bill_%1_%2.db").arg(strBynId).arg(strWxid);
	}
	return strFile;
}

//��ȡϵͳ��־·��
//static
QString CTBWeTool::GetSysLogPath()
{
	QString strValue = "";

	//��ʽ��C:/Users/��ǰ�û�����/AppData/Roaming/WeTool/system/log
	strValue = QString("%1/%2/system/log")
		.arg(CTBMachine::GetAppDataPath())
        .arg(GetMainAppName(sm_iAppType));

	CTBDir::Mkpath(strValue);

	return strValue;
}


//static
QString  CTBWeTool::GetSysLogFile()
{
	QDateTime now = QDateTime::currentDateTime();
	QString strFile = QString("%1/%2.log")
		.arg(GetSysLogPath())
        .arg(GetMainAppName(sm_iAppType));
	//QString strFile = QString("%1/%2.log").arg(GetSysLogPath(iAppType)).arg(GetMainAppName(iAppType));
	return strFile;
}


//static
QString CTBWeTool::GetSysLogCfgFile()
{
	QString strPath = GetCachePath() + "/system/cfg";
	CTBDir::Mkpath(strPath);

	QString strValue = strPath + "/log4cxx.properties";

	return strValue;
}

//��ȡ����ǰ·��
//static
QString CTBWeTool::GetAppCurPath()
{
	QString strPath = QCoreApplication::applicationDirPath();

	return strPath;
}

//static
QString CTBWeTool::GetWxidPath(const QString& strCurWxid)
{
    QString strValue = "";

    //��ʽ��C:/Users/��ǰ�û�����/AppData/Roaming/WeTool/users/��ǰ΢��id
    strValue = QString("%1/%2/users/%3")
            .arg(CTBMachine::GetAppDataPath())
        .arg(GetMainAppName(sm_iAppType))
		.arg(strCurWxid);

    return strValue;
}

QString CTBWeTool::GetWxidDBFile(const QString& strCurWxid)
{
    QString strPath = GetWxidDBPath(strCurWxid);
    CTBDir::Mkpath(strPath);

    QString strValue = strPath + "/wt.db";

    return strValue;
}

QString CTBWeTool::GetWxidDBPath(const QString& strCurWxid)
{
    QString strValue = "";

    //��ʽ��C:/Users/��ǰ�û�����/AppData/Roaming/WeTool/users/��ǰ΢��id/db
    strValue = QString("%1/%2/users/%3/db")
            .arg(CTBMachine::GetAppDataPath())
            .arg(GetMainAppName(sm_iAppType))
			.arg(strCurWxid);

    return strValue;
}


//static
QString CTBWeTool::GetWxidCfgFile(const QString& strCurWxid)
{
    //C:\Users\��ǰϵͳ��¼�û�\AppData\Roaming\WeTool\users\��ǰ΢�ŵ�¼�û�id\cfg\user_cfg.db
    QString strPath = GetWxidPath(strCurWxid) + "/cfg";
    CTBDir::Mkpath(strPath);

    QString strValue = strPath + "/user_cfg.db";

    return strValue;
}

QString CTBWeTool::GetWxidNewFriendFile(const QString & strCurWxid)
{
	QString strPath = GetWxidPath(strCurWxid) + "/cfg";
	CTBDir::Mkpath(strPath);

	QString strValue = strPath + "/newFriends.dat";

	return strValue;
}


QString CTBWeTool::GetWxidChatDBPath(const QString strCurWxid)
{
	QString strPath = GetWxidPath(strCurWxid)+"/chatDB";
	CTBDir::Mkpath(strPath);
	QString strValue = strPath + "/chatmessage.db";
	return strValue;
}

QString CTBWeTool::GetWxidMiscDBPath(const QString strCurWxid)
{
	QString strPath = GetWxidDBPath(strCurWxid);
	CTBDir::Mkpath(strPath);
	QString strValue = strPath + "/MiscData.db";
	return strValue;
}

//��ȡ����·��
//static
QString CTBWeTool::GetPayPath()
{
	QString strValue = "";

	//��ʽ��C:/Users/��ǰ�û�����/AppData/Roaming/BynTool/system/pay
	strValue = QString("%1/%2/system/pay")
		.arg(CTBMachine::GetAppDataPath())
        .arg(GetMainAppName(sm_iAppType));

	CTBDir::Mkpath(strValue);

	return strValue;
}
