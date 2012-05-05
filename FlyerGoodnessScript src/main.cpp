//*************** - FlyerGoodness Script - ********************
//* Simple program that downloads all the flyers periodically *
//* uploaded on flyergoodness.blogspot.it                     *
//*************************************************************

//Under GPLv3

//Fabrizio Signoretti, fasigno37@gmail.com
//Project Site: github.com/fasigno/FlyerGoodness-Script

//Needs a file with all site pages links.
//The links in the file provided are earned from the post history list in html code.

#include <QtCore/QCoreApplication>

#include <console.h>

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class console;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(argc < 2) {

       cout << "Sintassi Errata\n";
       cout << "Uso :: ./FlyerGoodnessScript filelinks\n";

        return -2;

    } else {
        console *task = new console(&a);
    }

    return a.exec();
}
