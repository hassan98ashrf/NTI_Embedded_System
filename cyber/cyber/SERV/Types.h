/*
 * Types.h
 *
 * Created: 11/12/2023 2:29:58 PM
 *  Author: Hassan
 */ 


#ifndef TYPES_H_
#define TYPES_H_

#define  NULLPTR ((void*)0)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef signed		char	     s8;			/*-128 	to +127*/
typedef unsigned	char	     u8;			/*  0 	to +255*/

typedef signed		short	    s16;			/*-32768 to +32767*/
typedef unsigned	short	    u16;			/*   0   to +65535*/

typedef signed		long	    s32;
typedef unsigned	long	    u32;
typedef unsigned   long long    u64;
typedef	float				    f32;
typedef	double				    f64;


typedef enum{
	FALSE=0X55,
	TRUE=0X80
}Bool_t;


#define  MAX_U8   ((u8)255)
#define  MIN_U8   ((u8)0)

#define  MAX_S8   ((s8)127)
#define  MIN_S8   ((s8)-128)





#endif /* TYPES_H_ */