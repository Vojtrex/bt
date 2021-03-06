# coding: utf-8
##############################################################################
# Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
#
# Subject to your compliance with these terms, you may use Microchip software
# and any derivatives exclusively with Microchip products. It is your
# responsibility to comply with third party license terms applicable to your
# use of third party software (including open source software) that may
# accompany Microchip software.
#
# THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
# EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
# WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
# PARTICULAR PURPOSE.
#
# IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
# INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
# WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
# BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
# FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
# ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
# THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
##############################################################################

samd21xproComponentIDList = ["sercom4", "sys_time", "tc3"]		
samd21xproAutoConnectList = [["bluetooth_bm71", "USART PLIB", "sercom4", "SERCOM4_UART"],
                          ["sys_time", "sys_time_TMR_dependency", "tc3", "TC3_TMR"]]
samd21xproPinConfigs = [{"pin": 11, "name": "SERCOM4_PAD0", "type": "SERCOM4_PAD0", "direction": "", "latch": "", "abcd": "D"},     # PB08
                        {"pin": 12, "name": "SERCOM4_PAD1", "type": "SERCOM4_PAD1", "direction": "", "latch": "", "abcd": "D"},     # PB09
                        {"pin": 6,  "name": "BM71_RX_IND", "type": "GPIO", "direction": "Out", "latch": "High", "abcd": ""},        # PB05
                        {"pin": 62, "name": "STBYRST", "type": "GPIO", "direction": "Out", "latch": "High", "abcd": ""}]            # PB01 

sam_d21_xplained_pro = bspSupportObj(samd21xproPinConfigs, samd21xproComponentIDList, None, samd21xproAutoConnectList, None)					

addBSPSupport("BSP_SAM_D21_Xplained_Pro", "D21_XPLAINED_PRO", sam_d21_xplained_pro)