#ifndef CUSTOMPROCESS_H
#define CUSTOMPROCESS_H

#include <QProcess>
#include <QDebug>

class customProcess : public QProcess
{
    Q_OBJECT

    int id;

public:
    explicit customProcess(int id, QObject *parent = 0);

signals:

    void finished(int id);

public:
    int returnId();

};

#endif // CUSTOMPROCESS_H
