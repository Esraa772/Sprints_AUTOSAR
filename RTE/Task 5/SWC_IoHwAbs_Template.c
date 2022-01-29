/**
 *
 * \file SWC_IoHwAbs_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_IoHwAbs
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 1/29/2022 05:58 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_IoHwAbs.h"


/**
 *
 * Runnable RE_IoHwAbs_EcuGet_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetHeight_Opr_IOGet
 *
 */

void RE_IoHwAbs_EcuGet_Height (Impl_IOPositionSensorReadingType* Arg_Position)
{
	Std_ReturnType status;
    if(status == E_OK)
    {
        Arg_Position = (IoPositionSensorReadingTypes) IoHwAbs_PositionSensorReadings[0];
    }
}


/**
 *
 * Runnable RE_IoHwAbs_EcuGet_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetIncline_Opr_IOGet
 *
 */

void RE_IoHwAbs_EcuGet_Incline (Impl_IOPositionSensorReadingType* Arg_Position)
{
	Std_ReturnType status;
    if(status == E_OK)
    {
        Arg_Position = (IoPositionSensorReadingTypes) IoHwAbs_PositionSensorReadings[0];
    }
}


/**
 *
 * Runnable RE_IoHwAbs_EcuGet_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetSlide_Opr_IOGet
 *
 */

void RE_IoHwAbs_EcuGet_Slide (Impl_IOPositionSensorReadingType* Arg_Position)
{
	Std_ReturnType status;
    if(status == E_OK)
    {
        Arg_Position = (IoPositionSensorReadingTypes) IoHwAbs_PositionSensorReadings[0];
    }
}


/**
 *
 * Runnable RE_IoHwAbs_EcuGet_Weight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetWeight_Opr_IOGet
 *
 */

void RE_IoHwAbs_EcuGet_Weight (Impl_IOWeightSensorReadingType* Arg_Weight)
{
	Std_ReturnType status;
    if(status == E_OK)
    {
        Arg_Weight = (IoWeightSensorReadingTypes) SpiData;
    }
}


/**
 *
 * Runnable RE_IoHwAbs_EcuSetForward_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_Opr_IOSetForward
 *
 */

void RE_IoHwAbs_EcuSetForward_Height (void)
{
	Std_ReturnType status;
    Dio_WriteChennel(DioConfg_DioChannel_SlideMotorCh, STD_HIGH);

}


/**
 *
 * Runnable RE_IoHwAbs_EcuSetForward_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetIncline_Opr_IOSetForward
 *
 */

void RE_IoHwAbs_EcuSetForward_Incline (void)
{
	Std_ReturnType status;
    Dio_WriteChennel(DioConfg_DioChannel_HeightMotorCh, STD_HIGH);
}


/**
 *
 * Runnable RE_IoHwAbs_EcuSetForward_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetSlide_Opr_IOSetForward
 *
 */

void RE_IoHwAbs_EcuSetForward_Slide (void)
{
	Std_ReturnType status;
    Dio_WriteChennel(DioConfg_DioChannel_InclineMotorCh, STD_HIGH);

}


/**
 *
 * Runnable RE_IoHwAbs_EcuSetReverse_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_Opr_IOSetReverse
 *
 */

void RE_IoHwAbs_EcuSetReverse_Height (void)
{
	Std_ReturnType status;
    Dio_WriteChennel(DioConfg_DioChannel_HeightMotorCh, STD_LOW);

}


/**
 *
 * Runnable RE_IoHwAbs_EcuSetReverse_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetIncline_Opr_IOSetReverse
 *
 */

void RE_IoHwAbs_EcuSetReverse_Incline (void)
{
	Std_ReturnType status;
    Dio_WriteChennel(DioConfg_DioChannel_InclineMotorCh, STD_LOW);

}


/**
 *
 * Runnable RE_IoHwAbs_EcuSetReverse_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetSlide_Opr_IOSetReverse
 *
 */

void RE_IoHwAbs_EcuSetReverse_Slide (void)
{
	Std_ReturnType status;
    Dio_WriteChennel(DioConfg_DioChannel_SlideMotorCh, STD_LOW);

}

