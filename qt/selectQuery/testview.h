#ifndef TESTVIEW_H
#define TESTVIEW_H

#include <QMainWindow>

namespace Ui {
class TESTVIEW;
}

class TESTVIEW : public QMainWindow
{
    Q_OBJECT

public:
    explicit TESTVIEW(QWidget *parent = nullptr);
    ~TESTVIEW();

private:
    Ui::TESTVIEW *ui;
};

#endif // TESTVIEW_H
