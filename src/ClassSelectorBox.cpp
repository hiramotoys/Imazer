#include "ClassSelectorBox.h"
#include <iostream>

ClassSelectorBox::ClassSelectorBox(const QRect &rect, const QString &title, QWidget *iParent) : QGroupBox(title, iParent){
    selectedObjID = -1;
    setGeometry(rect);
    layout = new QHBoxLayout();
    lines = new QRadioButton("Lines");
    connect(lines, SIGNAL(clicked()), this, SLOT(changeSelectedObjectIDToLines()));
    layout->addWidget(lines);
    green = new QRadioButton("Green");
    connect(green, SIGNAL(clicked()), this, SLOT(changeSelectedObjectIDToGreen()));
    layout->addWidget(green);
    ball = new QRadioButton("Ball");
    connect(ball, SIGNAL(clicked()), this, SLOT(changeSelectedObjectIDToBall()));
    layout->addWidget(ball);
    goalYellow = new QRadioButton("GoalY");
    connect(goalYellow, SIGNAL(clicked()), this, SLOT(changeSelectedObjectIDToGoalYellow()));
    layout->addWidget(goalYellow);
    goalBlue = new QRadioButton("GoalB");
    connect(goalBlue, SIGNAL(clicked()), this, SLOT(changeSelectedObjectIDToGoalBlue()));
    layout->addWidget(goalBlue);
    setLayout(layout);
}

ClassSelectorBox::~ClassSelectorBox(){
}

int ClassSelectorBox::getSelectedObjectID(){
    return selectedObjID;
}

void ClassSelectorBox::changeSelectedObjectIDToLines(){
    selectedObjID = NaoWorldObjectID::LINES;
    std::cout << "lines " << selectedObjID << std::endl;
}

void ClassSelectorBox::changeSelectedObjectIDToGreen(){
    selectedObjID = NaoWorldObjectID::GREEN;
    std::cout << "green " << selectedObjID << std::endl;
}

void ClassSelectorBox::changeSelectedObjectIDToBall(){
    selectedObjID = NaoWorldObjectID::BALL;
    std::cout << "balls " << selectedObjID << std::endl;
}

void ClassSelectorBox::changeSelectedObjectIDToGoalYellow(){
    selectedObjID = NaoWorldObjectID::GOAL_YELLOW;
    std::cout << "goaly " << selectedObjID << std::endl;
}

void ClassSelectorBox::changeSelectedObjectIDToGoalBlue(){
    selectedObjID = NaoWorldObjectID::GOAL_BLUE;
    std::cout << "goalb " << selectedObjID << std::endl;
}
