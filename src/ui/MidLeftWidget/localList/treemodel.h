#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QStandardItemModel>

class TreeModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit TreeModel(QObject *parent, const QString &head_name);
    ~TreeModel();

private:
    QMap<QString,QIcon>m_iconMap;
};

#endif // TREEMODEL_H
