//
//  BaseWindow.hpp
//  AStar
//
//  Created by Sam Clark on 4/29/17.
//
//

#ifndef BaseWindow_hpp
#define BaseWindow_hpp

#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <iostream>
#include <Clickable.hpp>
#include <Timer.hpp>

using namespace sf;
using namespace std;

class BaseWindow {
public:
    BaseWindow(int x, int y, string title, bool isResizable=true);
    virtual ~BaseWindow();
    
    void launch();
    
    void addClickable(Clickable* clickable);
    void removeClickable(Clickable* clickable);
    void draw(Text);
    void addDrawable(Drawable* drawable);
    void removeDrawable(Drawable* drawable);
    
    void addTimer(Timer*);
    
    RenderWindow* renderWindow;
    
    Font font;
    
protected:
    vector<Clickable*> clickables;
    vector<sf::Drawable*> drawables;
    vector<Timer*> timers;
    
    RectangleShape* background;
    
    Clickable* lastClicked;
    Clickable* lastHovered;
    
    virtual void resizeEvent(Event event);
    virtual void closeEvent(Event even);
};

#endif /* BaseWindow_hpp */
