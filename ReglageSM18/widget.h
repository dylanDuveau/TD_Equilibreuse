#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include "mcculdaq.h"
#include "constantes.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_Lancer_clicked();
    void onTimerMesure_timeout();

private:
    Ui::Widget *ui;
    MccUldaq laCarte;
    QTimer timerMesure;

};
#endif // WIDGET_H
