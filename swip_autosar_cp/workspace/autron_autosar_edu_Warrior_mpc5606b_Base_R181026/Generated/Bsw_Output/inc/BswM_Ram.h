/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : BswM_Ram.h                                                    **
**                                                                            **
**  PRODUCT   : AUTOSAR BswM Module                                           **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 2.5.3                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/

/*
 * INPUT FILE:    Configuration\ECU\Ecud_Os.arxml
 *                Configuration\ECU\Ecud_Com.arxml
 *                Configuration\ECU\Ecud_EcuM.arxml
 *                Configuration\ECU\Ecud_BswM.arxml
 *                Configuration\ECU\Ecud_ComM.arxml
 *                Configuration\ECU\Ecud_NvM.arxml
 * GENERATED ON:  This timestamp is removed.
 */

#ifndef BSWM_RAM_H
#define BSWM_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "BswM_PCTypes.h"

#if ((BSWM_NO_OF_PDU_GROUP_SWITCH > BSWM_ZERO) || (BSWM_NO_OF_DM_CONTROL > BSWM_ZERO))
#include "Com.h"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define BSWM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/* Global variable to store Initialization status of BswM */
extern VAR(boolean, BSWM_VAR_CLEARED) BswM_GblInitStatus;

#define BSWM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#if (BSWM_TOTAL_RULES > BSWM_ZERO)

extern VAR(BswM_RuleEvaluationType, BSWM_VAR_CLEARED) BswM_GaaRuleEvaluation[BSWM_TOTAL_RULES];

#endif

#if (BSWM_NO_OF_PDU_GROUP_SWITCH > BSWM_ZERO)

extern VAR(Com_IpduGroupVector, BSWM_VAR_CLEARED) BswM_GddIpduGroupControlVector;

#endif

#if (BSWM_NO_OF_DM_CONTROL > BSWM_ZERO) || (BSWM_NO_OF_PDU_GROUP_SWITCH > BSWM_ZERO)

extern VAR(Com_IpduGroupVector, BSWM_VAR_CLEARED) BswM_GddReceptionDMControlVector;

#endif


extern VAR(BswM_BswModeNotificationType, BSWM_VAR_CLEARED) BswM_GaaBswModeNotification[BSWM_TOTAL_PORTS_OF_BSW_MODE_NOTIFICATION];
      
extern VAR(BswM_ComMCurrentModeType, BSWM_VAR_CLEARED) BswM_GaaComMCurrentMode[BSWM_TOTAL_PORTS_OF_COMM_INDICATION];
      
extern VAR(BswM_DcmReqCommunicationType, BSWM_VAR_CLEARED) BswM_GaaDcmReqCommunication[BSWM_TOTAL_PORTS_OF_DCM_COM_REQUEST];
      
extern VAR(BswM_EcuMCurrentStateType, BSWM_VAR_CLEARED) BswM_GaaEcuMCurrentState[BSWM_TOTAL_PORTS_OF_ECUM_INDICATION];
      
extern VAR(BswM_EcuMCurrentWakeupType, BSWM_VAR_CLEARED) BswM_GaaEcuMCurrentWakeup[BSWM_TOTAL_PORTS_OF_ECUM_WAKEUP_SOURCE];
      
extern VAR(BswM_GenericRequestModeType, BSWM_VAR_CLEARED) BswM_GaaGenericCurrentState[BSWM_TOTAL_PORTS_OF_GENERIC_REQUEST];
      
extern VAR(BswM_NvMCurrentJobModeType, BSWM_VAR_CLEARED) BswM_GaaNvMCurrentJobMode[BSWM_TOTAL_PORTS_OF_NVM_CURRENT_JOB_MODE];
      
extern VAR(BswM_SwcModeRequestType, BSWM_VAR_CLEARED) BswM_GaaSwcModeRequest[BSWM_TOTAL_PORTS_OF_SWC_MODE_REQUEST];
      

#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#endif /* BSWM_RAM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/