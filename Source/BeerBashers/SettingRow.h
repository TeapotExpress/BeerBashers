#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SettingRow.generated.h"

UENUM(BlueprintType)
enum class ESettingValueMode : uint8
{
	Multiplier,
	Absolute
};
USTRUCT(BlueprintType)
struct BEERBASHERS_API FSettingRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ESettingValueMode ValueMode = ESettingValueMode::Multiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (EditCondition = "ValueMode == ESettingValueMode::Multiplier", EditConditionHides))
	float BaseValue = 1.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText DisplayName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FText> Labels;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<float> Values;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = "0"))
	int32 DefaultIndex = 0;
};