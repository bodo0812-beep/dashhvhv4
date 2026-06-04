#pragma once
#include <iostream>
#include <MinHook.h> // تأكد من إضافتها في الإعدادات

// تعريف الدوال الأصلية (المؤشرات)
typedef void(__fastcall* DrawText_t)(void*, const char*, float, float);
extern DrawText_t oDrawText;

// دالة البدء
void InitHooks();