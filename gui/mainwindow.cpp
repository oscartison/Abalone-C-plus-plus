#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QCoreApplication>
#include <QPushButton>
#include <cmath>
#include <iostream>

#include "mainwindow.h"
#include "hexacell.h"
#include "point.hpp"

namespace abalone { namespace view {

MainWindow::MainWindow(model::Game * subject, QWidget *parent)
    : QMainWindow(parent),
      subject_ {subject},
      move_{}
{
    subject_->registerObserver(this);
    update(subject);
    resize(1000,800);
}

MainWindow::~MainWindow()
{}

void MainWindow::makeMove() {
    try {
        if(move_.size() == 2) {
            subject_->makeMove(move_[0],move_[1]);
            move_.clear();
        } else if(move_.size() == 3) {
            subject_->makeMove(move_[0],move_[1],move_[2]);
            move_.clear();
        } else {
            throw std::invalid_argument("Please select 2 or 3 cases !");
        }
    }   catch (const std::exception & e) {
        QMessageBox::information(this,tr("Impossible move!!"),tr(e.what()));
        //  std::cout << e.what() << std::endl;
    }
}

void MainWindow::addPosToMove(abalone::model::Position pos){
    bool inserted = true;
    for(unsigned long i = 0; i < move_.size() && inserted;i++) {
        if (move_[i].x() == pos.x() && move_[i].y() == pos.y() &&move_[i].z() == pos.z()) {
            move_.erase (move_.begin()+i);
            inserted = false;
        }
    }
    if(inserted) {
        move_.push_back(pos);
    }
}

void MainWindow::update(const Observable *subject) {
    if (subject == subject_) {

        double rad = 40;
        double w = sqrt(3) / 2 * rad;

        scene_ = new QGraphicsScene();

        for (auto z = 0; z < subject_->getBoard().size(); z++) {
            for (auto y = 0; y < subject_->getBoard().size(); y++) {
                for (auto x = 0; x < subject_->getBoard().size(); x++) {
                    abalone::model::Position position = abalone::model::Position(x,y,z);
                    if (subject_->getBoard().isPosPossible(position)) {
                        HexaCell* hexa =new HexaCell(position,rad, (x*2*w)+(z*w), z*(1.5*rad), nullptr);
                        hexa->registerObserver(this);
                        scene_->addItem(hexa);

                        if (subject_->getBoard().playerAtPosition(position)) {
                            QPen pen(Qt::black, 5);

                            QBrush brush;
                            if(subject_->getBoard().playerAtPosition(position)->id() == 1) {
                                brush.setColor(Qt::black);
                            } else {
                                brush.setColor(Qt::white);
                            }

                            brush.setStyle(Qt::SolidPattern);
                            scene_->addEllipse((x*2*w)+(z*w) - rad/2, z*(1.5*rad) -rad/2,w,w, pen,brush);

                        }
                    }
                }
            }
        }

        QPushButton *button = new QPushButton;
        button->setGeometry(QRect(0,0, 100, 20));
        button->setText("Make move!");
        connect(button,SIGNAL(clicked()),this,SLOT(makeMove()));
        scene_->addWidget(button);
        view_ = new QGraphicsView(scene_);
        view_->setRenderHint(QPainter::Antialiasing);
        view_->setRenderHint(QPainter::TextAntialiasing);
        view_->setCacheMode(QGraphicsView::CacheBackground);
        view_->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
        view_->setDragMode(QGraphicsView::ScrollHandDrag);
        view_->update();
        this->setCentralWidget(view_);
    } else {
        Observable *test = const_cast<Observable *>(subject);
        HexaCell* h = static_cast<HexaCell*>(test);
        addPosToMove(h->pos_);

    }}

}}
