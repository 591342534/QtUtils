#include <stdafx.h>
#include "TBString.h"

CTBString::CTBString()
{

}
//sqlite��ת���ַ��Ĵ���
QString CTBString::ToEscape(const QString& strData)
{
	QString str = strData;

	str = str.replace("/", "//");
	str = str.replace("'", "''");
	str = str.replace("[", "/[");
	str = str.replace("]", "/]");
	str = str.replace("%", "/%");
	str = str.replace("&", "/&");
	str = str.replace("_", "/_");
	str = str.replace("(", "/(");
	str = str.replace(")", "/)");

	return str;
}

QString  CTBString::FromEscape(const QString& strData)
{
	QString str = strData;

	str = str.replace("//", "/");
	str = str.replace("''", "'");
	str = str.replace("/[", "[");
	str = str.replace("/]", "]");
	str = str.replace("/%", "%");
	str = str.replace("/&", "&");
	str = str.replace("/_", "_");
	str = str.replace("/(", "(");
	str = str.replace("/)", ")");

	return str;
}
