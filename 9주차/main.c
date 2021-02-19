#include <stdio.h>
#include <stdlib.h>

int displayIntro(void);
int chooseDay(void);
int compare(int chooseDay);

int displayIntro(void) {

    char name[10];
    printf("Hello, what's your name?\n");
    scanf("%s",name);
    printf("Take a guess. My birthday! %s!" , name);

}

int chooseDay(void) {
    int a;
    srand(time(NULL));
    a = (rand()%31)+1;
    return a;

}

int compare(int chooseDay) {
    int b = 0;
    while (b!=chooseDay) {
        scanf("%d",&b);
        if (b==chooseDay) {
            break;
        }
        if (b>chooseDay) {
            printf("Too big. Again\n");
        }
        if (b<chooseDay) {
            printf("Too small. Again\n");
        }


}
}

int main() {
    int c;
    displayIntro();
    c = chooseDay();
    compare(c);
    printf("Perfect. Correct!");
    return 0;

    }
