#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Beep Boop Beep");

    adjectives.push_back("Happy");
    adjectives.push_back("Lonely");
    adjectives.push_back("Enthusiastic");
    adjectives.push_back("Loveable");
    adjectives.push_back("Scary");
    adjectives.push_back("Depressed");

    verbs.push_back("Running");
    verbs.push_back("Fighting");
    verbs.push_back("Yeeting");
    verbs.push_back("Dying");
    verbs.push_back("Charging");
    verbs.push_back("Swimming");

    nouns.push_back("Penguin");
    nouns.push_back("Turtle");
    nouns.push_back("Log");
    nouns.push_back("Octopus");
    nouns.push_back("Angel");
    nouns.push_back("Demon");

    favoritesF = new QFile("favorites.txt");
    verbsF = new QFile("verbs.txt");
    adjectivesF = new QFile("adjectives.txt");
    nounsF = new QFile("nouns.txt");

    connect(ui->btnFavorite, SIGNAL(clicked()), this, SLOT(addFavorite()));
    connect(ui->btnNext, SIGNAL(clicked()), this, SLOT(getNext()));
    connect(ui->btnPrev, SIGNAL(clicked()), this, SLOT(getPrevious()));
    connect(ui->btnGo, SIGNAL(clicked()), this, SLOT(displayName()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getRandomInt(int n){

    int rand = QRandomGenerator::global()->bounded(0, n);

    return rand;
}

int MainWindow::getNameLength(){

    return ui->cbbNumber->currentText().toInt();
}

void MainWindow::displayName(){

    ui->leResult->setText(generateName());
}

QString MainWindow::generateName(){

    int nameLength = getNameLength();

    switch(nameLength){
        case 2:
            nameGenerated = adjectives[getRandomInt(adjectives.size())] + nouns[getRandomInt(nouns.size())];
            break;
        case 3:
            nameGenerated = adjectives[getRandomInt(adjectives.size())] +
                    verbs[getRandomInt(verbs.size())] + nouns[getRandomInt(nouns.size())];
            break;
    }

    addTempNames(nameGenerated);

    return nameGenerated;
}

void MainWindow::addTempNames(QString s){

    tempNames.push_back(s);

    return;
}

void MainWindow::addFavorite(){

    writeFile(favoritesF, ui->leResult->text());
}

QString MainWindow::getNext(){

    QString next;

    //...

    return next;

}

QString MainWindow::getPrevious(){

    QString prev;

    //...

    return prev;
}

void MainWindow::writeFile(QFile *f, QString s){

    if(!f->exists())
            qDebug() << f->fileName() << " does not exist";

    if(f->open(QIODevice::ReadOnly | QIODevice::WriteOnly | QIODevice::Text)){

        QTextStream ts(f);
        QString line;

        qDebug() << "Writing to file...";

        ts << s << endl;

        // checking if the write was successfull
        do{
            line = ts.readAll();
            if(line.contains(s, Qt::CaseInsensitive)){
                qDebug() << "Write to file COMPLETE";
                return;
            }
        } while(!line.isNull());
    }

    else{
        qDebug() << "Cannot open file";
        return;
    }
}
