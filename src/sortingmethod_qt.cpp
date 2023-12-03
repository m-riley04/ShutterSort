#include "sortingmethod_qt.h"
#include "ui_sortingmethod_qt.h"

SortingMethod_qt::SortingMethod_qt(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SortingMethod_qt)
{

    ui->setupUi(this);

    //==================== Connect widgets
    //----- Buttons
    connect(ui->line_name, &QLineEdit::textChanged, this, &SortingMethod_qt::typed_name);
}

SortingMethod_qt::~SortingMethod_qt()
{
    delete ui;
}

//===== COMMANDS ===============================
// Command for when a user types inside the name box
void SortingMethod_qt::typed_name() {

}

//===== GETTERS ===============================
// Returns the name of the method as a QString
QString SortingMethod_qt::getName() {
    return ui->line_name->text();
}

// Returns the tag of the method as a QString
QString SortingMethod_qt::getTag() {
    return ui->dropdown_tags->currentText();
}

// Returns the minimum value of the method as a QString
QString SortingMethod_qt::getMin() {
    return ui->line_min->text();
}

// Returns the maximum value of the method as a QString
QString SortingMethod_qt::getMax() {
    return ui->line_max->text();
}

// Returns the active status of the method as a bool
bool SortingMethod_qt::getActive() {
    return ui->checkbox_active->isChecked();
}
