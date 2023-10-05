/*******************************************************************************
**  FILE-NAME: PduR_CanTp.h                                                     **
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

#ifndef PDUR_CANTP_H
#define PDUR_CANTP_H


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "PduR.h"
#include "PduR_RxTp.h"
#include "PduR_TxTp.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/


/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define PDUR_START_SEC_CODE
#include "MemMap.h"

/* Extern Declaration for PduR_CanTpTxConfirmation() API */
extern FUNC(void, PDUR_CODE) PduR_CanTpTxConfirmation(PduIdType TpTxPduId,
NotifResultType Result);

/* Extern Declaration for PduR_CanTpCopyRxData() API */
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyRxData(
PduIdType TpRxPduId, 
P2CONST(PduInfoType, AUTOMATIC, PDUR_DATA) info, 
P2VAR(PduLengthType, AUTOMATIC, PDUR_DATA) bufferSizePtr);

/* Extern Declaration for PduR_CanTpStartOfReception() API */
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpStartOfReception
(PduIdType id, PduLengthType TpSduLength, 
P2VAR(PduLengthType, AUTOMATIC, PDUR_DATA) bufferSizePtr);

/* Extern Declaration for PduR_CanTpRxIndication() API */
extern FUNC(void, PDUR_CODE) PduR_CanTpRxIndication(PduIdType TpRxPduId,
NotifResultType Result);

/* Extern Declaration for PduR_CanTpCopyTxData() API */
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyTxData(PduIdType id,
P2CONST(PduInfoType, AUTOMATIC, PDUR_DATA) info,
P2VAR(RetryInfoType, AUTOMATIC, PDUR_DATA) retry,
P2VAR(PduLengthType, AUTOMATIC, PDUR_DATA) availableDataPtr);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* PDUR_CANTP_H*/


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

