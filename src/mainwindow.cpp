#include <functional>
#include "mainwindow.h"
#include "application.h"
#include "sortingfunctions.h"
#include "anchor.h"
#include "sorttimer.h"
#include "sortingmethod_qt.h"
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Initialize timer
    std::function<void(Anchor)> func    = update_anchor;
    std::chrono::milliseconds           interval(1000);
    Anchor anchor                       = app.getAnchors().front();
    app.setTimer(interval, func, anchor);

    // Initialize the UI component
    ui.setupUi(this);

    //====================== Connect widgets to functionalities
    //----- Buttons
    connect(ui.btn_start, &QPushButton::clicked, this, &MainWindow::clicked_start);
    connect(ui.btn_stop, &QPushButton::clicked, this, &MainWindow::clicked_stop);
    connect(ui.btn_moveMethodUp, &QPushButton::clicked, this, &MainWindow::clicked_moveMethodUp);
    connect(ui.btn_moveMethodDown, &QPushButton::clicked, this, &MainWindow::clicked_moveMethodDown);
    connect(ui.btn_addMethod, &QPushButton::clicked, this, &MainWindow::clicked_addMethod);
    connect(ui.btn_removeMethod, &QPushButton::clicked, this, &MainWindow::clicked_removeMethod);
    connect(ui.btn_apply, &QPushButton::clicked, this, &MainWindow::clicked_apply);

    //===== TESTING/DEBUG ================================
    // Fill sorting method stack with dummy test widgets
    /*for (int i = 0; i < 1; ++i) {
        auto item = new QListWidgetItem();

        auto widget = new SortingMethod_qt(this);
        QSize size = QSize(widget->geometry().width(), widget->geometry().height());

        item->setSizeHint(size);

        ui.list_methods->addItem(item);
        ui.list_methods->setItemWidget(item, widget);

    }*/
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
    int row         = ui.list_methods->currentRow();
    // Remove it (and remove it from memory)
    QListWidgetItem *it = ui.list_methods->takeItem(row);
    //QWidget *itWidget = ui.list_methods->itemWidget(it);
    ui.list_methods->insertItem(row-1, it);
}
// Moves the sorting method for the Anchor down the stack
void MainWindow::clicked_moveMethodDown() {
    int row         = ui.list_methods->currentRow();
    // Remove it (and remove it from memory)
    QListWidgetItem *it = ui.list_methods->takeItem(row);
    ui.list_methods->insertItem(row+1, it);
}
// Adds a blank sorting method to be filled in by the user to the top of the stack
void MainWindow::clicked_addMethod() {
    // Create sorting method
    Anchor anchor = app.getAnchors().front();
    SortingMethod method;

    // Push blank sorting method to the back of the anchor
    anchor.getSorter().getMethods().push_back(method);

    auto item       = new QListWidgetItem();
    auto widget     = new SortingMethod_qt(this);
    QSize size      = QSize(widget->geometry().width(), widget->geometry().height());
    item->setSizeHint(size);

    ui.list_methods->addItem(item);
    ui.list_methods->setItemWidget(item, widget);
}
// Removes the selected sorting method from the stack
void MainWindow::clicked_removeMethod(){
    int row         = ui.list_methods->currentRow();
    auto method     = ui.list_methods->item(row);

    // Remove it (and remove it from memory)
    QListWidgetItem *it = ui.list_methods->takeItem(row);
    delete it;
}

// Applies the changed made to the sorting methods stack
void MainWindow::clicked_apply() {

}

//----- Navigation Commands
void MainWindow::clicked_settings() {

}
