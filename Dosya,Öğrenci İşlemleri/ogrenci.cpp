#include   <iostream>
#include <QString>

class ogrenci{

public :
    QString ad,soyad;
    int vize,final;
    double gnot;
    ogrenci(QString ad,QString soyad,int vize,int final){
        this->ad=ad;
        this->soyad=soyad;
        this->vize=vize;
        this->final=final;
    }

    double gecmenotuhesapla(int vn,int fn){
        this->gnot=vn*0.4+fn*0.6;
        return gnot;
    }

};
