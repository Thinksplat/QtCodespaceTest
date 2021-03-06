#ifndef C4E80EE4_6D62_499D_B727_EF75372AE46A
#define C4E80EE4_6D62_499D_B727_EF75372AE46A

#include "IClickMsg.h"
#include <sstream>

class ClickBusiness : public IClickMsg
{
public:
    ClickBusiness(unsigned int resetcount, const std::string &angrymessage="Please Stop!") : resetcount(resetcount), angrymessage(angrymessage)
    {
    }

    void Click()
    {
        if (clickcount == 0)
        {
            // Clear out the message (for overflow reset)
            ss.str("");
            ss.clear();
        }

        ++clickcount;

        if (clickcount == resetcount)
        {
            ss << "BUSINESS: " << angrymessage << " You pushed the button " << resetcount << " times!" << std::endl;
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
    unsigned int clickcount = 0;
    unsigned int resetcount = 10;
    std::string angrymessage;
    std::stringstream ss;
};

#endif /* C4E80EE4_6D62_499D_B727_EF75372AE46A */
