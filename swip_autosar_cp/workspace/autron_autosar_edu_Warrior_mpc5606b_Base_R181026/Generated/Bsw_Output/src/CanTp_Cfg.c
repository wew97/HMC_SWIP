/*******************************************************************************
**  FILE-NAME: CanTp_Cfg.c                                                    **
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

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanTp.h"
#include "CanTp_PCTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define CANTP_CFG_C_AR_RELEASE_MAJOR_VERSION               (4)
#define CANTP_CFG_C_AR_RELEASE_MINOR_VERSION               (0)
#define CANTP_CFG_C_AR_RELEASE_REVISION_VERSION            (3)
#define CANTP_CFG_C_SW_MAJOR_VERSION                       (1)
#define CANTP_CFG_C_SW_MINOR_VERSION                       (0)
#define CANTP_CFG_C_SW_PATCH_VERSION                       (5)
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (CANTP_PCTYPES_AR_RELEASE_MAJOR_VERSION != \
  CANTP_CFG_C_AR_RELEASE_MAJOR_VERSION)
  #error "CanTp_Cfg.c : Mismatch in Specification Major Version"
#endif

#if (CANTP_PCTYPES_AR_RELEASE_MINOR_VERSION != \
  CANTP_CFG_C_AR_RELEASE_MINOR_VERSION)
  #error "CanTp_Cfg.c : Mismatch in Specification Minor Version"
#endif

#if (CANTP_PCTYPES_AR_RELEASE_REVISION_VERSION != \
  CANTP_CFG_C_AR_RELEASE_REVISION_VERSION)
  #error "CanTp_Cfg.c : Mismatch in Specification Revision Version"
#endif

#if (CANTP_PCTYPES_SW_MAJOR_VERSION != CANTP_CFG_C_SW_MAJOR_VERSION)
  #error "CanTp_Cfg.c : Mismatch in Software Major Version"
#endif

#if (CANTP_PCTYPES_SW_MINOR_VERSION != CANTP_CFG_C_SW_MINOR_VERSION)
  #error "CanTp_Cfg.c : Mismatch in Software Minor Version"
#endif

#if (CANTP_PCTYPES_SW_PATCH_VERSION != CANTP_CFG_C_SW_PATCH_VERSION)
  #error "CanTp_Cfg.c : Mismatch in Software Patch Version"
#endif



/*******************************************************************************
**                      Initialization Structure                              **
*******************************************************************************/
#define CANTP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Array to store Channel specific data variables*/
VAR(CanTp_ChannelRam, CANTP_VAR)CanTp_GaaChannelRam[4];


/* Array for N_As/N_Ar, N_Bs/N_Br, N_Cs/N_Cr Timersfor all the channels */
VAR(uint16, CANTP_VAR)CanTp_GaaTimers[4][3];


/* Array for STMin timers of all channels*/
VAR(uint8, CANTP_VAR)CanTp_GaaStMinTimers[4];


#define CANTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/* CONST(uint8, CANTP_CONST) CanTp_GaaChannelMapping[]; */
#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

CONST(CanTp_ChannelMode, CANTP_CONST) CanTp_GaaChannelMode[] =
{
  CANTP_MODE_HALF_DUPLEX,

  CANTP_MODE_HALF_DUPLEX,

  CANTP_MODE_HALF_DUPLEX,

  CANTP_MODE_HALF_DUPLEX
};

#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* CONST(CanTp_RxNSaOrNAeSduMapping, CANTP_CONST) CanTp_GaaNSaOrNAeSduMapping[]; */
#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

CONST(CanTp_RxExtPdus, CANTP_CONST) CanTp_GaaRxExtFcPdus[] =
{
  /* RxPDU 0 - 0 */
  {
    /* ddNoOfPdusOrSduId */
    0x00,

    /* ddRxNSaOrNAeSduMapIndex */
    CANTP_INVALID,

    /* ucAddressingMode */
    0x00
  },

  /* RxPDU 1 - 1 */
  {
    /* ddNoOfPdusOrSduId */
    0x01,

    /* ddRxNSaOrNAeSduMapIndex */
    CANTP_INVALID,

    /* ucAddressingMode */
    0x00
  },

  /* RxPDU 2 - 2 */
  {
    /* ddNoOfPdusOrSduId */
    0x02,

    /* ddRxNSaOrNAeSduMapIndex */
    CANTP_INVALID,

    /* ucAddressingMode */
    0x00
  }
};

#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

CONST(CanTp_RxExtPdus, CANTP_CONST) CanTp_GaaRxExtPdus[] =
{
  /* RxPDU 0 - 0 */
  {
    /* ddNoOfPdusOrSduId */
    0x00,

    /* ddRxNSaOrNAeSduMapIndex */
    CANTP_INVALID,

    /* ucAddressingMode */
    0x00
  },

  /* RxPDU 1 - 1 */
  {
    /* ddNoOfPdusOrSduId */
    0x01,

    /* ddRxNSaOrNAeSduMapIndex */
    CANTP_INVALID,

    /* ucAddressingMode */
    0x00
  },

  /* RxPDU 2 - 2 */
  {
    /* ddNoOfPdusOrSduId */
    0x02,

    /* ddRxNSaOrNAeSduMapIndex */
    CANTP_INVALID,

    /* ucAddressingMode */
    0x00
  },

  /* RxPDU 3 - 3 */
  {
    /* ddNoOfPdusOrSduId */
    0x03,

    /* ddRxNSaOrNAeSduMapIndex */
    CANTP_INVALID,

    /* ucAddressingMode */
    0x00
  }
};

#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

CONST(CanTp_RxNSduDynamic, CANTP_CONST) CanTp_GaaRxSduDynamic[] =
{
  /* RxNSDU 0 - CanTpConfig_CanTpChannel_0_Pdu_ISignalIPdu_GST_Msg_TP1_CanTpRxNSdu_0_Pdu_ISignalIPdu_GST_Msg_TP1_0 */
  {
    /* ddUpTargetPduId */
    0x0001,

    /* ddLoTxFcTargetPduId */
    0x000C,

    /* usNarTimeoutValue */
    0x00C8,

    /* usNbrTimeoutValue */
    0x0000,

    /* usNcrTimeoutValue */
    0x00C8,

    /* usRxWftMax */
    0x0000
  },

  /* RxNSDU 1 - CanTpConfig_CanTpChannel_1_Pdu_ISignalIPdu_GST_Msg_TP2_CanTpRxNSdu_1_Pdu_ISignalIPdu_GST_Msg_TP2_1 */
  {
    /* ddUpTargetPduId */
    0x0000,

    /* ddLoTxFcTargetPduId */
    0x000D,

    /* usNarTimeoutValue */
    0x00C8,

    /* usNbrTimeoutValue */
    0x0000,

    /* usNcrTimeoutValue */
    0x00C8,

    /* usRxWftMax */
    0x0000
  },

  /* RxNSDU 2 - CanTpConfig_CanTpChannel_2_Pdu_DcmIPdu_GST_Msg_TP_Phys_CanTpRxNSdu_2_Pdu_DcmIPdu_GST_Msg_TP_Phys_2 */
  {
    /* ddUpTargetPduId */
    0x0002,

    /* ddLoTxFcTargetPduId */
    0x000E,

    /* usNarTimeoutValue */
    0x00C8,

    /* usNbrTimeoutValue */
    0x0000,

    /* usNcrTimeoutValue */
    0x00C8,

    /* usRxWftMax */
    0x0000
  },

  /* RxNSDU 3 - CanTpConfig_CanTpChannel_3_RxOnly_Pdu_DcmIPdu_GST_Msg_TP_Func_CanTpRxNSdu_3_Pdu_DcmIPdu_GST_Msg_TP_Func_3 */
  {
    /* ddUpTargetPduId */
    0x0003,

    /* ddLoTxFcTargetPduId */
    0x00FF,

    /* usNarTimeoutValue */
    0x00C8,

    /* usNbrTimeoutValue */
    0x0000,

    /* usNcrTimeoutValue */
    0x00C8,

    /* usRxWftMax */
    0x0000
  }
};

#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

CONST(CanTp_ChannelType, CANTP_CONST) CanTp_GaaRxSduMap[] =
{
  /* Index 0 */
  0x01,

  /* Index 1 */
  0x02,

  /* Index 2 */
  0x03
};

#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

CONST(CanTp_RxNsduStatic, CANTP_CONST) CanTp_GaaRxSduStatic[] =
{
  /* RxNSDU 0 - CanTpConfig_CanTpChannel_0_Pdu_ISignalIPdu_GST_Msg_TP1_CanTpRxNSdu_0_Pdu_ISignalIPdu_GST_Msg_TP1 */
  {
    /* ddChannelId */
    1,

    /* usRxSduLength */
    0x0001,

    /* ucTaType */
    0x00,

    /* blRxPaddingActivation */
    CANTP_TRUE
  },

  /* RxNSDU 1 - CanTpConfig_CanTpChannel_1_Pdu_ISignalIPdu_GST_Msg_TP2_CanTpRxNSdu_1_Pdu_ISignalIPdu_GST_Msg_TP2 */
  {
    /* ddChannelId */
    2,

    /* usRxSduLength */
    0x0001,

    /* ucTaType */
    0x00,

    /* blRxPaddingActivation */
    CANTP_TRUE
  },

  /* RxNSDU 2 - CanTpConfig_CanTpChannel_2_Pdu_DcmIPdu_GST_Msg_TP_Phys_CanTpRxNSdu_2_Pdu_DcmIPdu_GST_Msg_TP_Phys */
  {
    /* ddChannelId */
    3,

    /* usRxSduLength */
    0x0001,

    /* ucTaType */
    0x00,

    /* blRxPaddingActivation */
    CANTP_TRUE
  },

  /* RxNSDU 3 - CanTpConfig_CanTpChannel_3_RxOnly_Pdu_DcmIPdu_GST_Msg_TP_Func_CanTpRxNSdu_3_Pdu_DcmIPdu_GST_Msg_TP_Func */
  {
    /* ddChannelId */
    0,

    /* usRxSduLength */
    0x0001,

    /* ucTaType */
    0x01,

    /* blRxPaddingActivation */
    CANTP_TRUE
  }
};

#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define CANTP_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

VAR(CanTp_STminBs, CANTP_VAR) CanTp_GaaSTminBs[] =
{
  /* RxNSduRam 0 - CanTpConfig_CanTpChannel_0_Pdu_ISignalIPdu_GST_Msg_TP1_CanTpRxNSdu_0_Pdu_ISignalIPdu_GST_Msg_TP1 */
  {
    /* ucBlockSize */
    0xFF,

    /* ucSTMin */
    0x05
  },

  /* RxNSduRam 1 - CanTpConfig_CanTpChannel_1_Pdu_ISignalIPdu_GST_Msg_TP2_CanTpRxNSdu_1_Pdu_ISignalIPdu_GST_Msg_TP2 */
  {
    /* ucBlockSize */
    0xFF,

    /* ucSTMin */
    0x05
  },

  /* RxNSduRam 2 - CanTpConfig_CanTpChannel_2_Pdu_DcmIPdu_GST_Msg_TP_Phys_CanTpRxNSdu_2_Pdu_DcmIPdu_GST_Msg_TP_Phys */
  {
    /* ucBlockSize */
    0xFF,

    /* ucSTMin */
    0x05
  },

  /* RxNSduRam 3 - CanTpConfig_CanTpChannel_3_RxOnly_Pdu_DcmIPdu_GST_Msg_TP_Func_CanTpRxNSdu_3_Pdu_DcmIPdu_GST_Msg_TP_Func */
  {
    /* ucBlockSize */
    0xFF,

    /* ucSTMin */
    0x05
  }
};

#define CANTP_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
CONST(uint8, CANTP_CONST) CanTp_GaaSTminMapping[10] =
{
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

CONST(CanTp_TxNSduDynamic, CANTP_CONST) CanTp_GaaTxSduDynamic[] =
{
  /* TxNSDU 0 - CanTpConfig_CanTpChannel_0_Pdu_ISignalIPdu_GST_Msg_TP1_CanTpTxNSdu_0_Pdu_ISignalIPdu_ECU1_Msg_TP1_0 */
  {
    /* ddUpConfirmationSduId */
    0x0002,

    /* ddLoTargetPduId */
    0x000C,

    /* usNasTimeoutValue */
    0x00C8,

    /* usNbsTimeoutValue */
    0x00C8,

    /* usNcsTimeoutValue */
    0x0000
  },

  /* TxNSDU 1 - CanTpConfig_CanTpChannel_1_Pdu_ISignalIPdu_GST_Msg_TP2_CanTpTxNSdu_1_Pdu_ISignalIPdu_ECU1_Msg_TP2_1 */
  {
    /* ddUpConfirmationSduId */
    0x0001,

    /* ddLoTargetPduId */
    0x000D,

    /* usNasTimeoutValue */
    0x00C8,

    /* usNbsTimeoutValue */
    0x00C8,

    /* usNcsTimeoutValue */
    0x0000
  },

  /* TxNSDU 2 - CanTpConfig_CanTpChannel_2_Pdu_DcmIPdu_GST_Msg_TP_Phys_CanTpTxNSdu_2_Pdu_DcmIPdu_ECU1_GST_Msg_TP_2 */
  {
    /* ddUpConfirmationSduId */
    0x0000,

    /* ddLoTargetPduId */
    0x000E,

    /* usNasTimeoutValue */
    0x00C8,

    /* usNbsTimeoutValue */
    0x00C8,

    /* usNcsTimeoutValue */
    0x0000
  }
};

#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

CONST(CanTp_TxNsduStatic, CANTP_CONST) CanTp_GaaTxSduStatic[] =
{
  /* TxNSDU 0 - CanTpConfig_CanTpChannel_0_Pdu_ISignalIPdu_GST_Msg_TP1_CanTpTxNSdu_0_Pdu_ISignalIPdu_ECU1_Msg_TP1 */
  {
    /* ddChannelId */
    1,

    /* usTxSduLength */
    0x0001,

    /* blTxPaddingActivation */
    CANTP_TRUE
  },

  /* TxNSDU 1 - CanTpConfig_CanTpChannel_1_Pdu_ISignalIPdu_GST_Msg_TP2_CanTpTxNSdu_1_Pdu_ISignalIPdu_ECU1_Msg_TP2 */
  {
    /* ddChannelId */
    2,

    /* usTxSduLength */
    0x0001,

    /* blTxPaddingActivation */
    CANTP_TRUE
  },

  /* TxNSDU 2 - CanTpConfig_CanTpChannel_2_Pdu_DcmIPdu_GST_Msg_TP_Phys_CanTpTxNSdu_2_Pdu_DcmIPdu_ECU1_GST_Msg_TP */
  {
    /* ddChannelId */
    3,

    /* usTxSduLength */
    0x0001,

    /* blTxPaddingActivation */
    CANTP_TRUE
  }
};

#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"



/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/