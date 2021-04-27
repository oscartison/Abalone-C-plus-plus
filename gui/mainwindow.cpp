#include <QGraphicsScene>
#include <QGraphicsView>
#include <QCoreApplication>
#include <cmath>
#include <iostream>

#include "mainwindow.h"
#include "hexacell.h"
#include "point.hpp"



namespace abalone { namespace view {

MainWindow::MainWindow(model::Game * subject, QWidget *parent)
    : QMainWindow(parent),
      subject_ {subject}
{
    QGraphicsScene  * scene = new QGraphicsScene();

    double rad = 40;
    double w = sqrt(3) / 2 * rad;

    for (auto z = 0; z < subject_->getBoard().size(); z++) {
        for (auto y = 0; y < subject_->getBoard().size(); y++) {
            for (auto x = 0; x < subject_->getBoard().size(); x++) {
                abalone::model::Position position = abalone::model::Position(x,y,z);
                if (subject_->getBoard().isPosPossible(position)) {
                    scene->addItem(new HexaCell(rad, (x*2*w)+(z*w), z*(1.5*rad), nullptr));
                }
            }
        }
    }

    QGraphicsView * view = new QGraphicsView(scene);

    view->setRenderHint(QPainter::Antialiasing);
    view->setRenderHint(QPainter::TextAntialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    view->update();

    resize(1000, 800);

    this->setCentralWidget(view);
}

MainWindow::~MainWindow()
{}

void MainWindow::update(const Observable *subject) {
    if (subject != subject_) {
        return;
    }
}

}}
