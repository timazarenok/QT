#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(int colum, int row, QWidget *parent) :
    QMainWindow(parent), m_coloum(colum), m_row(row)
{
    mainWidget = new QWidget;
    elementsLayout = new QGridLayout;
    buttonLayout = new  QVBoxLayout;
    mainLayout = new  QVBoxLayout;
    button = new QPushButton("Click");
    buttonLayout->addWidget(button);
    result = new matrix(m_coloum, m_row);
    addQLineEdits(m_coloum, m_row);
    addElementOnWidget();
    mainLayout->addLayout(elementsLayout);
    mainLayout->addLayout(buttonLayout);
    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(mainWidget);
    connect(this->button, &QPushButton::clicked, this, &MainWindow::slotShowResult);
}

MainWindow::~MainWindow()
{

}

void MainWindow::addQLineEdits(int column, int row)
{
    m_coloum = column;
    m_row = row;
    QLineEdit* temp;
    for(int i = 0, size = column * row; i != size; ++i)
    {
        temp = new QLineEdit;
        elements.push_back(temp);
    }
}

void MainWindow::addElementOnWidget()
{
    for (int i = 0, k = 0; i != m_coloum; ++i) {
        for(int j = 0; j != m_row; ++j, ++k){
            elementsLayout->addWidget(elements[k], i, j);
    }
 }
}

void MainWindow::fill_matrix()
{
    for(int i = 0, k = 0; i != m_coloum; ++i)
    {
        for(int j = 0; j != m_row; ++j, ++k)
        {
            result->pull_matrix(i, j, elements[k]->text().toInt());
            qDebug() << elements[k]->text().toInt();
        }
    }
}

void MainWindow::slotShowResult()
{
    fill_matrix();
    int r = result->find_det();
    QMessageBox::information(this, "Result", QString::number(r));
}
