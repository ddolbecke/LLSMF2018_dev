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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=drivers/acl.c drivers/analogInputs.c drivers/ChrFont0.c drivers/ClpLib.c drivers/databk.c drivers/delay.c drivers/FillPat.c drivers/interrupts.c drivers/motors.c drivers/mx4.c drivers/OledChar.c drivers/OledGrph.c drivers/Pmod8leds.c drivers/PmodBTN.c drivers/PmodCLP.c drivers/PmodMAXSONAR.c drivers/PmodOLED.c drivers/PmodSSD.c drivers/PmodTMP3.c drivers/servo.c drivers/PmodLS1.c drivers/PmodIR_Range.c drivers/PmodJSTK.c drivers/PmodBuzzer.c drivers/PmodKYPD.c drivers/uart.c sources/main.c drivers/PmodMIC3.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/drivers/acl.o ${OBJECTDIR}/drivers/analogInputs.o ${OBJECTDIR}/drivers/ChrFont0.o ${OBJECTDIR}/drivers/ClpLib.o ${OBJECTDIR}/drivers/databk.o ${OBJECTDIR}/drivers/delay.o ${OBJECTDIR}/drivers/FillPat.o ${OBJECTDIR}/drivers/interrupts.o ${OBJECTDIR}/drivers/motors.o ${OBJECTDIR}/drivers/mx4.o ${OBJECTDIR}/drivers/OledChar.o ${OBJECTDIR}/drivers/OledGrph.o ${OBJECTDIR}/drivers/Pmod8leds.o ${OBJECTDIR}/drivers/PmodBTN.o ${OBJECTDIR}/drivers/PmodCLP.o ${OBJECTDIR}/drivers/PmodMAXSONAR.o ${OBJECTDIR}/drivers/PmodOLED.o ${OBJECTDIR}/drivers/PmodSSD.o ${OBJECTDIR}/drivers/PmodTMP3.o ${OBJECTDIR}/drivers/servo.o ${OBJECTDIR}/drivers/PmodLS1.o ${OBJECTDIR}/drivers/PmodIR_Range.o ${OBJECTDIR}/drivers/PmodJSTK.o ${OBJECTDIR}/drivers/PmodBuzzer.o ${OBJECTDIR}/drivers/PmodKYPD.o ${OBJECTDIR}/drivers/uart.o ${OBJECTDIR}/sources/main.o ${OBJECTDIR}/drivers/PmodMIC3.o
POSSIBLE_DEPFILES=${OBJECTDIR}/drivers/acl.o.d ${OBJECTDIR}/drivers/analogInputs.o.d ${OBJECTDIR}/drivers/ChrFont0.o.d ${OBJECTDIR}/drivers/ClpLib.o.d ${OBJECTDIR}/drivers/databk.o.d ${OBJECTDIR}/drivers/delay.o.d ${OBJECTDIR}/drivers/FillPat.o.d ${OBJECTDIR}/drivers/interrupts.o.d ${OBJECTDIR}/drivers/motors.o.d ${OBJECTDIR}/drivers/mx4.o.d ${OBJECTDIR}/drivers/OledChar.o.d ${OBJECTDIR}/drivers/OledGrph.o.d ${OBJECTDIR}/drivers/Pmod8leds.o.d ${OBJECTDIR}/drivers/PmodBTN.o.d ${OBJECTDIR}/drivers/PmodCLP.o.d ${OBJECTDIR}/drivers/PmodMAXSONAR.o.d ${OBJECTDIR}/drivers/PmodOLED.o.d ${OBJECTDIR}/drivers/PmodSSD.o.d ${OBJECTDIR}/drivers/PmodTMP3.o.d ${OBJECTDIR}/drivers/servo.o.d ${OBJECTDIR}/drivers/PmodLS1.o.d ${OBJECTDIR}/drivers/PmodIR_Range.o.d ${OBJECTDIR}/drivers/PmodJSTK.o.d ${OBJECTDIR}/drivers/PmodBuzzer.o.d ${OBJECTDIR}/drivers/PmodKYPD.o.d ${OBJECTDIR}/drivers/uart.o.d ${OBJECTDIR}/sources/main.o.d ${OBJECTDIR}/drivers/PmodMIC3.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/drivers/acl.o ${OBJECTDIR}/drivers/analogInputs.o ${OBJECTDIR}/drivers/ChrFont0.o ${OBJECTDIR}/drivers/ClpLib.o ${OBJECTDIR}/drivers/databk.o ${OBJECTDIR}/drivers/delay.o ${OBJECTDIR}/drivers/FillPat.o ${OBJECTDIR}/drivers/interrupts.o ${OBJECTDIR}/drivers/motors.o ${OBJECTDIR}/drivers/mx4.o ${OBJECTDIR}/drivers/OledChar.o ${OBJECTDIR}/drivers/OledGrph.o ${OBJECTDIR}/drivers/Pmod8leds.o ${OBJECTDIR}/drivers/PmodBTN.o ${OBJECTDIR}/drivers/PmodCLP.o ${OBJECTDIR}/drivers/PmodMAXSONAR.o ${OBJECTDIR}/drivers/PmodOLED.o ${OBJECTDIR}/drivers/PmodSSD.o ${OBJECTDIR}/drivers/PmodTMP3.o ${OBJECTDIR}/drivers/servo.o ${OBJECTDIR}/drivers/PmodLS1.o ${OBJECTDIR}/drivers/PmodIR_Range.o ${OBJECTDIR}/drivers/PmodJSTK.o ${OBJECTDIR}/drivers/PmodBuzzer.o ${OBJECTDIR}/drivers/PmodKYPD.o ${OBJECTDIR}/drivers/uart.o ${OBJECTDIR}/sources/main.o ${OBJECTDIR}/drivers/PmodMIC3.o

# Source Files
SOURCEFILES=drivers/acl.c drivers/analogInputs.c drivers/ChrFont0.c drivers/ClpLib.c drivers/databk.c drivers/delay.c drivers/FillPat.c drivers/interrupts.c drivers/motors.c drivers/mx4.c drivers/OledChar.c drivers/OledGrph.c drivers/Pmod8leds.c drivers/PmodBTN.c drivers/PmodCLP.c drivers/PmodMAXSONAR.c drivers/PmodOLED.c drivers/PmodSSD.c drivers/PmodTMP3.c drivers/servo.c drivers/PmodLS1.c drivers/PmodIR_Range.c drivers/PmodJSTK.c drivers/PmodBuzzer.c drivers/PmodKYPD.c drivers/uart.c sources/main.c drivers/PmodMIC3.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX460F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/drivers/acl.o: drivers/acl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/acl.o.d 
	@${RM} ${OBJECTDIR}/drivers/acl.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/acl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/acl.o.d" -o ${OBJECTDIR}/drivers/acl.o drivers/acl.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/analogInputs.o: drivers/analogInputs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/analogInputs.o.d 
	@${RM} ${OBJECTDIR}/drivers/analogInputs.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/analogInputs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/analogInputs.o.d" -o ${OBJECTDIR}/drivers/analogInputs.o drivers/analogInputs.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/ChrFont0.o: drivers/ChrFont0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/ChrFont0.o.d 
	@${RM} ${OBJECTDIR}/drivers/ChrFont0.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/ChrFont0.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/ChrFont0.o.d" -o ${OBJECTDIR}/drivers/ChrFont0.o drivers/ChrFont0.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/ClpLib.o: drivers/ClpLib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/ClpLib.o.d 
	@${RM} ${OBJECTDIR}/drivers/ClpLib.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/ClpLib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/ClpLib.o.d" -o ${OBJECTDIR}/drivers/ClpLib.o drivers/ClpLib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/databk.o: drivers/databk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/databk.o.d 
	@${RM} ${OBJECTDIR}/drivers/databk.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/databk.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/databk.o.d" -o ${OBJECTDIR}/drivers/databk.o drivers/databk.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/delay.o: drivers/delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/delay.o.d 
	@${RM} ${OBJECTDIR}/drivers/delay.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/delay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/delay.o.d" -o ${OBJECTDIR}/drivers/delay.o drivers/delay.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/FillPat.o: drivers/FillPat.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/FillPat.o.d 
	@${RM} ${OBJECTDIR}/drivers/FillPat.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/FillPat.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/FillPat.o.d" -o ${OBJECTDIR}/drivers/FillPat.o drivers/FillPat.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/interrupts.o: drivers/interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/interrupts.o.d 
	@${RM} ${OBJECTDIR}/drivers/interrupts.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/interrupts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/interrupts.o.d" -o ${OBJECTDIR}/drivers/interrupts.o drivers/interrupts.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/motors.o: drivers/motors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/motors.o.d 
	@${RM} ${OBJECTDIR}/drivers/motors.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/motors.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/motors.o.d" -o ${OBJECTDIR}/drivers/motors.o drivers/motors.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/mx4.o: drivers/mx4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/mx4.o.d 
	@${RM} ${OBJECTDIR}/drivers/mx4.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mx4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/mx4.o.d" -o ${OBJECTDIR}/drivers/mx4.o drivers/mx4.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/OledChar.o: drivers/OledChar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/OledChar.o.d 
	@${RM} ${OBJECTDIR}/drivers/OledChar.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/OledChar.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/OledChar.o.d" -o ${OBJECTDIR}/drivers/OledChar.o drivers/OledChar.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/OledGrph.o: drivers/OledGrph.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/OledGrph.o.d 
	@${RM} ${OBJECTDIR}/drivers/OledGrph.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/OledGrph.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/OledGrph.o.d" -o ${OBJECTDIR}/drivers/OledGrph.o drivers/OledGrph.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/Pmod8leds.o: drivers/Pmod8leds.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/Pmod8leds.o.d 
	@${RM} ${OBJECTDIR}/drivers/Pmod8leds.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/Pmod8leds.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/Pmod8leds.o.d" -o ${OBJECTDIR}/drivers/Pmod8leds.o drivers/Pmod8leds.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodBTN.o: drivers/PmodBTN.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodBTN.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodBTN.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodBTN.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodBTN.o.d" -o ${OBJECTDIR}/drivers/PmodBTN.o drivers/PmodBTN.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodCLP.o: drivers/PmodCLP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodCLP.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodCLP.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodCLP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodCLP.o.d" -o ${OBJECTDIR}/drivers/PmodCLP.o drivers/PmodCLP.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodMAXSONAR.o: drivers/PmodMAXSONAR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodMAXSONAR.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodMAXSONAR.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodMAXSONAR.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodMAXSONAR.o.d" -o ${OBJECTDIR}/drivers/PmodMAXSONAR.o drivers/PmodMAXSONAR.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodOLED.o: drivers/PmodOLED.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodOLED.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodOLED.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodOLED.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodOLED.o.d" -o ${OBJECTDIR}/drivers/PmodOLED.o drivers/PmodOLED.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodSSD.o: drivers/PmodSSD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodSSD.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodSSD.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodSSD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodSSD.o.d" -o ${OBJECTDIR}/drivers/PmodSSD.o drivers/PmodSSD.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodTMP3.o: drivers/PmodTMP3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodTMP3.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodTMP3.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodTMP3.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodTMP3.o.d" -o ${OBJECTDIR}/drivers/PmodTMP3.o drivers/PmodTMP3.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/servo.o: drivers/servo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/servo.o.d 
	@${RM} ${OBJECTDIR}/drivers/servo.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/servo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/servo.o.d" -o ${OBJECTDIR}/drivers/servo.o drivers/servo.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodLS1.o: drivers/PmodLS1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodLS1.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodLS1.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodLS1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodLS1.o.d" -o ${OBJECTDIR}/drivers/PmodLS1.o drivers/PmodLS1.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodIR_Range.o: drivers/PmodIR_Range.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodIR_Range.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodIR_Range.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodIR_Range.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodIR_Range.o.d" -o ${OBJECTDIR}/drivers/PmodIR_Range.o drivers/PmodIR_Range.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodJSTK.o: drivers/PmodJSTK.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodJSTK.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodJSTK.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodJSTK.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodJSTK.o.d" -o ${OBJECTDIR}/drivers/PmodJSTK.o drivers/PmodJSTK.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodBuzzer.o: drivers/PmodBuzzer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodBuzzer.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodBuzzer.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodBuzzer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodBuzzer.o.d" -o ${OBJECTDIR}/drivers/PmodBuzzer.o drivers/PmodBuzzer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodKYPD.o: drivers/PmodKYPD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodKYPD.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodKYPD.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodKYPD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodKYPD.o.d" -o ${OBJECTDIR}/drivers/PmodKYPD.o drivers/PmodKYPD.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/uart.o: drivers/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/uart.o.d 
	@${RM} ${OBJECTDIR}/drivers/uart.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/uart.o.d" -o ${OBJECTDIR}/drivers/uart.o drivers/uart.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sources/main.o: sources/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sources" 
	@${RM} ${OBJECTDIR}/sources/main.o.d 
	@${RM} ${OBJECTDIR}/sources/main.o 
	@${FIXDEPS} "${OBJECTDIR}/sources/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/sources/main.o.d" -o ${OBJECTDIR}/sources/main.o sources/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodMIC3.o: drivers/PmodMIC3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodMIC3.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodMIC3.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodMIC3.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodMIC3.o.d" -o ${OBJECTDIR}/drivers/PmodMIC3.o drivers/PmodMIC3.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/drivers/acl.o: drivers/acl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/acl.o.d 
	@${RM} ${OBJECTDIR}/drivers/acl.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/acl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/acl.o.d" -o ${OBJECTDIR}/drivers/acl.o drivers/acl.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/analogInputs.o: drivers/analogInputs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/analogInputs.o.d 
	@${RM} ${OBJECTDIR}/drivers/analogInputs.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/analogInputs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/analogInputs.o.d" -o ${OBJECTDIR}/drivers/analogInputs.o drivers/analogInputs.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/ChrFont0.o: drivers/ChrFont0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/ChrFont0.o.d 
	@${RM} ${OBJECTDIR}/drivers/ChrFont0.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/ChrFont0.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/ChrFont0.o.d" -o ${OBJECTDIR}/drivers/ChrFont0.o drivers/ChrFont0.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/ClpLib.o: drivers/ClpLib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/ClpLib.o.d 
	@${RM} ${OBJECTDIR}/drivers/ClpLib.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/ClpLib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/ClpLib.o.d" -o ${OBJECTDIR}/drivers/ClpLib.o drivers/ClpLib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/databk.o: drivers/databk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/databk.o.d 
	@${RM} ${OBJECTDIR}/drivers/databk.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/databk.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/databk.o.d" -o ${OBJECTDIR}/drivers/databk.o drivers/databk.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/delay.o: drivers/delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/delay.o.d 
	@${RM} ${OBJECTDIR}/drivers/delay.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/delay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/delay.o.d" -o ${OBJECTDIR}/drivers/delay.o drivers/delay.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/FillPat.o: drivers/FillPat.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/FillPat.o.d 
	@${RM} ${OBJECTDIR}/drivers/FillPat.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/FillPat.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/FillPat.o.d" -o ${OBJECTDIR}/drivers/FillPat.o drivers/FillPat.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/interrupts.o: drivers/interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/interrupts.o.d 
	@${RM} ${OBJECTDIR}/drivers/interrupts.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/interrupts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/interrupts.o.d" -o ${OBJECTDIR}/drivers/interrupts.o drivers/interrupts.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/motors.o: drivers/motors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/motors.o.d 
	@${RM} ${OBJECTDIR}/drivers/motors.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/motors.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/motors.o.d" -o ${OBJECTDIR}/drivers/motors.o drivers/motors.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/mx4.o: drivers/mx4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/mx4.o.d 
	@${RM} ${OBJECTDIR}/drivers/mx4.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mx4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/mx4.o.d" -o ${OBJECTDIR}/drivers/mx4.o drivers/mx4.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/OledChar.o: drivers/OledChar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/OledChar.o.d 
	@${RM} ${OBJECTDIR}/drivers/OledChar.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/OledChar.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/OledChar.o.d" -o ${OBJECTDIR}/drivers/OledChar.o drivers/OledChar.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/OledGrph.o: drivers/OledGrph.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/OledGrph.o.d 
	@${RM} ${OBJECTDIR}/drivers/OledGrph.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/OledGrph.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/OledGrph.o.d" -o ${OBJECTDIR}/drivers/OledGrph.o drivers/OledGrph.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/Pmod8leds.o: drivers/Pmod8leds.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/Pmod8leds.o.d 
	@${RM} ${OBJECTDIR}/drivers/Pmod8leds.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/Pmod8leds.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/Pmod8leds.o.d" -o ${OBJECTDIR}/drivers/Pmod8leds.o drivers/Pmod8leds.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodBTN.o: drivers/PmodBTN.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodBTN.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodBTN.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodBTN.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodBTN.o.d" -o ${OBJECTDIR}/drivers/PmodBTN.o drivers/PmodBTN.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodCLP.o: drivers/PmodCLP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodCLP.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodCLP.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodCLP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodCLP.o.d" -o ${OBJECTDIR}/drivers/PmodCLP.o drivers/PmodCLP.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodMAXSONAR.o: drivers/PmodMAXSONAR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodMAXSONAR.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodMAXSONAR.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodMAXSONAR.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodMAXSONAR.o.d" -o ${OBJECTDIR}/drivers/PmodMAXSONAR.o drivers/PmodMAXSONAR.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodOLED.o: drivers/PmodOLED.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodOLED.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodOLED.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodOLED.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodOLED.o.d" -o ${OBJECTDIR}/drivers/PmodOLED.o drivers/PmodOLED.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodSSD.o: drivers/PmodSSD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodSSD.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodSSD.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodSSD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodSSD.o.d" -o ${OBJECTDIR}/drivers/PmodSSD.o drivers/PmodSSD.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodTMP3.o: drivers/PmodTMP3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodTMP3.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodTMP3.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodTMP3.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodTMP3.o.d" -o ${OBJECTDIR}/drivers/PmodTMP3.o drivers/PmodTMP3.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/servo.o: drivers/servo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/servo.o.d 
	@${RM} ${OBJECTDIR}/drivers/servo.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/servo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/servo.o.d" -o ${OBJECTDIR}/drivers/servo.o drivers/servo.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodLS1.o: drivers/PmodLS1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodLS1.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodLS1.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodLS1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodLS1.o.d" -o ${OBJECTDIR}/drivers/PmodLS1.o drivers/PmodLS1.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodIR_Range.o: drivers/PmodIR_Range.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodIR_Range.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodIR_Range.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodIR_Range.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodIR_Range.o.d" -o ${OBJECTDIR}/drivers/PmodIR_Range.o drivers/PmodIR_Range.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodJSTK.o: drivers/PmodJSTK.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodJSTK.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodJSTK.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodJSTK.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodJSTK.o.d" -o ${OBJECTDIR}/drivers/PmodJSTK.o drivers/PmodJSTK.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodBuzzer.o: drivers/PmodBuzzer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodBuzzer.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodBuzzer.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodBuzzer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodBuzzer.o.d" -o ${OBJECTDIR}/drivers/PmodBuzzer.o drivers/PmodBuzzer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodKYPD.o: drivers/PmodKYPD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodKYPD.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodKYPD.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodKYPD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodKYPD.o.d" -o ${OBJECTDIR}/drivers/PmodKYPD.o drivers/PmodKYPD.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/uart.o: drivers/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/uart.o.d 
	@${RM} ${OBJECTDIR}/drivers/uart.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/uart.o.d" -o ${OBJECTDIR}/drivers/uart.o drivers/uart.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sources/main.o: sources/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sources" 
	@${RM} ${OBJECTDIR}/sources/main.o.d 
	@${RM} ${OBJECTDIR}/sources/main.o 
	@${FIXDEPS} "${OBJECTDIR}/sources/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/sources/main.o.d" -o ${OBJECTDIR}/sources/main.o sources/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/PmodMIC3.o: drivers/PmodMIC3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/PmodMIC3.o.d 
	@${RM} ${OBJECTDIR}/drivers/PmodMIC3.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/PmodMIC3.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"sources" -I"drivers" -I"plib/pic32mx/include" -MMD -MF "${OBJECTDIR}/drivers/PmodMIC3.o.d" -o ${OBJECTDIR}/drivers/PmodMIC3.o drivers/PmodMIC3.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ./plib/pic32mx/lib/libmchp_peripheral_32MX460F512L.a ./plib/pic32mx/lib/libmchp_peripheral.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    .\plib\pic32mx\lib\libmchp_peripheral_32MX460F512L.a .\plib\pic32mx\lib\libmchp_peripheral.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ./plib/pic32mx/lib/libmchp_peripheral_32MX460F512L.a ./plib/pic32mx/lib/libmchp_peripheral.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/drivers.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    .\plib\pic32mx\lib\libmchp_peripheral_32MX460F512L.a .\plib\pic32mx\lib\libmchp_peripheral.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/drivers.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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
