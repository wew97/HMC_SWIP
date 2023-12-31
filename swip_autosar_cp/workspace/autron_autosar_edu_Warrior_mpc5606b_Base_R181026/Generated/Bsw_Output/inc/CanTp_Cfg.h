/*******************************************************************************
**  FILE-NAME: CanTp_Cfg.h                                                    **
**                                                                            **
**  MODULE-NAME: AUTOSAR CAN Transport Layer Module                           **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 1.7.10                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/

/*
 * INPUT FILE:    Configuration\ECU\Ecud_CanIf.arxml
 *                Configuration\ECU\Ecud_CanTp.arxml
 *                Configuration\ECU\Ecud_PduR.arxml
 * GENERATED ON:  This timestamp is removed.
 */

#ifndef CANTP_CFG_H
#define CANTP_CFG_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComStack_Types.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define CANTP_CFG_AR_RELEASE_MAJOR_VERSION                 (4)
#define CANTP_CFG_AR_RELEASE_MINOR_VERSION                 (0)
#define CANTP_CFG_AR_RELEASE_REVISION_VERSION              (3)
#define CANTP_CFG_SW_MAJOR_VERSION                         (1)
#define CANTP_CFG_SW_MINOR_VERSION                         (0)
#define CANTP_CFG_SW_PATCH_VERSION                         (5)

/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/


/* FILE VERSION INFORMATION */
#define CANTP_AR_RELEASE_MAJOR_VERSION                     (4)
#define CANTP_AR_RELEASE_MINOR_VERSION                     (0)
#define CANTP_AR_RELEASE_REVISION_VERSION                  (3)
#define CANTP_SW_MAJOR_VERSION                             (1)
#define CANTP_SW_MINOR_VERSION                             (0)
#define CANTP_SW_PATCH_VERSION                             (5)
#define CANTP_VENDOR_ID                                    ((uint16)76)
#define CANTP_MODULE_ID                                    ((uint16)35)
/*******************************************************************************
**                      Pre-Compile Options                                   **
*******************************************************************************/

/* Pre-compile option for Single Channel */
#define CANTP_SINGLE_CHANNEL (STD_OFF)

/* Pre-compile option for CanTp Full Duplex Mode */
#define CANTP_FULL_DUPLEX_MODE (STD_OFF)

/* Pre-compile option for Development Error Checking */
#define CANTP_DEV_ERROR_DETECT (STD_ON)

/* Pre-compile option for Version Info API */
#define CANTP_VERSION_INFO_API (STD_OFF)

/* Pre-compile option for Change Parameter API */
#define CANTP_CHANGE_PARAMETER_API (STD_ON)

/* Pre-compile option for Enabling Transmit Cancellation */
#define CANTP_TC (STD_ON)

/* Pre-compile option for Transmit NSdu Container */
#define CANTP_TX_NSDU (STD_ON)

/* Pre-compile option for TX PDU functional addressing */
#define CANTP_TX_PHYSICAL_ADDRESSING (STD_ON)

/* Pre-compile option for TX PDU extended address */
#define CANTP_TX_EXTENDED_ADDRESS (STD_OFF)

/* Pre-compile option for Tx PDU Mixed address */
#define CANTP_TX_MIXED_ADDRESS (STD_OFF)

/*  Pre-compile option for TX PDU functional addressing */
#define CANTP_TX_FUNCTIONAL_ADDRESSING (STD_OFF)

/* Pre-compile option for TX SDU padding activation */
#define CANTP_TX_SDU_PADDING_ACTIVATION (STD_ON)

/* Pre-compile option for Receive NSdu Container */
#define CANTP_RX_NSDU (STD_ON)

/* Pre-compile option for TX NPDU */
#define CANTP_TX_NPDU (STD_ON)

/* Pre-compile option for RX NPDU */
#define CANTP_RX_NPDU (STD_ON)

/* Pre-compile option for Rx PDU Mixed address */
#define CANTP_RX_MIXED_ADDRESS (STD_OFF)

/* Pre-compile option for RX PDU functional addressing */
#define CANTP_RX_FUNCTIONAL_ADDRESSING (STD_ON)

/* Pre-compile option for Rx physical addressing */
#define CANTP_RX_PHYSICAL_ADDRESSING (STD_ON)

/* Pre-compile option for RX SDU padding activation */
#define CANTP_RX_SDU_PADDING_ACTIVATION (STD_ON)

/* Pre-compile option for Read parameter API */
#define CANTP_READ_PARAMETER_API (STD_OFF)

/* Pre-compile option for RX PDU extended address */
#define CANTP_RX_EXTENDED_ADDRESS (STD_OFF)


/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/
typedef uint8 CanTp_ChannelType;

/* Transmit frame padding byte */
#define CANTP_PADDING_BYTE ((uint8)170)

/* Single Channel Id */
#define CANTP_CHANNEL_ID ((uint8)0)

/* Main function Period */
#define CANTP_MAIN_FUNCTION_PERIOD ((uint8)5)

/* Number of receive N-PDU this symbol represents the number of RxNPduIds */
#define CANTP_MAXNO_RX_NPDU ((uint16)4)

/* Maximum receive SDU ID this symbol represents the number of RxNSdus */
#define CANTP_MAXNO_RX_SDU ((uint16)4)

/* Maximum number of confirmation PduId */
#define CANTP_MAX_CONFIRM_ID ((uint16)2)

/* Maximum Rx Indication PduId configured */
#define CANTP_MAX_INDIC_ID ((uint16)3)


/* Maximum transmit SDU ID */
#define CANTP_MAX_TX_SDUID ((uint16)2)

/* Maximum receive SDU ID */
#define CANTP_MAX_RX_SDUID ((uint16)3)

/* This symbol represents the lowest Rx flow control Id which is configured */
#define CANTP_RX_FCPDU_START ((uint16)0)

/* This symbol represents the max RxFCNPdu flow control Id which is configured */
#define CANTP_MAX_RX_FCNPDUID ((uint16)2)

/* Number of  RxExtFcPdus */
#define CANTP_NO_OF_RXEXTFCPDUS ((uint8)3)

/* Number of  RxExtPdus */
#define CANTP_NO_OF_RXEXTPDUS ((uint8)4)

/* Number of  GaaRxSduStatic */
#define CANTP_NO_OF_RXSDUSTATIC ((uint8)4)

/* Number of  GaaRxSduMap */
#define CANTP_NO_OF_RXSDUMAP ((uint8)3)

/* Number of  Channel Mapping */
#define INVALID_CHANNELMAPS 

/* Number of  Channel Mapping */
#define INVALID_NSAORNAESDUMAPPING 

/* Number of Rx and Tx connection channels configured in CanTp */
#define CANTP_TOTAL_RX_TX_CHANNELS 4

/* No Of Configured Channel */
#define CANTP_NO_OF_CHANNELS 4


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* CanTp Tx Nsdu Handle(s) */
#define CanTpConf_CanTpTxNSdu_CanTpTxNSdu_0_Pdu_ISignalIPdu_ECU1_Msg_TP1\
  ((PduIdType)0)
#define CanTpConf_CanTpTxNSdu_CanTpTxNSdu_1_Pdu_ISignalIPdu_ECU1_Msg_TP2\
  ((PduIdType)1)
#define CanTpConf_CanTpTxNSdu_CanTpTxNSdu_2_Pdu_DcmIPdu_ECU1_GST_Msg_TP\
  ((PduIdType)2)

/* CanTp Rx Nsdu Handle(s) */
#define CanTpConf_CanTpRxNSdu_CanTpRxNSdu_0_Pdu_ISignalIPdu_GST_Msg_TP1\
  ((PduIdType)0)
#define CanTpConf_CanTpRxNSdu_CanTpRxNSdu_1_Pdu_ISignalIPdu_GST_Msg_TP2\
  ((PduIdType)1)
#define CanTpConf_CanTpRxNSdu_CanTpRxNSdu_2_Pdu_DcmIPdu_GST_Msg_TP_Phys\
  ((PduIdType)2)
#define CanTpConf_CanTpRxNSdu_CanTpRxNSdu_3_Pdu_DcmIPdu_GST_Msg_TP_Func\
  ((PduIdType)3)

/* CanTp Rx NPdu Handle(s) */
#define CanTpConf_CanTpRxNPdu_CanTpRxNPdu_0                ((PduIdType)0)
#define CanTpConf_CanTpRxNPdu_CanTpRxNPdu_1                ((PduIdType)1)
#define CanTpConf_CanTpRxNPdu_CanTpRxNPdu_2                ((PduIdType)2)
#define CanTpConf_CanTpRxNPdu_CanTpRxNPdu_3                ((PduIdType)3)

/* CanTp RxFc NPdu Handle(s) */
#define CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_0            ((PduIdType)0)
#define CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_1            ((PduIdType)1)
#define CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_2            ((PduIdType)2)

/* CanTp TxFc NPdu Confirmation Handle(s) */
#define CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_0            ((PduIdType)0)
#define CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_1            ((PduIdType)1)
#define CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_2            ((PduIdType)2)

/* CanTp Tx NPdu Handle(s) */
#define CanTpConf_CanTpTxNPdu_CanTpTxNPdu_0                ((PduIdType)0)
#define CanTpConf_CanTpTxNPdu_CanTpTxNPdu_1                ((PduIdType)1)
#define CanTpConf_CanTpTxNPdu_CanTpTxNPdu_2                ((PduIdType)2)

/* Configuration Set Handles */
#define CanTpConfig (&CanTp_GaaConfig[0])


#endif /* #ifndef CANTP_CFG_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
