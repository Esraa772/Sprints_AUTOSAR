/**
 *
 * \file SWC_SlideMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SlideMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 1/28/2022 10:32 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_SlideMotor.h"


/**
 *
 * Runnable RE_SlideMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideMotor_Opr_Move
 *
 */

void RE_SlideMotor_Move (Impl_StepMotorStepType Arg_Step)
{
	Std_ReturnType status;
    if(Arg_Step == MOTOR_STEP_PLUS)
    {
        Dio_WriteChannel();
    }
    
    else if (Arg_Step == MOTOR_STEP_MINUS)
    {
        Dio_WriteChannel();
    }
}

