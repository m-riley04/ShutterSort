#include "mainwindow.h"
#include "application.h"
#include "shuttersort.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Initialize the UI component
    ui.setupUi(this);

    // Connect widgets to functionalities
    connect(ui.btn_start, &QPushButton::clicked, this, &MainWindow::clicked_test);
}

MainWindow::~MainWindow()
{}

// A test function that changes the text of label_test to "Hello world!"
void MainWindow::clicked_test() {
    QString str("Hello world!");
    ui.label_test->setText(str);
}
