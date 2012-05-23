/*
 * stackedwidget.h
 *
 *  Created on: May 15, 2012
 *      Author: tom
 */

#ifndef STACKEDWIDGET_H_
#define STACKEDWIDGET_H_

#include <Wt/WStackedWidget>
#include "generalwidget.cpp"

namespace TurnLeft{
namespace TwoHearts{

class StackedWidget : public Wt::WStackedWidget
{
public:
    StackedWidget (GeneralWidget* parent);
};

}
}


#endif /* STACKEDWIDGET_H_ */
