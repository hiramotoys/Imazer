#ifndef ClassSelectorBox_H
#define ClassSelectorBox_H

#include <QGroupBox>
#include <QRect>
#include <QString>
#include <QWidget>
#include <QRadioButton>
#include <QHBoxLayout>
#include "NaoWorldObjectID.h"

class ClassSelectorBox : public QGroupBox{
    Q_OBJECT
 private:
    int selectedObjID;
    QRadioButton *lines;
    QRadioButton *green;
    QRadioButton *ball;
    QRadioButton *goalYellow;
    QRadioButton *goalBlue;
    QHBoxLayout *layout;
 public:
    ClassSelectorBox(const QRect &rect, const QString &title, QWidget *iParent=0);
    ~ClassSelectorBox();
    int getSelectedObjectID();
 protected slots:
    void changeSelectedObjectIDToLines();
    void changeSelectedObjectIDToGreen();
    void changeSelectedObjectIDToBall();
    void changeSelectedObjectIDToGoalYellow();
    void changeSelectedObjectIDToGoalBlue();
};

#endif // ClassSelectorBox
