#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>
#include <QLabel>
#include <QListWidget>
#include <hexacell.h>

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
    QPushButton * button_;
    QLabel * black_;
    QLabel * white_;
    QLabel * turn_;
    QList<abalone::view::HexaCell *> board_;
    QList<QGraphicsEllipseItem *> marbles_;
    std::vector<abalone::model::Position> move_;

public :

    /**
     * @brief drawInfo draws the information about the state of the game
     * ex. remaining marbles, player's turn,...
     */
    void drawInfo();

    /**
     * @brief MainWindow the constructor of the user interface to play the game.
     * @param subject the game that will be played on the the user interface
     * @param parent the parent widget of this window
     */
    MainWindow(model::Game * subject = nullptr, QWidget * parent = nullptr);

    /**
     * @brief ~MainWindow the destructor for MainWindow.
     */
    ~MainWindow();

    /**
     * @brief update updates the window when a change has been made in the subject
     * @param subject the subject that notified the window that he changed
     */
    virtual void update(const Observable * subject) override;

    /**
     * @brief printWin prints a message when a player has won
     * @return the player that won with congratulations
     */
    QString printWin();

    /**
     * @brief showMenu shows a messageBox where the players can choose to quit the game or restart a new game.
     */
    void showMenu();

private slots :

    /**
      * @brief restart restarts a new game
      */
    void restart();

    /**
     * @brief makeMove asks the subject to make a move with the right positions
     */
    void makeMove();

    /**
     * @brief addPosToMove adds the selected position to a vector that contains the move to make
     * @param pos the position to add to the vector
     */
    void addPosToMove(abalone::model::Position pos);

};

}}

#endif // MAINWINDOW_H
