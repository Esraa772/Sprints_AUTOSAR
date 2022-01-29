/**
 *
 * \file SWC_SlideSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SlideSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 1/29/2022 03:37 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_SlideSensor.h"


/**
 *
 * Runnable RE_SlideSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideSensor_Opr_GetPosition
 *
 */

void RE_SlideSensor_GetPosition (Impl_SensorPositionType* Arg_Position)
{
	Std_ReturnType status;
	Impl_IOPositionSensorReadingType Arg_Position;

	/* Server Call Points */
	status = Rte_Call_rpIOGetSlide_Opr_IOGet(&Arg_Position);
	
    if(Arg_Position == 0)
    {
        Arg_Position = SENSOR_POSITION_STEP_0;
    }
    else if(Arg_Position > 0 && Arg_Position < 64)
    {
        Arg_Position = SENSOR_POSITION_STEP_1;
    }
    else if(Arg_Position > 64 && Arg_Position < 192)
    {
        Arg_Position = SENSOR_POSITION_STEP_2;
    }
    else 
    {
        Arg_Position = SENSOR_POSITION_STEP_3;
    }
}

