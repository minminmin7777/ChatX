// CXChatInput.h

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CXChatInput.generated.h"

class UEditableTextBox;// 사용자가 글자를 입력할 수 있는UI 입력칸

/**
 *
 */
UCLASS()
class CHATX_API UCXChatInput : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;//UI위젯의 핵심 라이프사이클 함수임 일반 객체 생성자와 달리 화면에 나타날 준비가 되었을때 호출 비긴플레이 비슷
	// Native 블루프린트가 아닌 코드에서 직접처리하는것을 의미 / Construct UI 구성요소 초기 설정
	virtual void NativeDestruct() override;

protected:
	UFUNCTION()
	void OnChatInputTextCommitted(const FText& Text, ETextCommit::Type CommitMethod);

public:
	UPROPERTY(meta = (BindWidget))//얘가 있으면 EditableTextBox_ChatInput 얘가 하이어라키에 있어야함
		// meta = 이 UPROPERTY에 이런 추가 설정 적용해
		//BindWidget : 블루프린트에서 같은 이름의 위젯을 찾아 이 변수와 연결해라는 뜻 얘가 언리얼에 요청을 보냄
	TObjectPtr<UEditableTextBox> EditableTextBox_ChatInput;// EditableTextBox(채팅입력하는) 객체를 가리킴

};