#include <stdio.h>
#include <wchar.h>
#include <windows.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_CTYPE, ".utf8");
    wchar_t reverse_char = 0x202E; // Reverse character
    wchar_t target_name[20], new_name[30];

    printf("File to be renamed: ");
    wscanf(L"%19ls", &target_name);

    printf("\nUse character ~ to initiate reveral of characters.\n");
    printf("New filename: ");
    wscanf(L"%29ls", &new_name);

    for (int i = 0; i < wcslen(new_name); i++) {
        if (new_name[i] == L'~') {
            new_name[i] = reverse_char;
        }
    }

    int attempt_rename = _wrename(target_name, new_name);
    if (attempt_rename == 0)
    {
        printf("Rename success.\n");
    } else {
        printf("Rename failed.\n");
    }
    system("pause");
    return 0;
}