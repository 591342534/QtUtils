#ifndef TB_PROCESS_MANAGER_H
#define TB_PROCESS_MANAGER_H

#include <QtCore/qlist.h>

#include "TBProcessInfo.h"

class CTBProcessManager
{
private:
	CTBProcessManager();
	~CTBProcessManager();

public:
	//��ȡ������ǰ�����н�����Ϣ
	static QList<CTBProcessInfo> GetAllProcess();

	//�����Ƿ��ѿ���
	static bool IsOpenByName(const QString& strProcessName);
	static bool IsOpenById(long lProcessId);

	//WeTool�Ƿ��ѿ���
	static bool IsOpenWeTool();
	//WeCop�Ƿ��ѿ���
	static bool IsOpenWeCop();
	//Byn�Ƿ��ѿ���
	static bool IsOpenByn();

};

#endif //TB_PROCESS_MANAGER_H

