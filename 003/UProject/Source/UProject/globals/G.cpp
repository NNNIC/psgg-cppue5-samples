#include "G.hpp"

#define LOG(STR) UE_LOG(LogTemp, Log, TEXT(STR))

int G::m_logcount = 0;
void G::Log(FString s)
{
	UE_LOG(LogTemp, Log, TEXT("%s"), *s);	
	if (GEngine)
    {
        m_logcount++; // ���b�Z�[�W����ӂɎ��ʂ���L�[�B�����L�[���g�p����ƁA�ȑO�̃��b�Z�[�W�͐V�������̂ŏ㏑������܂��B
        float TimeToDisplay = 5.0f; // ���b�Z�[�W����ʏ�ɕ\������鎞�ԁi�b�j�B
        FColor DisplayColor = FColor::Yellow; // ���b�Z�[�W�̐F�B
        FString Message = s; // �\�����郁�b�Z�[�W�B

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
        m_logcount++; // ���b�Z�[�W����ӂɎ��ʂ���L�[�B�����L�[���g�p����ƁA�ȑO�̃��b�Z�[�W�͐V�������̂ŏ㏑������܂��B
        float TimeToDisplay = 5.0f; // ���b�Z�[�W����ʏ�ɕ\������鎞�ԁi�b�j�B
        FColor DisplayColor = FColor::Yellow; // ���b�Z�[�W�̐F�B
        FString Message = buf; // �\�����郁�b�Z�[�W�B

        GEngine->AddOnScreenDebugMessage(m_logcount, TimeToDisplay, DisplayColor, Message);
    }
}