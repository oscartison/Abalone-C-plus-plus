#ifndef POSITION_H
#define POSITION_H

#include <iostream>

/*!
 * \brief class that represents a position to a system with 3 axis
 *
 * this position is a position that a marble will have.
 */
class Position {

    /*!
    * \brief the position on the x axis.
    */
    int x_;

    /*!
    * \brief the position on the y axis.
    */
    int y_;

    /*!
    * \brief the position on the z axis.
    */
    int z_;

public :

    /*!
    * \brief Constructor.
    *
    * the position is created with 2 values.
    *
    * \param x the x-position.
    *
    * \param y the y-position.
    *
    * \param z the y-position.
    *
    */
    Position(int x, int y, int z);

    /*!
     * \brief getter for the position on the x-axis
     *
     * \return the position on the x-axis
     */
    inline int x() const;

    /*!
     * \brief getter for the position on the y-axis.
     *
     * \return the position on the y-axis.
     */
    inline int y() const;

    /*!
     * \brief getter for the position on the z-axis.
     *
     * \return the position on the z-axis.
     */
    inline int z() const;

    /*!
     * \brief checks if a position is possible according to a certain
     * size of board.
     *
     * \param size the size according to what we chcek if it is possible.
     *
     * \return true if the position is possible, false otherwise.
     */
    bool isPossiblePos(int size);

    /*!
     * \brief moves the position a of dx and dy.
     *
     * \param dx how much to move on the x-axis.
     *
     * \param dy how much to move on the y-axis.
     *
     * \param dy how much to move on the y-axis.
     */
    void move(int dx, int dy, int dz);

    /*!
     * \brief computes the distance between two positions.
     *
     * \param po2 the second position.
     *
     * \return the distance between the two positions.
     */
    int distance(Position po2);

};

/*!
 * \brief the - operator for 2 positions.
 *
 * \param p1 the first position.
 *
 * \param p2 the second position.
 *
 * \return the substraction of the 2 positions.
 */
Position operator-(const Position p1, const Position p2);

/*!
 * \brief the + operator for 2 positions
 *
 * \param p1 the first position
 *
 * \param p2 the second position
 *
 * \return the sum of the 2 positions
 */
Position operator+(const Position p1, const Position p2);

Position abaToPos(std::string s);

int Position::x() const {
    return x_;
}

int Position::y() const {
    return y_;
}

int Position::z() const {
    return z_;
}

#endif // POSITION_H
