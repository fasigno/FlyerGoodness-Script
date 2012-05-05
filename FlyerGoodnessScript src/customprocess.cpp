#include "customprocess.h"

customProcess::customProcess(int id, QObject *parent) :
    QProcess(parent)
{
        this->id = id;
}

int customProcess::returnId() {
    return id;
}
