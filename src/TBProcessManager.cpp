#include "stdafx.h"
#include "TBProcessManager.h"

#include "QtCore/qdebug.h"

#include <TlHelp32.h>
#pragma comment(lib, "psapi.lib")
#pragma comment(lib, "Kernel32.lib")

CTBProcessManager::CTBProcessManager()
{
}


CTBProcessManager::~CTBProcessManager()
{
}

//��ȡ������ǰ�����н�����Ϣ
//static
QList<CTBProcessInfo> CTBProcessManager::GetAllProcess()
{
	QList<CTBProcessInfo> listProcess;

	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		qDebug() << "CreateToolhelp32Snapshot (of processes) failed";
		return listProcess;
	}

	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(pe32);
	BOOL bMore = Process32First(hProcessSnap, &pe32);
	while (bMore)
	{
		CTBProcessInfo pi;
		pi.CopyFrom(pe32);

		listProcess.append(pi);

		bMore = Process32Next(hProcessSnap, &pe32);
	}
	CloseHandle(hProcessSnap);

	return listProcess;
}

//�����Ƿ��ѿ���
//static
bool CTBProcessManager::IsOpenByName(const QString& strProcessName)
{
	QList<CTBProcessInfo> listProcess = GetAllProcess();

	foreach(CTBProcessInfo pi, listProcess)
	{
		if (0 == QString::compare(pi.exeFile,strProcessName, Qt::CaseInsensitive))
		{
			return true;
		}
	}

	return false;
}

//static
bool CTBProcessManager::IsOpenById(long lProcessId)
{
	QList<CTBProcessInfo> listProcess = GetAllProcess();

	foreach(CTBProcessInfo pi, listProcess)
	{
		if (pi.th32ProcessID == lProcessId)
		{
			return true;
		}
	}

	return false;
}

//WeTool�Ƿ��ѿ���
//static
bool CTBProcessManager::IsOpenWeTool()
{
	return IsOpenByName("WeTool.exe");
}
//WeCop�Ƿ��ѿ���
//static
bool CTBProcessManager::IsOpenWeCop()
{
	return IsOpenByName("WeCop.exe");
}
//Byn�Ƿ��ѿ���
//static
bool CTBProcessManager::IsOpenByn()
{
	return IsOpenByName("Byn.exe");
}