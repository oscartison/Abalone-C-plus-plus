#ifndef POSITION_H
#define POSITION_H

/*!
 * \brief class that represents a position to a system with 3 axis
 *
 * this position is a position that a marble will have.
 */
class position {
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

public:

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
    position(int x, int y, int z);

    /*!
     * \brief getter for the position on the x-axis
     *
     * \return the position on the x-axis
     */
    int x() const;

    /*!
     * \brief getter for the position on the y-axis.
     *
     * \return the position on the y-axis.
     */
    char y() const;

    /*!
     * \brief getter for the position on the z-axis.
     *
     * \return the position on the z-axis.
     */
    char z() const;

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
     * \param dx how much to move on the x-axis
     *
     * \param dy how much to move on the y-axis
     *
     * \param dy how much to move on the y-axis
     */
    void move(int dx, int dy, int dz);


};

/*!
 * \brief the - operator for 2 positions
 *
 * \param p1 the first position
 *
 * \param p2 the second position
 *
 * \return the substraction of the 2 positions
 */
position operator-(const position p1, const position p2);

/*!
 * \brief the + operator for 2 positions
 *
 * \param p1 the first position
 *
 * \param p2 the second position
 *
 * \return the sum of the 2 positions
 */
position operator+(const position p1, const position p2);


#endif // POSITION_H
