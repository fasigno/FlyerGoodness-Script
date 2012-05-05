#ifndef CONSOLE_H
#define CONSOLE_H

#include <customprocess.h>
#include <QtCore/QCoreApplication>
#include <iostream>

#include <QStringList>

#include <QFile>
#include <QDir>
#include <QTextStream>

#include <QList>
#include <QPair>

#include <QDebug>

using namespace std;

class customProcess;

class console : public QObject
{
    Q_OBJECT

    QFile links;
    QStringList path;

    QList < QPair< QString, QString > > months;
    QList <int> download;

    bool apriLinks();

public:
    explicit console(QObject *parent = 0);

signals:

    void finished();

private slots:

    void redraw();

    void start();

    void finishedDownload();

};

#endif // CONSOLE_H
