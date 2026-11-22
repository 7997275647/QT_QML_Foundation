#include <QCoreApplication>
#include <QQmlApplicationEngine>
#include <QString>
#include <QTimer>
//user includes
#include "applicationwindow.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ApplicationWindow rootWindow("root window");

    ApplicationWindow *parentWindow1 = new ApplicationWindow("parent window 1", &rootWindow);
    ApplicationWindow *parentWindow2 = new ApplicationWindow("parent window 2", &rootWindow);

    for (int i = 0; i<2; i++){
        ApplicationWindow *childWindow1 = new ApplicationWindow(QString("child window %1 of parent window 1").arg(i), parentWindow1);
        ApplicationWindow *childWindow2 = new ApplicationWindow(QString("child window %1 of parent window 2").arg(i), parentWindow2);

    }

    QTimer:: singleShot(3000, [&](){
        parentWindow1->deleteLater();
    });

    QTimer:: singleShot(5000, [&](){
        a.quit();
    });

    return a.exec();
}
