 #include <stack>
#include <iostream>

//
// Created by VeselinFMI on 11/14/2022.
//
const int MAX_SIZE = 8;
int lab[MAX_SIZE][MAX_SIZE] = {
        0, 1, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 1, 0, 0, 0, 0,
        0, 1, 0, 1, 0, 0, 0, 0,
        0, 1, 1, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0
};

struct positionInLab {
    int x, y;

    bool operator==(const positionInLab &p) {
        return x == p.x && y == p.y;
    }

    bool operator!=(const positionInLab &p) {
        return x != p.x || y != p.y;
    }

    positionInLab down() {
        return positionInLab{x, y + 1};
    }

    positionInLab up() {
        return positionInLab{x, y - 1};
    }

    positionInLab left() {
        return positionInLab{x - 1, y};
    }

    positionInLab right() {
        return positionInLab{x + 1, y};
    }
};

bool possiblePositionInLab(positionInLab positionInLab) {
    return positionInLab.x >= 0 &&
        positionInLab.y >= 0 &&
        positionInLab.x < MAX_SIZE &&
        positionInLab.y < MAX_SIZE &&
        lab[positionInLab.x][positionInLab.y] == 0;
}

bool way (positionInLab current, positionInLab goal) {
    if (current == goal) { return true; }
    if (!possiblePositionInLab(current)) { return false; }

    //===============================
    lab[current.x][current.y] = 5;
    //===============================

    bool found = way(current.down(), goal) ||
                 way(current.right(), goal) ||
                 way(current.up(), goal) ||
                 way(current.left(), goal);

    //===============================
    lab[current.x][current.y] = 0;
    //===============================

    return found;
}

bool wayiter(positionInLab start, positionInLab goal)
{
    std::stack<positionInLab> s;

    s.push(start);

    while (!s.empty() && s.top() != goal)
    {
        positionInLab current = s.top(); s.pop();

        if (possiblePositionInLab(current))
        {
            lab[current.x][current.y] = 5;

            s.push(current.left());
            s.push(current.up());
            s.push(current.right());
            s.push(current.down());
        }
    }

    return !s.empty();
}
int main() {
    std::cout << way ({0,0},{7,7}) << std::endl;
    std::cout << wayiter ({0,0},{7,7}) << std::endl;
    return 0;
}