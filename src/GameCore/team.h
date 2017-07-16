#ifndef TEAM_H
#define TEAM_H

/**
 * @file team.h
 */

#include <vector>

class IShip;

/**
 * @brief The Team class A team is a group of ship friendly to each other.
 */
class Team
{
public:
    /**
     * @brief Team The default constructor.
     */
    Team();
    ~Team();
    /**
     * @brief getShips Get the ships of this team.
     * @return The ships of this team.
     */
    std::vector<IShip*>* getShips();
private:
    /**
     * @brief ships The ships of this team.
     */
    std::vector<IShip*>* ships;
};

#endif // TEAM_H
