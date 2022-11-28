#include <QDebug>
#include "MethodeCode.h"
#include "digicode.h"

#define TAILLE_CODE 4

CentraleDalarme::CentraleDalarme(const int _tailleCode, QObject *_parent) :
    QObject(_parent),
    tailleCode(_tailleCode),
    indiceCourant(0)
{
    combinaison = new quint8[tailleCode];
    for(int i = 0 ; i < tailleCode ; i++)
        combinaison[i]=0;

    leClavier = new Clavier(this);
    leClavier->show();
}

CentraleDalarme::~CentraleDalarme()
{
    delete[] combinaison;
    delete leClavier;
}

void CentraleDalarme::FabriquerCode(const quint8 _chiffre)
{
    // Code à compléter
    int indicevaleur = 0;
    combinaison[TAILLE_CODE] = indicevaleur;
    if (indiceCourant == TAILLE_CODE){
        for (indicevaleur = 0; indicevaleur < TAILLE_CODE - 1; indicevaleur ++){
            combinaison[indicevaleur] = combinaison[indicevaleur+1];
        }
        combinaison[indiceCourant -1] = _chiffre;
    }else{
        combinaison[indiceCourant] = _chiffre;
        indiceCourant += 1;
    }
    // Affichage de la combinaison lors de sa construction
    QString tampon = "Combinaison = ";
    for(int i = 0 ; i < tailleCode; i++)
        tampon += QString::number(combinaison[i]);
    qDebug() << tampon;

}
