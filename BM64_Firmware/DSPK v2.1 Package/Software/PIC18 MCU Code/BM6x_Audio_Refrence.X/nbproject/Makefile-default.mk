#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/BM6x_Audio_Refrence.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/BM6x_Audio_Refrence.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=sha1.c mcc/eusart.c mcc/i2c.c mcc/interrupt_manager.c mcc/mcc.c mcc/pin_manager.c mcc/tmr0.c mcc/tmr1.c bt_command_decode.c bt_command_send.c main.c timer.c bt_app.c yda174dsp_handler.c key.c key_handler.c line_in.c ble.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/sha1.p1 ${OBJECTDIR}/mcc/eusart.p1 ${OBJECTDIR}/mcc/i2c.p1 ${OBJECTDIR}/mcc/interrupt_manager.p1 ${OBJECTDIR}/mcc/mcc.p1 ${OBJECTDIR}/mcc/pin_manager.p1 ${OBJECTDIR}/mcc/tmr0.p1 ${OBJECTDIR}/mcc/tmr1.p1 ${OBJECTDIR}/bt_command_decode.p1 ${OBJECTDIR}/bt_command_send.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/timer.p1 ${OBJECTDIR}/bt_app.p1 ${OBJECTDIR}/yda174dsp_handler.p1 ${OBJECTDIR}/key.p1 ${OBJECTDIR}/key_handler.p1 ${OBJECTDIR}/line_in.p1 ${OBJECTDIR}/ble.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/sha1.p1.d ${OBJECTDIR}/mcc/eusart.p1.d ${OBJECTDIR}/mcc/i2c.p1.d ${OBJECTDIR}/mcc/interrupt_manager.p1.d ${OBJECTDIR}/mcc/mcc.p1.d ${OBJECTDIR}/mcc/pin_manager.p1.d ${OBJECTDIR}/mcc/tmr0.p1.d ${OBJECTDIR}/mcc/tmr1.p1.d ${OBJECTDIR}/bt_command_decode.p1.d ${OBJECTDIR}/bt_command_send.p1.d ${OBJECTDIR}/main.p1.d ${OBJECTDIR}/timer.p1.d ${OBJECTDIR}/bt_app.p1.d ${OBJECTDIR}/yda174dsp_handler.p1.d ${OBJECTDIR}/key.p1.d ${OBJECTDIR}/key_handler.p1.d ${OBJECTDIR}/line_in.p1.d ${OBJECTDIR}/ble.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/sha1.p1 ${OBJECTDIR}/mcc/eusart.p1 ${OBJECTDIR}/mcc/i2c.p1 ${OBJECTDIR}/mcc/interrupt_manager.p1 ${OBJECTDIR}/mcc/mcc.p1 ${OBJECTDIR}/mcc/pin_manager.p1 ${OBJECTDIR}/mcc/tmr0.p1 ${OBJECTDIR}/mcc/tmr1.p1 ${OBJECTDIR}/bt_command_decode.p1 ${OBJECTDIR}/bt_command_send.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/timer.p1 ${OBJECTDIR}/bt_app.p1 ${OBJECTDIR}/yda174dsp_handler.p1 ${OBJECTDIR}/key.p1 ${OBJECTDIR}/key_handler.p1 ${OBJECTDIR}/line_in.p1 ${OBJECTDIR}/ble.p1

# Source Files
SOURCEFILES=sha1.c mcc/eusart.c mcc/i2c.c mcc/interrupt_manager.c mcc/mcc.c mcc/pin_manager.c mcc/tmr0.c mcc/tmr1.c bt_command_decode.c bt_command_send.c main.c timer.c bt_app.c yda174dsp_handler.c key.c key_handler.c line_in.c ble.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/BM6x_Audio_Refrence.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F85J10
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/sha1.p1: sha1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sha1.p1.d 
	@${RM} ${OBJECTDIR}/sha1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/sha1.p1  sha1.c 
	@-${MV} ${OBJECTDIR}/sha1.d ${OBJECTDIR}/sha1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/sha1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc/eusart.p1: mcc/eusart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc" 
	@${RM} ${OBJECTDIR}/mcc/eusart.p1.d 
	@${RM} ${OBJECTDIR}/mcc/eusart.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc/eusart.p1  mcc/eusart.c 
	@-${MV} ${OBJECTDIR}/mcc/eusart.d ${OBJECTDIR}/mcc/eusart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc/eusart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc/i2c.p1: mcc/i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc" 
	@${RM} ${OBJECTDIR}/mcc/i2c.p1.d 
	@${RM} ${OBJECTDIR}/mcc/i2c.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc/i2c.p1  mcc/i2c.c 
	@-${MV} ${OBJECTDIR}/mcc/i2c.d ${OBJECTDIR}/mcc/i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc/i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc/interrupt_manager.p1: mcc/interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc" 
	@${RM} ${OBJECTDIR}/mcc/interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/mcc/interrupt_manager.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc/interrupt_manager.p1  mcc/interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/mcc/interrupt_manager.d ${OBJECTDIR}/mcc/interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc/interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc/mcc.p1: mcc/mcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc" 
	@${RM} ${OBJECTDIR}/mcc/mcc.p1.d 
	@${RM} ${OBJECTDIR}/mcc/mcc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc/mcc.p1  mcc/mcc.c 
	@-${MV} ${OBJECTDIR}/mcc/mcc.d ${OBJECTDIR}/mcc/mcc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc/mcc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc/pin_manager.p1: mcc/pin_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc" 
	@${RM} ${OBJECTDIR}/mcc/pin_manager.p1.d 
	@${RM} ${OBJECTDIR}/mcc/pin_manager.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc/pin_manager.p1  mcc/pin_manager.c 
	@-${MV} ${OBJECTDIR}/mcc/pin_manager.d ${OBJECTDIR}/mcc/pin_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc/pin_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc/tmr0.p1: mcc/tmr0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc" 
	@${RM} ${OBJECTDIR}/mcc/tmr0.p1.d 
	@${RM} ${OBJECTDIR}/mcc/tmr0.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc/tmr0.p1  mcc/tmr0.c 
	@-${MV} ${OBJECTDIR}/mcc/tmr0.d ${OBJECTDIR}/mcc/tmr0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc/tmr0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc/tmr1.p1: mcc/tmr1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc" 
	@${RM} ${OBJECTDIR}/mcc/tmr1.p1.d 
	@${RM} ${OBJECTDIR}/mcc/tmr1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc/tmr1.p1  mcc/tmr1.c 
	@-${MV} ${OBJECTDIR}/mcc/tmr1.d ${OBJECTDIR}/mcc/tmr1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc/tmr1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/bt_command_decode.p1: bt_command_decode.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/bt_command_decode.p1.d 
	@${RM} ${OBJECTDIR}/bt_command_decode.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/bt_command_decode.p1  bt_command_decode.c 
	@-${MV} ${OBJECTDIR}/bt_command_decode.d ${OBJECTDIR}/bt_command_decode.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/bt_command_decode.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/bt_command_send.p1: bt_command_send.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/bt_command_send.p1.d 
	@${RM} ${OBJECTDIR}/bt_command_send.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/bt_command_send.p1  bt_command_send.c 
	@-${MV} ${OBJECTDIR}/bt_command_send.d ${OBJECTDIR}/bt_command_send.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/bt_command_send.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/main.p1  main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/timer.p1: timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer.p1.d 
	@${RM} ${OBJECTDIR}/timer.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/timer.p1  timer.c 
	@-${MV} ${OBJECTDIR}/timer.d ${OBJECTDIR}/timer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/timer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/bt_app.p1: bt_app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/bt_app.p1.d 
	@${RM} ${OBJECTDIR}/bt_app.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/bt_app.p1  bt_app.c 
	@-${MV} ${OBJECTDIR}/bt_app.d ${OBJECTDIR}/bt_app.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/bt_app.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/yda174dsp_handler.p1: yda174dsp_handler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/yda174dsp_handler.p1.d 
	@${RM} ${OBJECTDIR}/yda174dsp_handler.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/yda174dsp_handler.p1  yda174dsp_handler.c 
	@-${MV} ${OBJECTDIR}/yda174dsp_handler.d ${OBJECTDIR}/yda174dsp_handler.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/yda174dsp_handler.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/key.p1: key.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/key.p1.d 
	@${RM} ${OBJECTDIR}/key.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/key.p1  key.c 
	@-${MV} ${OBJECTDIR}/key.d ${OBJECTDIR}/key.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/key.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/key_handler.p1: key_handler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/key_handler.p1.d 
	@${RM} ${OBJECTDIR}/key_handler.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/key_handler.p1  key_handler.c 
	@-${MV} ${OBJECTDIR}/key_handler.d ${OBJECTDIR}/key_handler.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/key_handler.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/line_in.p1: line_in.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/line_in.p1.d 
	@${RM} ${OBJECTDIR}/line_in.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/line_in.p1  line_in.c 
	@-${MV} ${OBJECTDIR}/line_in.d ${OBJECTDIR}/line_in.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/line_in.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ble.p1: ble.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ble.p1.d 
	@${RM} ${OBJECTDIR}/ble.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ble.p1  ble.c 
	@-${MV} ${OBJECTDIR}/ble.d ${OBJECTDIR}/ble.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ble.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/sha1.p1: sha1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sha1.p1.d 
	@${RM} ${OBJECTDIR}/sha1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/sha1.p1  sha1.c 
	@-${MV} ${OBJECTDIR}/sha1.d ${OBJECTDIR}/sha1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/sha1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc/eusart.p1: mcc/eusart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc" 
	@${RM} ${OBJECTDIR}/mcc/eusart.p1.d 
	@${RM} ${OBJECTDIR}/mcc/eusart.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc/eusart.p1  mcc/eusart.c 
	@-${MV} ${OBJECTDIR}/mcc/eusart.d ${OBJECTDIR}/mcc/eusart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc/eusart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc/i2c.p1: mcc/i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc" 
	@${RM} ${OBJECTDIR}/mcc/i2c.p1.d 
	@${RM} ${OBJECTDIR}/mcc/i2c.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc/i2c.p1  mcc/i2c.c 
	@-${MV} ${OBJECTDIR}/mcc/i2c.d ${OBJECTDIR}/mcc/i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc/i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc/interrupt_manager.p1: mcc/interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc" 
	@${RM} ${OBJECTDIR}/mcc/interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/mcc/interrupt_manager.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc/interrupt_manager.p1  mcc/interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/mcc/interrupt_manager.d ${OBJECTDIR}/mcc/interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc/interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc/mcc.p1: mcc/mcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc" 
	@${RM} ${OBJECTDIR}/mcc/mcc.p1.d 
	@${RM} ${OBJECTDIR}/mcc/mcc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc/mcc.p1  mcc/mcc.c 
	@-${MV} ${OBJECTDIR}/mcc/mcc.d ${OBJECTDIR}/mcc/mcc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc/mcc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc/pin_manager.p1: mcc/pin_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc" 
	@${RM} ${OBJECTDIR}/mcc/pin_manager.p1.d 
	@${RM} ${OBJECTDIR}/mcc/pin_manager.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc/pin_manager.p1  mcc/pin_manager.c 
	@-${MV} ${OBJECTDIR}/mcc/pin_manager.d ${OBJECTDIR}/mcc/pin_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc/pin_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc/tmr0.p1: mcc/tmr0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc" 
	@${RM} ${OBJECTDIR}/mcc/tmr0.p1.d 
	@${RM} ${OBJECTDIR}/mcc/tmr0.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc/tmr0.p1  mcc/tmr0.c 
	@-${MV} ${OBJECTDIR}/mcc/tmr0.d ${OBJECTDIR}/mcc/tmr0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc/tmr0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc/tmr1.p1: mcc/tmr1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc" 
	@${RM} ${OBJECTDIR}/mcc/tmr1.p1.d 
	@${RM} ${OBJECTDIR}/mcc/tmr1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/mcc/tmr1.p1  mcc/tmr1.c 
	@-${MV} ${OBJECTDIR}/mcc/tmr1.d ${OBJECTDIR}/mcc/tmr1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc/tmr1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/bt_command_decode.p1: bt_command_decode.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/bt_command_decode.p1.d 
	@${RM} ${OBJECTDIR}/bt_command_decode.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/bt_command_decode.p1  bt_command_decode.c 
	@-${MV} ${OBJECTDIR}/bt_command_decode.d ${OBJECTDIR}/bt_command_decode.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/bt_command_decode.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/bt_command_send.p1: bt_command_send.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/bt_command_send.p1.d 
	@${RM} ${OBJECTDIR}/bt_command_send.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/bt_command_send.p1  bt_command_send.c 
	@-${MV} ${OBJECTDIR}/bt_command_send.d ${OBJECTDIR}/bt_command_send.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/bt_command_send.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/main.p1  main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/timer.p1: timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer.p1.d 
	@${RM} ${OBJECTDIR}/timer.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/timer.p1  timer.c 
	@-${MV} ${OBJECTDIR}/timer.d ${OBJECTDIR}/timer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/timer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/bt_app.p1: bt_app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/bt_app.p1.d 
	@${RM} ${OBJECTDIR}/bt_app.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/bt_app.p1  bt_app.c 
	@-${MV} ${OBJECTDIR}/bt_app.d ${OBJECTDIR}/bt_app.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/bt_app.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/yda174dsp_handler.p1: yda174dsp_handler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/yda174dsp_handler.p1.d 
	@${RM} ${OBJECTDIR}/yda174dsp_handler.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/yda174dsp_handler.p1  yda174dsp_handler.c 
	@-${MV} ${OBJECTDIR}/yda174dsp_handler.d ${OBJECTDIR}/yda174dsp_handler.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/yda174dsp_handler.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/key.p1: key.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/key.p1.d 
	@${RM} ${OBJECTDIR}/key.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/key.p1  key.c 
	@-${MV} ${OBJECTDIR}/key.d ${OBJECTDIR}/key.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/key.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/key_handler.p1: key_handler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/key_handler.p1.d 
	@${RM} ${OBJECTDIR}/key_handler.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/key_handler.p1  key_handler.c 
	@-${MV} ${OBJECTDIR}/key_handler.d ${OBJECTDIR}/key_handler.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/key_handler.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/line_in.p1: line_in.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/line_in.p1.d 
	@${RM} ${OBJECTDIR}/line_in.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/line_in.p1  line_in.c 
	@-${MV} ${OBJECTDIR}/line_in.d ${OBJECTDIR}/line_in.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/line_in.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ble.p1: ble.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ble.p1.d 
	@${RM} ${OBJECTDIR}/ble.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/ble.p1  ble.c 
	@-${MV} ${OBJECTDIR}/ble.d ${OBJECTDIR}/ble.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ble.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/BM6x_Audio_Refrence.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/BM6x_Audio_Refrence.X.${IMAGE_TYPE}.map  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"       --memorysummary dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -odist/${CND_CONF}/${IMAGE_TYPE}/BM6x_Audio_Refrence.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/BM6x_Audio_Refrence.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/BM6x_Audio_Refrence.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/BM6x_Audio_Refrence.X.${IMAGE_TYPE}.map  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DCRYPTO_HASH_CONFIG_SHA_SMALL_RAM -DACK_TO_EVENT -DDATABASE2_TEST -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    --memorysummary dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -odist/${CND_CONF}/${IMAGE_TYPE}/BM6x_Audio_Refrence.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
