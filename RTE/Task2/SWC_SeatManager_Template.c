/**
 *
 * \file SWC_SeatManager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SeatManager
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 1/28/2022 07:55 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_SeatManager.h"


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

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_DE_HeightBtnState(&DE_HeightBtnState);
	if(DE_HeightBtnState == MULTI_STATE_BTN_MINUS)
    {
        Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS);
    }
    
    else if (DE_HeightBtnState == MULTI_STATE_BTN_PLUS)
    {
        Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);
    }
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

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_DE_InclineBtnState(&DE_InclineBtnState);
	if(DE_InclineBtnState == MULTI_STATE_BTN_MINUS)
    {
        Rte_Call_rpInclineMotor_Move(MOTOR_STEP_MINUS);
    }
    
    else if (DE_InclineBtnState == MULTI_STATE_BTN_PLUS)
    {
        Rte_Call_rpInclineMotor_Move(MOTOR_STEP_PLUS);
    }
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

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_DE_SlideBtnState(&DE_SlideBtnState);
	if(DE_SlideBtnState == MULTI_STATE_BTN_MINUS)
    {
        Rte_Call_rpSlideMotor_Move(MOTOR_STEP_MINUS);
    }
    
    else if (DE_SlideBtnState == MULTI_STATE_BTN_PLUS)
    {
        Rte_Call_rpSlideMotor_Move(MOTOR_STEP_PLUS);
    }
}

