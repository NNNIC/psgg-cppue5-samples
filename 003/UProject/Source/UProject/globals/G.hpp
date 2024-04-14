#pragma once

#include "CoreMinimal.h"
#include "Engine.h"

class G {
private:
    static int m_logcount;
public:
    static void Log(FString s);
    static void LogInt(int s);
};
