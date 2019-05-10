#ifndef ADDSUBJECTWINDOW_H
#define ADDSUBJECTWINDOW_H

#include <QMainWindow>
#include "database.h"

namespace Ui {
class addSubjectWindow;
}

class addSubjectWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit addSubjectWindow(QWidget *parent = nullptr);
    ~addSubjectWindow();
public slots:
    void slotaddSubject();
signals:

private:
    Ui::addSubjectWindow *ui;
};

#endif // ADDSUBJECTWINDOW_H
