#include <QtWidgets>
#include <iostream>
#include "mainwidget.h"

// Constructor for main widget
MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    button_ = new QPushButton(tr("Push Me!"));
    textBrowser_ = new QTextBrowser();

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(button_, 0, 0);
    mainLayout->addWidget(textBrowser_, 1, 0);

    // connect to button the buttonClicked slot
    connect(button_, SIGNAL(clicked()), this, SLOT(buttonClicked()));

    setLayout(mainLayout);
    setWindowTitle(tr("Connecting buttons to processes.."));
}

void MainWidget::buttonClicked()
{
    if (clickcount == 0)
    {
        textBrowser_->clear();
    }
    ++clickcount;
    if (clickcount == 10)
    {
        textBrowser_->append(tr("You pushed the button 10 times!"));
        clickcount = 0;
    }
    else
    {
        textBrowser_->append(QString("Button clicked! %1").arg(clickcount));
    }
}
