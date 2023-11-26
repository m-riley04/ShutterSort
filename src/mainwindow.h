#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "application.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void clicked_test();

private:
    Application app;

    Ui::WindowClass ui;
};
