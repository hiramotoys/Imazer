#include "ClassSelectorBox.h"

ClassSelectorBox::ClassSelectorBox(const QRect &rect, const QString &title, QWidget *iParent) : QGroupBox(title, iParent){
    selectedObjID = -1;
    setGeometry(rect);
    layout = QHBoxLayout();
    lines = new QRadioButton("Lines", layout);
    connect(lines, SIGNAL(clicked()), this, SLOT(changeSelectedObjectIDToLines()));
    green = new QRadioButton("Green", layout);
    connect(green, SIGNAL(clicked()), this, SLOT(changeSelectedObjectIDToLines()));
    ball = new QRadioButton("Ball", layout);
    connect(ball, SIGNAL(clicked()), this, SLOT(changeSelectedObjectIDToLines()));
    goalYellow = new QRadioButton("Goal Yellow", layout);
    connect(goalYellow, SIGNAL(clicked()), this, SLOT(changeSelectedObjectIDToLines()));
    goalBlue = new QRadioButton("Goal Blue", layout);
    connect(goalBlue, SIGNAL(clicked()), this, SLOT(changeSelectedObjectIDToLines()));
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
