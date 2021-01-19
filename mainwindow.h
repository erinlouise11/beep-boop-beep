#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QRandomGenerator>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int getRandomInt(int);
    QString generateName();
    int getNameLength();
    void addTempNames(QString);
    void closeFile(QFile);
    void writeFile(QFile*, QString);
    void showLikedNames(QFile*);

public slots:
    void displayName();
    void likeName();
    void getPrevious();
    void getNext();
//    void removeLikedName(QString);

private:
    Ui::MainWindow *ui;
    QVector<QString> adjectives, nouns, verbs, tempNames;
    QFile *favoritesF, *verbsF, *adjectivesF, *nounsF;
    QString nameGenerated;
};
#endif // MAINWINDOW_H
