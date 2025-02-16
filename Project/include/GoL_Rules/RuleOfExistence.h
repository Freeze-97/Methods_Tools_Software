/*
 * Filename    RuleOfExistence.h
 * Author      Erik Ström
 * Date        July 2019
 * Version     0.2
*/
#ifndef RULEOFEXISTENCE_H
#define RULEOFEXISTENCE_H

#include<string>
#include<map>
#include <utility>
#include<vector>
#include "Cell_Culture/Cell.h"
#include "Support/Globals.h"
using namespace std;

/*
These rules lies at the heart
of the simulation, and determines the fate of each cell in the world population.
*/

// Data structure for storing population limits. Used by rules to determine what ACTION to make.
struct PopulationLimits {
    int UNDERPOPULATION, // cell dies of loneliness
            OVERPOPULATION, // cell dies of over crowding
            RESURRECTION; // cell lives on / is resurrected
};

// Data structure for storing directional values. Used by rules to determine neighbouring cells.
struct Directions {
    int HORIZONTAL, VERTICAL;
};

// All directions; N, E, S, W, NE, SE, SW, NW
const vector<Directions> ALL_DIRECTIONS{ { 0,-1 },{ 1,0 },{ 0,1 },{ -1,0 },{ 1,-1 },{ 1,1 },{ -1,1 },{ -1,-1 } };

// Cardinal directions; N, E, S, W
const vector<Directions> CARDINAL{ { 0,-1 },{ 1,0 },{ 0,1 },{ -1,0 } };

// Diagonal directions; NE, SE, SW, NW
const vector<Directions> DIAGONAL{ { 1,-1 },{ 1,1 },{ -1,1 },{ -1,-1 } };

/*
Abstract base class, upon which concrete rules will derive.

The derivations of RuleOfExistence is what determines the culture of Cell Population. Each rule implements
specific behaviours and so may execute some parts in different orders. In order to accommodate this
requirement RuleOfExistence will utilize a **Template Method** desing pattern, where all derived rules
implements their logic based on the virtual method executeRule().
*/
class RuleOfExistence {
protected:
    string ruleName;

    // Reference to the population of cells
    map<Point, Cell>& cells;

    // Amounts of alive neighbouring cells, with specified limits
    const PopulationLimits POPULATION_LIMITS;

    // The directions, by which neighbouring cells are identified
    const vector<Directions>& DIRECTIONS;

    int countAliveNeighbours(Point currentPoint);
    ACTION getAction(int aliveNeighbours, bool isAlive);

public:
    RuleOfExistence(PopulationLimits limits, map<Point, Cell>& cells, const vector<Directions>& DIRECTIONS, string ruleName)
            : POPULATION_LIMITS(limits), cells(cells), DIRECTIONS(DIRECTIONS), ruleName(std::move(ruleName)) {}
    virtual ~RuleOfExistence() = default;

    // Execute rule, in order specific to the concrete rule, by utilizing template method DP
    virtual void executeRule() = 0;

    string getRuleName() { return ruleName; }

    /**
     * @test This should return the correct amount of neighbours who are alive
     * @param - The point we are checking
     * @return - Amount of neighbours alive
     */
    int testCountAliveNeighbours(Point currentPoint) {
        return countAliveNeighbours(currentPoint);
    }

    /**
     * @test This should return the correct amount of limits
     * @return A Poulation limits struct with the 3 different numbers
     */
    PopulationLimits testGetPopulationLimits() {
        return POPULATION_LIMITS;
    }

    /**
     * @test Should return correct Directions
     * @return Both types of directions, horizontal and vertical
     */
    vector<Directions> testGetDirections() {
        return DIRECTIONS;
    }

    /**
     * @test Should return the correct action to be made
     * @param aliveNeighbours - How many cells are alive the cell
     * @param isAlive - Is the cell alive
     * @return the action to be made for the cell
     */
    ACTION testGetAction(int aliveNeighbours, bool isAlive) {
        return getAction(aliveNeighbours, isAlive);
    }
};

#endif