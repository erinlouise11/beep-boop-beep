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

    nameGenerated = verbs[2] + nouns[4];

    ui->leResult->setText(nameGenerated);

    connect(ui->btnFavorite, SIGNAL(clicked()), this, SLOT(favorite()));
    connect(ui->btnGo, SIGNAL(clicked()), this, SLOT(generateName()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getRandomInt(int n) {

    int rand = QRandomGenerator::global()->bounded(0, n);

    return rand;
}

