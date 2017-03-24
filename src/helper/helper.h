#ifndef HELPER_H
#define HELPER_H

#include <QObject>

class Helper : public QObject
{
    Q_OBJECT
public:
    explicit Helper(QObject *parent = 0);

signals:

public slots:

public:
    //输出日志信息到文件中
    static void myMessageOutput(QtMsgType type, const QMessageLogContext &context,
                                const QString &msg);
    //加载中文字符
    static void setChinese(const QString &file_path);
    //加载样式表
    static void setStyleSheet(const QString &styleName);
};

#endif // HELPER_H
