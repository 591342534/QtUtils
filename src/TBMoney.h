#ifndef TB_MONEY_H
#define TB_MONEY_H

#include <QtCore/qstring.h>

/**
* @brief ��Ǯ�ľ�̬��
* @note  ͳһ�����Ǯ���ֵ�ת���ʹ���
*/
class CTBMoney
{
private:
	CTBMoney();
	~CTBMoney();

public:

	static double ToDouble(const QString& strMoney);

	static QString ToString(double dblMoney, char format = 'g', int precision = 2);

	static QString ToString(const QString& strMoney, int precision = 2, const QString& strPrefix = "", const QString& strSuffix = "");


};

#endif //TB_MONEY_H

