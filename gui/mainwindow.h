#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>
#include <QLabel>

#include "game.h"
#include "observer.h"
#include "vector"
#include "position.h"

namespace abalone { namespace view {

class MainWindow : public QMainWindow, public Observer
{
    Q_OBJECT
    model::Game * subject_;
    QGraphicsView * view_;
    QGraphicsScene  * scene_;
    QPushButton *button_;
    QLabel* black_;
    QLabel* white_;
    QLabel* turn_;
    std::vector<abalone::model::Position> move_;

public :
    void drawInfo();
    MainWindow(model::Game * subject = nullptr, QWidget *parent = nullptr);
    ~MainWindow();
    virtual void update(const Observable * subject) override;

private slots :

    void makeMove();
    void addPosToMove(abalone::model::Position pos);

};

}}

#endif // MAINWINDOW_H
