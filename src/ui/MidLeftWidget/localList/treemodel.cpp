#include "treemodel.h"
#include <QStandardItem>

TreeModel::TreeModel(QObject *parent, const QString &head_name)
    :QStandardItemModel(parent)
{
    setHorizontalHeaderLabels(QStringList() << head_name);

    m_iconMap["add_musci"] = QIcon(":/image/locallist/add_music.png");
    m_iconMap["add_folder_music"] = QIcon(":/image/locallist/addFolderMusic.png");

    QStandardItem *item_add_music = new QStandardItem(m_iconMap["add_music"],
            QString::fromLocal8Bit("添加本地歌曲"));
    item_add_music->setFont(QFont("Times", 9, QFont::Normal));

    QStandardItem *item_add_music_folder = new QStandardItem(m_iconMap["add_folder_music"],
            QString::fromLocal8Bit("添加本地歌曲文件夹"));
    item_add_music_folder->setFont(QFont("Times", 9, QFont::Normal));
    appendRow(item_add_music);
    appendRow(item_add_music_folder);
}

TreeModel::~TreeModel()
{

}

