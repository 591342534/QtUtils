#include <stdafx.h>
#include "TBMachine.h"

#include <QtCore/qstandardpaths.h>

CTBMachine::CTBMachine()
{

}

QString CTBMachine::GetCurUserName()
{
    QString strValue = "";
    strValue = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    // C:/Users/hulaishun
    // ȡ���һ���ֶξ��ǵ�ǰ�û�����
    strValue = strValue.section("/",-1);

    return strValue;
}

//static
QString CTBMachine::GetAppDataPath(const QString strCurLoginedName /*= ""*/)
{
    QString strValue = strCurLoginedName.trimmed();
    if(strValue.size() <= 0)
    {
        strValue = GetCurUserName();
    }

    //��ʽ:C:/Users/��ǰ�û�����/AppData/Roaming
    strValue.prepend("C:/Users/");
    strValue.append("/AppData/Roaming");

    return strValue;
}
