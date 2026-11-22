#ifndef FIREFOX_H
#define FIREFOX_H

#include <QObject>

class FireFox : public QObject
{
    Q_OBJECT
public:
    explicit FireFox(QObject *parent = nullptr);
    void browse(const QString &phrase);
signals:
};

#endif // FIREFOX_H
