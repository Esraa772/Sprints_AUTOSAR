/**
 *
 * \file SWC_HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 1/29/2022 05:59 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_HMI.h"


/**
 *
 * Runnable RE_HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_RE_HMI_MainFunction_100ms
 *
 */

void RE_HMI_MainFunction (void)
{
	Std_ReturnType status;
	Impl_MultiStateBtnType DE_HeightBtnState;
	Impl_MultiStateBtnType DE_InclineBtnState;
	Impl_MultiStateBtnType DE_SlideBtnState;
	uint8 DE_Height;
	uint8 DE_Incline;
	uint8 DE_Slide;

	/* Data Send Points */
	status = Rte_Write_ppSeatCtrlBtns_DE_HeightBtnState(DE_HeightBtnState);
	status = Rte_Write_ppSeatCtrlBtns_DE_InclineBtnState(DE_InclineBtnState);
	status = Rte_Write_ppSeatCtrlBtns_DE_SlideBtnState(DE_SlideBtnState);
	
	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlData_DE_Height(&DE_Height);
	status = Rte_Read_rpSeatCtrlData_DE_Incline(&DE_Incline);
	status = Rte_Read_rpSeatCtrlData_DE_Slide(&DE_Slide);
	
     
    if(DE_Height == 0 || DE_Height == TIME_OUT || DE_Height == NOT_UPDATED)
    {
        DE_HeightBtnState = MULTI_STATE_BTN_INIT;
    }
    
    else if(DE_Height == 1)
    {
        DE_HeightBtnState = MULTI_STATE_BTN_MINUS;
    }
    
    else if (DE_Height == 2)
    {
        DE_HeightBtnState = MULTI_STATE_BTN_PLUS;
    }
    
    if(DE_Incline == 0 || DE_Incline == TIME_OUT || DE_Incline == NOT_UPDATED)
    {
        DE_InclineBtnState = MULTI_STATE_BTN_INIT;
    }
    
    else if(DE_Incline == 1)
    {
        DE_InclineBtnState = MULTI_STATE_BTN_MINUS;
    }
    
    else if (DE_Incline == 2)
    {
        DE_InclineBtnState = MULTI_STATE_BTN_PLUS;
    }
    
    if(DE_Slide == 0 || DE_Slide == TIME_OUT || DE_Slide == NOT_UPDATED)
    {
        DE_SlideBtnState = MULTI_STATE_BTN_INIT;
    }
    
    else if(DE_Slide == 1)
    {
        DE_SlideBtnState = MULTI_STATE_BTN_MINUS;
    }
    
    else if (DE_Slide == 2)
    {
        DE_SlideBtnState = MULTI_STATE_BTN_PLUS;
    }
}


/**
 *
 * Runnable RE_HMI_SeatModeChanged
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatModeBtn_DE_SeatModeBtn
 *
 */

void RE_HMI_SeatModeChanged (void)
{
	Std_ReturnType status;
	Impl_SeatModeBtnType DE_SeatModeBtn;
	uint8 SeatCtrlMode = RTE_MODE_SeatCtrlMode_INIT;

	/* Data Receive Points */
	status = Rte_Read_rpSeatModeBtn_DE_SeatModeBtn(&DE_SeatModeBtn);
	
    if (DE_SeatModeBtn == SEAT_MODE_BTN_MANUAL)
    {
        SeatCtrlMode = RTE_MODE_SeatCtrlMode_MANUAL;
    }
    
    else if (DE_SeatModeBtn == SEAT_MODE_BTN_AUTO)
    {
        SeatCtrlMode = RTE_MODE_SeatCtrlMode_AUTO;
    }
    else
    {
        
    }
    
	/* Mode Switch Points */
	status = Rte_Switch_ppSeatCtrlMode_SeatCtrlMode(SeatCtrlMode);
	
}

