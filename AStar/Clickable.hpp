//
//  Clickable.hpp
//  AStar
//
//  Created by Sam Clark on 4/29/17.
//
//

#ifndef Clickable_hpp
#define Clickable_hpp

class BaseWindow;

class Clickable {
public:
    Clickable(BaseWindow* window);
    ~Clickable();
    
    bool isInBounds(int x, int y);
    
    virtual int getX1() = 0;
    virtual int getY1() = 0;
    virtual int getX2() = 0;
    virtual int getY2() = 0;
    
    virtual void pressEvent();
    virtual void releaseEvent();
    
    virtual void hoverEvent();
    virtual void unhoverEvent();
    
private:
    BaseWindow* window;
};

#endif /* Clickable_hpp */
