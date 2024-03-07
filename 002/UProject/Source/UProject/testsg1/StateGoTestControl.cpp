#include "StateGoTestControl.hpp"



void StateGoTestControl::_update()
{
        while(true) {
            bool bFirst =false;
            m_bNoWait = false;
            if (m_nextstate != nullptr) {
                m_curstate  = m_nextstate;
                m_nextstate = nullptr;
                bFirst = true;
            }
            if (m_curstate != nullptr) {
                (this->*m_curstate)(bFirst);
            }
            if (!m_bNoWait) break;
        }	
}

void StateGoTestControl::Start()
{
	 Goto(&StateGoTestControl::S_START);
}
bool StateGoTestControl::IsEnd()
{
	 return CheckState(&StateGoTestControl::S_END);
}
void StateGoTestControl::Update() 
{
	_update();
}

//  states                                   [STATE-GO OUTPUT START] indent(0) $/^S_/$
//             psggConverterLib.dll converted from psgg-file:StateGoTestControl.psgg                                // *DoNotEdit*
                                                                            // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_0001                                                                  // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void StateGoTestControl::S_0001(bool bFirst)                                // *DoNotEdit*
{                                                                           // *DoNotEdit*
    if (bFirst)                                                             // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        Log("A state-machine is running\n");                                // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    if (!HasNextState())                                                    // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        Goto(&StateGoTestControl::S_GOSUB);                                 // *DoNotEdit*
    }                                                                       // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_END                                                                   // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void StateGoTestControl::S_END(bool bFirst)                                 // *DoNotEdit*
{                                                                           // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_EVEN_OR_ODD                                                           // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void StateGoTestControl::S_EVEN_OR_ODD(bool bFirst)                         // *DoNotEdit*
{                                                                           // *DoNotEdit*
    if (m_i % 2 == 0) { Goto( &StateGoTestControl::S_PRINT_EVEN ); }        // *DoNotEdit*
    else { Goto( &StateGoTestControl::S_PRINT_ODD ); }                      // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_GOSUB                                                                 // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void StateGoTestControl::S_GOSUB(bool bFirst)                               // *DoNotEdit*
{                                                                           // *DoNotEdit*
    GoSubState(&StateGoTestControl::S_SUBSTART1,&StateGoTestControl::S_LOOP);                                       // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_LOOP                                                                  // *DoNotEdit*
    Loop 10 times                                                           // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void StateGoTestControl::S_LOOP(bool bFirst)                                // *DoNotEdit*
{                                                                           // *DoNotEdit*
    m_i=0;                                                                  // *DoNotEdit*
    Goto(&StateGoTestControl::S_LOOP_LoopCheckAndGosub____);                // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
void StateGoTestControl::S_LOOP_LoopCheckAndGosub____(bool bFirst)          // *DoNotEdit*
{                                                                           // *DoNotEdit*
    if (m_i < 10) GoSubState(&StateGoTestControl::S_SUBSTART,&StateGoTestControl::S_LOOP_LoopNext____);             // *DoNotEdit*
    else               Goto(&StateGoTestControl::S_END);                    // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
void StateGoTestControl::S_LOOP_LoopNext____(bool bFirst)                   // *DoNotEdit*
{                                                                           // *DoNotEdit*
    m_i++;                                                                  // *DoNotEdit*
    Goto(&StateGoTestControl::S_LOOP_LoopCheckAndGosub____);                // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_PRINT_EVEN                                                            // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void StateGoTestControl::S_PRINT_EVEN(bool bFirst)                          // *DoNotEdit*
{                                                                           // *DoNotEdit*
    if (bFirst)                                                             // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        //printf_s("Count : %d (EVEN)\n",m_i);                              // *DoNotEdit*
        Log("EVEN");                                                        // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    if (!HasNextState())                                                    // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        Goto(&StateGoTestControl::S_SUBRETURN);                             // *DoNotEdit*
    }                                                                       // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_PRINT_ODD                                                             // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void StateGoTestControl::S_PRINT_ODD(bool bFirst)                           // *DoNotEdit*
{                                                                           // *DoNotEdit*
    if (bFirst)                                                             // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        //printf_s("Count : %d (ODD)\n",m_i);                               // *DoNotEdit*
        Log("ODD");                                                         // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    if (!HasNextState())                                                    // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        Goto(&StateGoTestControl::S_SUBRETURN);                             // *DoNotEdit*
    }                                                                       // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_START                                                                 // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void StateGoTestControl::S_START(bool bFirst)                               // *DoNotEdit*
{                                                                           // *DoNotEdit*
    Goto(&StateGoTestControl::S_0001);                                      // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_SUBRETURN                                                             // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void StateGoTestControl::S_SUBRETURN(bool bFirst)                           // *DoNotEdit*
{                                                                           // *DoNotEdit*
    ReturnState();                                                          // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_SUBRETURN1                                                            // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void StateGoTestControl::S_SUBRETURN1(bool bFirst)                          // *DoNotEdit*
{                                                                           // *DoNotEdit*
    ReturnState();                                                          // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_SUBSTART                                                              // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void StateGoTestControl::S_SUBSTART(bool bFirst)                            // *DoNotEdit*
{                                                                           // *DoNotEdit*
    Goto(&StateGoTestControl::S_EVEN_OR_ODD);                               // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_SUBSTART1                                                             // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void StateGoTestControl::S_SUBSTART1(bool bFirst)                           // *DoNotEdit*
{                                                                           // *DoNotEdit*
    Goto(&StateGoTestControl::S_WORK);                                      // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_WORK                                                                  // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void StateGoTestControl::S_WORK(bool bFirst)                                // *DoNotEdit*
{                                                                           // *DoNotEdit*
    if (bFirst)                                                             // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        Log("A subroutine is running.\n");                                  // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    if (!HasNextState())                                                    // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        Goto(&StateGoTestControl::S_SUBRETURN1);                            // *DoNotEdit*
    }                                                                       // *DoNotEdit*
}                                                                           // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
//                                           [STATE-GO OUTPUT END]

static int m_logline = 0;
// write your code here!
void StateGoTestControl::Log(FString s)
{
    UE_LOG(LogTemp, Log, TEXT("%s"), *s);
    if (GEngine)
    {
        m_logline++; // メッセージを一意に識別するキー。同じキーを使用すると、以前のメッセージは新しいもので上書きされます。
        float TimeToDisplay = 5.0f; // メッセージが画面上に表示される時間（秒）。
        FColor DisplayColor = FColor::Yellow; // メッセージの色。
        FString Message = s; // 表示するメッセージ。

        GEngine->AddOnScreenDebugMessage(m_logline, TimeToDisplay, DisplayColor, Message);
    }
}
