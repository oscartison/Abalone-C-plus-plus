#ifndef POSITION_H
#define POSITION_H

class position {
    int x_axis_;
    char y_axis_;

public:
    int x_axis();
    char y_axis();

    int x_axis() const;
    char y_axis() const;

    static bool isPossiblePos(int x, char y, int size);

    void move(int dx, int dy);


};


position operator-(const position p1, const position p2);

position operator+(const position p1, const position p2);


#endif // POSITION_H
