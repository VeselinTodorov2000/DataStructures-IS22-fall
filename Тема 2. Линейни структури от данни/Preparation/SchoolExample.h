//
// Created by VeselinFMI on 10/27/2022.
//

#ifndef LINKEDLISTS_SCHOOLEXAMPLE_H
#define LINKEDLISTS_SCHOOLEXAMPLE_H
#include <iostream>
#include <string>

class School {
private:
    std::string name;
    int founded;
    int rooms;

public:
    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        School::name = name;
    }

    int getFounded() const {
        return founded;
    }

    void setFounded(int founded) {
        School::founded = founded;
    }

    int getRooms() const {
        return rooms;
    }

    void setRooms(int rooms) {
        School::rooms = rooms;
    }

    void formObject()
    {
        School s;
        s.setName("Name");
        s.setFounded(2022);
        s.setRooms(20);
    }
};

class SchoolBuilder {
private:
    std::string name;
    int founded;
    int rooms;

public:
    SchoolBuilder withName(std::string name) {
        this->name = name;
    }

    SchoolBuilder withYearFounded(int founded) {
        this->founded = founded;
    }

    SchoolBuilder withNumberOfRooms(int rooms) {
        this->rooms = rooms;
    }

    School build() {
        School s;
        s.setName(name);
        s.setFounded(founded);
        s.setRooms(rooms);

        return s;
    }
};


#endif //LINKEDLISTS_SCHOOLEXAMPLE_H
