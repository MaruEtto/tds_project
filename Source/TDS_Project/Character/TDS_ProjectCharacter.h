// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TDS_Project/FuncLibrary/Types.h"
#include "TDS_ProjectCharacter.generated.h"

UCLASS(Blueprintable)
class ATDS_ProjectCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ATDS_ProjectCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override; // ������� ��������� �������������� ����� ������

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	EMovementState MovementState = EMovementState::Run_State;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FCharacterSpeed MovementInfo;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool SprintRunEnabled = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool WalkEnabled = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool AimEnabled = false;

	UFUNCTION()
		void InputAxisX(float Value);
	UFUNCTION()
		void InputAxisY(float Value);

	float AxisX = 0.0f;
	float AxisY = 0.0f;

	// Tick func
	UFUNCTION()
		void MovementTick(float DeltaTime);

	UFUNCTION(BlueprintCallable) // BlueprintCallable ��������� ������� ������ ������� �� ���������
		void CharacterUpdate();
	UFUNCTION(BlueprintCallable)
		void ChangeMovementState();

};