#ifndef TB_PROCESS_INFO_H
#define TB_PROCESS_INFO_H

#include <qt_windows.h>
#include <TlHelp32.h>
#include <qglobal.h>

#include <QtCore/qstring.h>

class CTBProcessInfo
{
public:
	CTBProcessInfo();
	~CTBProcessInfo();

	CTBProcessInfo(const CTBProcessInfo& that);
	CTBProcessInfo& operator=(const CTBProcessInfo& that);

	void Clear();
	QString GetDesc();

public:
	void CopyFrom(PROCESSENTRY32 pe32);

private:
	void CopyFrom(const CTBProcessInfo& that);

public:
	unsigned long		dwSize;					//��С
	unsigned long		cntUsage;				//��ʹ������
	unsigned long		th32ProcessID;			//��ǰ����id
	unsigned long		th32DefaultHeapID;		//
	unsigned long		th32ModuleID;			//ģ��id

	unsigned long		cntThreads;				//�߳�����
	unsigned long		th32ParentProcessID;	//��ǰ���̵ĸ�����id
	long				pcPriClassBase;			//
	unsigned long		dwFlags;				//��־
	QString				exeFile;				//·������
};

#endif //TB_PROCESS_INFO_H

