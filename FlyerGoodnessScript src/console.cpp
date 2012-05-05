#include "console.h"

console::console(QObject *parent) :
    QObject(parent)
{

    QObject::connect(this, SIGNAL(finished()), parent, SLOT(quit()), Qt::QueuedConnection);

    path = QCoreApplication::arguments();

    if(apriLinks() == true) { //Lettura dal file.

        QTextStream in(&links);

        while(!in.atEnd()) {

            QString line = in.readLine();

            if(line.isEmpty() == false) {

                months.append(qMakePair(line.split("-").at(0), line.split("-").at(1)));

                download.append(0);

            }
        }

    } else {
        emit finished();
    } //Fine lettura dal file.

    //Scaricamento :

    for(int i=0; i<months.size(); i++) {

        QDir().mkdir(months.at(i).second);

        QString program = "wget";
        QStringList arguments;

        arguments << "-nd" << "-E" << "-H" <<  "-k" << "-K" << "-p" << "-A" << "jpg" << months.at(i).first;

        customProcess *myProcess = new customProcess(i);

        QObject::connect(myProcess, SIGNAL(started()), this, SLOT(start()));

        QObject::connect(myProcess, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(finishedDownload()));

        myProcess->setWorkingDirectory(months.at(i).second);

        myProcess->start(program, arguments);

        myProcess->waitForFinished(); //Attende la fine del processo.

        myProcess->kill();

    }

    cout << "\n";

    emit finished();

}

bool console::apriLinks() {

    links.setFileName(path.at(1));
    if (!links.open(QIODevice::ReadOnly | QIODevice::Text)) {
        cout << "File con links non trovato!" << std::endl;
        return false;
    }

    return true;
}

void console::redraw() {

    //Output:

     std::system ( "clear" );
//    write(1,"\E[H\E[2J",7); //Cancella lo schermo.

    cout << "\n";
    cout << "Scaricamento Immagini Attedere :  \n";
    cout << "---------------------------------\n";

    if(months.isEmpty() == false) {

        for(int i=0; i< months.count(); i++) {

            char imm = ' ';

        switch(download.at(i)) {

            case 0: imm = '*';
                break;

            case 1: imm = '>';
                break;

            case 2: imm = 'v';
                break;

        }

        cout << " [" << imm << "] " << months.at(i).second.toStdString() << "\n";

    }

        cout << "\n";

    }

}

void console::start() {

    customProcess * sender = dynamic_cast<customProcess*> (QObject::sender());
    int id = sender->returnId();

    download.removeAt(id);

    download.insert(id, 1);

    redraw();
}

void console::finishedDownload() {

    customProcess * sender = dynamic_cast<customProcess*> (QObject::sender());
    int id = sender->returnId();

    download.removeAt(id);

    download.insert(id, 2);

    cout << "Finito = " << id;

    redraw();
}
