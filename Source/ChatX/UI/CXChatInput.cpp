// CXChatInput.cpp


#include "UI/CXChatInput.h"

#include "Components/EditableTextBox.h"
#include "Player/CXPlayerController.h"

void UCXChatInput::NativeConstruct()
{
	Super::NativeConstruct();

	if (EditableTextBox_ChatInput->OnTextCommitted.IsAlreadyBound(this, &ThisClass::OnChatInputTextCommitted) == false)//IsAlreadyBound이 이벤트에 OnChatInputTextCommitted 연결되어 있니?
	{
		EditableTextBox_ChatInput->OnTextCommitted.AddDynamic(this, &ThisClass::OnChatInputTextCommitted);
	}//OnTextCommitted 사용자가 "ㅎㅇ" ->Enter시 발생(입력 확정했을 때 발생하는 이벤트)
}

void UCXChatInput::NativeDestruct()
{
	Super::NativeDestruct();

	if (EditableTextBox_ChatInput->OnTextCommitted.IsAlreadyBound(this, &ThisClass::OnChatInputTextCommitted) == true)
	{
		EditableTextBox_ChatInput->OnTextCommitted.RemoveDynamic(this, &ThisClass::OnChatInputTextCommitted);
	}
}

void UCXChatInput::OnChatInputTextCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{
	if (CommitMethod == ETextCommit::OnEnter)//CommitMethod 입력을 어떻게 확정했는지, -> ETextCommit::OnEnter 엔터 눌러 확정
	{
		APlayerController* OwningPlayerController = GetOwningPlayer();//GetOwningPlayer -현재 ui위젯 소유하는 플레이어 컨트롤러를 반환함(컨트롤러에서 만들었으니 컨트롤러가 소유)
		if (IsValid(OwningPlayerController) == true)//ㄴ 위에!! 왜 굳이APlayerController으로 반환하는가? :
		{
			ACXPlayerController* OwningCXPlayerController = Cast<ACXPlayerController>(OwningPlayerController);
			
			if (IsValid(OwningPlayerController) == true)
			{
				OwningCXPlayerController->SetChatMessageString(Text.ToString());
				EditableTextBox_ChatInput->SetText(FText());
			}
		}
	}
}
