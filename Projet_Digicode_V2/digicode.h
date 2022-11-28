#ifndef DIGICODE_H
#define DIGICODE_H

#include <QWidget>
#include <QTimer>
#include "MethodeCode.h"
#include "qlineedit.h"


namespace Ui {
class Clavier;
}

class Clavier : public QWidget
{
    Q_OBJECT

public:
    explicit Clavier(CentraleDalarme *_centrale, QWidget *parent = 0);
    ~Clavier();

private slots:
    void on_pushButtonMarche_clicked();
    void TraiterChiffre();
    void on_pushButtonArret_clicked();
    void onTimerLed_timeout();


private:
    Ui::Clavier *ui;
    CentraleDalarme *centrale;
    QTimer timerLed;
    QLineEdit *line;
};

#endif // DIGICODE_H
