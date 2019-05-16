#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QWidget>
#include <QGridLayout>
#include "matrix.h"
#include <QDebug>
#include <QPushButton>
#include <QStackedLayout>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    using matrix = Matrix<int>;
    explicit MainWindow(int colum, int row, QWidget *parent = nullptr);
    ~MainWindow();
    int m_coloum;
    int m_row;
    void addQLineEdits(int column, int row);
    void addElementOnWidget();
    void fill_matrix();
public slots:
    void slotShowResult();

private:
    QVector<QLineEdit*> elements;
    QGridLayout* elementsLayout;
    QVBoxLayout* buttonLayout;
    QVBoxLayout* mainLayout;
    QWidget* mainWidget;
    matrix* result;
    QPushButton* button;
};

#endif // MAINWINDOW_H
