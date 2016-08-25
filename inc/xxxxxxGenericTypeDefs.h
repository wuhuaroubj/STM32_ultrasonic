/*******************************************************************

                  Generic Type Definitions

********************************************************************
 FileName:        GenericTypeDefs.h
 Dependencies:    None
 Processor:       
 Compiler:        
 Company:         
 author:		  jason
********************************************************************
 File Description:

 Change History:
  Rev   Date         Description
  1.1   2016/08/24     Add base signed types

*******************************************************************/

#ifndef __GENERIC_TYPE_DEFS_H_
#define __GENERIC_TYPE_DEFS_H_


/* Specify an extension for GCC based compilers */
#if defined(__GNUC__)
#define __EXTENSION __extension__
#else
#define __EXTENSION
#endif

#if !defined(__PACKED)
    #define __PACKED
#endif
/* get compiler defined type definitions (NULL, size_t, etc) */
#include <stddef.h> 

typedef enum _BOOL { FALSE = 0, TRUE } BOOL;    /* Undefined size */
typedef enum _BIT { CLEAR = 0, SET } BIT;

#define PUBLIC                                  /* Function attributes */
#define PROTECTED
#define PRIVATE   static

/* INT is processor specific in length may vary in size */
typedef signed int          INT;
typedef signed char         INT8;
typedef signed short int    INT16;
typedef signed long int     INT32;

/* UINT is processor specific in length may vary in size */
typedef unsigned int        UINT;
typedef unsigned char       UINT8;
typedef unsigned short int  UINT16;
typedef unsigned long int   UINT32;     /* other name for 32-bit integer */

typedef union
{
    UINT8 Val;
    struct
    {
        __EXTENSION UINT8 b0:1;
        __EXTENSION UINT8 b1:1;
        __EXTENSION UINT8 b2:1;
        __EXTENSION UINT8 b3:1;
        __EXTENSION UINT8 b4:1;
        __EXTENSION UINT8 b5:1;
        __EXTENSION UINT8 b6:1;
        __EXTENSION UINT8 b7:1;
    } bits;
} UINT8_VAL, UINT8_BITS;

typedef union 
{
    UINT16 Val;
    UINT8 v[2] __PACKED;
    struct __PACKED
    {
        UINT8 LB;
        UINT8 HB;
    } byte;
    struct __PACKED
    {
        __EXTENSION UINT8 b0:1;
        __EXTENSION UINT8 b1:1;
        __EXTENSION UINT8 b2:1;
        __EXTENSION UINT8 b3:1;
        __EXTENSION UINT8 b4:1;
        __EXTENSION UINT8 b5:1;
        __EXTENSION UINT8 b6:1;
        __EXTENSION UINT8 b7:1;
        __EXTENSION UINT8 b8:1;
        __EXTENSION UINT8 b9:1;
        __EXTENSION UINT8 b10:1;
        __EXTENSION UINT8 b11:1;
        __EXTENSION UINT8 b12:1;
        __EXTENSION UINT8 b13:1;
        __EXTENSION UINT8 b14:1;
        __EXTENSION UINT8 b15:1;
    } bits;
} UINT16_VAL, UINT16_BITS;

typedef union
{
    UINT32 Val;
    UINT16 w[2] __PACKED;
    UINT8  v[4] __PACKED;
    struct __PACKED
    {
        UINT16 LW;
        UINT16 HW;
    } word;
    struct __PACKED
    {
        UINT8 LB;
        UINT8 HB;
        UINT8 UB;
        UINT8 MB;
    } byte;
    struct __PACKED
    {
        UINT16_VAL low;
        UINT16_VAL high;
    }wordUnion;
    struct __PACKED
    {
        __EXTENSION UINT8 b0:1;
        __EXTENSION UINT8 b1:1;
        __EXTENSION UINT8 b2:1;
        __EXTENSION UINT8 b3:1;
        __EXTENSION UINT8 b4:1;
        __EXTENSION UINT8 b5:1;
        __EXTENSION UINT8 b6:1;
        __EXTENSION UINT8 b7:1;
        __EXTENSION UINT8 b8:1;
        __EXTENSION UINT8 b9:1;
        __EXTENSION UINT8 b10:1;
        __EXTENSION UINT8 b11:1;
        __EXTENSION UINT8 b12:1;
        __EXTENSION UINT8 b13:1;
        __EXTENSION UINT8 b14:1;
        __EXTENSION UINT8 b15:1;
        __EXTENSION UINT8 b16:1;
        __EXTENSION UINT8 b17:1;
        __EXTENSION UINT8 b18:1;
        __EXTENSION UINT8 b19:1;
        __EXTENSION UINT8 b20:1;
        __EXTENSION UINT8 b21:1;
        __EXTENSION UINT8 b22:1;
        __EXTENSION UINT8 b23:1;
        __EXTENSION UINT8 b24:1;
        __EXTENSION UINT8 b25:1;
        __EXTENSION UINT8 b26:1;
        __EXTENSION UINT8 b27:1;
        __EXTENSION UINT8 b28:1;
        __EXTENSION UINT8 b29:1;
        __EXTENSION UINT8 b30:1;
        __EXTENSION UINT8 b31:1;
    } bits;
} UINT32_VAL;


#undef __EXTENSION

#endif /* __GENERIC_TYPE_DEFS_H_ */

