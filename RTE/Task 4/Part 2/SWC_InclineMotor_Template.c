/**
 *
 * \file SWC_InclineMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_InclineMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 1/29/2022 03:37 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_InclineMotor.h"


/**
 *
 * Runnable RE_InclineMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppInclineMotor_Opr_Move
 *
 */

void RE_InclineMotor_Move (Impl_StepMotorStepType Arg_Step)
{
	Std_ReturnType status;

	/* Server Call Points */
    if (Arg_Step == MOTOR_STEP_PLUS)
	{
        status = Rte_Call_rpIOSetIncline_Opr_IOSetForward();
    }
    
	else if (Arg_Step == MOTOR_STEP_MINUS)
    {
        status = Rte_Call_rpIOSetIncline_Opr_IOSetReverse();
    }
	
}

