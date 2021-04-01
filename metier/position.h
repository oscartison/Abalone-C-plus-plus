#ifndef POSITION_H
#define POSITION_H
#include <iostream>

namespace abalone { namespace model {

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
abalone::model::Position operator-(const abalone::model::Position p1, const abalone::model::Position p2);

/*!
 * \brief the + operator for 2 positions
 *
 * \param p1 the first position
 *
 * \param p2 the second position
 *
 * \return the sum of the 2 positions
 */
abalone::model::Position operator+(const abalone::model::Position p1, const abalone::model::Position p2);

/*!
 * \brief abaToPos this method will take 2 chars in a
 *  string in aba pro and makes a position out of it
 * \param s the string to convert in a position
 * \return the position
 *
 * \throw an exception is thrown if the given string is not
 *  in aba-pro
 */
abalone::model::Position abaToPos(std::string s);

int abalone::model::Position::x() const {
    return x_;
}

int abalone::model::Position::y() const {
    return y_;
}

int abalone::model::Position::z() const {
    return z_;
}

}}

#endif // POSITION_H
