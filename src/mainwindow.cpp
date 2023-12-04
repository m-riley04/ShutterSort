#include <functional>
#include "mainwindow.h"
#include "sortingfunctions.h"
#include "anchor.h"
#include "sorttimer.h"
#include "sortingmethod_qt.h"
#include <QListWidgetItem>
#include <QFileDialog>
#include <list>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Load input/output paths from JSON
    //TODO: Load data from JSON
    std::string inputDirectory = "C:\\Users\\riley\\Desktop\\InputDirectory";
    std::string outputDirectory = "C:\\Users\\riley\\Desktop\\OutputDirectory";
    std::list<SortingMethod> sortingMethods = {};

    // Initialize Sorter for Anchor
    Sorter sorter;

    // Initialize Anchor
    //Anchor anchor(inputDirectory, outputDirectory, sorter);
    this->currentAnchor.setDirectory(inputDirectory);
    this->currentAnchor.setOutputDirectory(outputDirectory);
    this->currentAnchor.setSorter(sorter);

    SortTimer timer;

    // Initialize timer and set
    std::function<void(Anchor)> func    = update_anchor;
    std::chrono::milliseconds           interval(1000);
    this->timer.setAnchor(this->currentAnchor);
    this->timer.setFunction(func);
    this->timer.setInterval(interval);

    // Initialize the UI component
    ui.setupUi(this);

    //====================== Initialize Widgets Values
    ui.line_anchorPath->setText(QString(inputDirectory.c_str()));
    ui.line_outputPath->setText(QString(outputDirectory.c_str()));
    //TODO: Initialize sorting methods list

    //====================== Connect widgets to functionalities
    //----- Buttons
    connect(ui.btn_start, &QPushButton::clicked, this, &MainWindow::clicked_start);
    connect(ui.btn_stop, &QPushButton::clicked, this, &MainWindow::clicked_stop);
    connect(ui.btn_moveMethodUp, &QPushButton::clicked, this, &MainWindow::clicked_moveMethodUp);
    connect(ui.btn_moveMethodDown, &QPushButton::clicked, this, &MainWindow::clicked_moveMethodDown);
    connect(ui.btn_addMethod, &QPushButton::clicked, this, &MainWindow::clicked_addMethod);
    connect(ui.btn_removeMethod, &QPushButton::clicked, this, &MainWindow::clicked_removeMethod);
    connect(ui.btn_apply, &QPushButton::clicked, this, &MainWindow::clicked_apply);
    connect(ui.btn_upload, &QPushButton::clicked, this, &MainWindow::clicked_upload);

    //------ Other
    connect(ui.line_anchorPath, &QLineEdit::textChanged, this, &MainWindow::typed_input);
    connect(ui.line_outputPath, &QLineEdit::textChanged, this, &MainWindow::typed_output);
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
    this->timer.start();
    QString str("Sorting...");
    ui.label_test->setText(str);
}
// Stops the sorting for the Anchor
void MainWindow::clicked_stop() {
    this->timer.stop();
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
    // Create blank sorting method
    SortingMethod method;

    // Create custom widget
    auto item       = new QListWidgetItem();
    auto widget     = new SortingMethod_qt(this);
    QSize size      = QSize(widget->geometry().width(), widget->geometry().height());
    item->setSizeHint(size);

    ui.list_methods->addItem(item);
    ui.list_methods->setItemWidget(item, widget);
}
// Removes the selected sorting method from the stack
void MainWindow::clicked_removeMethod(){
    // Get current row
    int row         = ui.list_methods->currentRow();
    size_t index    = row;
    std::list<SortingMethod> & list = currentSortingMethods;

    // Remove from std::list of sortingmethods
    if (index < list.size() && list.size() > 0) {
        auto it = std::next(list.begin(), index);
        list.erase(it);
    } else {
        // Handle the error - index out of bounds
    }
    // Copy currentSortingMethods list to anchor's sortingmethod list
    this->currentAnchor.getSorter().setMethodsList(this->currentSortingMethods);


    // Remove widget from list
    auto method     = ui.list_methods->item(row);

    // Remove it (and remove it from memory)
    QListWidgetItem *it = ui.list_methods->takeItem(row);
    delete it;
}

// Applies the changed made to the sorting methods stack
void MainWindow::clicked_apply() {
    // Clear previous sorting methods list
    currentSortingMethods.clear();

    // Iterate through all sortingmethod widgets
    for (int i = 0; i < ui.list_methods->count(); i++) {
        // Get the widget
        QListWidgetItem* item = ui.list_methods->item(i);
        SortingMethod_qt* widget = qobject_cast<SortingMethod_qt *>(ui.list_methods->itemWidget(item));

        // Get the data
        std::string name = widget->getName().toStdString();
        std::string tag = widget->getTag().toStdString();
        double min = widget->getMin();
        double max = widget->getMax();
        bool active = widget->getActive();

        // Create new sorting method from data
        SortingMethod method(name, tag, std::any(min), std::any(max));
        method.setStatus(active);

        // Push sorting method to currentSortingMethods
        this->currentSortingMethods.push_back(method);
    }

    // Copy currentSortingMethods list to anchor's sortingmethod list
    this->currentAnchor.getSorter().setMethodsList(this->currentSortingMethods);

    // Debug Print
    this->currentAnchor.getSorter().printMethods();
}

void MainWindow::clicked_upload() {
    QFileDialog::getOpenFileName();
}

void MainWindow::typed_input() {
    std::string input   = ui.line_anchorPath->text().toStdString();
    std::string output  = ui.line_outputPath->text().toStdString();
    Anchor anchor(input, output, this->currentAnchor.getSorter());
    this->currentAnchor = anchor;

    ui.label_test->setText(QString("Set the new input folder."));
}

void MainWindow::typed_output() {
    std::string input   = ui.line_anchorPath->text().toStdString();
    std::string output  = ui.line_outputPath->text().toStdString();
    Anchor anchor(input, output, this->currentAnchor.getSorter());
    this->currentAnchor = anchor;

    ui.label_test->setText(QString("Set the new input folder."));
}

void MainWindow::save() {

}

void MainWindow::load() {

}
