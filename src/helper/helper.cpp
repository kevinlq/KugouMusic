#include "helper.h"
#include <QMutex>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QTranslator>
#include <QApplication>

Helper::Helper(QObject *parent) : QObject(parent)
{

}

void Helper::myMessageOutput(QtMsgType type, const QMessageLogContext &context,
                             const QString &msg)
{
    static QMutex mutex;
    mutex.lock();
    QString text;

    switch (type) {
    case QtDebugMsg:
        //fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        text = QString("Qdebug:");
        break;
    case QtInfoMsg:
        //fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        text = QString("QtInfo:");
        break;
    case QtWarningMsg:
        //fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        text = QString("WArning:");
        break;
    case QtCriticalMsg:
        //fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        text = QString("Critical:");
        break;
    case QtFatalMsg:
        //fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        text = QString("Fatal:");
        //abort();
    }
    QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
    QString current_data_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString current_date = QString("(%1)").arg(current_data_time);
    QString message = QString("%1 %2 %3 %4").arg(text).arg(context_info).arg(msg).arg(current_date);
    QFile file("log.txt");
    file.open(QIODevice::WriteOnly |  QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream << message<<"\r\n";
    file.flush();
    file.close();;

    mutex.unlock();
}

void Helper::setChinese(const QString &file_path)
{
    QTranslator *translator = new QTranslator(qApp);
    translator->load(QString("%1").arg(file_path));
    qApp->installTranslator(translator);
}


void Helper::setStyleSheet(const QString &styleName)
{
    QFile file(QString(":/image/css/%1.css").arg(styleName));
    file.open(QFile::ReadOnly);
    QString qss = QLatin1String(file.readAll());
    qApp->setStyleSheet(qss);
}
