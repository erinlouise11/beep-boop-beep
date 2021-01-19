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
    adjectives.push_back("Fat");
    adjectives.push_back("Cute");
    adjectives.push_back("Tasty");

    verbs.push_back("Running");
    verbs.push_back("Fighting");
    verbs.push_back("Yeeting");
    verbs.push_back("Dying");
    verbs.push_back("Charging");
    verbs.push_back("Swimming");
    verbs.push_back("Quivering");
    verbs.push_back("Blubbering");
    verbs.push_back("Dancing");
    verbs.push_back("Headbanging");

    nouns.push_back("Penguin");
    nouns.push_back("Turtle");
    nouns.push_back("Log");
    nouns.push_back("Octopus");
    nouns.push_back("Angel");
    nouns.push_back("Demon");
    nouns.push_back("Idiot");
    nouns.push_back("Blob");
    nouns.push_back("Peanut");
    nouns.push_back("Shoe");

    QString path = "D:/QtOpenSource/Projects/BeepBoopBeep/";

    favoritesF = new QFile(path + "favorites.txt");
    verbsF = new QFile(path +"verbs.txt");
    adjectivesF = new QFile(path +"adjectives.txt");
    nounsF = new QFile(path +"nouns.txt");

    showLikedNames(favoritesF);

    connect(ui->btnFavorite, SIGNAL(clicked()), this, SLOT(likeName()));
    connect(ui->btnNext, SIGNAL(clicked()), this, SLOT(getNext()));
    connect(ui->btnPrev, SIGNAL(clicked()), this, SLOT(getPrevious()));
    connect(ui->btnGo, SIGNAL(clicked()), this, SLOT(displayName()));
}

MainWindow::~MainWindow(){
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

    return;
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

void MainWindow::likeName(){

    writeFile(favoritesF, ui->leResult->text());

    return;
}

void MainWindow::getNext(){

    QString current = ui->leResult->text();
    int i = tempNames.indexOf(current);

    if(i != -1){
        if(i < tempNames.size() && i != tempNames.size()-1){
            ui->leResult->setText(tempNames[i+1]);
        }
        else if(i == tempNames.size()-1)
            ui->leResult->setText(current);
    }
    else
        ui->leResult->setText("");
}

void MainWindow::getPrevious(){

    QString current = ui->leResult->text();
    int i = tempNames.indexOf(current);

    if(i != -1){
        if(i > 0){
            ui->leResult->setText(tempNames[i-1]);
        }
        else
            ui->leResult->setText(current);
    }
    else
        ui->leResult->setText("");


}

void MainWindow::writeFile(QFile *f, QString s){

    if(!f->exists()){
        qDebug() << f->fileName() << " does not exist";
        return;
    }

    if(f->open(QIODevice::Append | QIODevice::Text)){

        QTextStream ts(f);

        qDebug() << "Writing to file";

        ts << s << endl;

        qDebug() << "Write COMPLETE";

        f->close();

        showLikedNames(f);

        return;
    }

    else{
        qDebug() << "Cannot open file";
        return;
    }    

    return;
}

void MainWindow::showLikedNames(QFile *f){

    if(!f->exists()){
        qDebug() << f->fileName() << " does not exist";
        return;
    }

    if(f->open(QIODevice::ReadOnly)){

        QTextStream ts(f);
        QString line = ts.readLine();
        bool exists = false;

        while(!line.isNull()){

            for(int i = 0; i < ui->lwLikedNames->count(); i++){
                if(line == ui->lwLikedNames->item(i)->text()){
                    exists = true;
                    break;
                }
            }

            if(exists){
                exists = false;
                line = ts.readLine();
            }
            else{
                new QListWidgetItem(line, ui->lwLikedNames);
                line = ts.readLine();
            }
        }

        f->close();

        return;
    }

    else{
        qDebug() << "Cannot open file";
        return;
    }

    return;
}
