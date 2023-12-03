#ifndef SORTINGMETHOD_QT_H
#define SORTINGMETHOD_QT_H

#include <QWidget>
#include "sortingmethod.h"

namespace Ui {
class SortingMethod_qt;
}

class SortingMethod_qt : public QWidget
{
    Q_OBJECT

public:
    explicit SortingMethod_qt(QWidget *parent = nullptr);
    ~SortingMethod_qt();

    QString getName();
    QString getTag();
    QVariant getMin();
    QVariant getMax();
    bool getActive();

private:
    SortingMethod methodData;
    Ui::SortingMethod_qt *ui;
};

#endif // SORTINGMETHOD_QT_H
