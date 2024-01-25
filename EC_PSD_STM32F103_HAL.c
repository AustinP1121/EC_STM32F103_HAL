/*!
 * @mainpage
 *
 *  <A NAME="Contents"></A>
 * @section contents_sec Table of Contents
 * <A HREF="#Introduction">Introduction</A><br>
 * <A HREF="#VersionLog">Version Log</A><br>
 * <A HREF="#Acronyms">Acronyms</A><br>
 * <A HREF="#Targets">Target Hardware</A><br>
 * <A HREF="#CodingStandard">Coding Standard</A><br>
 * <A HREF="#Documentation">Documentation</A><br>
 * <A HREF="#Requirements">Requirements</A><br>
 * <A HREF="#Testing">Testing</A><br>
 * <A HREF="#Tools">Tools</A><br>
 *
 * <HR>
 *
 *  <A NAME="Introduction"></A>
 * @section intro_sec Introduction
 *
 * The Hardware Abstraction Layer (HAL) provides a layer above the drivers that
 * allows application code to configure system peripherals without having to
 * write extensive driver code.
 *
 * The HAL is designed for STMicroelectronics' STM32F103xx lines of MCUs. As
 * such, it is not possible to run the HAL on processors of other families.
 *
 * This HAL is apart of the larger project EchoCommand. It is to be used on the
 * PSD, the passive sonar component of the system. To learn more about EchoCommand,
 * refer to the following on the project's onedrive repository:
 * 	<a href="https://moreheadstateedu28844-my.sharepoint.com/:p:/r/
 * 	personal/m1215550_moreheadstate_edu/Documents/Spring%202024/CS-499D/Presenta
 * 	tions/Final_Presentation_EC_Pedigo.pptx?d=w96d25434ac6a43b398d5154a55f02024&
 * 	csf=1&web=1&e=9SbGZB">Onedrive link</a>
 *
 *
 * <br><A HREF="#Contents">Table of Contents</A><br>
 *
 * <hr>
 *
 * <A NAME="VersionLog"></A>
 *
 * @section Version Version Log
 *
 * @subsection Dev 1.1.1
 * <b>2024-01-24</b>
 * <a href="">Github repository</a>
 * - Setup HAL file structure
 *
 *
 *
 *
 * <br><A HREF="#Contents">Table of Contents</A><br>
 * <hr>
 *
 * <A NAME="Acronyms"></A>
 *
 * @section Acronyms Acronyms
 * Any acronyms used within this documentation are defined here.<br>
 *
 * HAL - Hardware Abstraction Layer
 * ADC - Analog to Digital Converter <br>
 * DIO - Digital Input / Output  <br>
 * I2C - Inter-Integrated Circuit <br>
 * MCU - Micro Controller Unit    <br>
 * MEM - Memory <br>
 * PSD - Passive Sonar Device <br>
 * RAM - Random Access Memory <br>
 * ROM - Read Only Memory <br>
 * RTC - Real Time Clock  <br>
 * RTOS - Real-Time Operating System <br>
 * RCC - Reset-Control Clock <br>
 * SPI - Serial Peripheral Interface <br>
 * SYS - System <br>
 * TMR - Timer <br>
 * TSK - Task <br>
 * WDT - Watchdog Timer <br>
 *
 * <br><A HREF="#Contents">Table of Contents</A><br>
 * <hr>
 *
 *
 * <A NAME="API"></A>
 *
 * @section HAL HAL
 * Hardware Abstraction Layer (HAL) functions for each peripheral
 *
 * @subsection DMA DMA
 * Functions relating to the control and configuration of the DMA channels.
 * <br><br>
 * put function descriptions here
 * <br>
 *
 * @subsection GPIO GPIO
 * Functions relating to the control and configuration of the GPIO pins.
 * <br><br>
 * put function descriptions here
 * <br>
 *
 * @subsection I2C I2C
 * Functions relating to the control and configuration of the I2C busses.
 * <br><br>
 * put function descriptions here
 * <br>
 *
 * @subsection SPI SPI
 * Functions relating to the control and configuration of the SPI busses.
 * <br><br>
 * put function descriptions here
 * <br>
 *
 * @subsection Timers Timers
 * Functions relating to the control and configuration of system timers.
 * <br><br>
 * put function descriptions here
 * <br>
 *
 * @subsection UART UART
 * Functions relating to the control and configuration of the UART busses.
 * <br><br>
 * put function descriptions here
 * <br>
 *
 * <br><A HREF="#Contents">Table of Contents</A><br>
 * <hr>
 *
 *
 * <A NAME="CodingStandard"></A>
 *
 * @section Standard Coding Standard Overview
 *
 * MISRA C 2012 guidelines will be observed throughout the HAL.
 *
 * Since copies of the guidelines are barred behind a significantly priced
 * paywall, it is recommended that one wishing to read them purchase it.
 *
 * @subsection
 *
 * <br><A HREF="#Contents">Table of Contents</A><br>
 * <hr>
 *
 *
 * <A NAME="Documentation"></A>
 *
 * @section Docs Documentation
 *
 * Refer to the STM32F103xx reference manual located for download at STMicroelectronic's
 * website for details on the operation and programming of the STM32103xx series MCUs.
 *
 * <br><A HREF="#Contents">Table of Contents</A><br>
 * <hr>
 *
 * <A NAME="Requirements"></A>
 *
 * @section Requirements Requirements
 * Refer to the Software Requirements Specification (SRS) document on the <a href=
 * "https://moreheadstateedu28844-my.sharepoint.com/:w:/r/personal/m1215550_
 * moreheadstate_edu/Documents/Spring%202024/CS-499D/Software/EC_PSD_SRS_V1.0.
 * docx?d=w0b13341fbdcc44b9a310257ac57c7fea&csf=1&web=1&e=4fekF7">OneDrive Repository</a>.
 *
 * The requirements within the SRS are subject to change.
 *
 * <br><A HREF="#Contents">Table of Contents</A><br>
 * <hr>
 *
 * <A NAME="Testing"></A>
 *
 * @section Validation System Testing and Validation
 *
 * Test cases will be created and implemented based on black-box testing methods.
 *
 * By setting an expected input and output for the component (i.e. a HAL module function),
 * the result of each test will be used to evaluate if requirements have been
 * met.
 *
 * Performance metrics (number of clock cycles consumed by a task) will be recorded
 * and analyzed via Metrix++.
 *
 * @subsection Bugs Bug Tracking
 * Bugs and other software issues are documented and triaged on the project's GitHub.
 *
 *
 * @subsection Tools Tools
 *
 * - Unity/Throw the Switch
 * - Metrix++
 *
 * <br><A HREF="#Contents">Table of Contents</A><br>
 * <hr>
 */

#include "Utilities/STM32F103xx_Types.h"

