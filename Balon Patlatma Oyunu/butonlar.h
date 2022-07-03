#ifndef BUTONLAR_H
#define BUTONLAR_H
#include <QPushButton>

class butonlar : public QPushButton
{
    Q_OBJECT
public:
    butonlar(QWidget *parrent=0);
    bool tikladinmi;
    bool kactimi;
public slots:
    void tikla();
};

#endif // BUTONLAR_H


