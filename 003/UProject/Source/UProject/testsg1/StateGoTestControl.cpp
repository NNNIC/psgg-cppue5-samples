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
void StateGoTestControl::PreemptiveInit(StateGoData& data)
{
    data.m_cur = findFuncPtrIndex(&StateGoTestControl::S_START);
    data.m_next = 0;
}

int StateGoTestControl::PreemptiveCallUpdate(StateGoData& data)
{
    if (data.m_cur < 0  || data.m_cur >= STATE_MAX) return -1;
    if (data.m_next < 0 || data.m_next >= STATE_MAX) data.m_next = 0;

    m_curstate = m_statelist[ data.m_cur];
    m_nextstate = m_statelist[data.m_next];

    if (CheckState(&StateGoTestControl::S_END)) return -9999;

    m_data = &data; 

    _update();

    data.m_cur = findFuncPtrIndex(m_curstate);
    data.m_next = findFuncPtrIndex(m_nextstate);

    //_ASSERT(data.m_cur == (int)m_state);

    return data.m_cur;
}

void StateGoTestControl::PreemptiveCallTest()
{
    StateGoData data;
    PreemptiveInit(data);
    while (true) {
        int r = PreemptiveCallUpdate(data);
        if (r < 0) break;
    }
}


//  states                                   [STATE-GO OUTPUT START] indent(0) $/^S_/$
//             psggConverterLib.dll converted from psgg-file:StateGoTestControl.psgg                                // *DoNotEdit*
                                                                            // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_0000                                                                  // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void StateGoTestControl::S_0000(bool bFirst)                                // *DoNotEdit*
{                                                                           // *DoNotEdit*
    m_state = ES_0000;                                                      // *DoNotEdit*
    if (bFirst)                                                             // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        m_data->m_index = 0;                                                // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    if (!HasNextState())                                                    // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        Goto(&StateGoTestControl::S_0002);                                  // *DoNotEdit*
    }                                                                       // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_0001                                                                  // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void StateGoTestControl::S_0001(bool bFirst)                                // *DoNotEdit*
{                                                                           // *DoNotEdit*
    m_state = ES_0001;                                                      // *DoNotEdit*
    if (bFirst)                                                             // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        G::Log("A state-machine is running\n");                             // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    if (!HasNextState())                                                    // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        Goto(&StateGoTestControl::S_0000);                                  // *DoNotEdit*
    }                                                                       // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_0002                                                                  // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void StateGoTestControl::S_0002(bool bFirst)                                // *DoNotEdit*
{                                                                           // *DoNotEdit*
    m_state = ES_0002;                                                      // *DoNotEdit*
    if (bFirst)                                                             // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        G::LogInt(m_data->m_index);                                         // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    if (!HasNextState())                                                    // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        Goto(&StateGoTestControl::S_0003);                                  // *DoNotEdit*
    }                                                                       // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_0003                                                                  // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void StateGoTestControl::S_0003(bool bFirst)                                // *DoNotEdit*
{                                                                           // *DoNotEdit*
    m_state = ES_0003;                                                      // *DoNotEdit*
    m_data->m_index++;                                                      // *DoNotEdit*
    if (m_data->m_index <= 10) { Goto( &StateGoTestControl::S_0002 ); }     // *DoNotEdit*
    else { Goto( &StateGoTestControl::S_END ); }                            // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_END                                                                   // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void StateGoTestControl::S_END(bool bFirst)                                 // *DoNotEdit*
{                                                                           // *DoNotEdit*
    m_state = ES_END;                                                       // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_START                                                                 // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void StateGoTestControl::S_START(bool bFirst)                               // *DoNotEdit*
{                                                                           // *DoNotEdit*
    m_state = ES_START;                                                     // *DoNotEdit*
    Goto(&StateGoTestControl::S_0001);                                      // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
//                                           [STATE-GO OUTPUT END]
