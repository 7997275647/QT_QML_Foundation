#include "firefox.h"
#include <QDebug>

FireFox::FireFox(QObject *parent)
    : QObject{parent}
{}

void FireFox::browse(const QString &phrase){
    qDebug() << "Displaying Results for: " << phrase;
}
