/*
 * generalwidget.h
 *
 *  Created on: May 15, 2012
 *      Author: tom
 */

#ifndef TL_TWO_HEARTS_GENERALWIDGET_H_
#define TL_TWO_HEARTS_GENERALWIDGET_H_

#include <Wt/WContainerWidget>

namespace TurnLeft{
namespace TwoHearts{

class GeneralWidget : public Wt::WContainerWidget
{
private:
    std::string indexTitle;
public:
    GeneralWidget(std::string title, Wt::WContainerWidget*);
    std::string getName();
};

}
}

#endif /* TL_TWO_HEARTS_GENERALWIDGET_H_ */
