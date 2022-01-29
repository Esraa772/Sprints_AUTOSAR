/**
 *
 * \file SWC_HeightMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_HeightMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 1/29/2022 03:37 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_HeightMotor.h"


/**
 *
 * Runnable RE_HeightMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppHeightMotor_Opr_Move
 *
 */

void RE_HeightMotor_Move (Impl_StepMotorStepType Arg_Step)
{
	Std_ReturnType status;

	/* Server Call Points */
	
    if (Arg_Step == MOTOR_STEP_PLUS)
    {
        status = Rte_Call_rpIOSetHeight_Opr_IOSetForward();
    }
    
    else if (Arg_Step == MOTOR_STEP_MINUS)
    {
        status = Rte_Call_rpIOSetHeight_Opr_IOSetReverse();
    }
}

