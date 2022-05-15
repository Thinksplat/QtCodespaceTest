#ifndef AEF10B4E_A66A_48B9_9A31_02D0FE125C56
#define AEF10B4E_A66A_48B9_9A31_02D0FE125C56

#include <QWidget>
#include "IClickMsg.h"

class QPushButton;
class QTextBrowser;

class BetterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BetterWidget(IClickMsg &clicker, QWidget *parent = 0); // Constructor

    Q_SLOT void buttonClicked();

private:
    IClickMsg &clicker;
    QTextBrowser *textBrowser_;
};
#endif /* AEF10B4E_A66A_48B9_9A31_02D0FE125C56 */
