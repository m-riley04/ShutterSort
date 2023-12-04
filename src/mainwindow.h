#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "src/ui_mainwindow.h"
#include <QMainWindow>
#include "application.h"
#include <list>
#include "sortingmethod.h"

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

    //========================== Button Commands
    /*
    Button commands (clicked_*) are functions that
    are triggered after a specific button
    is clicked.
    */
    //----- Debug command
    void clicked_test();

    //----- Anchor Control Commands
    void clicked_start();
    void clicked_stop();

    //----- Sorting Method Stack Commands
    void clicked_moveMethodUp();
    void clicked_moveMethodDown();
    void clicked_addMethod();
    void clicked_removeMethod();
    void clicked_apply();

    //----- Navigation Commands
    void clicked_settings();

    //----- Other
    void clicked_upload();

    //========================== Other Widget Commands
    void typed_input();
    void typed_output();

    // Misc
    void save();
    void load();

private:
    std::list<SortingMethod> currentSortingMethods;
    Anchor currentAnchor;
    Ui::MainWindow ui;
    SortTimer timer;
    //Application app;
};
#endif // MAINWINDOW_H
