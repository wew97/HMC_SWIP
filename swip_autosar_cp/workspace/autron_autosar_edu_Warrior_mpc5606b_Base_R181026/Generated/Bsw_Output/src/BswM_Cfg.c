/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : BswM_Cfg.c                                                    **
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

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "BswM_PCTypes.h"
#include "BswM_Rule.h"

#include "EcuM.h"
#include "ComM.h"
#include "SchM_BswM.h"
#include "ComM_EcuMBswM.h"
#include "Rte_BswM.h"
#include "Com.h"
#include "Dcm.h"
#include "NvM.h"
#include "Rte.h"
#include "Rte_Main.h"
#include "Mem_Integration.h"
#include "Dem.h"
#include "WdgM.h"
#include "FiM.h"


/*******************************************************************************
**                      Initialization Structure                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/* Structure for Bsw Mode Notification Property */
CONST(BswM_BswModeNotificationProperty, BSWM_CONST) BswM_GaaBswModeNotificationProperty[BSWM_TOTAL_PORTS_OF_BSW_MODE_NOTIFICATION] =
{
  /*  0 - 0 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[6],

    /* ddTotalRules */
    0x08U,

    /* ddModeInitValue */
    (BswM_ModeDeclarationType)RTE_MODE_DcmDiagnosticSessionControl_DCM_DEFAULT_SESSION,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  },

  /*  1 - 1 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[14],

    /* ddTotalRules */
    0x01U,

    /* ddModeInitValue */
    (BswM_ModeDeclarationType)RTE_MODE_DcmEcuReset_NONE,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  }
};



/* CONST(BswM_CanSMIndicationProperty, BSWM_CONST) BswM_GaaCanSMIndicationProperty[BSWM_TOTAL_PORTS_OF_CANSM_INDICATION]; */

/* Structure for ComM Mode Indication Property */
CONST(BswM_ComMIndicationProperty, BSWM_CONST) BswM_GaaComMIndicationProperty[BSWM_TOTAL_PORTS_OF_COMM_INDICATION] =
{
  /*  0 - 0 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[15],

    /* ddTotalRules */
    0x0AU,

    /* ddNetworkId */
    0x00U,

    /* ddModeInitValue */
    COMM_NO_COMMUNICATION,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  }
};



/* CONST(BswM_ComMPNCIndicationProperty, BSWM_CONST) BswM_GaaComMPncIndicationProperty[BSWM_TOTAL_PORTS_OF_COMM_PNC_REQUEST]; */

/* Structure for Deadline Monitoring Control */
CONST(BswM_DMControlType, BSWM_CONST) BswM_GaaDMControl[BSWM_NO_OF_DM_CONTROL] =
{
  /*  0 - 0 */
  {
    /* ucIdEnable */
    0x00U,

    /* ucIdDisable */
    0x00U,

    /* ucTotalEnable */
    0x00U,

    /* ucTotalDisable */
    0x01U
  },

  /*  1 - 1 */
  {
    /* ucIdEnable */
    0x01U,

    /* ucIdDisable */
    0x00U,

    /* ucTotalEnable */
    0x01U,

    /* ucTotalDisable */
    0x00U
  }
};



/* CONST(BswM_DcmApplicationUpdatedProperty, BSWM_CONST) BswM_GaaDcmApplicationUpdatedProperty[BSWM_TOTAL_PORTS_OF_DCM_APPLICATION_UPDATED_INDICATION]; */

/* Structure for Dcm Mode Indication Property */
CONST(BswM_DcmCommunicationRequestProperty, BSWM_CONST) BswM_GaaDcmComRequestProperty[BSWM_TOTAL_PORTS_OF_DCM_COM_REQUEST] =
{
  /*  0 - 0 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[25],

    /* ddTotalRules */
    0x04U,

    /* ddNetworkId */
    0x00U,

    /* ddModeInitValue */
    DCM_ENABLE_RX_TX_NORM_NM,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  }
};




/* Structure for EcuM State Indication Property */
CONST(BswM_EcuMIndicationProperty, BSWM_CONST) BswM_GaaEcuMIndicationProperty[BSWM_TOTAL_PORTS_OF_ECUM_INDICATION] =
{
  /*  0 - 0 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[29],

    /* ddTotalRules */
    0x01U,

    /* ddModeInitValue */
    ECUM_STATE_STARTUP_ONE,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  }
};




/* Structure for EcuM Wakeup state Indication Property */
CONST(BswM_EcuMWakeupIndicationProperty, BSWM_CONST) BswM_GaaEcuMWakeupIndicationProperty[BSWM_TOTAL_PORTS_OF_ECUM_WAKEUP_SOURCE] =
{
  /*  0 - 0 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[30],

    /* ddTotalRules */
    0x01U,

    /* ddEcuMWakeupSourceId */
    0x00000040U,

    /* ddModeInitValue */
    ECUM_WKSTATUS_NONE,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  },

  /*  1 - 1 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[31],

    /* ddTotalRules */
    0x01U,

    /* ddEcuMWakeupSourceId */
    0x00000080U,

    /* ddModeInitValue */
    ECUM_WKSTATUS_NONE,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  }
};



/* CONST(BswM_EthSMIndicationProperty, BSWM_CONST) BswM_GaaEthSMIndicationProperty[BSWM_TOTAL_PORTS_OF_ETHSM_INDICATION]; */
/* CONST(BswM_FrSMIndicationProperty, BSWM_CONST) BswM_GaaFrSMIndicationProperty[BSWM_TOTAL_PORTS_OF_FRSM_INDICATION]; */

/* Structure for Generic Request Property */
CONST(BswM_GenericRequestProperty, BSWM_CONST) BswM_GaaGenericRequestProperty[BSWM_TOTAL_PORTS_OF_GENERIC_REQUEST] =
{
  /*  0 - 0 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[32],

    /* ddTotalRules */
    0x01U,

    /* usModeRequesterId */
    0x0014U,

    /* usRequestedModeMax */
    0x0001U,

    /* ddModeInitValue */
    NVM_LOWPOWER_ALLOW,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  },

  /*  1 - 1 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[33],

    /* ddTotalRules */
    0x0EU,

    /* usModeRequesterId */
    0x002AU,

    /* usRequestedModeMax */
    0x0190U,

    /* ddModeInitValue */
    BSWM_ECUSTATE_READY,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  },

  /*  2 - 2 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[47],

    /* ddTotalRules */
    0x0AU,

    /* usModeRequesterId */
    0x012AU,

    /* usRequestedModeMax */
    0x0003U,

    /* ddModeInitValue */
    BSWM_SHUTDOWNTARGET_RUN,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  }
};



/* CONST(BswM_J1939DcmBroadcastStatusProperty, BSWM_CONST) BswM_GaaJ1939DcmBroadcastStatusProperty[BSWM_TOTAL_PORTS_OF_J1939DCM_BROADCAST_STATUS]; */
/* CONST(BswM_J1939NmIndicationProperty, BSWM_CONST) BswM_GaaJ1939NmIndicationProperty[BSWM_TOTAL_PORTS_OF_J1939NM_INDICATION]; */
/* CONST(BswM_LinSMIndicationProperty, BSWM_CONST) BswM_GaaLinSMIndicationProperty[BSWM_TOTAL_PORTS_OF_LINSM_INDICATION]; */
/* CONST(BswM_LinSMScheduleIndicationProperty, BSWM_CONST) BswM_GaaLinScheduleIndicationProperty[BSWM_TOTAL_PORTS_OF_LIN_SCHEDULE_INDICATION]; */
/* CONST(BswM_LinTpRequestProperty, BSWM_CONST) BswM_GaaLinTpModeRequestProperty[BSWM_TOTAL_PORTS_OF_LINTP_MODE_REQUEST]; */
/* CONST(BswM_NvMBlockModeIndicationProperty, BSWM_CONST) BswM_GaaNvMBlockModeIndicationProperty[BSWM_TOTAL_PORTS_OF_NVM_CURRENT_BLOCK_MODE]; */

/* Structure for NvM Multi Block Indication Property */
CONST(BswM_NvMJobModeIndicationProperty, BSWM_CONST) BswM_GaaNvMJobModeIndicationProperty[BSWM_TOTAL_PORTS_OF_NVM_CURRENT_JOB_MODE] =
{
  /*  0 - 0 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[57],

    /* ddTotalRules */
    0x01U,

    /* ucServiceId */
    0x0CU,

    /* ddModeInitValue */
    NVM_MAXVALUE,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  },

  /*  1 - 1 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[58],

    /* ddTotalRules */
    0x02U,

    /* ucServiceId */
    0x0DU,

    /* ddModeInitValue */
    NVM_MAXVALUE,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  }
};




/* Structure for Pdu Group Switch */
CONST(BswM_PduGroupSwitchType, BSWM_CONST) BswM_GaaPduGroupSwitch[BSWM_NO_OF_PDU_GROUP_SWITCH] =
{
  /*  0 - 0 */
  {
    /* blReinit */
    BSWM_TRUE,

    /* ucIdEnable */
    0x00U,

    /* ucIdDisable */
    0x00U,

    /* ucTotalEnable */
    0x00U,

    /* ucTotalDisable */
    0x01U
  },

  /*  1 - 1 */
  {
    /* blReinit */
    BSWM_TRUE,

    /* ucIdEnable */
    0x00U,

    /* ucIdDisable */
    0x01U,

    /* ucTotalEnable */
    0x00U,

    /* ucTotalDisable */
    0x01U
  },

  /*  2 - 2 */
  {
    /* blReinit */
    BSWM_TRUE,

    /* ucIdEnable */
    0x02U,

    /* ucIdDisable */
    0x00U,

    /* ucTotalEnable */
    0x01U,

    /* ucTotalDisable */
    0x00U
  },

  /*  3 - 3 */
  {
    /* blReinit */
    BSWM_TRUE,

    /* ucIdEnable */
    0x03U,

    /* ucIdDisable */
    0x00U,

    /* ucTotalEnable */
    0x01U,

    /* ucTotalDisable */
    0x00U
  }
};



/* CONST(BswM_PduRouterControlType, BSWM_CONST) BswM_GaaPduRouterControl[BSWM_NO_OF_PDUR_ROUTER_CONTROL]; */

/* Structure for Rule Property */
CONST(BswM_RuleInitPropertyType, BSWM_CONST) BswM_GaaRuleInitProperty[BSWM_TOTAL_RULES] =
{
  /* Rule 0 - 0 */
  {
    /* *pRuleFunction */
    Rule_ComModeNotification_Project_FULL_COM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 1 - 1 */
  {
    /* *pRuleFunction */
    Rule_ComModeNotification_Project_NO_COM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 2 - 2 */
  {
    /* *pRuleFunction */
    Rule_ComModeNotification_Project_SILENT_COM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 3 - 3 */
  {
    /* *pRuleFunction */
    Rule_ComControl_Project_ENABLE_TX,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 4 - 4 */
  {
    /* *pRuleFunction */
    Rule_ComControl_Project_ENABLE_RX,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 5 - 5 */
  {
    /* *pRuleFunction */
    Rule_ComControl_Project_DISABLE_DM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 6 - 6 */
  {
    /* *pRuleFunction */
    Rule_ComControl_Project_DISABLE_RX,

    /* ucRuleInitState */
    BSWM_TRUE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 7 - 7 */
  {
    /* *pRuleFunction */
    Rule_ComControl_Project_DISABLE_TX,

    /* ucRuleInitState */
    BSWM_TRUE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 8 - 8 */
  {
    /* *pRuleFunction */
    Rule_ComControl_Project_ENABLE_DM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 9 - 9 */
  {
    /* *pRuleFunction */
    Rule_ComModeRequest_Project_FULL_COM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 10 - 10 */
  {
    /* *pRuleFunction */
    Rule_ComModeRequest_Project_NO_COM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 11 - 11 */
  {
    /* *pRuleFunction */
    Rule_DiagnosticSessionNotification_DEFAULT_SESSION,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 12 - 12 */
  {
    /* *pRuleFunction */
    Rule_DiagnosticSessionNotification_ECU_PROGRAMMING_MODE,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 13 - 13 */
  {
    /* *pRuleFunction */
    Rule_DiagnosticSessionNotification_EXTENDED_DIAGNOSTIC_MODE,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 14 - 14 */
  {
    /* *pRuleFunction */
    Rule_DiagnosticSessionNotification_EXTENDED_DIAGNOSTIC_SESSION,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 15 - 15 */
  {
    /* *pRuleFunction */
    Rule_DiagnosticSessionNotification_PROGRAMMING_SESSION,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 16 - 16 */
  {
    /* *pRuleFunction */
    Rule_DiagnosticSessionNotification_QUIESCENT_CURRENT_DIAGNOSTIC_MODE_START,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 17 - 17 */
  {
    /* *pRuleFunction */
    Rule_DiagnosticSessionNotification_SAFETY_SYSTEM_DIAGNOSTIC_SESSION,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 18 - 18 */
  {
    /* *pRuleFunction */
    Rule_DiagnosticSessionNotification_SLEEP_MODE_START_REQUEST,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 19 - 19 */
  {
    /* *pRuleFunction */
    Rule_EcuStateTo_OFF,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 20 - 20 */
  {
    /* *pRuleFunction */
    Rule_EcuStateTo_RESET,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 21 - 21 */
  {
    /* *pRuleFunction */
    Rule_EcuStateTo_RUN_From_SLEEP,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 22 - 22 */
  {
    /* *pRuleFunction */
    Rule_EcuStateTo_RUN_From_STARTUP,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 23 - 23 */
  {
    /* *pRuleFunction */
    Rule_EcuStateTo_SHUTDOWN,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 24 - 24 */
  {
    /* *pRuleFunction */
    Rule_EcuStateTo_SLEEP,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 25 - 25 */
  {
    /* *pRuleFunction */
    Rule_EcuStateTo_STARTUP_THREE,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 26 - 26 */
  {
    /* *pRuleFunction */
    Rule_EcuStateTo_STARTUP_TWO,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 27 - 27 */
  {
    /* *pRuleFunction */
    Rule_EcuState_OFF,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 28 - 28 */
  {
    /* *pRuleFunction */
    Rule_EcuState_RESET,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 29 - 29 */
  {
    /* *pRuleFunction */
    Rule_EcuState_RUN,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 30 - 30 */
  {
    /* *pRuleFunction */
    Rule_EcuState_SHUTDOWN,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 31 - 31 */
  {
    /* *pRuleFunction */
    Rule_EcuState_SLEEP,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 32 - 32 */
  {
    /* *pRuleFunction */
    Rule_EcuState_STARTUP_THREE,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 33 - 33 */
  {
    /* *pRuleFunction */
    Rule_EcuState_STARTUP_TWO,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 34 - 34 */
  {
    /* *pRuleFunction */
    Rule_ShutdownTargetTo_OFF,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 35 - 35 */
  {
    /* *pRuleFunction */
    Rule_ShutdownTargetTo_RESET,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 36 - 36 */
  {
    /* *pRuleFunction */
    Rule_ShutdownTargetTo_RUN,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 37 - 37 */
  {
    /* *pRuleFunction */
    Rule_ShutdownTargetTo_SLEEP,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 38 - 38 */
  {
    /* *pRuleFunction */
    Rule_WakeupEventNotification_CAN1RX,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 39 - 39 */
  {
    /* *pRuleFunction */
    Rule_WakeupEventNotification_CAN1RX_POLL,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  }
};



/*CONST(BswM_SlaveCoreInfoType, BSWM_CONST) BswM_GaaStartSlaveCores[BSWM_NO_OF_START_SLAVE_CORES]; */
/*CONST(BswM_SlaveCoreInfoType, BSWM_CONST) BswM_GaaStopSlaveCores[BSWM_NO_OF_STOP_SLAVE_CORES]; */
/* CONST(BswM_SwcModeNotificationProperty, BSWM_CONST) BswM_GaaSwcModeNotificationProperty[BSWM_TOTAL_PORTS_OF_SWC_MODE_NOTIFICATION]; */

/* Structure for Swc Mode Request Property */
CONST(BswM_SwcModeRequestProperty, BSWM_CONST) BswM_GaaSwcModeRequestProperty[BSWM_TOTAL_PORTS_OF_SWC_MODE_REQUEST] =
{
  /*  0 - 0 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[0],

    /* ddTotalRules */
    0x02U,

    /* blModeInitValueStatus */
    BSWM_INVALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  },

  /*  1 - 1 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[2],

    /* ddTotalRules */
    0x04U,

    /* blModeInitValueStatus */
    BSWM_INVALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  }
};



/* CONST(BswM_TriggerIpduSendType, BSWM_CONST) BswM_GaaTriggerIpduSend[BSWM_NO_OF_TRIGGER_IPDU_SEND]; */
/* CONST(BswM_WdgM_PartitionResetProperty, BSWM_CONST) BswM_GaaWdgMPartitionResetProperty[BSWM_TOTAL_PORTS_OF_WDGM_REQUEST_PARTITION_RESET]; */


/* Array for DM Pdu Group List */
CONST(Com_IpduGroupIdType, BSWM_CONST) BswM_GaaDMPduGroupList[BSWM_NO_OF_DM_PDU_GROUP_LIST] = {
    0,   0
};





/* Array for Pdu Group List */
CONST(Com_IpduGroupIdType, BSWM_CONST) BswM_GaaPduGroupList[BSWM_NO_OF_PDU_GROUP_LIST] = {
    0,   1,   0,   1
};




/* Array for Total Rules of Mode Request Port */
CONST(BswM_RuleIdType, BSWM_CONST) BswM_GaaRuleIdList[BSWM_TOTAL_RULE_IDS] = {
    9,  10,  34,  35,  36,  37,  11,  12,  13,  14, 
   15,  16,  17,  18,  35,   0,   1,   2,   3,   4, 
    5,   6,   7,   8,  24,   3,   4,   6,   7,  26, 
   38,  39,  24,  19,  20,  21,  22,  23,  24,  25, 
   27,  28,  29,  30,  31,  32,  33,  19,  20,  21, 
   22,  23,  24,  34,  35,  36,  37,  25,  19,  20
};




#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/