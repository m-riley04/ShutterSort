#include "sortingmethod_qt.h"
#include "ui_sortingmethod_qt.h"

SortingMethod_qt::SortingMethod_qt(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SortingMethod_qt)
{
    ui->setupUi(this);
}

SortingMethod_qt::~SortingMethod_qt()
{
    delete ui;
}

QString SortingMethod_qt::getName() {
    return ui->line_name->text();
}

QString SortingMethod_qt::getTag() {
    return ui->dropdown_tags->currentText();
}

QVariant SortingMethod_qt::getMin() {
    return ui->line_min->text();
}

QVariant SortingMethod_qt::getMax() {
    return ui->line_max->text();
}
