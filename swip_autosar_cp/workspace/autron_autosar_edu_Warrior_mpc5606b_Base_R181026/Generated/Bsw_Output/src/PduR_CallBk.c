/*******************************************************************************
**  FILE-NAME: PduR_CallBk.c                                                  **
**                                                                            **
**  MODULE-NAME: AUTOSAR Pdu Router Module                                    **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 2.2.2                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/

/*
 * INPUT FILE(s):    Configuration\ECU\Ecud_Dcm.arxml
 *                Configuration\ECU\Ecud_CanTp.arxml
 *                Configuration\ECU\Ecud_Com.arxml
 *                Configuration\ECU\Ecud_CanIf.arxml
 *                Configuration\ECU\Ecud_EcuC.arxml
 *                Configuration\ECU\Ecud_PduR.arxml
 * GENERATED ON:  This timestamp is removed.
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "PduR.h"
#include "PduR_PCTypes.h"
#include "PduR_TxUp.h"
#include "PduR_RxLo.h"
#include "PduR_TxLo.h"
#include "PduR_RxTp.h"
#include "PduR_TxTp.h"
#include "PduR_Incl.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define PDUR_CALLBK_C_AR_RELEASE_MAJOR_VERSION             4
#define PDUR_CALLBK_C_AR_RELEASE_MINOR_VERSION             0
#define PDUR_CALLBK_C_AR_RELEASE_REVISION_VERSION          3
#define PDUR_CALLBK_C_SW_MAJOR_VERSION                     2
#define PDUR_CALLBK_C_SW_MINOR_VERSION                     2
#define PDUR_CALLBK_C_SW_PATCH_VERSION                     0

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define PDUR_START_SEC_CODE
#include "MemMap.h"
/* Function Definition for PduR_CanTpCopyTxData() API */
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyTxData(PduIdType id,
P2CONST(PduInfoType, AUTOMATIC, PDUR_DATA) info,
P2VAR(RetryInfoType, AUTOMATIC, PDUR_DATA) retry,
P2VAR(PduLengthType, AUTOMATIC, PDUR_DATA) availableDataPtr)
{
BufReq_ReturnType LddReturnVal;
LddReturnVal = PduR_LoTpCopyTxData(id, (uint8)0x07, PDUR_CANTP, info, retry, availableDataPtr);
return LddReturnVal;
}
#define PDUR_STOP_SEC_CODE
#include "MemMap.h" 
#define PDUR_START_SEC_CODE
#include "MemMap.h"
/* Function Definition for PduR_CanTpTxConfirmation() API */
FUNC(void, PDUR_CODE) PduR_CanTpTxConfirmation(PduIdType TpTxPduId,
NotifResultType Result)
{
 PduR_LoTpTxConfirmation(TpTxPduId, (uint8)0x08, PDUR_CANTP, Result);
}
#define PDUR_STOP_SEC_CODE
#include "MemMap.h" 
#define PDUR_START_SEC_CODE
#include "MemMap.h"
/* Function Definition for PduR_CanTpCopyRxData() API */
FUNC(BufReq_ReturnType, PDUR_CODE) 
PduR_CanTpCopyRxData(PduIdType TpRxPduId, 
P2CONST(PduInfoType, AUTOMATIC, PDUR_DATA) info, 
P2VAR(PduLengthType, AUTOMATIC, PDUR_DATA) bufferSizePtr)
{
BufReq_ReturnType LddReturnVal;
LddReturnVal = PduR_LoTpCopyRxData(TpRxPduId, (uint8)0x04, PDUR_CANTP, info, bufferSizePtr);
return LddReturnVal;
}
#define PDUR_STOP_SEC_CODE
#include "MemMap.h" 
#define PDUR_START_SEC_CODE
#include "MemMap.h"
/* Function Definition for PduR_CanTpRxIndication() API */
FUNC(void, PDUR_CODE) PduR_CanTpRxIndication(PduIdType TpRxPduId,
NotifResultType Result)
{
PduR_LoTpRxIndication(TpRxPduId,  (uint8)0x05, PDUR_CANTP, Result);
}
#define PDUR_STOP_SEC_CODE
#include "MemMap.h" 
#define PDUR_START_SEC_CODE
#include "MemMap.h"
/* Function Definition for PduR_CanTpStartOfReception() API */
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpStartOfReception
(PduIdType id, PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, PDUR_DATA)bufferSizePtr)
{
BufReq_ReturnType LddReturnVal;
LddReturnVal = PduR_LoTpStartOfReception(id, (uint8)0x06, PDUR_CANTP, TpSduLength, bufferSizePtr);
return LddReturnVal;
}
#define PDUR_STOP_SEC_CODE
#include "MemMap.h" 
#define PDUR_START_SEC_CODE
#include "MemMap.h"
/* Function Definition for PduR_CanIfRxIndication() API */
FUNC(void, PDUR_CODE) PduR_CanIfRxIndication(PduIdType IfRxPduId,
P2CONST(PduInfoType, AUTOMATIC, PDUR_DATA) PduInfoPtr)
{
PduR_LoRxIndication(IfRxPduId, (uint8)0x01, PDUR_CANIF, PduInfoPtr);
}
#define PDUR_STOP_SEC_CODE
#include "MemMap.h" 
#define PDUR_START_SEC_CODE
#include "MemMap.h"
/* Function Definition for PduR_CanIfTxConfirmation() API */
FUNC(void, PDUR_CODE) PduR_CanIfTxConfirmation(PduIdType IfTxPduId)
{
PduR_LoTxConfirmation(IfTxPduId, (uint8)0x02, PDUR_CANIF);
}
#define PDUR_STOP_SEC_CODE
#include "MemMap.h" 
#define PDUR_START_SEC_CODE
#include "MemMap.h"
/* Function Definition for PduR_ComTransmit() API */
FUNC(Std_ReturnType, PDUR_CODE) PduR_ComTransmit(PduIdType TxPduId,
P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr)
{
Std_ReturnType LddReturnVal;
LddReturnVal = PduR_UpTransmit(TxPduId, (uint8)0x89, PDUR_COM, PduInfoPtr);
return LddReturnVal;
}
#define PDUR_STOP_SEC_CODE
#include "MemMap.h" 
#define PDUR_START_SEC_CODE
#include "MemMap.h"
/* Function Definition for PduR_DcmTransmit() API */
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmTransmit(PduIdType TxPduId,
P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr)
{
Std_ReturnType LddReturnVal;
LddReturnVal = PduR_UpTransmit(TxPduId, (uint8)0x99, PDUR_DCM, PduInfoPtr);
return LddReturnVal;
}
#define PDUR_STOP_SEC_CODE
#include "MemMap.h" 
#define PDUR_START_SEC_CODE
#include "MemMap.h"
/* Function Definition for PduR_DcmCancelReceive() API */
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmCancelReceive(PduIdType id)
{
Std_ReturnType LddReturnVal;
LddReturnVal = PduR_CancelReceive(id, (uint8)0x9C);
return LddReturnVal;
} 
#define PDUR_STOP_SEC_CODE
#include "MemMap.h" 
#define PDUR_START_SEC_CODE
#include "MemMap.h"
/* Function Definition for PduR_DcmCancelTransmit() API */
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmCancelTransmit(PduIdType id)
{
Std_ReturnType LddReturnVal;
LddReturnVal = PduR_UpCancelTransmit(id, (uint8)0x9A, PDUR_DCM);
return LddReturnVal;
}
#define PDUR_STOP_SEC_CODE
#include "MemMap.h" 


/*******************************************************************************
**                      ZERO COST OPERATION                                   **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

