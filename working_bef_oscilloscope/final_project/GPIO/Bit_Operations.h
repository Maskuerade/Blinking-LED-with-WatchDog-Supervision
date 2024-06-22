/*
 * Bit_Operations.h
 *
 *  Created on: Jun 18, 2024
 *      Author: Eng Habeba
 */

#ifndef BIT_OPERATIONS_H_
#define BIT_OPERATIONS_H_


#define SET_BIT(X, BIT)            (X |=  (1 << (BIT)))
#define CLEAR_BIT(X, BIT)          (X &= ~(1 << (BIT)))
#define READ_BIT(X, BIT)           (((X) >> (BIT)) & 1)
#define TOGGLE_BIT(X, BIT)         (X ^= (1 << (BIT)))



#endif /* BIT_OPERATIONS_H_ */
