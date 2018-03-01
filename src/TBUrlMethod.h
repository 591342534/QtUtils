#ifndef TB_URL_METHOD_H
#define TB_URL_METHOD_H

#include <QtCore/qstring.h>

//Э������
enum EUrlProtocolType
{
    URL_PROTOCOL_TYPE_HTTP      = 1,            //http
    URL_PROTOCOL_TYPE_HTTPS     = 2,            //https
};

//���󷽷�
enum EUrlRequestMethod
{
    URL_REQUEST_METHOD_GET      = 1,            //get
    URL_REQUEST_METHOD_POST     = 2             //post
};

/**
 * @brief �Ʊ�URL���÷���
 */
class CTBUrlMethod
{
public:
    CTBUrlMethod();
    ~CTBUrlMethod();

    CTBUrlMethod(const CTBUrlMethod& src);
    const CTBUrlMethod& operator=(const CTBUrlMethod& src);

    void Init();

    void Clear();

    bool IsValid();

    QString GetFullUrl();

public:
    int GetType();
    void SetType(int iType);

    QString GetAddress();
    void SetAddress(const QString& strAddress);

    int GetPort();
    void SetPort(int iPort);

    QString GetPath();
    void SetPath(const QString& strPath);

    int GetMethod();
    void SetMethod(int iMethod);

    QString GetParam();
    void SetParam(const QString& strParam);

private:
    int                 m_iType;                //Э�����ͣ�Ĭ��ֵΪ1(http)
    QString             m_strAddress;           //������������ַ,��www.baidu.com���Ӧ��ip:14.215.177.38
    int                 m_iPort;                //�������Ķ˿ڣ�Ĭ��ֵΪ80
    QString             m_strPath;              //��������url·������/api/user/login.html
    int                 m_iMethod;              //���󷽷���Ĭ��ֵΪ1(get)
    QString             m_strParam;             //url�еĲ�����һ���ʽΪ&k1=v1&k2=v2......&kn=vn
};

#endif // TB_URL_METHOD_H
