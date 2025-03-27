#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

// تعريف هيكل لمستخدم
struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

// قائمة بالمستخدمين المسجلين
struct User users[MAX_USERS];
int userCount = 0;

// تسجيل مستخدم جديد
void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("لا يمكن تسجيل المزيد من المستخدمين\n");
        return;
    }

    struct User newUser;
    printf("الرجاء إدخال اسم المستخدم: ");
    scanf("%s", newUser.username);
    printf("الرجاء إدخال كلمة المرور: ");
    scanf("%s", newUser.password);

    users[userCount++] = newUser;
    printf("تم تسجيل المستخدم بنجاح\n");
}

// تسجيل الدخول
void login() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("الرجاء إدخال اسم المستخدم: ");
    scanf("%s", username);
    printf("الرجاء إدخال كلمة المرور: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("تم تسجيل الدخول بنجاح\n");
            return;
        }
    }

    printf("فشل تسجيل الدخول. يرجى التحقق من اسم المستخدم وكلمة المرور\n");
}

int main() {
    int choice;

    while (1) {
        printf("الرجاء اختيار العملية:\n");
        printf("1. تسجيل مستخدم جديد\n");
        printf("2. تسجيل الدخول\n");
        printf("3. الخروج\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                login();
                break;
            case 3:
                return 0;
            default:
                printf("اختيار غير صحيح. يرجى المحاولة مرة أخرى\n");
        }
    }

    return 0;
}
