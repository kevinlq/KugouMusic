#include "musicapplication.h"
#include <QDebug>

MusicApplication::MusicApplication(int &argc, char **argv)
    :QApplication(argc,argv)
{
    m_sharedMemory.setKey("Music");
    if (m_sharedMemory.attach())
    {
        m_IsRun = true;
    }else
    {
        m_IsRun = false;
        if (!m_sharedMemory.create(1))
        {
            qDebug()<<"Unable to create single instance !";
            qDebug()<<m_sharedMemory.errorString();
            return;
        }
    }
}

MusicApplication:: ~MusicApplication()
{

}

bool MusicApplication::isRunning()
{
    return m_IsRun;
}

