#ifndef ABSTRACTTABWIDGET_H
#define ABSTRACTTABWIDGET_H

#include <QTabWidget>

class AbstractTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit AbstractTabWidget(QWidget *parent);
    ~AbstractTabWidget();
private:
    void initForm();
};

#endif // ABSTRACTTABWIDGET_H
