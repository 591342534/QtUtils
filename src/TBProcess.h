#ifndef TB_PROCESS_H
#define TB_PROCESS_H

#include <QtCore/qstring.h>
#include <QtCore/qstringlist.h>

class CTBProcess
{
private:
    CTBProcess();
    ~CTBProcess();

public:
    //ͨ�����������жϽ����Ƿ��Ѵ���
    static bool IsExistByName(const QString& strProcessName);
    //��ȡ����ID���жϽ����Ƿ��Ѵ���
    static bool IsExistByPid(int iProcessPid);

    //��ȡ��ǰ�����н��������б�
    static QStringList GetAllProcessName();

    //��ȡ��ǰ�����н���pid�б�
    static QList<int> GetAllProcessPid();

    //ͨ�������������رս���
    static bool CloseByName(const QString& strProcessName);
    //ͨ������pid���رս���
    static bool CloseByPid(int iProcessPid);

    //ͨ�������ļ�����������
    static int OpenByFile(const QString& strProcessFile);
    static int OpenByFileArg(const QString& strProcessFile, const QStringList &arguments);
    static int OpenByCommand(const QString &command);

public:
	//static 


};

#endif //TB_PROCESS_H

