#ifndef POINTS_HPP
#define POINTS_HPP


class Points
{
public:
    Points();
    void addPoint();
    int getPoints() const;
    void resetPoints();

private:
    int actualPoints;
};

#endif // POINTS_HPP
