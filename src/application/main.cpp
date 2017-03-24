#include <QApplication>
#include <QTextCodec>
#include "musicapplication.h"
#include "musicwidget.h"
#include "helper.h"

int main(int argc,char *argv[])
{
    MusicApplication app(argc,argv);
    if (app.isRunning())
        return 0;

    //×¢²áMessageHandler
    //qInstallMessageHandler(myMessageOutput);

    Helper::setChinese(":/image/translator/qt_zh_CN.qm");
    Helper::setStyleSheet("style");
    MusicWidget::Instance()->show();
    return app.exec();
}
