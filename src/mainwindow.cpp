#include <functional>
#include "mainwindow.h"
#include "application.h"
#include "sortingfunctions.h"
#include "anchor.h"
#include "sorttimer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Initialize timer
    std::function<void(Anchor)> func = update_anchor;
    std::chrono::milliseconds interval(1000);
    Anchor anchor = app.getAnchors().front();
    app.setTimer(interval, func, anchor);

    // Initialize the UI component
    ui.setupUi(this);

    //====================== Connect widgets to functionalities
    //----- Buttons
    connect(ui.btn_start, &QPushButton::clicked, this, &MainWindow::clicked_start);
    connect(ui.btn_stop, &QPushButton::clicked, this, &MainWindow::clicked_stop);
}

MainWindow::~MainWindow()
{}

//========================== Button Commands
//----- Debug Commands
// A test function that changes the text of label_test to "Hello world!"
void MainWindow::clicked_test() {
    QString str("Hello world!");
    ui.label_test->setText(str);
}

//----- Anchor Control Commands
// Starts the sorting for the Anchor
void MainWindow::clicked_start() {
    this->app.getTimer().start();
    QString str("Sorting...");
    ui.label_test->setText(str);
}
// Stops the sorting for the Anchor
void MainWindow::clicked_stop() {
    this->app.getTimer().stop();
    QString str("Sorting is stopped.");
    ui.label_test->setText(str);
}

//----- Sorting Method Stack Commands
// Moves the selected sorting method up the stack
void MainWindow::clicked_moveMethodUp() {

}
// Moves the sorting method for the Anchor down the stack
void MainWindow::clicked_moveMethodDown() {

}
// Adds a blank sorting method to be filled in by the user to the top of the stack
void MainWindow::clicked_addMethod() {

}
// Removes the selected sorting method from the stack
void MainWindow::clicked_removeMethod(){

}

//----- Navigation Commands
void MainWindow::clicked_settings() {

}
