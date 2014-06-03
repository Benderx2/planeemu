//! C239 is a fictional aircraft btw
#ifndef __C239_H
#define __C239_H
#include <stdbool.h>
//! C239 Engine 
struct C239_747
{
	uint32_t THRUST;
	uint32_t MAX_THRUST;
	uint32_t DAMAGE;
	uint32_t TEMP;
	uint32_t WEIGHT;
	// Engine Online?
	bool ONLINE;
};
typedef struct C239_747 C239_747_t;
struct C239_747
{
	uint32_t SPAN;
	uint32_t FUEL_WEIGHT;
	uint32_t AERILON;
	uint32_t FLAPS;
	// A C239 wing has 2 engines
	ENG_C239_t* ENG1;
	ENG_C239_t* ENG2; 
};
typedef struct WING_C239 WING_C239_t;
struct TAIL_C239 
{
	// The rudder is the primary way by which the pilots 
	// control airflow if the rudder is left then it pushes
	// the air towards left causing it to push it to the left
	// + means right - means left 
	int32_t RUDDER_ANGLE;
	// the C239 like any plane has two elevators
	// one for the captain, and the other for 
	// the first pilot.
	// if the virt angle is negative the plane's
	// nose goes downwards, too much negative and the plane's
	// speed goes beyond limits pushing the nose 
	// down, too much high will cause the plane
	// to lose airspeed and lift causing it to stall, there are ways to recover from a stall,
	// like pushing the plane down, or increasing the bank angle. (AF447)
	int32_t C_ELV_ANGLE;
	int32_t F_ELV_ANGLE;
};
typedef struct TAIL_C239 TAIL_C239_t;
struct C239
{
	// Common sense, a plane has 2 wings
	WING_747_t* WING1;
	WING_747_t* WING2;
	// A tail of the plane
	TAIL_747_t* TAIL;
	uint32_t CENTRAL_FUEL_TANK_WEIGHT;
	uint32_t SPEED;
	// VR - Point of rotation
	// This speed is when the pilot in control rotates (pushes the nose up)
	// and takes off
	uint32_t VR;
	// V2 - Take off safety speed
	// It is the speed required by plane to maintain
	// accelaration till the assigned altitude by the air traffic control
	// V2 + 10 is better speed as by the airbus docs.
	uint32_t V2;

	// VMCG - Point of minimum control on ground, at this point 
	// if an engine fails or a catastrophic incident
	// happens, the rudder can only help.
	uint32_t VMCG;
};

#endif
