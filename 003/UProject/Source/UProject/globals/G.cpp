#include "G.hpp"

#define LOG(STR) UE_LOG(LogTemp, Log, TEXT(STR))

int G::m_logcount = 0;
void G::Log(FString s)
{
	UE_LOG(LogTemp, Log, TEXT("%s"), *s);	
	if (GEngine)
    {
        m_logcount++; // メッセージを一意に識別するキー。同じキーを使用すると、以前のメッセージは新しいもので上書きされます。
        float TimeToDisplay = 5.0f; // メッセージが画面上に表示される時間（秒）。
        FColor DisplayColor = FColor::Yellow; // メッセージの色。
        FString Message = s; // 表示するメッセージ。

        GEngine->AddOnScreenDebugMessage(m_logcount, TimeToDisplay, DisplayColor, Message);
    }
}

void G::LogInt(int n)
{
    char buf[256];
    sprintf_s(buf, "%d", n);

    //UE_LOG(LogTemp, Log, "%s", &buf[0]);
    if (GEngine)
    {
        m_logcount++; // メッセージを一意に識別するキー。同じキーを使用すると、以前のメッセージは新しいもので上書きされます。
        float TimeToDisplay = 5.0f; // メッセージが画面上に表示される時間（秒）。
        FColor DisplayColor = FColor::Yellow; // メッセージの色。
        FString Message = buf; // 表示するメッセージ。

        GEngine->AddOnScreenDebugMessage(m_logcount, TimeToDisplay, DisplayColor, Message);
    }
}