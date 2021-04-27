#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "game.h"
#include "observer.h"

namespace abalone { namespace view {

class MainWindow : public QMainWindow, public Observer
{
    Q_OBJECT
    model::Game * subject_;

public:
    MainWindow(model::Game * subject = nullptr, QWidget *parent = nullptr);
    ~MainWindow();
    virtual void update(const Observable * subject) override;
};

}}

#endif // MAINWINDOW_H
