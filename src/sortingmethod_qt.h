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

    //----- Commands
    void typed_name();
    void selected_tag();
    void typed_min();
    void typed_max();
    void checked_active();

    /* --- GETTERS --- */
    QString getName();
    QString getTag();
    QString getMin();
    QString getMax();
    bool getActive();

private:
    QString name;
    QString tag;
    QString min;
    QString max;
    bool active;
    Ui::SortingMethod_qt *ui;
};

#endif // SORTINGMETHOD_QT_H
