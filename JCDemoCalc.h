#ifndef JCDEMOCALC_H
#define JCDEMOCALC_H

#include <QWidget>
#include <QLayout>
#include <QProcess>

class JCDemoCalc : public QWidget
{
    Q_OBJECT

public:
    explicit JCDemoCalc(QWidget *parent = nullptr);
    ~JCDemoCalc();

private:
    QGridLayout *gridLayout;
    QProcess *process;
    QWindow *childWindow;
    QWidget *childWidget;

};

#endif // JCDEMOCALC_H
