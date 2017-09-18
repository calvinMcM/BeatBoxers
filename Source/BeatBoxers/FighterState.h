// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BeatBoxersStructs.h"
#include "FighterState.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UFighterState : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

/**
 * 
 */
class BEATBOXERS_API IFighterState
{
	GENERATED_IINTERFACE_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/** Saves a reference to the FighterWorld so it can push calls to trace etc. */
	virtual void RegisterFighterWorld(class UObject* FighterWorld) = 0;

	/** Saves a reference to the Fighter so it can act as an interface to it. */
	virtual void RegisterFighter(class UObject* Fighter) = 0;

	/** Saves a reference to the Moveset so it can push notifications about when a window ends. */
	virtual void RegisterMoveset(class UObject* Moveset) = 0;

	/** Saves a reference to the InputParser so it can notify it when control is returned. */
	virtual void RegisterInputParser(class UObject* InputParser) = 0;

	/** A check if input is being accepted right now or should be buffered. */
	virtual bool IsInputBlocked() const = 0;

	/** A check to see if the character is currently attempting to block. Relies on opponent direction received from Fighter. */
	virtual bool IsBlocking() const = 0;

	/** Begins a move window. */
	virtual void StartMoveWindow(FMoveWindow& Window, bool IsLastInSequence) = 0;

	/** Interrupts any ongoing move windows and starts a stun. */
	virtual void StartStun(float Duration) = 0;

	/** Interface to Fighter function, blocks when it sees fit. */
	virtual void SetMoveDirection(float Direction) = 0;

	/** Interface to Fighter function, blocks when it sees fit. */
	virtual void SetWantsToCrouch(bool WantsToCrouch) = 0;

	/** Interface to Fighter function, blocks when it sees fit. */
	virtual void Jump() = 0;
};
