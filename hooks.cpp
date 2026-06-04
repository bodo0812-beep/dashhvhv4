#include "hooks.h"
#include <string>

// هنا تضع العنوان (Address) الحقيقي للدالة داخل اللعبة (يتم استخراجه بـ Cheat Engine)
#define ADDR_DRAW_TEXT 0x12345678 

DrawText_t oDrawText = nullptr;

// الدالة البديلة التي سنقوم بحقنها
void __fastcall Hooked_DrawText(void* instance, const char* text, float x, float y) {
    // منطق تغيير الاسم: إذا كان النص هو "Minecraft" نستبدله بـ "DASH HVH"
    std::string currentText = text;
    if (currentText == "Minecraft") {
        return oDrawText(instance, "DASH HVH", x, y);
    }
    
    // غير ذلك، ارسم النص الأصلي
    return oDrawText(instance, text, x, y);
}

void InitHooks() {
    // 1. تهيئة MinHook
    MH_Initialize();

    // 2. تفعيل الـ Hook
    MH_CreateHook((void*)ADDR_DRAW_TEXT, &Hooked_DrawText, (void**)&oDrawText);
    MH_EnableHook((void*)ADDR_DRAW_TEXT);
    
    // (ملاحظة: لتغيير الخلفية، ستحتاج لعمل Hook لدالة الـ Render بنفس الطريقة)
}