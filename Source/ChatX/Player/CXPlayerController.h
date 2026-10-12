// CXPlayerController.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CXPlayerController.generated.h"

class UCXChatInput;

/**
 *
 */
UCLASS()
class CHATX_API ACXPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	void SetChatMessageString(const FString& InChatMessageString);

	void PrintChatMessageString(const FString& InChatMessageString);

	UFUNCTION(Client, Reliable)
	void ClientRPCPrintChatMessageString(const FString& InChatMessageString);

	UFUNCTION(Server, Reliable)
	void ServerRPCPrintChatMessageString(const FString& InChatMessageString);

protected:
	UPROPERTY(EditDefaultsOnly)//디폴트 값만 수정 가능하게
	TSubclassOf<UCXChatInput> ChatInputWidgetClass;//에디터에서 어떤 채팅 위젯 설계도를 사용할지 정하게 해줌

	UPROPERTY()
	TObjectPtr<UCXChatInput> ChatInputWidgetInstance;//만들어진 채팅 위젯 객체 저장하는 변수.그리고 실제로 만들어진 채팅 위젯은 여기 저장
	//TSubclassOf는 클래스 자체를 가리키고	TObjectPtr는 클래스로 만들어진 실제 객체를 가리킴

	FString ChatMessageSrting;
};


