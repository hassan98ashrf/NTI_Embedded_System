/*
 * PING.h
 *
 * Created: 10/26/2023 2:40:53 PM
 *  Author: hassa
 */ 


#ifndef PING_H_
#define PING_H_


#define PLAYER2_UP   PIND3
#define PLAYER2_DOWN PIND5
#define PLAYER1_UP   PIND6
#define PLAYER1_DOWN PIND7

#define BALL2_DOWN   PIND5
#define BALL2_UP     PIND3
#define BALL1_DOWN   PIND7
#define BALL1_UP     PIND6
#define PUZ PINC6

void Ping_Init(void);

void Ping_Play(void);



#endif /* PING_H_ */