#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include "GLWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pGLWidget = new GLWidget(this);
    setCentralWidget(m_pGLWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
