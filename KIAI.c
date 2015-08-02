#include <stdio.h>
#include <stdlib.h>

int KIAI(char c) {
    static char previous = ' ';
    static int state = 0;
    switch (c) {
        case 'K':
            state = 1;
            break;
        case 'I':
            if (state == 1 || state == 3)
                state++;
            else
                state = 0;
            break;
        case 'A':
            if (state == 2)
                state++;
            else
                state = 0;
            break;
    }
    return state;
}

int main(int argc, char* argv[]) {
    char kiai[4] = {'K', 'I', 'A', 'I'};
    int seed = 0;
    if (argc == 2)
        seed = atoi(argv[1]);
    srand(seed);
    for (long long i = 1; ; i++) {
        char c = kiai[rand() % 4];
        printf("%c", c);
        int state = KIAI(c);
        //printf("state: %d\n", state);
        if (state == 4) {
            printf("が入るまで%lld回かかりました．", i);
            return 0;
        }
    }
}
