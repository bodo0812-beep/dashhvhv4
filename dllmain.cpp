#include <windows.h>
#include <thread>

// هذه الدالة هي "قلب الهاك"، هنا سنكتب كود تغيير الخلفية والاسم لاحقاً
void MainThread(HMODULE hModule) {
    // حلقة تكرارية (Loop) ليبقى الهاك يعمل طوال فترة اللعب
    while (true) {
        // هنا سنضيف كود الـ Hook الخاص بنا لاحقاً
        
        // Sleep يمنع استهلاك المعالج بالكامل (مهم جداً!)
        Sleep(100); 
    }
}

// هذه الدالة هي "باب الدخول" الذي يستدعيه الويندوز عند تحميل الملف
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        // عند تحميل الـ DLL، نقوم بإنشاء Thread جديد لتشغيل الهاك
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, 0);
        break;
    }
    return TRUE;
}