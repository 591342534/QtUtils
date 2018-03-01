#ifndef TB_WE_TOOL_H
#define TB_WE_TOOL_H

#include <QtCore/qstring.h>

//��������
enum EAppType
{
	APP_TYPE_WETOOL			= 1,		//wetool
	APP_TYPE_WECOP			= 2,		//�����
	APP_TYPE_BYN			= 3,		//�ԿͰ�
	APP_TYPE_BYN_TOOL		= 4,		//�Կ͹���
	APP_TYPE_BYN_COLLECT	= 5,		//qqȺ�ɼ�����
};

class CTBWeTool
{
private:
    CTBWeTool();

public:
    //���ó�������
    static void SetAppType(int iAppType);

    static QString GetMainAppName(int iAppType = APP_TYPE_WETOOL);
    static QString GetCachePath();
    static QString GetCacheImagePath();
    static QString GetSysCfgFile();
	//��ȡϵͳ����ini�ļ�
	static QString GetSysCfgIniFile();
	static QString GetHeadImgPath(); //ͷ��洢·��
    //��ȡ΢�����ݿ��·��(����ȫ·��)
    static QString GetWetaoDBPath();
    //��ȡ΢�����ݿ���ļ�(����ȫ·�����ļ�����׺)
    static QString GetWetaoDBFile();

	//��ȡ��Ӧ�񹤾ߵ�·��(����ȫ·��)
	static QString GetBynToolDBPath();
	//��ȡ��Ӧ�񹤾����ݿ���ļ�(����ȫ·�����ļ�����׺)
	static QString GetBynToolDBFile();

	//��ȡdump�ļ�(����ȫ·��)
	static QString GetDumpFile();
	//��ȡѹ����־�ļ�(����ȫ·��)
	static QString GetZipLogFile(const QString& strUserName);

	//wecop���Ż�ȯDB
	static QString GetWeCopDBFile(const QString& wecop_user_name);

	//������db�ļ�
	static QString GetBillDBFile(const QString& strBynId, const QString& strWxid);

	//��ȡϵͳ��־·��
	static QString GetSysLogPath();
	static QString GetSysLogFile();
	static QString GetSysLogCfgFile();
	//��ȡ����ǰ·��
	static QString GetAppCurPath();
	//��ȡ����·��
	static QString GetPayPath();

    static QString GetWxidPath(const QString& strCurWxid);
    static QString GetWxidDBFile(const QString& strCurWxid);
    static QString GetWxidDBPath(const QString& strCurWxid);
    static QString GetWxidCfgFile(const QString& strCurWxid);
	static QString GetWxidNewFriendFile(const QString& strCurWxid);

	//�����db·��
	static QString GetWxidChatDBPath(const QString strCurWxid);
	static QString GetWxidMiscDBPath(const QString strCurWxid);

private:
    static int          sm_iAppType;            //��������
};

#endif // TB_WE_TOOL_H
