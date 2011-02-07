#ifndef MotionControlerBox_H
#define MotionControlerBox_H
#include <string>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <alproxies/almotionproxy.h>

class MotionControlerBox : public QGroupBox{
    Q_OBJECT
 private:
    AL::ALPtr<AL::ALMotionProxy> motionProxy;
    QVBoxLayout *layout;
    QLabel *stiffnessLabel;
    QCheckBox *headStiffnessCheckBox;
    QCheckBox *allStiffnessCheckBox;
 public:
    MotionControlerBox(QRect &rect, const QString &title, QWidget *iParent=0);
    ~MotionControlerBox();
    void connectToNao(std::string IP, int PORT);
 private:
    void initWidget();
    void registerMotionClient(std::string IP, int PORT);
    void unregisterMotionClient();

 protected:
    void changeHeadStiffnessStatus(bool ischecked);
    void changeAllStiffnessStatus(bool ischecked);
};
#endif // MotionControlerBox
