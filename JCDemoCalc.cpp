#include "JCDemoCalc.h"

#include <Windows.h>
#include <QDebug>
#include <QWindow>
#include <QMainWindow>

#pragma comment(lib, "user32.lib")

JCDemoCalc::JCDemoCalc(QWidget *parent) : QWidget(parent)
{
    QString program = "E:/calc.exe"; // OK
    QStringList arguments = QStringList();
    QString className = QStringLiteral("SciCalc");
    QString windowName = QStringLiteral("计算器");

    // process
    process = new QProcess;
    process->start(program, arguments);

    qDebug() << process->state() <<"before";
    process->waitForStarted(3000);
    qDebug() << process->state() <<"after";

    Sleep(500);

    // child
    uint32_t timeout = 1000;
    HWND childWin;
    do {
        // childWin = FindWindow(reinterpret_cast<LPCTSTR>(NULL), reinterpret_cast<LPCTSTR>(windowName.utf16())); // OK: NULL
        childWin = FindWindow(reinterpret_cast<LPCTSTR>(className.utf16()), reinterpret_cast<LPCTSTR>(windowName.utf16())); // OK: QStringLiteral(className, windowName)
        qDebug() << "childWin" << childWin << timeout;
        Sleep(10);
        timeout--;
    } while ((childWin == nullptr) && (timeout > 0));

    childWindow = QWindow::fromWinId(reinterpret_cast<WId>(childWin));
    childWindow->create();
    childWindow->setVisible(true);
    // childWindow->show();
    childWindow->requestActivate();
    qDebug() << "childWindow" << childWindow;

    childWidget = QWidget::createWindowContainer(childWindow, this);
    // childWidget->show();
    qDebug() << "childWidget" << childWidget;

    // gridLayout
    gridLayout = new QGridLayout;
    gridLayout->setSpacing(5);
    gridLayout->setContentsMargins(0, 0, 0, 0); //left top right bottom
    gridLayout->addWidget(childWidget, 0, 0);
    gridLayout->setRowStretch(0, 1);
    gridLayout->setColumnStretch(0, 1);

    this->setLayout(gridLayout);
}

JCDemoCalc::~JCDemoCalc()
{
    process->close();
}
