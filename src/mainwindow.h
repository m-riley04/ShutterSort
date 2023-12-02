#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "src/ui_mainwindow.h"
#include <QMainWindow>
#include "application.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Button Commands
    void clicked_test();

private:
    Ui::MainWindow ui;
    Application app;
};
#endif // MAINWINDOW_H
