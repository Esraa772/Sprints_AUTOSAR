/**
 *
 * \file SWC_SeatManager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SeatManager
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 1/29/2022 02:20 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_SeatManager.h"

static Impl_boolean IsMotorAdjustNeeded (Impl_SensorPositionType Position,Impl_SensorWeightType Weight, Impl_StepMotorStepType Step)
{
    Impl_boolean AdjutMotor = FALSE;
    
    switch(Position)
    {
        Case SENSOR_POSITION_STEP_0 :
        if(Weight > 60)
        {
            Step = MOTOR_STEP_PLUS;
            AdjutMotor = TRUE;
        }
        break;
        Case SENSOR_POSITION_STEP_1 :
        if(Weight > 80)
        {
            Step = MOTOR_STEP_PLUS;
            AdjutMotor = TRUE;
        }
        else if(Weight <= 80 && Weight >= 60)
        {
            /*No need to move*/
        }
        else
        {
            Step = MOTOR_STEP_MINUS;
            AdjutMotor = TRUE;
        }
        break;
        Case SENSOR_POSITION_STEP_2 :
        if(Weight > 100)
        {
            Step = MOTOR_STEP_PLUS;
            AdjutMotor = TRUE;
        }
        else if(Weight <= 100 && Weight >= 80)
        {
            /*No need to move*/
        }
        else
        {
            Step = MOTOR_STEP_MINUS;
            AdjutMotor = TRUE;
        }
        break;
        Case SENSOR_POSITION_STEP_3 :
        if(Weight < 100)
        {
            Step = MOTOR_STEP_MINUS;
            AdjutMotor = TRUE;
        }
        break;
        default:
        break;
    }
    
    return AdjutMotor;
}

/**
 *
 * Runnable RE_SeatManager_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_RE_SeatManager_AutoHeight_200ms
 *
 */

void RE_SeatManager_AutoHeight (void)
{
	Std_ReturnType status;
	Impl_StepMotorStepType Arg_Step;
	Impl_SensorPositionType Arg_Position;
	Impl_SensorWeightType Arg_Weight;
    Impl_boolean AdjutMotor;
    
	/* Server Call Points */
	status = Rte_Call_rpHeightMotor_Opr_Move(Arg_Step);
	status = Rte_Call_rpHeightSensor_Opr_GetPosition(&Arg_Position);
	status = Rte_Call_rpWeightSensor_Opr_GetWeight(&Arg_Weight);
	
    AdjutMotor = IsMotorAdjustNeeded(Arg_Position,Arg_Weight,Arg_Step);
    
    if(AdjutMotor)
    {
        Rte_Call_rpHeightMotor_Opr_Move(Arg_Step);
    }
}


/**
 *
 * Runnable RE_SeatManager_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_RE_SeatManager_AutoIncline_200ms
 *
 */

void RE_SeatManager_AutoIncline (void)
{
	Std_ReturnType status;
	Impl_StepMotorStepType Arg_Step;
	Impl_SensorPositionType Arg_Position;
	Impl_SensorWeightType Arg_Weight;
    Impl_boolean AdjutMotor;

	/* Server Call Points */
	status = Rte_Call_rpInclineMotor_Opr_Move(Arg_Step);
	status = Rte_Call_rpInclineSensor_Opr_GetPosition(&Arg_Position);
	status = Rte_Call_rpWeightSensor_Opr_GetWeight(&Arg_Weight);
	
    AdjutMotor = IsMotorAdjustNeeded(Arg_Position,Arg_Weight,Arg_Step);
    if(AdjutMotor)
    {
        Rte_Call_rpInclineMotor_Opr_Move(Arg_Step);
    }
}


/**
 *
 * Runnable RE_SeatManager_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_RE_SeatManager_AutoSlide_200ms
 *
 */

void RE_SeatManager_AutoSlide (void)
{
	Std_ReturnType status;
	Impl_StepMotorStepType Arg_Step;
	Impl_SensorPositionType Arg_Position;
	Impl_SensorWeightType Arg_Weight;
    Impl_boolean AdjutMotor;

	/* Server Call Points */
	status = Rte_Call_rpSlideMotor_Opr_Move(Arg_Step);
	status = Rte_Call_rpSlideSensor_Opr_GetPosition(&Arg_Position);
	status = Rte_Call_rpWeightSensor_Opr_GetWeight(&Arg_Weight);
	
    AdjutMotor = IsMotorAdjustNeeded(Arg_Position,Arg_Weight,Arg_Step);

    if(AdjutMotor)
    {
        Rte_Call_rpSlideMotor_Opr_Move(Arg_Step);
    }
}


/**
 *
 * Runnable RE_SeatManager_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_DE_HeightBtnState
 *
 */

void RE_SeatManager_SetHeight (void)
{
	Std_ReturnType status;
	Impl_MultiStateBtnType DE_HeightBtnState;
	Impl_StepMotorStepType Arg_Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_DE_HeightBtnState(&DE_HeightBtnState);
	
     if(DE_HeightBtnState == MULTI_STATE_BTN_MINUS)
    {
        Arg_Step = MOTOR_STEP_MINUS;
    }
    
    else if (DE_HeightBtnState == MULTI_STATE_BTN_PLUS)
    {
        Arg_Step = MOTOR_STEP_PLUS;
    }
    
    
	/* Server Call Points */
	status = Rte_Call_rpHeightMotor_Opr_Move(Arg_Step);
	
}


/**
 *
 * Runnable RE_SeatManager_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_DE_InclineBtnState
 *
 */

void RE_SeatManager_SetIncline (void)
{
	Std_ReturnType status;
	Impl_MultiStateBtnType DE_InclineBtnState;
	Impl_StepMotorStepType Arg_Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_DE_InclineBtnState(&DE_InclineBtnState);
	
    if(DE_InclineBtnState == MULTI_STATE_BTN_MINUS)
    {
        Arg_Step = MOTOR_STEP_MINUS;
    }
    
    else if (DE_InclineBtnState == MULTI_STATE_BTN_PLUS)
    {
        Arg_Step = MOTOR_STEP_PLUS;
    }
	/* Server Call Points */
	status = Rte_Call_rpInclineMotor_Opr_Move(Arg_Step);
	
}


/**
 *
 * Runnable RE_SeatManager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_DE_SlideBtnState
 *
 */

void RE_SeatManager_SetSlide (void)
{
	Std_ReturnType status;
	Impl_MultiStateBtnType DE_SlideBtnState;
	Impl_StepMotorStepType Arg_Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_DE_SlideBtnState(&DE_SlideBtnState);
	
    if(DE_SlideBtnState == MULTI_STATE_BTN_MINUS)
    {
        Arg_Step = MOTOR_STEP_MINUS;
    }
    
    else if (DE_SlideBtnState == MULTI_STATE_BTN_PLUS)
    {
        Arg_Step = MOTOR_STEP_PLUS;
    }
    
	/* Server Call Points */
	status = Rte_Call_rpSlideMotor_Opr_Move(Arg_Step);
	
}

