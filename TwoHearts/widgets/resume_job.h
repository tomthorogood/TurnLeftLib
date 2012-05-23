/*
 * resume_job.h
 *
 *  Created on: May 15, 2012
 *      Author: tom
 */

#ifndef COM_TOMTHOROGOOD_RESUME_JOB_H_
#define COM_TOMTHOROGOOD_RESUME_JOB_H_

#include <TurnLeftLib/TwoHearts/Widgets>
#include <Wt/WAnchor>

namespace com{
namespace tomthorogood{
class ResumeJob : public TurnLeft::TwoHearts::GeneralWidget
{
private:
    Wt::WAnchor *company;
    Wt::WText *dateFrom;
    Wt::WText *dateTo;
    Wt::WText *description;
    Wt::WText *position
};
}}
#endif /* COM_TOMTHOROGOOD_RESUME_JOB_H_ */
