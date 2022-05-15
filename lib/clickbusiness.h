#ifndef C4E80EE4_6D62_499D_B727_EF75372AE46A
#define C4E80EE4_6D62_499D_B727_EF75372AE46A

#include "IClickMsg.h"
#include <sstream>

class ClickBusiness : public IClickMsg
{
public:
    ClickBusiness(int resetcount) : resetcount(resetcount)
    {
    }

    void Click()
    {
        if (clickcount == 0)
        {
            ss.str("");
            ss.clear();
        }
        ++clickcount;

        if (clickcount == resetcount)
        {
            ss << "BUSINESS: You pushed the button " << resetcount << " times!" << std::endl;
            clickcount = 0;
        }
        else
        {
            ss << "BUSINESS: Button clicked! " << clickcount << std::endl;
        }
    }
    std::string Str()
    {
        return ss.str();
    }

private:
    int clickcount = 0;
    int resetcount = 10;
    std::stringstream ss;
};

#endif /* C4E80EE4_6D62_499D_B727_EF75372AE46A */
