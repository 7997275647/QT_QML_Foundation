#include <QGuiApplication>
#include <QQmlApplicationEngine>
//user includes
#include "firefox.h"
#include "internetexplorer.h"
#include "userinteractor.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //QGuiApplication app(argc, argv);

    UserInteractor userInteractor;
    InternetExplorer internetExplorer;
    FireFox fireFox;



    QObject::connect(&userInteractor, &UserInteractor::phraseTyped, &fireFox, &FireFox::browse);
    QObject::connect(&userInteractor, &UserInteractor::phraseTyped, &internetExplorer, &InternetExplorer::browseRequested);
    userInteractor.getInput();

    /*QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("QTQMLAPP2", "Main");

    return QGuiApplication::exec();*/
    return a.exec();
}
