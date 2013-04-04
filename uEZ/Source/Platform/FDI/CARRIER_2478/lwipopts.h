/*
 * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 * 
 * Author: Adam Dunkels <adam@sics.se>
 *
 */
#ifndef __LWIPOPTS_H__
#define __LWIPOPTS_H__

#define TCPIP_THREAD_NAME               "lwIP"
#define TCPIP_THREAD_STACKSIZE          500
#define TCPIP_THREAD_PRIO               3

#define DEFAULT_THREAD_STACKSIZE        200
#define DEFAULT_THREAD_PRIO             1

#define LWIP_DEBUG                      0
#define DBG_TYPES_ON                    0xff
#ifdef DEG
#define ETHARP_DEBUG                    LWIP_DBG_OFF
#define NETIF_DEBUG                     LWIP_DBG_ON
#define PBUF_DEBUG                      LWIP_DBG_ON
#define API_LIB_DEBUG                   LWIP_DBG_OFF
#define API_MSG_DEBUG                   LWIP_DBG_OFF
#define SOCKETS_DEBUG                   LWIP_DBG_ON
#define ICMP_DEBUG                      LWIP_DBG_ON
#define IGMP_DEBUG                      LWIP_DBG_OFF
#define INET_DEBUG                      LWIP_DBG_OFF
#define IP_DEBUG                        LWIP_DBG_ON
#define IP_REASS_DEBUG                  LWIP_DBG_ON
#define RAW_DEBUG                       LWIP_DBG_ON
#define MEM_DEBUG                       LWIP_DBG_OFF
#define MEMP_DEBUG                      LWIP_DBG_ON
#define SYS_DEBUG                       LWIP_DBG_OFF
#define TCP_DEBUG                       LWIP_DBG_OFF
#define TCP_INPUT_DEBUG                 LWIP_DBG_ON
#define TCP_FR_DEBUG                    LWIP_DBG_OFF
#define TCP_RTO_DEBUG                   LWIP_DBG_OFF
#define TCP_CWND_DEBUG                  LWIP_DBG_OFF
#define TCP_WND_DEBUG                   LWIP_DBG_OFF
#define TCP_OUTPUT_DEBUG                LWIP_DBG_ON
#define TCP_RST_DEBUG                   LWIP_DBG_OFF
#define TCP_QLEN_DEBUG                  LWIP_DBG_OFF
#define UDP_DEBUG                       LWIP_DBG_OFF
#define TCPIP_DEBUG                     LWIP_DBG_OFF
#define PPP_DEBUG                       LWIP_DBG_OFF
#define SLIP_DEBUG                      LWIP_DBG_OFF
#define DHCP_DEBUG                      LWIP_DBG_OFF
#define AUTOIP_DEBUG                    LWIP_DBG_OFF
#define SNMP_MSG_DEBUG                  LWIP_DBG_OFF
#define SNMP_MIB_DEBUG                  LWIP_DBG_OFF
#define DNS_DEBUG                       LWIP_DBG_OFF
#endif

//#ifdef C
#define ETHARP_DEBUG                    LWIP_DBG_OFF
#define NETIF_DEBUG                     LWIP_DBG_OFF
#define PBUF_DEBUG                      LWIP_DBG_OFF
#define API_LIB_DEBUG                   LWIP_DBG_OFF
#define API_MSG_DEBUG                   LWIP_DBG_OFF
#define SOCKETS_DEBUG                   LWIP_DBG_OFF
#define ICMP_DEBUG                      LWIP_DBG_OFF
#define IGMP_DEBUG                      LWIP_DBG_OFF
#define INET_DEBUG                      LWIP_DBG_OFF
#define IP_DEBUG                        LWIP_DBG_OFF
#define IP_REASS_DEBUG                  LWIP_DBG_OFF
#define RAW_DEBUG                       LWIP_DBG_OFF
#define MEM_DEBUG                       LWIP_DBG_OFF
#define MEMP_DEBUG                      LWIP_DBG_OFF
#define SYS_DEBUG                       LWIP_DBG_OFF
#define TCP_DEBUG                       LWIP_DBG_OFF
#define TCP_INPUT_DEBUG                 LWIP_DBG_OFF
#define TCP_FR_DEBUG                    LWIP_DBG_OFF
#define TCP_RTO_DEBUG                   LWIP_DBG_OFF
#define TCP_CWND_DEBUG                  LWIP_DBG_OFF
#define TCP_WND_DEBUG                   LWIP_DBG_OFF
#define TCP_OUTPUT_DEBUG                LWIP_DBG_OFF
#define TCP_RST_DEBUG                   LWIP_DBG_OFF
#define TCP_QLEN_DEBUG                  LWIP_DBG_OFF
#define UDP_DEBUG                       LWIP_DBG_OFF
#define TCPIP_DEBUG                     LWIP_DBG_OFF
#define PPP_DEBUG                       LWIP_DBG_OFF
#define SLIP_DEBUG                      LWIP_DBG_OFF
#define DHCP_DEBUG                      LWIP_DBG_OFF
#define AUTOIP_DEBUG                    LWIP_DBG_OFF
#define SNMP_MSG_DEBUG                  LWIP_DBG_OFF
#define SNMP_MIB_DEBUG                  LWIP_DBG_OFF
#define DNS_DEBUG                       LWIP_DBG_OFF
//#endif

#define LWIP_NOASSERT                   0

#define UEZ_LWIP_SMALL                  1
#define UEZ_LWIP_MEDIUM                 2

#ifndef UEZ_LWIP_MEMORY_USAGE
    #define UEZ_LWIP_TIGHT_MEMORY           UEZ_LWIP_MEDIUM
#endif

#if (UEZ_LWIP_TIGHT_MEMORY == UEZ_LWIP_SMALL)
    // ---------------- This configuration uses about 12K of memory --------------------
    /**
     * SYS_LIGHTWEIGHT_PROT==1: if you want inter-task protection for certain
     * critical regions during buffer allocation, deallocation and memory
     * allocation and deallocation.
     */
    #define SYS_LIGHTWEIGHT_PROT            1

    /**
     * MEM_ALIGNMENT: should be set to the alignment of the CPU
     *    4 byte alignment -> #define MEM_ALIGNMENT 4
     *    2 byte alignment -> #define MEM_ALIGNMENT 2
     */
    #define MEM_ALIGNMENT                   4

    /**
     * MEM_SIZE: the size of the heap memory. If the application will send
     * a lot of data that needs to be copied, this should be set high.
     */
    #define MEM_SIZE                        12000

    /*
       ------------------------------------------------
       ---------- Internal Memory Pool Sizes ----------
       ------------------------------------------------
    */
    /**
     * MEMP_NUM_PBUF: the number of memp struct pbufs (used for PBUF_ROM and PBUF_REF).
     * If the application sends a lot of data out of ROM (or other static memory),
     * this should be set high.
     */
    #define MEMP_NUM_PBUF                   10

    /**
     * MEMP_NUM_UDP_PCB: the number of UDP protocol control blocks. One
     * per active UDP "connection".
     * (requires the LWIP_UDP option)
     */
    #define MEMP_NUM_UDP_PCB                4

    /**
     * MEMP_NUM_TCP_PCB: the number of simulatenously active TCP connections.
     * (requires the LWIP_TCP option)
     */
    #define MEMP_NUM_TCP_PCB                4

    /**
     * MEMP_NUM_TCP_PCB_LISTEN: the number of listening TCP connections.
     * (requires the LWIP_TCP option)
     */
    #define MEMP_NUM_TCP_PCB_LISTEN         4

    /**
     * MEMP_NUM_TCP_SEG: the number of simultaneously queued TCP SECTIONs.
     * (requires the LWIP_TCP option)
     */
    #define MEMP_NUM_TCP_SEG                8

    /**
     * MEMP_NUM_SYS_TIMEOUT: the number of simulateously active timeouts.
     * (requires NO_SYS==0)
     */
    #define MEMP_NUM_SYS_TIMEOUT            5

    /**
     * MEMP_NUM_NETBUF: the number of struct netbufs.
     * (only needed if you use the sequential API, like api_lib.c)
     */
    #define MEMP_NUM_NETBUF                 3

    /**
     * MEMP_NUM_NETCONN: the number of struct netconns.
     * (only needed if you use the sequential API, like api_lib.c)
     */
    #define MEMP_NUM_NETCONN                4

    /**
     * MEMP_NUM_TCPIP_MSG_API: the number of struct tcpip_msg, which are used
     * for callback/timeout API communication. 
     * (only needed if you use tcpip.c)
     */
    #define MEMP_NUM_TCPIP_MSG_API          4

    /**
     * PBUF_POOL_SIZE: the number of buffers in the pbuf pool. 
     */
    #define PBUF_POOL_SIZE                  24

    /**
     * PBUF_POOL_BUFSIZE: the size of each pbuf in the pbuf pool. The default is
     * designed to accomodate single full size TCP frame in one pbuf, including
     * TCP_MSS, IP header, and link header.
     */
    #define PBUF_POOL_BUFSIZE               64

    /*
       ---------------------------------
       ---------- TCP options ----------
       ---------------------------------
    */
    /**
     * LWIP_TCP==1: Turn on TCP.
     */
    #define LWIP_TCP                        1

    /* TCP Maximum SECTION size. */
    #define TCP_MSS                         1500

    /* TCP sender buffer space (bytes). */
    #define TCP_SND_BUF                     1500

    /**
     * TCP_WND: The size of a TCP window.
     */
    #define TCP_WND                         1500

    /**
     * TCP_MAXRTX: Maximum number of retransmissions of data SECTIONs.
     */
    #define TCP_MAXRTX                      12

    /**
     * TCP_SYNMAXRTX: Maximum number of retransmissions of SYN SECTIONs.
     */
    #define TCP_SYNMAXRTX                   4
                                 
    #define MEM_USE_POOLS                   1
    #define MEMP_USE_CUSTOM_POOLS           1
    #define MEMP_OVERFLOW_CHECK             0  // This flag should be 0 for releases!

    #define LWIP_PROVIDE_ERRNO 1

#endif // #if (UEZ_LWIP_TIGHT_MEMORY == UEZ_LWIP_SMALL)

#if (UEZ_LWIP_TIGHT_MEMORY == UEZ_LWIP_MEDIUM)
    // ---------------- This configuration uses about 64K of memory --------------------

    /**
     * SYS_LIGHTWEIGHT_PROT==1: if you want inter-task protection for certain
     * critical regions during buffer allocation, deallocation and memory
     * allocation and deallocation.
     */
    #define SYS_LIGHTWEIGHT_PROT            1

    /**
     * MEM_ALIGNMENT: should be set to the alignment of the CPU
     *    4 byte alignment -> #define MEM_ALIGNMENT 4
     *    2 byte alignment -> #define MEM_ALIGNMENT 2
     */
    #define MEM_ALIGNMENT                   4

    /**
     * MEM_SIZE: the size of the heap memory. If the application will send
     * a lot of data that needs to be copied, this should be set high.
     */
    #define MEM_SIZE                        64000

    /*
       ------------------------------------------------
       ---------- Internal Memory Pool Sizes ----------
       ------------------------------------------------
    */
    /**
     * MEMP_NUM_PBUF: the number of memp struct pbufs (used for PBUF_ROM and PBUF_REF).
     * If the application sends a lot of data out of ROM (or other static memory),
     * this should be set high.
     */
    #define MEMP_NUM_PBUF                   20

    /**
     * MEMP_NUM_UDP_PCB: the number of UDP protocol control blocks. One
     * per active UDP "connection".
     * (requires the LWIP_UDP option)
     */
    #define MEMP_NUM_UDP_PCB                4

    /**
     * MEMP_NUM_TCP_PCB: the number of simulatenously active TCP connections.
     * (requires the LWIP_TCP option)
     */
    #define MEMP_NUM_TCP_PCB                4

    /**
     * MEMP_NUM_TCP_PCB_LISTEN: the number of listening TCP connections.
     * (requires the LWIP_TCP option)
     */
    #define MEMP_NUM_TCP_PCB_LISTEN         4

    /**
     * MEMP_NUM_TCP_SEG: the number of simultaneously queued TCP SECTIONs.
     * (requires the LWIP_TCP option)
     */
    #define MEMP_NUM_TCP_SEG                8

    /**
     * MEMP_NUM_SYS_TIMEOUT: the number of simulateously active timeouts.
     * (requires NO_SYS==0)
     */
    #define MEMP_NUM_SYS_TIMEOUT            5

    /**
     * MEMP_NUM_NETBUF: the number of struct netbufs.
     * (only needed if you use the sequential API, like api_lib.c)
     */
    #define MEMP_NUM_NETBUF                 4

    /**
     * MEMP_NUM_NETCONN: the number of struct netconns.
     * (only needed if you use the sequential API, like api_lib.c)
     */
    #define MEMP_NUM_NETCONN                4

    /**
     * MEMP_NUM_TCPIP_MSG_API: the number of struct tcpip_msg, which are used
     * for callback/timeout API communication. 
     * (only needed if you use tcpip.c)
     */
    #define MEMP_NUM_TCPIP_MSG_API          8

    /**
     * PBUF_POOL_SIZE: the number of buffers in the pbuf pool. 
     */
    #define PBUF_POOL_SIZE                  32

    /**
     * PBUF_POOL_BUFSIZE: the size of each pbuf in the pbuf pool. The default is
     * designed to accomodate single full size TCP frame in one pbuf, including
     * TCP_MSS, IP header, and link header.
     */
    #define PBUF_POOL_BUFSIZE               1514

    /*
       ---------------------------------
       ---------- TCP options ----------
       ---------------------------------
    */
    /**
     * LWIP_TCP==1: Turn on TCP.
     */
    #define LWIP_TCP                        1

    /* TCP Maximum SECTION size. */
    #define TCP_MSS                         1500

    /* TCP sender buffer space (bytes). */
    #define TCP_SND_BUF                     1500

    /**
     * TCP_WND: The size of a TCP window.
     */
    #define TCP_WND                         1500

    /**
     * TCP_MAXRTX: Maximum number of retransmissions of data SECTIONs.
     */
    #define TCP_MAXRTX                      12

    /**
     * TCP_SYNMAXRTX: Maximum number of retransmissions of SYN SECTIONs.
     */
    #define TCP_SYNMAXRTX                   4
                                 
    #define MEM_USE_POOLS                   1
    #define MEMP_USE_CUSTOM_POOLS           1
    #define MEMP_OVERFLOW_CHECK             0  // This flag should be 0 for releases!

    #define LWIP_PROVIDE_ERRNO 1
#endif



#if (COMPILER_TYPE==CodeRed)
    #define MEMP_SECTION_ATTRIBUTE \
        __attribute__((section(".USBRAM"))) // Use part of the USB RAM for ethernet
#elif (COMPILER_TYPE==RowleyARM)
    #define MEMP_SECTION_ATTRIBUTE \
        __attribute__((section(".lwip")))
#elif ((COMPILER_TYPE==RowleyARM) && (PLATFORM == FDI_NXP_IRD1_0))
    #define MEMP_SECTION_ATTRIBUTE \
        __attribute__((section("AHBSRAM1")))
#elif (COMPILER_TYPE==Keil4)
    #define MEMP_SECTION_ATTRIBUTE \
        __attribute__((section("AHBSRAM1")))
#else
    #define MEMP_SECTION_ATTRIBUTE
#endif

#endif /* __LWIPOPTS_H__ */
