/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : BswM_Cfg.h                                                    **
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

#ifndef BSWM_CFG_H
#define BSWM_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
#define BSWM_AR_RELEASE_MAJOR_VERSION                      4
#define BSWM_AR_RELEASE_MINOR_VERSION                      0
#define BSWM_AR_RELEASE_REVISION_VERSION                   3
#define BSWM_SW_MAJOR_VERSION                              2
#define BSWM_SW_MINOR_VERSION                              5
#define BSWM_SW_PATCH_VERSION                              0
#define BSWM_VENDOR_ID                                     76
#define BSWM_MODULE_ID                                     42

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#define BSWM_INVALID                                       0x00U
#define BSWM_VALID                                         0x01U
#define BSWM_MIXED                                         0x02U

#define BSWM_IDLE                                          0x00U
#define BSWM_READY                                         0x01U

#define BSWM_ZERO                                          0x00U
#define BSWM_ONE                                           0x01U

#define BSWM_FALSE                                         0x00U
#define BSWM_TRUE                                          0x01U

#define BSWM_IMMEDIATE                                     0x00U
#define BSWM_DEFERRED                                      0x01U

#define BSWM_UNDEFINED                                     0xDEU

/* To check if Dem is enable or not */
#define BSWM_DEMERROR_REPORT                               (STD_OFF)

/* Pre-compile option for Development Error Checking */
#define BSWM_DEV_ERROR_DETECT                              (STD_ON)

/* Pre-compile option for Version Info API */
#define BSWM_VERSION_INFO_API                              (STD_OFF)


/* Main function period */
#define BSWM_MAIN_FUNCTION_PERIOD                          0.01


/* Pre-compile option to enable/disable the indication/request from CanSM */
#define BSWM_CANSM_ENABLED                                 (STD_ON)

/* Pre-compile option to enable/disable the indication/request from ComM */
#define BSWM_COMM_ENABLED                                  (STD_ON)

/* Pre-compile option to enable/disable the indication/request from Dcm */
#define BSWM_DCM_ENABLED                                   (STD_ON)

/* Pre-compile option to enable/disable the indication/request from EcuM */
#define BSWM_ECUM_ENABLED                                  (STD_ON)

/* Pre-compile option to enable/disable the indication/request from EthSM */
#define BSWM_ETHSM_ENABLED                                 (STD_OFF)

/* Pre-compile option to enable/disable the indication/request from ComM */
#define BSWM_FRSM_ENABLED                                  (STD_OFF)

/* Pre-compile option to enable/disable the Generic indication/request */
#define BSWM_GENERIC_REQUEST_ENABLED                       (STD_ON)

/* Pre-compile option to enable/disable the indication/request from J1939 Dcm */
#define BSWM_J1939DCM_ENABLED                              (STD_OFF)

/* Pre-compile option to enable/disable the indication/request from J1939 Nm */
#define BSWM_J1939NM_ENABLED                               (STD_OFF)

/* Pre-compile option to enable/disable the indication/request from LinSM */
#define BSWM_LINSM_ENABLED                                 (STD_OFF)

/* Pre-compile option to enable/disable the indication/request from LinTP */
#define BSWM_LINTP_ENABLED                                 (STD_OFF)

/* Pre-compile option to enable/disable the indication/request from NvM */
#define BSWM_NVM_ENABLED                                   (STD_ON)

/* Pre-compile option to enable/disable the indication/request from SchM */
#define BSWM_SCHM_ENABLED                                  (STD_ON)

/* Pre-compile option to enable/disable the indication/request from WdgM */
#define BSWM_WDGM_ENABLED                                  (STD_ON)


/* Pre-compile option for Bsw Notification support */
#define BSWM_BSW_MODE_NOTIFICATION_ENABLED                 (STD_ON)

/* Pre-compile option for Swc Notification support */
#define BSWM_SWC_MODE_NOTIFICATION_ENABLED                 (STD_OFF)

/* Pre-compile option for Swc Request support */
#define BSWM_SWC_MODE_REQUEST_ENABLED                      (STD_ON)


/* BSWM_BSW_MODE_NOTIFICATION_INIT_STATUS init status */
#define BSWM_BSW_MODE_NOTIFICATION_INIT_STATUS             (BSWM_VALID)

/* BSWM_COMM_INDICATION_INIT_STATUS init status */
#define BSWM_COMM_INDICATION_INIT_STATUS                   (BSWM_VALID)

/* BSWM_DCM_COM_REQUEST_INIT_STATUS init status */
#define BSWM_DCM_COM_REQUEST_INIT_STATUS                   (BSWM_VALID)

/* BSWM_ECUM_INDICATION_INIT_STATUS init status */
#define BSWM_ECUM_INDICATION_INIT_STATUS                   (BSWM_VALID)

/* BSWM_ECUM_WAKEUP_SOURCE_INIT_STATUS init status */
#define BSWM_ECUM_WAKEUP_SOURCE_INIT_STATUS                (BSWM_VALID)

/* BSWM_GENERIC_REQUEST_INIT_STATUS init status */
#define BSWM_GENERIC_REQUEST_INIT_STATUS                   (BSWM_VALID)

/* BSWM_NVM_CURRENT_JOB_MODE_INIT_STATUS init status */
#define BSWM_NVM_CURRENT_JOB_MODE_INIT_STATUS              (BSWM_VALID)

/* BSWM_SWC_MODE_REQUEST_INIT_STATUS init status */
#define BSWM_SWC_MODE_REQUEST_INIT_STATUS                  (BSWM_INVALID)


/* Total Number of Deadline Monitoring Control Actions */
#define BSWM_NO_OF_DM_CONTROL                              2U

/* Total Number of DM Pdu Group List */
#define BSWM_NO_OF_DM_PDU_GROUP_LIST                       2U

/* Total Number of Ipdu List */
#define BSWM_NO_OF_IPDU_LIST                               0U

/* Total Number of Pdu Router Control Actions */
#define BSWM_NO_OF_PDUR_ROUTER_CONTROL                     0U

/* Total Number of Pdu Group List */
#define BSWM_NO_OF_PDU_GROUP_LIST                          4U

/* Total Number of Pdu Group Switch Actions */
#define BSWM_NO_OF_PDU_GROUP_SWITCH                        4U

/* Total Number of Pdu Routing List */
#define BSWM_NO_OF_PDU_ROUTING_LIST                        0U

/* Total Number of Slave Cores Configured for Rte_Start */
#define BSWM_NO_OF_START_SLAVE_CORES                       0U

/* Total Number of Slave Cores Configured for Rte_Stop */
#define BSWM_NO_OF_STOP_SLAVE_CORES                        0U

/* Total Number of Trigger Ipdu Send Actions */
#define BSWM_NO_OF_TRIGGER_IPDU_SEND                       0U


/* Total Deferred Rules of Bsw Indication */
#define BSWM_TOTAL_DEFERRED_RULES_OF_BSW_INDICATION        0U


/* Total Mode Request Ports of Bsw Mode Notification */
#define BSWM_TOTAL_PORTS_OF_BSW_MODE_NOTIFICATION          2U

/* Total Mode Request Ports of CanSM Indication */
#define BSWM_TOTAL_PORTS_OF_CANSM_INDICATION               0U

/* Total Mode Request Ports of ComM Indication */
#define BSWM_TOTAL_PORTS_OF_COMM_INDICATION                1U

/* Total Mode Request Ports of ComM Pnc Indication */
#define BSWM_TOTAL_PORTS_OF_COMM_PNC_REQUEST               0U

/* Total Mode Request Ports of Dcm Application Updated Indication */
#define BSWM_TOTAL_PORTS_OF_DCM_APPLICATION_UPDATED_INDICATION 0U

/* Total Mode Request Ports of Dcm Com Request */
#define BSWM_TOTAL_PORTS_OF_DCM_COM_REQUEST                1U

/* Total Mode Request Ports of EcuM Indication */
#define BSWM_TOTAL_PORTS_OF_ECUM_INDICATION                1U

/* Total Mode Request Ports of EcuM Wakeup Indication */
#define BSWM_TOTAL_PORTS_OF_ECUM_WAKEUP_SOURCE             2U

/* Total Mode Request Ports of EthSM Indication */
#define BSWM_TOTAL_PORTS_OF_ETHSM_INDICATION               0U

/* Total Mode Request Ports of FrSM Indication */
#define BSWM_TOTAL_PORTS_OF_FRSM_INDICATION                0U

/* Total Mode Request Ports of Generic Request */
#define BSWM_TOTAL_PORTS_OF_GENERIC_REQUEST                3U

/* Total J1939 Dcm Broadcast Status Rules */
#define BSWM_TOTAL_PORTS_OF_J1939DCM_BROADCAST_STATUS      0U

/* Total J1939 Nm Indication Rules */
#define BSWM_TOTAL_PORTS_OF_J1939NM_INDICATION             0U

/* Total Mode Request Ports of LinSM Indication */
#define BSWM_TOTAL_PORTS_OF_LINSM_INDICATION               0U

/* Total Mode Request Ports of LinTp Mode Request */
#define BSWM_TOTAL_PORTS_OF_LINTP_MODE_REQUEST             0U

/* Total Mode Request Ports of Lin Schedule Indication */
#define BSWM_TOTAL_PORTS_OF_LIN_SCHEDULE_INDICATION        0U

/* Total Mode Request Ports of NvM Block Mode Indication */
#define BSWM_TOTAL_PORTS_OF_NVM_CURRENT_BLOCK_MODE         0U

/* Total Mode Request Ports of NvM Job Mode Indication */
#define BSWM_TOTAL_PORTS_OF_NVM_CURRENT_JOB_MODE           2U

/* Total Mode Request Ports of Swc Mode Notification */
#define BSWM_TOTAL_PORTS_OF_SWC_MODE_NOTIFICATION          0U

/* Total Mode Request Ports of Swc Mode Request */
#define BSWM_TOTAL_PORTS_OF_SWC_MODE_REQUEST               2U

/* Total Mode Request Ports of WdgM Partition Reset */
#define BSWM_TOTAL_PORTS_OF_WDGM_REQUEST_PARTITION_RESET   0U


/* Total Rules */
#define BSWM_TOTAL_RULES                                   40U

/* Total Number of Rule IDs */
#define BSWM_TOTAL_RULE_IDS                                60U



/* Type definition for config */
typedef uint8 BswM_ConfigType;

/* Type definition for rules */
typedef uint8 BswM_RuleIdType;

/* Type definition for users */
typedef uint16 BswM_UserType;

/* Type definition for modes */
typedef uint16 BswM_ModeType;

/* Type definition for modes */
typedef uint8 BswM_ModeDeclarationType;



#endif /* BSWM_CFG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
