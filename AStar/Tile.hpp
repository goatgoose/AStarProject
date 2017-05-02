//
//  Tile.hpp
//  AStar
//
//  Created by Sam Clark on 4/29/17.
//
//

#ifndef Tile_hpp
#define Tile_hpp

#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

class AStarWindow;

using namespace std;
using namespace sf;

class Tile {
public:
    Tile(int x, int y, AStarWindow* window);
    
    void update();
    
    void setObsticle();
    void unsetObsticle();
    void setStart();
    void setFinish();
    
    bool isObsticle();
    
    Tile* getRelativeTile(int relativeX, int relativeY);
    vector<Tile*> getNeighbors();
    
    int getX();
    int getY();
    
    friend ostream& operator<<(ostream& os, const Tile& tile);
private:
    int x;
    int y;
    AStarWindow* window;
    
    RectangleShape* background;
    bool obsticle;
};

#endif /* Tile_hpp */
