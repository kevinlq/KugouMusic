#ifndef MUSICAPPLICATION_H
#define MUSICAPPLICATION_H
#include <QApplication>
#include <QSharedMemory>

class MusicApplication : public QApplication
{
public:
    MusicApplication(int &argc,char **argv);
    ~MusicApplication();
    bool isRunning();
private:
    bool m_IsRun;
    QSharedMemory m_sharedMemory;
};

#endif // MUSICAPPLICATION_H
