#include "widgetusb202.h"
#include "ui_widgetusb202.h"

WidgetUSB202::WidgetUSB202(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WidgetUSB202)
{
    ui->setupUi(this);
    UlError erreur;
    erreur = laCarte.ulDConfigBit(LED1,DD_OUTPUT);
    if(erreur != ERR_NO_ERROR)
          qDebug() << "Config " << LED1 << " Code Erreur : " << erreur;
    erreur = laCarte.ulDConfigBit(LED2,DD_OUTPUT);
    if(erreur != ERR_NO_ERROR)
          qDebug() << "Config " << LED2 << " Code Erreur : " << erreur;
    erreur = laCarte.ulDConfigBit(LED3,DD_OUTPUT);
    if(erreur != ERR_NO_ERROR)
          qDebug() << "Config " << LED3 << " Code Erreur : " << erreur;
    erreur = laCarte.ulDConfigBit(LED4,DD_OUTPUT);
    if(erreur != ERR_NO_ERROR)
          qDebug() << "Config " << LED4 << " Code Erreur : " << erreur;

}

WidgetUSB202::~WidgetUSB202()
{
    delete ui;
}


void WidgetUSB202::on_checkBox_LED1_stateChanged(int arg1)
{
    UlError erreur;
        erreur = laCarte.ulDBitOut(LED1,static_cast<bool>(arg1));
        if(erreur != ERR_NO_ERROR)
            qDebug() << "Ecriture DIO" << LED1 << " Code Erreur : " << erreur;;
}
void WidgetUSB202::on_checkBox_LED2_stateChanged(int arg1)
{
    UlError erreur;
        erreur = laCarte.ulDBitOut(LED2,static_cast<bool>(arg1));
        if(erreur != ERR_NO_ERROR)
            qDebug() << "Ecriture DIO" << LED2 << " Code Erreur : " << erreur;
}

void WidgetUSB202::on_checkBox_LED3_stateChanged(int arg1)
{
    UlError erreur;
        erreur = laCarte.ulDBitOut(LED3,static_cast<bool>(arg1));
        if(erreur != ERR_NO_ERROR)
            qDebug() << "Ecriture DIO" << LED3 << " Code Erreur : " << erreur;
}

void WidgetUSB202::on_checkBox_LED4_stateChanged(int arg1)
{
    UlError erreur;
        erreur = laCarte.ulDBitOut(LED4,static_cast<bool>(arg1));
        if(erreur != ERR_NO_ERROR)
            qDebug() << "Ecriture DIO" << LED4 << " Code Erreur : " << erreur;
}

void WidgetUSB202::onTimerBp_timeOut()
{

}

