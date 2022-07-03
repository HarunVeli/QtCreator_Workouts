#include "butonlar.h"

butonlar::butonlar(QWidget *parrent):QPushButton(parrent)
{
    tikladinmi=false;
    kactimi=true;
    connect(this,&QPushButton::clicked,this,&butonlar::tikla);
}

void butonlar::tikla()
{
    tikladinmi=!tikladinmi;
    kactimi=false;
}
