#pragma once

#include <QtCore/qstring.h>

class CTBString
{
private:
    CTBString();

public:	
	//sqlite��ת���ַ��Ĵ���
	static QString ToEscape(const QString& strData);
	static QString FromEscape(const QString& strData);
};

