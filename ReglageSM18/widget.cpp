#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&timerMesure,&QTimer::timeout,this,&Widget::onTimerMesure_timeout);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_Lancer_clicked()
{
     double *valeursBrutes = nullptr;
    double vitesse = 33000;
    ScanOption options = static_cast<ScanOption>(SO_SINGLEIO | SO_CONTINUOUS | SO_EXTCLOCK | SO_EXTTRIGGER);
    qDebug() << "scanOption : " << Qt::hex << options;
    AInScanFlag flags = AINSCAN_FF_DEFAULT ;
    UlError erreur = laCarte.ulAInScan(CH0,CH1,NB_ECHANTILLONS_PAR_CANAL,&vitesse,options,flags,valeursBrutes);
    qDebug()<< "ulAInScan " << erreur;
    timerMesure.start(1000);
}

void Widget::onTimerMesure_timeout()
{
 UlError ulAIn  (const int _canal, double &_valeur, const AInFlag _flags = AIN_FF_DEFAULT);
}

