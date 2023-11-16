#include <stdio.h>
#include <windows.h>
#include <conio.h>

void simulateKeyboardInput(char character) {
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = 0;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;

    // 转换字符为键值并按下
    input.ki.wVk = VkKeyScanA(character);
    input.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &input, sizeof(INPUT));

    // 松开按键
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}

int main() {

    char str[40];
    printf("Please input the path of file:\n");
    scanf("%s",str);//读入文件路径
    char a;
    while((a=getchar())!='\n'&&a!=EOF){
        ;

    }

    FILE *file = fopen(str, "r"); // 打开文件
    if (file == NULL) {
        perror("not have the file");
        return 1;
    }
    char ch;
    printf("please press any key except of ESC continue......\n");
    while(ch=getch()){ /*监控键盘输入*/
        if(ch==27){
            break;
        }
        else{
            //为光标移到提供时间
            for (int i = 15; i >0; i--)
            {
                printf("Please move the Cursor to that you want copy position\n");
                printf("Still have %ds\n",i);
                Sleep(1000);
            }
                while (!feof(file)) {
            char character = fgetc(file);

            // 检测文件结束
            if (feof(file)) {
                break;
            }

            // 模拟键盘输出
            simulateKeyboardInput(character);

            // 添加适当的延时模拟人为输入的速度
            Sleep(100);
            }
            fclose(file); // 关闭文件
            exit(0);      //直接结束
            //printf("press ESC to stop!!!\n");
        }

    }
    return 0;
}