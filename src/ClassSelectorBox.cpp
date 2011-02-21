#include "ClassSelectorBox.h"

ClassSelectorBox::ClassSelectorBox(const QRect &rect, const QString &title, QWidget *iParent) : QGroupBox(title, iParent){
    selectedObjID = -1;
    setGeometry(rect);
    layout = new QHBoxLayout();
    lines = new QRadioButton("Lines");
    connect(lines, SIGNAL(clicked()), this, SLOT(changeSelectedObjectIDToLines()));
    layout->addWidget(lines);
    green = new QRadioButton("Green");
    connect(green, SIGNAL(clicked()), this, SLOT(changeSelectedObjectIDToLines()));
    layout->addWidget(green);
    ball = new QRadioButton("Ball");
    connect(ball, SIGNAL(clicked()), this, SLOT(changeSelectedObjectIDToLines()));
    layout->addWidget(ball);
    goalYellow = new QRadioButton("Goal Yellow");
    connect(goalYellow, SIGNAL(clicked()), this, SLOT(changeSelectedObjectIDToLines()));
    layout->addWidget(goalYellow);
    goalBlue = new QRadioButton("Goal Blue");
    connect(goalBlue, SIGNAL(clicked()), this, SLOT(changeSelectedObjectIDToLines()));
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
}

void ClassSelectorBox::changeSelectedObjectIDToGreen(){
    selectedObjID = NaoWorldObjectID::GREEN;
}

void ClassSelectorBox::changeSelectedObjectIDToBall(){
    selectedObjID = NaoWorldObjectID::BALL;
}

void ClassSelectorBox::changeSelectedObjectIDToGoalYellow(){
    selectedObjID = NaoWorldObjectID::GOAL_YELLOW;
}

void ClassSelectorBox::changeSelectedObjectIDToGoalBlue(){
    selectedObjID = NaoWorldObjectID::GOAL_BLUE;
}
