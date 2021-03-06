#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <map>

#include <QOpenGLWidget>
#include <QKeyEvent>

#include "command.h"


class InputHandler
{
public:
    InputHandler();
    ~InputHandler();
    void bind(int key, Command *command);

    void update();

    void keyPressEvent(int key);
    void keyReleaseEvent(int key);

    void mousePressEvent(int button);
    void mouseReleaseEvent(int button);

private:
    /*key , action*/
    std::map<int,Command*> commands;
};

#endif // INPUTHANDLER_H
