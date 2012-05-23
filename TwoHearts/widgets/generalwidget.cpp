/*
 * generalwidget.cpp
 *
 *  Created on: May 15, 2012
 *      Author: tom
 */

#include "generalwidget.h"

namespace TurnLeft{
namespace TwoHearts{

GeneralWidget::GeneralWidget(std::string _indexTitle, Wt::WContainerWidget* parent=0)
:   Wt::WContainerWidget(parent)
{
    indexTitle = _indexTitle;
}

std::string
GeneralWidget::getName()
{
    return indexTitle;
}

}
}
