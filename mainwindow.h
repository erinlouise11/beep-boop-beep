#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QString>
#include <QRandomGenerator>

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
    void favorite(QString);
    void removeFavorite(QString);

private:
    Ui::MainWindow *ui;
    QVector<QString> adjectives, nouns, verbs, favorites;
    QString nameGenerated;
};
#endif // MAINWINDOW_H
