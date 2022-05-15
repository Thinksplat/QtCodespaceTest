#ifndef D6DA9F24_4223_434B_B226_4993E43B7728
#define D6DA9F24_4223_434B_B226_4993E43B7728

#include <QWidget>

class QPushButton;
class QTextBrowser;

// This is the declaration of our MainWidget class
// The definition/implementation is in mainwidget.cpp
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0); //Constructor

    Q_SLOT void buttonClicked();

private:
  int clickcount = 0;
   QPushButton* button_;
   QTextBrowser* textBrowser_;
};

#endif /* D6DA9F24_4223_434B_B226_4993E43B7728 */
